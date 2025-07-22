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
#ifndef BIQUAD_FIP16_H
#define BIQUAD_FIP16_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(BIQUAD_FIP16_ISLINKED)
#define BIQUAD_FIP16_ID ((uint16)8081)

#if !defined(X2C_USE_UNION_FOR_POINTER)
typedef struct {
    uint16          identifier;
    int16           *In;
    int16           Out;
    int16           b0;
    int16           b1;
    int16           b2;
    int16           a1;
    int16           a2;
    uint8           sfrb0;
    uint8           sfrb1;
    uint8           sfrb2;
    uint8           sfra1;
    uint8           sfra2;
    int16           in_old;
    int16           in_veryold;
    int16           out_old;
    int16           out_veryold;
} BIQUAD_FIP16;
#else
typedef struct {
    uint16          identifier;
    INT16_PTR       In;
    int16           Out;
    int16           b0;
    int16           b1;
    int16           b2;
    int16           a1;
    int16           a2;
    uint8           sfrb0;
    uint8           sfrb1;
    uint8           sfrb2;
    uint8           sfra1;
    uint8           sfra2;
    int16           in_old;
    int16           in_veryold;
    int16           out_old;
    int16           out_veryold;
} BIQUAD_FIP16;
#endif

#define BIQUAD_FIP16_FUNCTIONS { \
    BIQUAD_FIP16_ID, \
    (void (*)(void*))Biquad_FiP16_Update, \
    (void (*)(void*))Biquad_FiP16_Init, \
    (tLoadImplementationParameter)Biquad_FiP16_Load, \
    (tSaveImplementationParameter)Biquad_FiP16_Save, \
    (void* (*)(void*, uint16))Biquad_FiP16_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void Biquad_FiP16_Update(BIQUAD_FIP16 *block);
void Biquad_FiP16_Init(BIQUAD_FIP16 *block);
uint8 Biquad_FiP16_Load(const BIQUAD_FIP16 *block, uint8 data[], uint16 *dataLength, uint16 maxSize);
uint8 Biquad_FiP16_Save(BIQUAD_FIP16 *block, const uint8 data[], uint16 dataLength);
void* Biquad_FiP16_GetAddress(BIQUAD_FIP16 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif
