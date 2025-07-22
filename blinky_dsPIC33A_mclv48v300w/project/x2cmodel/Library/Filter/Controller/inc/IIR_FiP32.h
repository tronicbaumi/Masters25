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
#ifndef IIR_FIP32_H
#define IIR_FIP32_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(IIR_FIP32_ISLINKED)
#define IIR_FIP32_ID ((uint16)8098)

#if !defined(X2C_USE_UNION_FOR_POINTER)
typedef struct {
    uint16          identifier;
    int32           *In;
    int32           Out;
    int32           *coeffB;
    int32           *coeffA;
    uint8           sfrB;
    uint8           sfrA;
    int32           *inputBuffer;
    int32           *outputBuffer;
    int8            indexIn;
    int8            indexOut;
    int8            orderN;
    int8            orderD;
} IIR_FIP32;
#else
typedef struct {
    uint16          identifier;
    INT32_PTR       In;
    int32           Out;
    INT32_PTR       coeffB;
    INT32_PTR       coeffA;
    uint8           sfrB;
    uint8           sfrA;
    INT32_PTR       inputBuffer;
    INT32_PTR       outputBuffer;
    int8            indexIn;
    int8            indexOut;
    int8            orderN;
    int8            orderD;
} IIR_FIP32;
#endif

#define IIR_FIP32_FUNCTIONS { \
    IIR_FIP32_ID, \
    (void (*)(void*))IIR_FiP32_Update, \
    (void (*)(void*))IIR_FiP32_Init, \
    (tLoadImplementationParameter)IIR_FiP32_Load, \
    (tSaveImplementationParameter)IIR_FiP32_Save, \
    (void* (*)(void*, uint16))IIR_FiP32_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void IIR_FiP32_Update(IIR_FIP32 *block);
void IIR_FiP32_Init(IIR_FIP32 *block);
uint8 IIR_FiP32_Load(const IIR_FIP32 *block, uint8 data[], uint16 *dataLength, uint16 maxSize);
uint8 IIR_FiP32_Save(IIR_FIP32 *block, const uint8 data[], uint16 dataLength);
void* IIR_FiP32_GetAddress(IIR_FIP32 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif
