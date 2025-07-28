/**
 * @file
 * @brief Generated model file.
 * 
 * Date:  2025-07-28 09:29
 * 
 * X2C-Version: 6.5.3797
 * X2C-Edition: Free
 */
/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Model: mc_foc_sl_fip_dspic33a_mclv48v300w                                                                          */
/* Date:  2025-07-28 09:29                                                                                            */

/* X2C-Version: 6.5.3797                                                                                              */
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
#include "Constant_Bool.h"
#include "Real2Int_Float32_FiP16.h"
#include "Gain_FiP16.h"
#include "I_FiP16.h"
#include "RateLimiter_FiP16.h"
#include "LoopBreaker_Bool.h"
#include "BEMF_MCHP_FiP16.h"
#include "ManualSwitch_FiP16.h"
#include "LoopBreaker_FiP16.h"
#include "Constant_FiP16.h"
#include "Not_Bool.h"
#include "uSub_FiP16.h"
#include "Sin3Gen_FiP16.h"
#include "PI_FiP16.h"
#include "Saturation_FiP16.h"
#include "Park_MCHP_FiP16.h"
#include "AutoSwitch_FiP16.h"
#include "Sequencer_FiP16.h"
#include "SinGen_FiP16.h"
#include "Sub_FiP16.h"
#include "Clarke_Park_MCHP_FiP16.h"
#include "Constant_Float32.h"
#include "uI_FiP16.h"
#include "Average_FiP16.h"
#include "Abs_FiP16.h"
#include "TypeConv_FiP16_Bool.h"
#include "Park_Clarke_inv_SVM_MCHP_FiP16.h"
#include "Add_FiP16.h"
#include "Sign_FiP16.h"
#include "Mult_FiP16.h"
#include "Scope_Main.h"
#include "CommonFcts.h"

/**********************************************************************************************************************/
/**     Defines                                                                                                      **/
/**********************************************************************************************************************/
#define FUNCTIONS \
    CONSTANT_BOOL_FUNCTIONS , \
    REAL2INT_FLOAT32_FIP16_FUNCTIONS , \
    GAIN_FIP16_FUNCTIONS , \
    I_FIP16_FUNCTIONS , \
    RATELIMITER_FIP16_FUNCTIONS , \
    LOOPBREAKER_BOOL_FUNCTIONS , \
    BEMF_MCHP_FIP16_FUNCTIONS , \
    MANUALSWITCH_FIP16_FUNCTIONS , \
    LOOPBREAKER_FIP16_FUNCTIONS , \
    CONSTANT_FIP16_FUNCTIONS , \
    NOT_BOOL_FUNCTIONS , \
    USUB_FIP16_FUNCTIONS , \
    SIN3GEN_FIP16_FUNCTIONS , \
    PI_FIP16_FUNCTIONS , \
    SATURATION_FIP16_FUNCTIONS , \
    PARK_MCHP_FIP16_FUNCTIONS , \
    AUTOSWITCH_FIP16_FUNCTIONS , \
    SEQUENCER_FIP16_FUNCTIONS , \
    SINGEN_FIP16_FUNCTIONS , \
    SUB_FIP16_FUNCTIONS , \
    CLARKE_PARK_MCHP_FIP16_FUNCTIONS , \
    CONSTANT_FLOAT32_FUNCTIONS , \
    UI_FIP16_FUNCTIONS , \
    AVERAGE_FIP16_FUNCTIONS , \
    ABS_FIP16_FUNCTIONS , \
    TYPECONV_FIP16_BOOL_FUNCTIONS , \
    PARK_CLARKE_INV_SVM_MCHP_FIP16_FUNCTIONS , \
    ADD_FIP16_FUNCTIONS , \
    SIGN_FIP16_FUNCTIONS , \
    MULT_FIP16_FUNCTIONS , \
    SCOPE_MAIN_FUNCTIONS

