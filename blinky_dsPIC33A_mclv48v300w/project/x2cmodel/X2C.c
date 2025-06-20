/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Model: blinky_dspic33a_mclv48v300w                                                                                 */
/* Date:  2025-06-20 10:06                                                                                            */

/* X2C-Version: 6.5.3765                                                                                              */
/* X2C-Edition: Free                                                                                                  */

/* Common includes                                                                                                    */
#include <stddef.h>
#include "TableStruct.h"
/* Generated file includes                                                                                            */
#include "FlashTable.h"
#include "RamTable.h"
#include "X2C.h"

/**********************************************************************************************************************/
/**                                                       Model                                                      **/
/**********************************************************************************************************************/
struct x2cModel x2cModel;

/* Model identifier                                                                                                   */
const uint32 x2cModelIdentifier = 0x16D4B6B0u;

/**********************************************************************************************************************/
/**                                                       Scope                                                      **/
/**********************************************************************************************************************/
SCOPE_MAIN x2cScope;

/* Block function table                                                                                               */
const tBlockFunctions blockFunctionTable[] = {
    FUNCTIONS,
    { 0u, NULL, NULL, NULL, NULL, NULL } /* End of table entry */
};

/* Parameter identifier table                                                                                         */
const tParameterTable parameterIdTable[] = {
    PARAMETER_TABLE,
    { 0u, NULL } /* End of table entry */
};

/* Inport Parameter identifier table                                                                                  */
const tIoParamIdEntry inportParamIdTable[] = {
    INPORT_PARAMID_TABLE, 
    { 0u, 0u, NULL } /* End of table entry */
};

/* Outport Parameter identifier table                                                                                 */
const tIoParamIdEntry outportParamIdTable[] = {
    OUTPORT_PARAMID_TABLE, 
    { 0u, 0u, NULL } /* End of table entry */
};

/* Mask Parameter identifier table                                                                                    */
const tMaskParameterEntry maskParamIdTable[] = {
    { 0u, NULL, NULL, NULL, NULL } /* End of table entry */
};

/* Extended Mask Parameter identifier table (used by Model API)                                                       */
const tMaskParamExtRecord maskParamExtTable[] = {
    { 0u, 0u, NULL, NULL, NULL, NULL, NULL } /* End of table entry */
};

/* Mask Parameter data table (used by Model API)                                                                      */
const tMaskParamDataRecord maskParamDataTable[] = {
    { 0u, 0u, NULL, 0u, 0u } /* End of table entry */
};

/**********************************************************************************************************************/
/** Model Sample Time                                                                                                **/
/**********************************************************************************************************************/
float_CoT getModelSampleTime()
{
    return ((float_CoT)5.0E-5);
}

