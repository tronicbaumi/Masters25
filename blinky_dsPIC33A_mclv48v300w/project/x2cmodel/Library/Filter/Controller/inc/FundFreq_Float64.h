/*
 * Copyright (c) 2018, Linz Center of Mechatronics GmbH (LCM), web: www.lcm.at
 * All rights reserved.
 */
/*
 * This file is licensed according to the BSD 3-clause license as follows:
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the "Linz Center of Mechatronics GmbH" and "LCM" nor
 *       the names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL "Linz Center of Mechatronics GmbH" BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * This file is part of X2C. web: x2c.lcm.at
 * $LastChangedRevision: 3674 $
 * $LastChangedDate:: 2025-03-07 12:00:30 +0100#$
 */
/* USERCODE-BEGIN:Description                                                                                         */
/* Description: Calculation of fundamental wave.                              */
/* USERCODE-END:Description                                                                                           */
#ifndef FUNDFREQ_FLOAT64_H
#define FUNDFREQ_FLOAT64_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(FUNDFREQ_FLOAT64_ISLINKED)
#define FUNDFREQ_FLOAT64_ID ((uint16)8020)

#if !defined(X2C_USE_UNION_FOR_POINTER)
typedef struct {
    uint16          identifier;
    float64         *In;
    float64         *phi;
    float64         Out;
    uint64          cnt;
    float64         phi_old;
    float64         sum_a;
    float64         sum_b;
    float64         a;
    float64         b;
} FUNDFREQ_FLOAT64;
#else
typedef struct {
    uint16          identifier;
    FLOAT64_PTR     In;
    FLOAT64_PTR     phi;
    float64         Out;
    uint64          cnt;
    float64         phi_old;
    float64         sum_a;
    float64         sum_b;
    float64         a;
    float64         b;
} FUNDFREQ_FLOAT64;
#endif

#define FUNDFREQ_FLOAT64_FUNCTIONS { \
    FUNDFREQ_FLOAT64_ID, \
    (void (*)(void*))FundFreq_Float64_Update, \
    (void (*)(void*))FundFreq_Float64_Init, \
    (tLoadImplementationParameter)Common_Load, \
    (tSaveImplementationParameter)Common_Save, \
    (void* (*)(void*, uint16))FundFreq_Float64_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void FundFreq_Float64_Update(FUNDFREQ_FLOAT64 *block);
void FundFreq_Float64_Init(FUNDFREQ_FLOAT64 *block);
void* FundFreq_Float64_GetAddress(FUNDFREQ_FLOAT64 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif
