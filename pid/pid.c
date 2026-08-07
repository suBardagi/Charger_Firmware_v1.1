/*
created by suBardagi
*/

#include "pid.h"
//#include "stdarg.h"

// void pid_init(PID_controller *pid, 
//               float Kp, float Ki, float Kd, 
//               uint8_t use_limits, uint8_t use_dt, 
//               float output_min, float output_max, 
//               float integral_min, float integral_max, 
//               float dt, float deriv_filter_alpha);
//     {

//     pid->Kp = Kp;
//     pid->Ki = Ki;
//     pid->Kd = Kd;
//     pid->integral = 0.0f;
//     pid->prev_error = 0.0f;
//     pid->prev_prev_error = 0.0f;
//     pid->use_limits = use_limits;
//     pid->use_dt = use_dt;
//     pid->step_count = 0;
//     pid->started = 0;

//     pid->integral_min = 0.0f;
//     pid->integral_max = 0.0f;
//     pid->output_min = 0.0f;
//     pid->output_max = 0.0f;

//     pid->dt = 0.0f;
//     pid->deriv_filter_alpha = 0.0f;

//     if(pid->deriv_filter_alpha < 0.0f) pid->deriv_filter_alpha = 0.0f;
//     if(pid->deriv_filter_alpha > 1.0f) pid->deriv_filter_alpha = 1.0f;

//     pid->derivative_filtered = 0.0f;
    

//     // va_list args;
//     // va_start(args, use_dt);

//     // if(pid->use_limits){
//     //     pid->integral_min = (float)va_arg(args, float);
//     //     pid->integral_max = (float)va_arg(args, float);
//     //     pid->output_min = (float)va_arg(args, float);
//     //     pid->output_max = (float)va_arg(args, float);
//     // }

//     // if(pid->use_dt){
//     //     pid->dt = (float)va_arg(args, float);
//     //     pid->deriv_filter_alpha = (float)va_arg(args, float);

//     //     if(pid->deriv_filter_alpha < 0.0f) pid->deriv_filter_alpha = 0.0f;
//     //     if(pid->deriv_filter_alpha > 1.0f) pid->deriv_filter_alpha = 1.0f;

//     //     pid->derivative_filtered = 0.0f;
//     // }

//     // va_end(args);
// }

void pid_init(PID_controller *pid, 
              float Kp, float Ki, float Kd, 
              uint8_t use_limits, uint8_t use_dt, 
              float output_min, float output_max, 
              float integral_min, float integral_max, 
              float dt, float deriv_filter_alpha) 
{
    // Temel katsayılar
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    
    // Konfigürasyon bayrakları
    pid->use_limits = use_limits;
    pid->use_dt = use_dt;

    // Limitler kullanılıyorsa atama yap, kullanılmıyorsa sıfırla
    if (use_limits) {
        pid->output_min = output_min;
        pid->output_max = output_max;
        pid->integral_min = integral_min;
        pid->integral_max = integral_max;
    } else {
        pid->output_min = 0.0f;
        pid->output_max = 0.0f;
        pid->integral_min = 0.0f;
        pid->integral_max = 0.0f;
    }

    // Zaman adımı (dt) kullanılıyorsa atama yap
    if (use_dt) {
        pid->dt = dt;
    } else {
        pid->dt = 0.0f;
    }

    pid->deriv_filter_alpha = deriv_filter_alpha;

    // Geçmiş değerleri ve integrali sıfırla (Başlangıç durumu)
    pid->integral = 0.0f;
    pid->prev_error = 0.0f;
    pid->prev_prev_error = 0.0f;
    pid->derivative_filtered = 0.0f;
    pid->step_count = 0;
    pid->started = 0;
}

float pid_compute(PID_controller *pid, float set, float measurement){

    float error = set - measurement;
    
    //Integral update
    if(pid->use_dt){
        if(!pid->started){
            if(pid->step_count==0){
                pid->integral += error * pid->dt * pid->Ki; // Rectangle
            }
            else if(pid->step_count==1){
                pid->integral += 0.5f * (error + pid->prev_error) * pid->dt * pid->Ki; // Trapezoidal
                pid->started = 1;
            }
        }
        else{  // Simpson's rule cycle
            if(pid->step_count==0){
                pid->integral += (error * pid->dt * pid->Ki) / 3.0f;
            }
            else if(pid->step_count==1){
                pid->integral += (4.0f * error * pid->dt * pid->Ki) / 3.0f;
            }
            else{
                pid->integral += (error * pid->dt * pid->Ki) / 3.0f;
            }
        }

        pid->step_count = (pid->step_count + 1) % 3;

        //float simpson_term = (pid->dt / 3.0f)*(error + 4.0f * pid->prev_error + pid->prev_prev_error);
        //pid->integral += simpson_term * pid->Ki;
        //pid->integral += 0.5f * (error + pid->prev_error) * pid->dt * pid->Ki;
    }
    else {
        pid->integral += error * pid->Ki;
    }

    //Integral limits
    if(pid->use_limits){
        if(pid->integral > pid->integral_max) pid->integral = pid->integral_max;
        if(pid->integral < pid->integral_min) pid->integral = pid->integral_min;
    }

    //Derivative
    float derivative;
    if(pid->use_dt){
        float raw_deriv = (error - pid->prev_error) / pid->dt;
        float alpha = pid->deriv_filter_alpha;
        pid->derivative_filtered = alpha * pid->derivative_filtered + (1.0f - alpha) * raw_deriv;
        derivative = pid->derivative_filtered;
    }
    else{
        derivative = error - pid->prev_error;
    }

    float output = (pid->Kp*error)+(pid->integral)+(pid->Kd*derivative);

    if(pid->use_limits){
        if(output > pid->output_max) output = pid->output_max;
        if(output < pid->output_min) output = pid->output_min;
    }
    pid->prev_prev_error = pid->prev_error;
    pid->prev_error = error;
    return output;

}

void pid_reset(PID_controller *pid){
    // İntegral ve geçmiş hata değerlerini sıfırla
    pid->integral = 0.0f;
    pid->prev_error = 0.0f;
    pid->prev_prev_error = 0.0f;
    
    // İntegral hesaplama (Simpson vb.) adımlarını başa sar
    pid->step_count = 0;
    pid->started = 0;
    
    // Eğer türev filtresi kullanılıyorsa onun da geçmişini temizle
    if(pid->use_dt){
        pid->derivative_filtered = 0.0f;
    }
}
