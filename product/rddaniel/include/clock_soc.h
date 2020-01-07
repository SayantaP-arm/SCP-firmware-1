/*
 * Arm SCP/MCP Software
 * Copyright (c) 2020, Arm Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CLOCK_SOC_H
#define CLOCK_SOC_H

#include <fwk_macros.h>

#define CLOCK_RATE_REFCLK       (100UL * FWK_MHZ)

/*
 * PLL clock indexes.
 */
enum clock_pll_idx {
    CLOCK_PLL_IDX_CPU0,
    CLOCK_PLL_IDX_CPU1,
    CLOCK_PLL_IDX_CPU2,
    CLOCK_PLL_IDX_CPU3,
    CLOCK_PLL_IDX_CPU4,
    CLOCK_PLL_IDX_CPU5,
    CLOCK_PLL_IDX_CPU6,
    CLOCK_PLL_IDX_CPU7,
    CLOCK_PLL_IDX_CPU8,
    CLOCK_PLL_IDX_CPU9,
    CLOCK_PLL_IDX_CPU10,
    CLOCK_PLL_IDX_CPU11,
    CLOCK_PLL_IDX_CPU12,
    CLOCK_PLL_IDX_CPU13,
    CLOCK_PLL_IDX_CPU14,
    CLOCK_PLL_IDX_CPU15,
    CLOCK_PLL_IDX_SYS,
    CLOCK_PLL_IDX_DMC,
    CLOCK_PLL_IDX_INTERCONNECT,
    CLOCK_PLL_IDX_COUNT
};

#endif /* CLOCK_SOC_H */