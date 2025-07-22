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
/* Description: */
/* USERCODE-END:Description                                                                                           */
#ifndef LOWPASSBIQ_FLOAT32_H
#define LOWPASSBIQ_FLOAT32_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(LOWPASSBIQ_FLOAT32_ISLINKED)
#define LOWPASSBIQ_FLOAT32_ID ((uint16)8131)

#if !defined(X2C_USE_UNION_FOR_POINTER)
typedef struct {
    uint16          identifier;
    float32         *In;
    float32         Out;
    float32         b0;
    float32         b1;
    float32         b2;
    float32         a1;
    float32         a2;
    float32         in_old;
    float32         in_veryold;
    float32         out_old;
    float32         out_veryold;
} LOWPASSBIQ_FLOAT32;
#else
typedef struct {
    uint16          identifier;
    FLOAT32_PTR     In;
    float32         Out;
    float32         b0;
    float32         b1;
    float32         b2;
    float32         a1;
    float32         a2;
    float32         in_old;
    float32         in_veryold;
    float32         out_old;
    float32         out_veryold;
} LOWPASSBIQ_FLOAT32;
#endif

#define LOWPASSBIQ_FLOAT32_FUNCTIONS { \
    LOWPASSBIQ_FLOAT32_ID, \
    (void (*)(void*))LowpassBiQ_Float32_Update, \
    (void (*)(void*))LowpassBiQ_Float32_Init, \
    (tLoadImplementationParameter)LowpassBiQ_Float32_Load, \
    (tSaveImplementationParameter)LowpassBiQ_Float32_Save, \
    (void* (*)(void*, uint16))LowpassBiQ_Float32_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void LowpassBiQ_Float32_Update(LOWPASSBIQ_FLOAT32 *block);
void LowpassBiQ_Float32_Init(LOWPASSBIQ_FLOAT32 *block);
uint8 LowpassBiQ_Float32_Load(const LOWPASSBIQ_FLOAT32 *block, uint8 data[], uint16 *dataLength, uint16 maxSize);
uint8 LowpassBiQ_Float32_Save(LOWPASSBIQ_FLOAT32 *block, const uint8 data[], uint16 dataLength);
void* LowpassBiQ_Float32_GetAddress(LOWPASSBIQ_FLOAT32 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif
