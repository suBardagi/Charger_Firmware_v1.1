/*
created by suBardagi
*/

#ifndef _ERROR_HANDLER_H_
#define _ERROR_HANDLER_H_

#include "stdint.h"
#include "stdbool.h"

typedef enum
{
    STATE_INIT = 0,    // Başlangıç, tüm röleler ve PWM'ler kapalı
    STATE_GRID_SYNCH,  // Bekleme
    STATE_PRECHARGE,   // DC Bara ön şarj işlemi
    STATE_RUNNING,     // Sistem aktif, güç aktarımı yapılıyor
    STATE_FAULT,       // HATA DURUMU
    STATE_SHUTDOWN     // Sistem güvenli şekilde kapatıldı, kilitlendi
} System_State_e;

typedef struct
{
    uint16_t can_rx_timeout : 1;
    uint16_t can_tx_error : 1;

    uint16_t grid_ovp : 1;
    uint16_t grid_uvp : 1;
    uint16_t pfc_ocp : 1;

    uint16_t dc_bus_ovp : 1;

    uint16_t bat_ocp : 1;
    uint16_t bat_ovp : 1;
}Error_flags_t;

typedef struct
{
    System_State_e current_state;
    Error_flags_t flags;
    bool global_fault_active;
    uint32_t state_timer;
}System_Manager_t;

extern System_Manager_t sys_manager;

void System_Manager_Init(void);
void System_Manager_Update(void);

#endif
