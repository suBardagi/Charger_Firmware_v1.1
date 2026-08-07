/*
created by suBardagi
*/

#include "can_test.h"
#include "board.h"
#include "inc/hw_memmap.h"

#define TX_MSG_OBJ_ID 1
#define RX_MSG_OBJ_ID 2

void CAN_Test_Init(CAN_Test_t *can_data)
{
    can_data->tx_msg_count = 0;
    can_data->rx_msg_count = 0;
    can_data->tx_error_count = 0;
    can_data->rx_timeout_count = 0;
    can_data->bus_error_flag = 0;
    int i;

    // Dummy veri
    can_data->tx_msg_data[0] = 0x1111;
    can_data->tx_msg_data[1] = 0x2222;
    can_data->tx_msg_data[2] = 0x3333;
    can_data->tx_msg_data[3] = 0x4444;

    for(i = 0 ; i<4 ; i++)
    {
        can_data->rx_msg_data[i] = 0x0000;
    }

    CAN_enableAutoBusOn(CANA_BASE);
    CAN_setAutoBusOnTime(CANA_BASE, 500000);

}

void CAN_Test_Transmit(CAN_Test_t *can_data)
{
    if((CAN_getTxRequests(CANA_BASE) & (1UL << (TX_MSG_OBJ_ID-1))) == 0)
    {
        // CAN modülü üzerinden veriyi gönder
        // Parametreler: Base Adres, Mailbox ID, Veri Uzunluğu (8 byte), Veri Dizisi
        CAN_sendMessage(CANA_BASE, TX_MSG_OBJ_ID, 8, can_data->tx_msg_data);
        
        can_data->tx_msg_count++;
    }
    else
    {
        can_data->tx_error_count++;

        if(can_data->tx_error_count > 10000)
        {
            can_data->bus_error_flag = 1;
            can_data->tx_error_count = 10000;
        }
    }
}

void CAN_Test_Receive(CAN_Test_t *can_data)
{
    if(CAN_getNewDataFlags(CANA_BASE) & (1UL << (RX_MSG_OBJ_ID - 1)))
    {
        // Gelen mesajı yapıdaki rx_msg_data dizisine oku
        CAN_readMessage(CANA_BASE, RX_MSG_OBJ_ID, can_data->rx_msg_data);
        can_data->rx_msg_count++;

        can_data->rx_timeout_count = 0;

        if(can_data->tx_error_count == 0)
        {
            can_data->bus_error_flag = 0;
        }
        else 
        {
            can_data->rx_timeout_count++;
            if(can_data->rx_timeout_count > 10000)
            {
                can_data->bus_error_flag = 1;
                can_data->rx_timeout_count = 10000;
            }
        }
    }
}
