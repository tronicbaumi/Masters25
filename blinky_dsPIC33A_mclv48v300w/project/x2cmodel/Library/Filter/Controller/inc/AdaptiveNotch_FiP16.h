/*
 * Copyright (c) 2018, Linz Center of Mechatronics GmbH (LCM) http://www.lcm.at/
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
 * This file is part of X2C. http://x2c.lcm.at/
 * $LastChangedRevision: 3344 $
 * $LastChangedDate:: 2024-07-04 13:08:58 +0200#$
 */
/* USERCODE-BEGIN:Description                                                                                         */
/* Description: */
/* USERCODE-END:Description                                                                                           */
#ifndef ADAPTIVENOTCH_FIP16_H
#define ADAPTIVENOTCH_FIP16_H

#ifdef __cplusplus
extern "C" {
#endif

#include "CommonFcts.h"

#if !defined(ADAPTIVENOTCH_FIP16_ISLINKED)
#define ADAPTIVENOTCH_FIP16_ID ((uint16)8049)

#if !defined(X2C_USE_UNION_FOR_POINTER)
typedef struct {
    uint16          ID;
    int16           *In;
    int16           *n;
    int16           Out;
    int16           n_thresh;
    int16           a_fact;
    int16           b_fact;
    int16           c_fact;
    int8            sfrA;
    int16           a1;
    int16           a2;
    int16           b1;
    int16           k;
    int16           in_old;
    int16           in_very_old;
    int16           out_old;
    int16           out_very_old;
    int16           n_old;
} ADAPTIVENOTCH_FIP16;
#else
typedef struct {
    uint16          ID;
    INT16_PTR       In;
    INT16_PTR       n;
    int16           Out;
    int16           n_thresh;
    int16           a_fact;
    int16           b_fact;
    int16           c_fact;
    int8            sfrA;
    int16           a1;
    int16           a2;
    int16           b1;
    int16           k;
    int16           in_old;
    int16           in_very_old;
    int16           out_old;
    int16           out_very_old;
    int16           n_old;
} ADAPTIVENOTCH_FIP16;
#endif

#define ADAPTIVENOTCH_FIP16_FUNCTIONS { \
    ADAPTIVENOTCH_FIP16_ID, \
    (void (*)(void*))AdaptiveNotch_FiP16_Update, \
    (void (*)(void*))AdaptiveNotch_FiP16_Init, \
    (tLoadImplementationParameter)AdaptiveNotch_FiP16_Load, \
    (tSaveImplementationParameter)AdaptiveNotch_FiP16_Save, \
    (void* (*)(const void*, uint16))AdaptiveNotch_FiP16_GetAddress }

/**********************************************************************************************************************/
/** Public prototypes                                                                                                **/
/**********************************************************************************************************************/
void AdaptiveNotch_FiP16_Update(ADAPTIVENOTCH_FIP16 *pTAdaptiveNotch_FiP16);
void AdaptiveNotch_FiP16_Init(ADAPTIVENOTCH_FIP16 *pTAdaptiveNotch_FiP16);
uint8 AdaptiveNotch_FiP16_Load(const ADAPTIVENOTCH_FIP16 *pTAdaptiveNotch_FiP16, uint8 data[], uint16 *dataLength, uint16 maxSize);
uint8 AdaptiveNotch_FiP16_Save(ADAPTIVENOTCH_FIP16 *pTAdaptiveNotch_FiP16, const uint8 data[], uint16 dataLength);
void* AdaptiveNotch_FiP16_GetAddress(const ADAPTIVENOTCH_FIP16 *block, uint16 elementId);

#endif

#ifdef __cplusplus
}
#endif

#endif
