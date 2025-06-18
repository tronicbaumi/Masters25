/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Model: blinky_dspic33a_mclv48v300w                                                                                 */
/* Date:  2025-06-18 17:36                                                                                            */

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
const uint32 x2cModelIdentifier = 0x2AF80209u;

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

    /* Block: Gain                                                                                                    */
    /* Gain = 1.0                                                                                                     */
    x2cModel.blocks.bGain.V = 16384;
    x2cModel.blocks.bGain.sfr = 14;

    /* Block: Gain1                                                                                                   */
    /* Gain = 1.0                                                                                                     */
    x2cModel.blocks.bGain1.V = 16384;
    x2cModel.blocks.bGain1.sfr = 14;

    /* Block: Gain2                                                                                                   */
    /* Gain = 1.0                                                                                                     */
    x2cModel.blocks.bGain2.V = 16384;
    x2cModel.blocks.bGain2.sfr = 14;


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

    /* Block Gain                                                                                                     */
    x2cModel.blocks.bGain.In =
        &x2cModel.inports.bSW2;

    /* Block Gain1                                                                                                    */
    x2cModel.blocks.bGain1.In =
        &x2cModel.inports.bSW1;

    /* Block Gain2                                                                                                    */
    x2cModel.blocks.bGain2.In =
        &x2cModel.inports.bV_POT;

    /******************************************************************************************************************/
    /**                                                 Link Outports                                                **/
    /******************************************************************************************************************/
    x2cModel.outports.bLED1 =
        &x2cModel.blocks.bGain1.Out;
    x2cModel.outports.bLED2 =
        &x2cModel.blocks.bGain.Out;
    x2cModel.outports.bPWM1 =
        &x2cModel.blocks.bGain2.Out;

    /******************************************************************************************************************/
    /**                                           Run Block Init Functions                                           **/
    /******************************************************************************************************************/
    Gain_FiP16_Init(&x2cModel.blocks.bGain);
    Gain_FiP16_Init(&x2cModel.blocks.bGain1);
    Gain_FiP16_Init(&x2cModel.blocks.bGain2);
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
    Gain_FiP16_Update(&x2cModel.blocks.bGain);
    Gain_FiP16_Update(&x2cModel.blocks.bGain1);
    Gain_FiP16_Update(&x2cModel.blocks.bGain2);
    Scope_Main_Update(&x2cScope);
}

