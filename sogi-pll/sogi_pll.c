/*
created by suBardagi
Unified Architecture
*/

#include "sogi_pll.h"
#include "math.h"
#include "tests/adc_test/adc_test.h"
#include "pid/pid.h"

extern MeasuredData_t measured_values;

// Ortak Statik Değişkenler (Sadece 1 kere tanımlanır)
static uint16_t zcd_timeout_counter = 0;
static float prev_vac_zcd = 0.0f;


void SOGI_PLL_Init(SOGI_PLL_t *pll, float Ts, float kp, float ki, float f_nominal) 
{   
    // --- 1. ORTAK İLK DEĞER ATAMALARI ---
    pll->estimated_freq = f_nominal;
    pll->va = 0.0f;
    pll->vb = 0.0f;
    pll->theta = 0.0f;
    pll->sin_theta = 0.0f;
    pll->cos_theta = 1.0f;
    pll->grid_freq = f_nominal;
    pll->zcd = 0;
    pll->Ts = Ts;
    pll->pd_error = 0.0f;
    pll->is_locked = 0;

    pid_init(&(pll->pi_ctrl), kp, ki, 0.0f, 0, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    
    pll->pi_ctrl.use_limits = 1;
    pll->pi_ctrl.integral_min = -100.0f; // Limitleri standartlaştırdık
    pll->pi_ctrl.integral_max = 100.0f;
    pll->pi_ctrl.output_min   = -100.0f;
    pll->pi_ctrl.output_max   = 100.0f;
    pll->pi_ctrl.use_dt = 1;
    pll->pi_ctrl.dt = pll->Ts;
    pll->pi_ctrl.deriv_filter_alpha = 0.0f;
    pll->pi_ctrl.derivative_filtered = 0.0f;

    // --- 2. YÖNTEME ÖZEL KATSAYI ATAMALARI ---
#ifdef USE_TUSTIN
    int i = 0;
    for(i = 0; i < 3; i++) {
        pll->u[i] = 0.0f;
        pll->osg_u[i] = 0.0f;
        pll->osg_qu[i] = 0.0f;
    }

    float wn = f_nominal * TWO_PI;
    float k = 0.5f; 
    
    float x = 2.0f * k * wn * Ts;
    float y = (wn * Ts) * (wn * Ts);
    float temp = (1.0f / (x + y + 4.0f));

    pll->osg_b0 = x * temp;
    pll->osg_b2 = -1.0f * pll->osg_b0;
    pll->osg_a1 = 2.0f * (4.0f - y) * temp;
    pll->osg_a2 = (x - y - 4.0f) * temp;
    pll->osg_qb0 = (k * y) * temp;
    pll->osg_qb1 = 2.0f * pll->osg_qb0;
    pll->osg_qb2 = pll->osg_qb0;
#endif
}


void SOGI_PLL_Update(SOGI_PLL_t *pll, float vac) 
{
    // --- 1. ORTAK ZCD (Sıfır Geçişi) KONTROLÜ ---
    float zcd_threshold = 0.1f; 
    uint32_t timeout_limit = (uint32_t)(0.03f / pll->Ts);

    if((vac > zcd_threshold && prev_vac_zcd <= zcd_threshold) || 
       (vac < -zcd_threshold && prev_vac_zcd >= -zcd_threshold)) {
        zcd_timeout_counter = 0;
    } else {
        zcd_timeout_counter++;
    }
    prev_vac_zcd = vac;

    // --- 2. ORTAK FREERUN (KOPMA) KORUMASI ---
    if(zcd_timeout_counter >= timeout_limit)
    {
        pll->va = 0.0f;
        pll->vb = 0.0f;
        pid_reset(&(pll->pi_ctrl)); 
        
#ifdef USE_TUSTIN
        int j = 0;
        for(j = 0; j < 3; j++) {
            pll->u[j] = 0.0f; pll->osg_u[j] = 0.0f; pll->osg_qu[j] = 0.0f;
        }
#endif

        pll->theta += OMEGA_NOMINAL * pll->Ts;
        if (pll->theta >= TWO_PI) pll->theta -= TWO_PI;
        else if (pll->theta < 0.0f) pll->theta += TWO_PI;
        
        pll->sin_theta = sinf(pll->theta);
        pll->cos_theta = cosf(pll->theta);
        
        pll->grid_freq = 50.0f;
        pll->estimated_freq = 50.0f;
        pll->is_locked = 0;
        return; 
    }


    // --- 3. SOGI FİLTRESİ (ŞALTERLİ BÖLGE) ---
#ifdef USE_TUSTIN
    // TUSTIN MATEMATİĞİ
    pll->u[0] = vac;
    pll->osg_u[0] = (pll->osg_b0 * (pll->u[0] - pll->u[2])) + (pll->osg_a1 * pll->osg_u[1]) + (pll->osg_a2 * pll->osg_u[2]);
    pll->osg_qu[0] = (pll->osg_qb0 * pll->u[0]) + (pll->osg_qb1 * pll->u[1]) + (pll->osg_qb2 * pll->u[2]) + (pll->osg_a1 * pll->osg_qu[1]) + (pll->osg_a2 * pll->osg_qu[2]);

    pll->osg_u[2] = pll->osg_u[1]; pll->osg_u[1] = pll->osg_u[0];
    pll->osg_qu[2] = pll->osg_qu[1]; pll->osg_qu[1] = pll->osg_qu[0];
    pll->u[2] = pll->u[1]; pll->u[1] = pll->u[0];

    pll->va = pll->osg_u[0];
    pll->vb = pll->osg_qu[0];

#else
    // EULER MATEMATİĞİ
    float err1 = vac - pll->va;
    float err2 = (err1 * 1.41421356f) - pll->vb; 
    float sogi_omega = pll->estimated_freq * TWO_PI;

    pll->va += (err2 * sogi_omega) * pll->Ts;
    pll->vb += (pll->va * sogi_omega) * pll->Ts;
#endif


    // --- 4. ORTAK PARK DÖNÜŞÜMÜ, PID VE FREKANS HESABI ---
    float raw_pd_error = (pll->va * pll->cos_theta) + (pll->vb * pll->sin_theta);
    static float filtered_pd_error = 0.0f;
    filtered_pd_error = 0.95f * filtered_pd_error + 0.05f * raw_pd_error;
    pll->pd_error = filtered_pd_error; 

    float pi_out = pid_compute(&(pll->pi_ctrl), filtered_pd_error, 0.0f);
    
    // Euler kodunda hesapladığın ama unuttuğun PI filtresini buraya ekledik (İstersen kullan)
    static float filtered_pi_out = 0.0f;
    filtered_pi_out = 0.9f * filtered_pi_out + 0.1f * pi_out;

    float omega = pi_out + OMEGA_NOMINAL; 
    pll->grid_freq = omega / TWO_PI; 
    pll->estimated_freq = pll->grid_freq;

    pll->theta += omega * pll->Ts;
    if (pll->theta >= TWO_PI) pll->theta -= TWO_PI;
    else if (pll->theta < 0.0f) pll->theta += TWO_PI;

    pll->sin_theta = sinf(pll->theta);
    pll->cos_theta = cosf(pll->theta);

    pll->zcd = (pll->sin_theta > 0.0f) ? 1 : 0;

    // Kilitlenme kontrolü
    if((pll->estimated_freq > 48.0f) && (pll->estimated_freq < 52.0f) && (__builtin_fabsf(vac) > 0.5f)) {
        pll->is_locked = 1;
    } else {
        pll->is_locked = 0;
    }
}
