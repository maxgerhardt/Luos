/******************************************************************************
 * @file luos
 * @brief User functionalities of the Luos library
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/
#ifndef LUOS_H
#define LUOS_H

#include "luos_list.h"
#include "container_structs.h"
#include "routingTable.h"
#include "luos_od.h"
#include "streaming.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/******************************************************************************
 * @struct luos_stats_t
 * @brief store informations about luos stats
 ******************************************************************************/
typedef struct __attribute__((__packed__))
{
    union
    {
        struct __attribute__((__packed__))
        {
            memory_stats_t memory;
            uint8_t max_loop_time_ms;
        };
        uint8_t unmap[5]; /*!< streamable form. */
    };
} luos_stats_t;

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Function
 ******************************************************************************/

void Luos_Init(void);
void Luos_Loop(void);
void Luos_ContainersClear(void);
container_t *Luos_CreateContainer(CONT_CB cont_cb, uint8_t type, const char *alias, char *firm_revision);
error_return_t Luos_SendMsg(container_t *container, msg_t *msg);
error_return_t Luos_ReadMsg(container_t *container, msg_t **returned_msg);
error_return_t Luos_ReadFromContainer(container_t *container, int16_t id, msg_t **returned_msg);
error_return_t Luos_SendData(container_t *container, msg_t *msg, void *bin_data, uint16_t size);
error_return_t Luos_SendStreaming(container_t *container, msg_t *msg, streaming_channel_t *stream);
error_return_t Luos_ReceiveStreaming(container_t *container, msg_t *msg, streaming_channel_t *stream);
void Luos_SetBaudrate(uint32_t baudrate);
void Luos_SendBaudrate(container_t *container, uint32_t baudrate);
error_return_t Luos_SetExternId(container_t *container, target_mode_t target_mode, uint16_t target, uint16_t newid);
uint16_t Luos_NbrAvailableMsg(void);

#endif /* LUOS_H */