#define PARAMETER_TABLE \
    { 1u, &x2cModel.blocks.sFOCmain.bClarke_Park_MCHP } , \
    { 2u, &x2cModel.blocks.sFOCmain.bConstant } , \
    { 3u, &x2cModel.blocks.sFOCmain.bConstant1 } , \
    { 4u, &x2cModel.blocks.sFOCmain.bGain } , \
    { 5u, &x2cModel.blocks.sFOCmain.bGain2 } , \
    { 6u, &x2cModel.blocks.sFOCmain.bGain3 } , \
    { 7u, &x2cModel.blocks.sFOCmain.bManualSwitch2 } , \
    { 8u, &x2cModel.blocks.sFOCmain.bManualSwitch3 } , \
    { 9u, &x2cModel.blocks.sFOCmain.bManualSwitch5 } , \
    { 10u, &x2cModel.blocks.sFOCmain.bNot } , \
    { 11u, &x2cModel.blocks.sFOCmain.bPI_flux } , \
    { 12u, &x2cModel.blocks.sFOCmain.bPI_torque } , \
    { 13u, &x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage } , \
    { 14u, &x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage1 } , \
    { 15u, &x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP } , \
    { 16u, &x2cModel.blocks.sFOCmain.sPLLEstimator.bLoopBreaker } , \
    { 17u, &x2cModel.blocks.sFOCmain.sPLLEstimator.bPark_MCHP } , \
    { 18u, &x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bAdd } , \
    { 19u, &x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bAutoSwitch } , \
    { 20u, &x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bGain } , \
    { 21u, &x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bSub } , \
    { 22u, &x2cModel.blocks.sFOCmain.sPLLEstimator.buI } , \
    { 23u, &x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP } , \
    { 24u, &x2cModel.blocks.sFOCmain.bSaturation_Vd } , \
    { 25u, &x2cModel.blocks.sFOCmain.bSaturation_Vq } , \
    { 26u, &x2cModel.blocks.sFOCmain.bSin3Gen } , \
    { 27u, &x2cModel.blocks.sFOCmain.bSub_flux } , \
    { 28u, &x2cModel.blocks.sFOCmain.bSub_torque } , \
    { 29u, &x2cModel.blocks.sFOCmain.bVdOverride } , \
    { 30u, &x2cModel.blocks.sFOCmain.bVdOverrideVal } , \
    { 31u, &x2cModel.blocks.sFOCmain.bVqOverride } , \
    { 32u, &x2cModel.blocks.sFOCmain.bVqOverrideVal } , \
    { 33u, &x2cModel.blocks.bLoopBreaker } , \
    { 34u, &x2cModel.blocks.bLoopBreaker1 } , \
    { 35u, &x2cModel.blocks.bNot } , \
    { 36u, &x2cModel.blocks.bPosSignalPath } , \
    { 37u, &x2cModel.blocks.bQEI_OFFSET1 } , \
    { 38u, &x2cModel.blocks.bReal2Int } , \
    { 39u, &x2cModel.blocks.sSpeedPI.bManualSwitch } , \
    { 40u, &x2cModel.blocks.sSpeedPI.bPI_speed } , \
    { 41u, &x2cModel.blocks.sSpeedPI.bRateLimiter } , \
    { 42u, &x2cModel.blocks.sSpeedPI.bSpeed_error } , \
    { 43u, &x2cModel.blocks.sSpeedPI.bSpeetPerturbation } , \
    { 44u, &x2cModel.blocks.sSpeedPI.sSuperBlock.bAdd } , \
    { 45u, &x2cModel.blocks.sSpeedPI.sSuperBlock.bAutoSwitch } , \
    { 46u, &x2cModel.blocks.sSpeedPI.sSuperBlock.bConstant } , \
    { 47u, &x2cModel.blocks.sSpeedPI.sSuperBlock.bConstant1 } , \
    { 48u, &x2cModel.blocks.sSpeedPI.sSuperBlock.bConstant2 } , \
    { 49u, &x2cModel.blocks.sSpeedPI.sSuperBlock.bConstant3 } , \
    { 50u, &x2cModel.blocks.sSpeedPI.sSuperBlock.bGain } , \
    { 51u, &x2cModel.blocks.sSpeedPI.sSuperBlock.bRateLimiter } , \
    { 52u, &x2cModel.blocks.sSpeedPI.sSuperBlock.bSinGen } , \
    { 53u, &x2cModel.blocks.sSpeedPI.sSuperBlock1.bAdd } , \
    { 54u, &x2cModel.blocks.sSpeedPI.sSuperBlock1.bAutoSwitch } , \
    { 55u, &x2cModel.blocks.sSpeedPI.sSuperBlock1.bConstant } , \
    { 56u, &x2cModel.blocks.sSpeedPI.sSuperBlock1.bConstant1 } , \
    { 57u, &x2cModel.blocks.sSpeedPI.sSuperBlock1.bConstant2 } , \
    { 58u, &x2cModel.blocks.sSpeedPI.sSuperBlock1.bConstant3 } , \
    { 59u, &x2cModel.blocks.sSpeedPI.sSuperBlock1.bGain } , \
    { 60u, &x2cModel.blocks.sSpeedPI.sSuperBlock1.bRateLimiter } , \
    { 61u, &x2cModel.blocks.sSpeedPI.sSuperBlock1.bSinGen } , \
    { 62u, &x2cModel.blocks.sSpeedPI.bTorquePerturbation } , \
    { 63u, &x2cModel.blocks.sSpeedPI.btorqueSetpoint } , \
    { 64u, &x2cModel.blocks.sSuperBlock.bAbs } , \
    { 65u, &x2cModel.blocks.sSuperBlock.bAdd } , \
    { 66u, &x2cModel.blocks.sSuperBlock.bAverage } , \
    { 67u, &x2cModel.blocks.sSuperBlock.bConstant } , \
    { 68u, &x2cModel.blocks.sSuperBlock.bGain } , \
    { 69u, &x2cModel.blocks.bVelSignalPatth } , \
    { 70u, &x2cModel.blocks.sstartup.bConstant } , \
    { 71u, &x2cModel.blocks.sstartup.bConstant1 } , \
    { 72u, &x2cModel.blocks.sstartup.bConstant2 } , \
    { 73u, &x2cModel.blocks.sstartup.bConstant3 } , \
    { 74u, &x2cModel.blocks.sstartup.bConstant5 } , \
    { 75u, &x2cModel.blocks.sstartup.bFlux_select } , \
    { 76u, &x2cModel.blocks.sstartup.bFlux_select1 } , \
    { 77u, &x2cModel.blocks.sstartup.bIdRateLimiter } , \
    { 78u, &x2cModel.blocks.sstartup.bIq_select } , \
    { 79u, &x2cModel.blocks.sstartup.bLoopBreaker } , \
    { 80u, &x2cModel.blocks.sstartup.bLoopBreaker1 } , \
    { 81u, &x2cModel.blocks.sstartup.bManualSwitch } , \
    { 82u, &x2cModel.blocks.sstartup.bManualSwitch1 } , \
    { 83u, &x2cModel.blocks.sstartup.bPI } , \
    { 84u, &x2cModel.blocks.sstartup.bPosError } , \
    { 85u, &x2cModel.blocks.sstartup.bPosSwitch } , \
    { 86u, &x2cModel.blocks.sstartup.bRamp_Up_Current } , \
    { 87u, &x2cModel.blocks.sstartup.bSequencer } , \
    { 88u, &x2cModel.blocks.sstartup.sSuperBlock.bConstant4 } , \
    { 89u, &x2cModel.blocks.sstartup.sSuperBlock.bI } , \
    { 90u, &x2cModel.blocks.sstartup.sSuperBlock.bI_Init_Zero } , \
    { 91u, &x2cModel.blocks.sstartup.sSuperBlock.bI_Init_Zero1 } , \
    { 92u, &x2cModel.blocks.sstartup.sSuperBlock.bMult } , \
    { 93u, &x2cModel.blocks.sstartup.sSuperBlock.bRamp_Up_PositionGenerator } , \
    { 94u, &x2cModel.blocks.sstartup.sSuperBlock.bSaturation } , \
    { 95u, &x2cModel.blocks.sstartup.sSuperBlock.bSign } , \
    { 96u, &x2cModel.blocks.sstartup.sSuperBlock.bTypeConv } , \
    { 97u, &x2cModel.blocks.sstartup.bTypeConv } , \
    { 98u, &x2cModel.blocks.sstartup.bTypeConv1 } , \
    { 99u, &x2cModel.blocks.sstartup.bTypeConv2 } , \
    { 118u, &x2cScope }

