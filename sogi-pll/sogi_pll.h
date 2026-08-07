/*
created by suBardagi
Unified Architecture
*/

#ifndef _SOGI_PLL_H_
#define _SOGI_PLL_H_

#include "stdint.h"
#include "pid/pid.h"

// --- SOGI MOD ŞALTERİ ---
// Tustin için bu satırı açık bırak, Euler için yoruma al (//)
#define USE_TUSTIN  

// --- ORTAK SABİTLER ---
#define TWO_PI 6.28318530718f
#define OMEGA_NOMINAL (50.0f * TWO_PI)

typedef struct 
{
    // 1. HER İKİ MOD İÇİN DE ORTAK DEĞİŞKENLER
    float estimated_freq;
    float va;
    float vb;
    float theta;
    float sin_theta;
    float cos_theta;
    float grid_freq;
    uint16_t zcd;
    uint16_t is_locked;
    float Ts;
    float pd_error;

    PID_controller pi_ctrl;

    // 2. SADECE TUSTIN MODU İÇİN EKLENEN DEĞİŞKENLER (Şalterliyken RAM'de yer kaplar)
#ifdef USE_TUSTIN
    // TI SPRABT3A Katsayıları
    float osg_b0;
    float osg_b2;
    float osg_a1;
    float osg_a2;
    float osg_qb0;
    float osg_qb1;
    float osg_qb2;

    // TI SPRABT3A Geçmiş Veri (z-1, z-2) Tamponları
    float u[3];      
    float osg_u[3];  
    float osg_qu[3]; 
#endif

} SOGI_PLL_t;

// Dışarıdan main.c tarafından erişilecek global PLL nesnesi
extern SOGI_PLL_t grid_pll;

// Ortak fonksiyon prototipleri
void SOGI_PLL_Init(SOGI_PLL_t *pll, float Ts, float kp, float ki, float f_nominal);
void SOGI_PLL_Update(SOGI_PLL_t *pll, float vac);

#endif // _SOGI_PLL_H_
