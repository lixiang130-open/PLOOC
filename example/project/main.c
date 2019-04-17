
/*****************************************************************************
 *   Copyright(C)2009-2019 by GorgonMeducer<embedded_zhuoran@hotmail.com>    *
 *                                                                           *
 *  Licensed under the Apache License, Version 2.0 (the "License");          *
 *  you may not use this file except in compliance with the License.         *
 *  You may obtain a copy of the License at                                  *
 *                                                                           *
 *     http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                           *
 *  Unless required by applicable law or agreed to in writing, software      *
 *  distributed under the License is distributed on an "AS IS" BASIS,        *
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 *  See the License for the specific language governing permissions and      *
 *  limitations under the License.                                           *
 *                                                                           *
 ****************************************************************************/

/*============================ INCLUDES ======================================*/
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "platform.h"

#include "byte_queue/byte_queue.h"
#include "enhanced_byte_queue/enhanced_byte_queue.h"
/*============================ MACROS ========================================*/

#ifndef QUEUE_BUFFER_SIZE
#   define QUEUE_BUFFER_SIZE       256
#endif

/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/
/*============================ IMPLEMENTATION ================================*/
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>


static enhanced_byte_queue_t s_tQueue;

int main(void)
{
    platform_init();
    do {
        static uint8_t s_chQueueBuffer[QUEUE_BUFFER_SIZE];
        const enhanced_byte_queue_cfg_t tCFG = {
            s_chQueueBuffer,
            sizeof(s_chQueueBuffer),
        };
        ENHANCED_BYTE_QUEUE.Init(&s_tQueue, (enhanced_byte_queue_cfg_t *)&tCFG);
    } while(0);

    //! you can enqueue
    ENHANCED_BYTE_QUEUE.Enqueue(&s_tQueue, 'p');
    ENHANCED_BYTE_QUEUE.Enqueue(&s_tQueue, 'L');
    ENHANCED_BYTE_QUEUE.Enqueue(&s_tQueue, 'O');
    ENHANCED_BYTE_QUEUE.Enqueue(&s_tQueue, 'O');
    ENHANCED_BYTE_QUEUE.Enqueue(&s_tQueue, 'C');
    //! you can dequeue
    do {
        uint_fast16_t n = ENHANCED_BYTE_QUEUE.Count(&s_tQueue);
        uint8_t chByte;
        printf("There are %d byte in the queue!\r\n", n);
        printf("let's peek!\r\n");
        
        while(ENHANCED_BYTE_QUEUE.Peek.PeekByte(&s_tQueue, &chByte)) {
            printf("%c\r\n", chByte);
        }
        printf("There are %d byte in the queue!\r\n", 
                ENHANCED_BYTE_QUEUE.Count(&s_tQueue));
        printf("Let's peek them all \r\n");
        ENHANCED_BYTE_QUEUE.Peek.GetAllPeeked(&s_tQueue);
        printf("There are %d byte in the queue!\r\n", 
                ENHANCED_BYTE_QUEUE.Count(&s_tQueue));
    } while(0);
   


    printf("Hello PLOOC!\r\n");
    while(1);
}