#define INPORT_PARAMID_TABLE \
    { 100u, 2u, &x2cModel.inports.bCPU_LOAD } , \
    { 101u, 2u, &x2cModel.inports.bI_a } , \
    { 102u, 2u, &x2cModel.inports.bI_b } , \
    { 103u, 2u, &x2cModel.inports.bI_sum } , \
    { 104u, 2u, &x2cModel.inports.bQEI_POS } , \
    { 105u, 2u, &x2cModel.inports.bQEI_VEL } , \
    { 106u, 1u, &x2cModel.inports.bSW1 } , \
    { 107u, 2u, &x2cModel.inports.bSW2 } , \
    { 108u, 2u, &x2cModel.inports.bV_POT } 

#define OUTPORT_PARAMID_TABLE \
    { 109u, 2u, &x2cModel.outports.sFOCmain.bEstimated_angle } , \
    { 110u, 2u, &x2cModel.outports.sFOCmain.bEstimated_speed } , \
    { 111u, 1u, &x2cModel.outports.bHOME_INIT } , \
    { 112u, 1u, &x2cModel.outports.bLED1 } , \
    { 113u, 2u, &x2cModel.outports.bLED2 } , \
    { 114u, 2u, &x2cModel.outports.bPWM1 } , \
    { 115u, 2u, &x2cModel.outports.bPWM2 } , \
    { 116u, 2u, &x2cModel.outports.bPWM3 } , \
    { 117u, 2u, &x2cModel.outports.bQEI_OFFSET } 