/**********************************************************************************************************************/
/**                                                  Initialization                                                  **/
/**********************************************************************************************************************/
void X2C_Init(void)
{
    /******************************************************************************************************************/
    /**                                          Initialize Block Parameters                                         **/
    /******************************************************************************************************************/

    /* Block: AutoSwitch                                                                                              */
    /* Thresh_up = 0.0                                                                                                */
    /* Thresh_down = 0.0                                                                                              */
    x2cModel.blocks.bAutoSwitch.Thresh_up = 0;
    x2cModel.blocks.bAutoSwitch.Thresh_down = 0;
    x2cModel.blocks.bAutoSwitch.Status = &RamTable_int16[0];

    /* Block: AutoSwitch1                                                                                             */
    /* Thresh_up = 0.0                                                                                                */
    /* Thresh_down = 0.0                                                                                              */
    x2cModel.blocks.bAutoSwitch1.Thresh_up = 0;
    x2cModel.blocks.bAutoSwitch1.Thresh_down = 0;
    x2cModel.blocks.bAutoSwitch1.Status = &RamTable_int16[1];

    /* Block: Constant                                                                                                */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.bConstant.K = 32767;

    /* Block: Constant1                                                                                               */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.bConstant1.K = 32767;

    /* Block: Constant2                                                                                               */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.bConstant2.K = 0;

    /* Block: Constant3                                                                                               */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.bConstant3.K = 32767;

    /* Block: Gain1                                                                                                   */
    /* Gain = -1.0                                                                                                    */
    x2cModel.blocks.bGain1.V = -16384;
    x2cModel.blocks.bGain1.sfr = 14;

    /* Block: SinGen                                                                                                  */
    /* fmax = 10.0                                                                                                    */
    /* Offset = 0.0                                                                                                   */
    /* Phase = 0.0                                                                                                    */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.bSinGen.delta_phi = 33;
    x2cModel.blocks.bSinGen.phase = 0;
    x2cModel.blocks.bSinGen.offset = 0;
    x2cModel.blocks.bSinGen.phi = 0;


    /* Initialize RAM table content */
    initRamTables();

    /******************************************************************************************************************/
    /**                                              Initialize Inports                                              **/
    /******************************************************************************************************************/
    x2cModel.inports.bCPU_LOAD = (int16)0;
    x2cModel.inports.bSW1 = (int16)0;
    x2cModel.inports.bSW2 = (int16)0;
    x2cModel.inports.bV_POT = (int16)0;

    /******************************************************************************************************************/
    /**                                               Link Block Inputs                                              **/
    /******************************************************************************************************************/

    /* Block AutoSwitch                                                                                               */
    x2cModel.blocks.bAutoSwitch.In1 =
        &x2cModel.blocks.bConstant.Out;
    x2cModel.blocks.bAutoSwitch.Switch =
        &x2cModel.inports.bSW2;
    x2cModel.blocks.bAutoSwitch.In3 =
        &x2cModel.inports.bV_POT;

    /* Block AutoSwitch1                                                                                              */
    x2cModel.blocks.bAutoSwitch1.In1 =
        &x2cModel.blocks.bConstant1.Out;
    x2cModel.blocks.bAutoSwitch1.Switch =
        &x2cModel.blocks.bSinGen.u;
    x2cModel.blocks.bAutoSwitch1.In3 =
        &x2cModel.blocks.bConstant2.Out;

    /* Block Constant                                                                                                 */

    /* Block Constant1                                                                                                */

    /* Block Constant2                                                                                                */

    /* Block Constant3                                                                                                */

    /* Block Gain1                                                                                                    */
    x2cModel.blocks.bGain1.In =
        &x2cModel.inports.bSW1;

    /* Block SinGen                                                                                                   */
    x2cModel.blocks.bSinGen.A =
        &x2cModel.blocks.bConstant3.Out;
    x2cModel.blocks.bSinGen.f =
        &x2cModel.blocks.bAutoSwitch.Out;

    /******************************************************************************************************************/
    /**                                                 Link Outports                                                **/
    /******************************************************************************************************************/
    x2cModel.outports.bLED1 =
        &x2cModel.blocks.bGain1.Out;
    x2cModel.outports.bLED2 =
        &x2cModel.blocks.bAutoSwitch1.Out;
    x2cModel.outports.bPWM1 =
        &x2cModel.blocks.bSinGen.u;

    /******************************************************************************************************************/
    /**                                           Run Block Init Functions                                           **/
    /******************************************************************************************************************/
    AutoSwitch_FiP16_Init(&x2cModel.blocks.bAutoSwitch);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.bAutoSwitch1);
    Constant_FiP16_Init(&x2cModel.blocks.bConstant);
    Constant_FiP16_Init(&x2cModel.blocks.bConstant1);
    Constant_FiP16_Init(&x2cModel.blocks.bConstant2);
    Constant_FiP16_Init(&x2cModel.blocks.bConstant3);
    Gain_FiP16_Init(&x2cModel.blocks.bGain1);
    SinGen_FiP16_Init(&x2cModel.blocks.bSinGen);
    Scope_Main_Init(&x2cScope);

    /* Initialize TableStruct tables                                                                                  */
    TableStruct->TFncTable = blockFunctionTable;
    TableStruct->TParamTable = parameterIdTable;
    TableStruct->inportParamTable = inportParamIdTable;
    TableStruct->outportParamTable = outportParamIdTable;
    TableStruct->maskParameterTable = maskParamIdTable;
}

/**********************************************************************************************************************/
/**                                            Run Block Update Functions                                            **/
/**********************************************************************************************************************/
void X2C_Update(void)
{
    X2C_Update_1();

}

/* X2C_Update for blocks with 1*Ts                                                                                    */
void X2C_Update_1(void)
{
    AutoSwitch_FiP16_Update(&x2cModel.blocks.bAutoSwitch);
    SinGen_FiP16_Update(&x2cModel.blocks.bSinGen);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.bAutoSwitch1);
    Gain_FiP16_Update(&x2cModel.blocks.bGain1);
    Scope_Main_Update(&x2cScope);
}

