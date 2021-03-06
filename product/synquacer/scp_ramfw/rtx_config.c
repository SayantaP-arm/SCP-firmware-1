/*
 * Arm SCP/MCP Software
 * Copyright (c) 2015-2020, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "system_clock.h"

#include <rtx_lib.c>
#include <rtx_os.h>

#include <mod_synquacer_system.h>

#include <fwk_log.h>
#include <fwk_mm.h>

#include <fmw_cmsis.h>

#include <stdbool.h>
#include <stdint.h>

/*
 * Required by RTX to configure the SysTick timer.
 */
uint32_t SystemCoreClock = CLOCK_RATE_REFCLK;

/*
 * Idle thread
 */
__NO_RETURN void osRtxIdleThread(void *argument)
{
    (void)argument;

    while (true)
        __WFI();
}

/*
 * OS error handler
 */
uint32_t osRtxErrorNotify(uint32_t code, void *object_id)
{
    (void)object_id;

    switch (code) {
    case osRtxErrorStackUnderflow:
        /*
         * Stack underflow detected for thread
         * thread_id=object_id
         */
        FWK_LOG_ERR("[SYSTEM] osRtxErrorStackUnderflow.");
        break;

    case osRtxErrorISRQueueOverflow:
        /*
         * ISR Queue overflow detected when inserting object
         * object_id
         */
        FWK_LOG_ERR("[SYSTEM] osRtxErrorISRQueueOverflow.");
        break;

    case osRtxErrorTimerQueueOverflow:
        /*
         * User Timer Callback Queue overflow detected for timer
         * timer_id=object_id
         */
        FWK_LOG_ERR("[SYSTEM] osRtxErrorTimerQueueOverflow.");
        break;

    case osRtxErrorClibSpace:
        /*
         * Standard C/C++ library libspace not available:
         * increase OS_THREAD_LIBSPACE_NUM
         */
        FWK_LOG_ERR("[SYSTEM] osRtxErrorClibSpace.");
        break;

    case osRtxErrorClibMutex:
        /*
         * Standard C/C++ library mutex initialization failed
         */
        FWK_LOG_ERR("[SYSTEM] oosRtxErrorClibMutex.");
        break;

    default:
        break;
    }

    osRtxIdleThread(object_id);
}

uint32_t osRtxMemoryInit(void *mem, uint32_t size)
{
    return 1;
}

void *osRtxMemoryAlloc(void *mem, uint32_t size, uint32_t type)
{
    return fwk_mm_alloc(1, size);
}

uint32_t osRtxMemoryFree(void *mem, void *block)
{
    return 1;
}