/**********************************************************************************************************************/
/**                                            Model structure definition                                            **/
/**********************************************************************************************************************/
struct x2cModel {
/*  Control Blocks                                                                                                    */
    struct {
/*      Sub-system FOCmain                                                                                            */
        struct {
/*          Sub-system PLLEstimator                                                                                   */
            struct {
/*              Sub-system SuperBlock                                                                                 */
                struct {
                    ADD_FIP16 bAdd;
                    AUTOSWITCH_FIP16 bAutoSwitch;
                    GAIN_FIP16 bGain;
                    SUB_FIP16 bSub;
                } sSuperBlock;
                AVERAGE_FIP16 bAverage;
                AVERAGE_FIP16 bAverage1;
                BEMF_MCHP_FIP16 bBEMF_MCHP;
                LOOPBREAKER_FIP16 bLoopBreaker;
                PARK_MCHP_FIP16 bPark_MCHP;
                UI_FIP16 buI;
            } sPLLEstimator;
            CLARKE_PARK_MCHP_FIP16 bClarke_Park_MCHP;
            CONSTANT_FIP16 bConstant;
            CONSTANT_FIP16 bConstant1;
            GAIN_FIP16 bGain;
            GAIN_FIP16 bGain2;
            GAIN_FIP16 bGain3;
            MANUALSWITCH_FIP16 bManualSwitch2;
            MANUALSWITCH_FIP16 bManualSwitch3;
            MANUALSWITCH_FIP16 bManualSwitch5;
            NOT_BOOL bNot;
            PI_FIP16 bPI_flux;
            PI_FIP16 bPI_torque;
            PARK_CLARKE_INV_SVM_MCHP_FIP16 bPark_Clarke_inv_SVM_MCHP;
            SATURATION_FIP16 bSaturation_Vd;
            SATURATION_FIP16 bSaturation_Vq;
            SIN3GEN_FIP16 bSin3Gen;
            SUB_FIP16 bSub_flux;
            SUB_FIP16 bSub_torque;
            MANUALSWITCH_FIP16 bVdOverride;
            CONSTANT_FIP16 bVdOverrideVal;
            MANUALSWITCH_FIP16 bVqOverride;
            CONSTANT_FIP16 bVqOverrideVal;
        } sFOCmain;
/*      Sub-system SpeedPI                                                                                            */
        struct {
/*          Sub-system SuperBlock                                                                                     */
            struct {
                ADD_FIP16 bAdd;
                AUTOSWITCH_FIP16 bAutoSwitch;
                CONSTANT_FIP16 bConstant;
                CONSTANT_FIP16 bConstant1;
                CONSTANT_BOOL bConstant2;
                CONSTANT_FIP16 bConstant3;
                GAIN_FIP16 bGain;
                RATELIMITER_FIP16 bRateLimiter;
                SINGEN_FIP16 bSinGen;
            } sSuperBlock;
/*          Sub-system SuperBlock1                                                                                    */
            struct {
                ADD_FIP16 bAdd;
                AUTOSWITCH_FIP16 bAutoSwitch;
                CONSTANT_FIP16 bConstant;
                CONSTANT_FIP16 bConstant1;
                CONSTANT_BOOL bConstant2;
                CONSTANT_FIP16 bConstant3;
                GAIN_FIP16 bGain;
                RATELIMITER_FIP16 bRateLimiter;
                SINGEN_FIP16 bSinGen;
            } sSuperBlock1;
            MANUALSWITCH_FIP16 bManualSwitch;
            PI_FIP16 bPI_speed;
            RATELIMITER_FIP16 bRateLimiter;
            SUB_FIP16 bSpeed_error;
            CONSTANT_FIP16 bSpeetPerturbation;
            CONSTANT_FIP16 bTorquePerturbation;
            CONSTANT_FIP16 btorqueSetpoint;
        } sSpeedPI;
/*      Sub-system SuperBlock                                                                                         */
        struct {
            ABS_FIP16 bAbs;
            ADD_FIP16 bAdd;
            AVERAGE_FIP16 bAverage;
            CONSTANT_FIP16 bConstant;
            GAIN_FIP16 bGain;
        } sSuperBlock;
/*      Sub-system startup                                                                                            */
        struct {
/*          Sub-system SuperBlock                                                                                     */
            struct {
                CONSTANT_FIP16 bConstant4;
                I_FIP16 bI;
                CONSTANT_FIP16 bI_Init_Zero;
                CONSTANT_FIP16 bI_Init_Zero1;
                MULT_FIP16 bMult;
                UI_FIP16 bRamp_Up_PositionGenerator;
                SATURATION_FIP16 bSaturation;
                SIGN_FIP16 bSign;
                TYPECONV_FIP16_BOOL bTypeConv;
            } sSuperBlock;
            CONSTANT_FIP16 bConstant;
            CONSTANT_FIP16 bConstant1;
            CONSTANT_FIP16 bConstant2;
            CONSTANT_FIP16 bConstant3;
            CONSTANT_BOOL bConstant5;
            AUTOSWITCH_FIP16 bFlux_select;
            AUTOSWITCH_FIP16 bFlux_select1;
            RATELIMITER_FIP16 bIdRateLimiter;
            AUTOSWITCH_FIP16 bIq_select;
            LOOPBREAKER_FIP16 bLoopBreaker;
            LOOPBREAKER_BOOL bLoopBreaker1;
            MANUALSWITCH_FIP16 bManualSwitch;
            MANUALSWITCH_FIP16 bManualSwitch1;
            PI_FIP16 bPI;
            USUB_FIP16 bPosError;
            AUTOSWITCH_FIP16 bPosSwitch;
            CONSTANT_FIP16 bRamp_Up_Current;
            SEQUENCER_FIP16 bSequencer;
            TYPECONV_FIP16_BOOL bTypeConv;
            TYPECONV_FIP16_BOOL bTypeConv1;
            TYPECONV_FIP16_BOOL bTypeConv2;
        } sstartup;
        LOOPBREAKER_FIP16 bLoopBreaker;
        LOOPBREAKER_FIP16 bLoopBreaker1;
        NOT_BOOL bNot;
        MANUALSWITCH_FIP16 bPosSignalPath;
        CONSTANT_FLOAT32 bQEI_OFFSET1;
        REAL2INT_FLOAT32_FIP16 bReal2Int;
        MANUALSWITCH_FIP16 bVelSignalPatth;
    } blocks;
/*  Inports                                                                                                           */
    struct {
        int16 bCPU_LOAD;
        int16 bI_a;
        int16 bI_b;
        int16 bI_sum;
        int16 bQEI_POS;
        int16 bQEI_VEL;
        bool bSW1;
        int16 bSW2;
        int16 bV_POT;
    } inports;
/*  Outports                                                                                                          */
    struct {
/*      Sub-system FOCmain                                                                                            */
        struct {
            int16* bEstimated_angle;
            int16* bEstimated_speed;
        } sFOCmain;
        bool* bHOME_INIT;
        bool* bLED1;
        int16* bLED2;
        int16* bPWM1;
        int16* bPWM2;
        int16* bPWM3;
        int16* bQEI_OFFSET;
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

#define X2C_UPDATE_4_DIVIDER (4u)
#define X2C_UPDATE_10_DIVIDER (10u)

/**********************************************************************************************************************/
/**     Prototypes                                                                                                   **/
/**********************************************************************************************************************/
void X2C_Init(void);
void X2C_Update(void);
void X2C_Update_1(void);
void X2C_Update_10(void);
void X2C_Update_4(void);

#ifdef __cplusplus
}
#endif

#endif
