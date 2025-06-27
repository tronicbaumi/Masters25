/**
 * @file
 * @brief Generated model file.
 * 
 * Date:  2025-06-25 12:10
 * 
 * X2C-Version: 6.5.3600
 * X2C-Edition: Free
 */
/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Model: blinky_dspic33a_mclv48v300w                                                                                 */
/* Date:  2025-06-25 12:10                                                                                            */

/* X2C-Version: 6.5.3600                                                                                              */
/* X2C-Edition: Free                                                                                                  */

#ifndef X2C_H
#define X2C_H

#ifdef __cplusplus
extern "C" {
#endif

/**********************************************************************************************************************/
/**     Includes                                                                                                     **/
/**********************************************************************************************************************/
/* Common includes                                                                                                    */
#include "Gain_FiP16.h"
#include "SinGen_FiP16.h"
#include "Constant_FiP16.h"
#include "AutoSwitch_FiP16.h"
#include "Scope_Main.h"
#include "CommonFcts.h"

/**********************************************************************************************************************/
/**     Defines                                                                                                      **/
/**********************************************************************************************************************/
#define FUNCTIONS \
    GAIN_FIP16_FUNCTIONS , \
    SINGEN_FIP16_FUNCTIONS , \
    CONSTANT_FIP16_FUNCTIONS , \
    AUTOSWITCH_FIP16_FUNCTIONS , \
    SCOPE_MAIN_FUNCTIONS

#define PARAMETER_TABLE \
    { 1u, &x2cModel.blocks.bAutoSwitch } , \
    { 2u, &x2cModel.blocks.bAutoSwitch1 } , \
    { 3u, &x2cModel.blocks.bConstant } , \
    { 4u, &x2cModel.blocks.bConstant1 } , \
    { 5u, &x2cModel.blocks.bConstant2 } , \
    { 6u, &x2cModel.blocks.bConstant3 } , \
    { 7u, &x2cModel.blocks.bGain1 } , \
    { 8u, &x2cModel.blocks.bSinGen } , \
    { 16u, &x2cScope }

#define INPORT_PARAMID_TABLE \
    { 9u, 2u, &x2cModel.inports.bCPU_LOAD } , \
    { 10u, 2u, &x2cModel.inports.bSW1 } , \
    { 11u, 2u, &x2cModel.inports.bSW2 } , \
    { 12u, 2u, &x2cModel.inports.bV_POT } 

#define OUTPORT_PARAMID_TABLE \
    { 13u, 2u, &x2cModel.outports.bLED1 } , \
    { 14u, 2u, &x2cModel.outports.bLED2 } , \
    { 15u, 2u, &x2cModel.outports.bPWM1 } 


/**********************************************************************************************************************/
/**                                            Model structure definition                                            **/
/**********************************************************************************************************************/
struct x2cModel {
/*  Control Blocks                                                                                                    */
    struct {
        AUTOSWITCH_FIP16 bAutoSwitch;
        AUTOSWITCH_FIP16 bAutoSwitch1;
        CONSTANT_FIP16 bConstant;
        CONSTANT_FIP16 bConstant1;
        CONSTANT_FIP16 bConstant2;
        CONSTANT_FIP16 bConstant3;
        GAIN_FIP16 bGain1;
        SINGEN_FIP16 bSinGen;
    } blocks;
/*  Inports                                                                                                           */
    struct {
        int16 bCPU_LOAD;
        int16 bSW1;
        int16 bSW2;
        int16 bV_POT;
    } inports;
/*  Outports                                                                                                          */
    struct {
        int16* bLED1;
        int16* bLED2;
        int16* bPWM1;
    } outports;
};

/**********************************************************************************************************************/
/**     Externals                                                                                                    **/
/**********************************************************************************************************************/
extern struct x2cModel x2cModel;

extern const uint32 x2cModelIdentifier;

extern const tBlockFunctions blockFunctionTable[];
extern const tParameterTable parameterIdTable[];
extern const tIoParamIdEntry inportParamIdTable[];
extern const tIoParamIdEntry outportParamIdTable[];
extern const tMaskParameterEntry maskParamIdTable[];
extern const tMaskParamExtRecord maskParamExtTable[];
extern const tMaskParamDataRecord maskParamDataTable[];


/**********************************************************************************************************************/
/**     Prototypes                                                                                                   **/
/**********************************************************************************************************************/
void X2C_Init(void);
void X2C_Update(void);
void X2C_Update_1(void);

#ifdef __cplusplus
}
#endif

#endif
