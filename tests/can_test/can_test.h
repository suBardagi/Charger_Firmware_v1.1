/*
created by suBardagi
*/

#ifndef CAN_TEST_H_
#define CAN_TEST_H_

#include "stdint.h"
#include "driverlib.h"

typedef struct 
{
    uint16_t tx_msg_data[4];
    uint16_t rx_msg_data[4];
    uint32_t tx_msg_count;
    uint32_t rx_msg_count;

    uint32_t tx_error_count;
    uint32_t rx_timeout_count;
    uint8_t bus_error_flag;
}CAN_Test_t;

void CAN_Test_Init(CAN_Test_t *can_data);
void CAN_Test_Transmit(CAN_Test_t *can_data);
void CAN_Test_Receive(CAN_Test_t *can_data);

#endif
