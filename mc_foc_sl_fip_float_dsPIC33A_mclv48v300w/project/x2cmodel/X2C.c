/* This file is part of X2C. http://x2c.lcm.at/                                                                       */

/* Model: mc_foc_sl_fip_dspic33a_mclv48v300w                                                                          */
/* Date:  2025-07-28 12:30                                                                                            */

/* X2C-Version: 6.5.3797                                                                                              */
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
const uint32 x2cModelIdentifier = 0x559927DAu;

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

    /* Block: FOCmain/Clarke_Park_MCHP                                                                                */

    /* Block: FOCmain/Constant                                                                                        */
    /* Value = 0.14                                                                                                   */
    x2cModel.blocks.sFOCmain.bConstant.K = 4588;

    /* Block: FOCmain/Constant1                                                                                       */
    /* Value = 0.3                                                                                                    */
    x2cModel.blocks.sFOCmain.bConstant1.K = 9830;

    /* Block: FOCmain/Gain                                                                                            */
    /* Gain = 1.0                                                                                                     */
    x2cModel.blocks.sFOCmain.bGain.V = 16384;
    x2cModel.blocks.sFOCmain.bGain.sfr = 14;

    /* Block: FOCmain/Gain2                                                                                           */
    /* Gain = 0.98                                                                                                    */
    x2cModel.blocks.sFOCmain.bGain2.V = 32113;
    x2cModel.blocks.sFOCmain.bGain2.sfr = 15;

    /* Block: FOCmain/Gain3                                                                                           */
    /* Gain = 0.98                                                                                                    */
    x2cModel.blocks.sFOCmain.bGain3.V = 32113;
    x2cModel.blocks.sFOCmain.bGain3.sfr = 15;

    /* Block: FOCmain/ManualSwitch2                                                                                   */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.sFOCmain.bManualSwitch2.Toggle = 1;

    /* Block: FOCmain/ManualSwitch3                                                                                   */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.sFOCmain.bManualSwitch3.Toggle = 1;

    /* Block: FOCmain/ManualSwitch5                                                                                   */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.sFOCmain.bManualSwitch5.Toggle = 1;

    /* Block: FOCmain/Not                                                                                             */

    /* Block: FOCmain/PI_flux                                                                                         */
    /* Kp = 0.8                                                                                                       */
    /* Ki = 8.0                                                                                                       */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sFOCmain.bPI_flux.b0 = 13;
    x2cModel.blocks.sFOCmain.bPI_flux.b1 = 26214;
    x2cModel.blocks.sFOCmain.bPI_flux.sfrb0 = 15;
    x2cModel.blocks.sFOCmain.bPI_flux.sfrb1 = 15;
    x2cModel.blocks.sFOCmain.bPI_flux.i_old = 0;
    x2cModel.blocks.sFOCmain.bPI_flux.enable_old = 0;

    /* Block: FOCmain/PI_torque                                                                                       */
    /* Kp = 0.8                                                                                                       */
    /* Ki = 8.0                                                                                                       */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sFOCmain.bPI_torque.b0 = 13;
    x2cModel.blocks.sFOCmain.bPI_torque.b1 = 26214;
    x2cModel.blocks.sFOCmain.bPI_torque.sfrb0 = 15;
    x2cModel.blocks.sFOCmain.bPI_torque.sfrb1 = 15;
    x2cModel.blocks.sFOCmain.bPI_torque.i_old = 0;
    x2cModel.blocks.sFOCmain.bPI_torque.enable_old = 0;

    /* Block: FOCmain/PLLEstimator/Average                                                                            */
    /* n = 64                                                                                                         */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage.n = 64;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage.sfrn = 6;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage.sum = 0;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage.count = 0;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage.avg = &RamTable_int16[0];

    /* Block: FOCmain/PLLEstimator/Average1                                                                           */
    /* n = 64                                                                                                         */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage1.n = 64;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage1.sfrn = 6;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage1.sum = 0;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage1.count = 0;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage1.avg = &RamTable_int16[256];

    /* Block: FOCmain/PLLEstimator/BEMF_MCHP                                                                          */
    /* Ls = 0.17                                                                                                      */
    /* Rs = 0.2                                                                                                       */
    /* U0 = 24.0                                                                                                      */
    /* I0 = 22.0                                                                                                      */
    /* ts_fact = 1.0                                                                                                  */
    /* CurrentSampleFactor = 1.0                                                                                      */
    x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP.Ls = 25532;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP.Rs = 6007;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP.sfrLs = 13;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP.sfrRs = 15;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP.Ib_old = 0;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP.Ia_old = 0;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP.CurrentSampleFactor = 1;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP.V_Ls_alpha = 0;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP.V_Ls_beta = 0;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP.FactCounter = 0;

    /* Block: FOCmain/PLLEstimator/LoopBreaker                                                                        */

    /* Block: FOCmain/PLLEstimator/Park_MCHP                                                                          */

    /* Block: FOCmain/PLLEstimator/SuperBlock/Add                                                                     */

    /* Block: FOCmain/PLLEstimator/SuperBlock/AutoSwitch                                                              */
    /* Thresh_up = 0.0                                                                                                */
    /* Thresh_down = 0.0                                                                                              */
    x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bAutoSwitch.Thresh_up = 0;
    x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bAutoSwitch.Thresh_down = 0;
    x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bAutoSwitch.Status = &RamTable_int16[512];

    /* Block: FOCmain/PLLEstimator/SuperBlock/Gain                                                                    */
    /* Gain = 0.5567624999999999                                                                                      */
    x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bGain.V = 18244;
    x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bGain.sfr = 15;

    /* Block: FOCmain/PLLEstimator/SuperBlock/Sub                                                                     */

    /* Block: FOCmain/PLLEstimator/uI                                                                                 */
    /* Ki = 1400.0                                                                                                    */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sFOCmain.sPLLEstimator.buI.b0 = 2294;
    x2cModel.blocks.sFOCmain.sPLLEstimator.buI.sfr = 15;
    x2cModel.blocks.sFOCmain.sPLLEstimator.buI.i_old = 0;
    x2cModel.blocks.sFOCmain.sPLLEstimator.buI.enable_old = 0;

    /* Block: FOCmain/Park_Clarke_inv_SVM_MCHP                                                                        */

    /* Block: FOCmain/Saturation_Vd                                                                                   */
    /* max = 0.98                                                                                                     */
    /* min = -0.98                                                                                                    */
    x2cModel.blocks.sFOCmain.bSaturation_Vd.max = 32113;
    x2cModel.blocks.sFOCmain.bSaturation_Vd.min = -32113;

    /* Block: FOCmain/Saturation_Vq                                                                                   */
    /* max = 0.98                                                                                                     */
    /* min = -0.98                                                                                                    */
    x2cModel.blocks.sFOCmain.bSaturation_Vq.max = 32113;
    x2cModel.blocks.sFOCmain.bSaturation_Vq.min = -32113;

    /* Block: FOCmain/Sin3Gen                                                                                         */
    /* fmax = 65.0                                                                                                    */
    /* Offset = 0.0                                                                                                   */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sFOCmain.bSin3Gen.delta_phi = 213;
    x2cModel.blocks.sFOCmain.bSin3Gen.offset = 0;
    x2cModel.blocks.sFOCmain.bSin3Gen.phi = 0;

    /* Block: FOCmain/Sub_flux                                                                                        */

    /* Block: FOCmain/Sub_torque                                                                                      */

    /* Block: FOCmain/VdOverride                                                                                      */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.sFOCmain.bVdOverride.Toggle = 1;

    /* Block: FOCmain/VdOverrideVal                                                                                   */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sFOCmain.bVdOverrideVal.K = 0;

    /* Block: FOCmain/VqOverride                                                                                      */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.sFOCmain.bVqOverride.Toggle = 1;

    /* Block: FOCmain/VqOverrideVal                                                                                   */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sFOCmain.bVqOverrideVal.K = 0;

    /* Block: LoopBreaker                                                                                             */

    /* Block: LoopBreaker1                                                                                            */

    /* Block: Not                                                                                                     */

    /* Block: PosSignalPath                                                                                           */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.bPosSignalPath.Toggle = 1;

    /* Block: QEI_OFFSET1                                                                                             */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.bQEI_OFFSET1.K = 0;

    /* Block: Real2Int                                                                                                */
    /* Scale = 1.0                                                                                                    */
    x2cModel.blocks.bReal2Int.scale = 32768;

    /* Block: SpeedPI/IqPerturpation/Add                                                                              */

    /* Block: SpeedPI/IqPerturpation/AutoSwitch                                                                       */
    /* Thresh_up = 0.0                                                                                                */
    /* Thresh_down = 0.0                                                                                              */
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bAutoSwitch.Thresh_up = 0;
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bAutoSwitch.Thresh_down = 0;
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bAutoSwitch.Status = &RamTable_int16[513];

    /* Block: SpeedPI/IqPerturpation/Constant                                                                         */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bConstant.K = 32767;

    /* Block: SpeedPI/IqPerturpation/Constant1                                                                        */
    /* Value = 0.01                                                                                                   */
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bConstant1.K = 328;

    /* Block: SpeedPI/IqPerturpation/Constant2                                                                        */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bConstant2.K = 1;

    /* Block: SpeedPI/IqPerturpation/Constant3                                                                        */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bConstant3.K = 0;

    /* Block: SpeedPI/IqPerturpation/Gain                                                                             */
    /* Gain = -1.0                                                                                                    */
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bGain.V = -16384;
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bGain.sfr = 14;

    /* Block: SpeedPI/IqPerturpation/RateLimiter                                                                      */
    /* Tr = 0.01                                                                                                      */
    /* Tf = 0.01                                                                                                      */
    /* ts_fact = 10.0                                                                                                 */
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bRateLimiter.RateUp = 107374182;
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bRateLimiter.RateDown = 107374182;
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bRateLimiter.out_old = 0;
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bRateLimiter.enable_old = 0;

    /* Block: SpeedPI/IqPerturpation/SinGen                                                                           */
    /* fmax = 100.0                                                                                                   */
    /* Offset = 0.0                                                                                                   */
    /* Phase = 0.0                                                                                                    */
    /* ts_fact = 10.0                                                                                                 */
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bSinGen.delta_phi = 3277;
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bSinGen.phase = 0;
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bSinGen.offset = 0;
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bSinGen.phi = 0;

    /* Block: SpeedPI/ManualSwitch                                                                                    */
    /* Toggle = 0.0                                                                                                   */
    x2cModel.blocks.sSpeedPI.bManualSwitch.Toggle = 0;

    /* Block: SpeedPI/PI_speed                                                                                        */
    /* Kp = 0.8                                                                                                       */
    /* Ki = 12.0                                                                                                      */
    /* ts_fact = 10.0                                                                                                 */
    x2cModel.blocks.sSpeedPI.bPI_speed.b0 = 197;
    x2cModel.blocks.sSpeedPI.bPI_speed.b1 = 26214;
    x2cModel.blocks.sSpeedPI.bPI_speed.sfrb0 = 15;
    x2cModel.blocks.sSpeedPI.bPI_speed.sfrb1 = 15;
    x2cModel.blocks.sSpeedPI.bPI_speed.i_old = 0;
    x2cModel.blocks.sSpeedPI.bPI_speed.enable_old = 0;

    /* Block: SpeedPI/RateLimiter                                                                                     */
    /* Tr = 2.0                                                                                                       */
    /* Tf = 2.0                                                                                                       */
    /* ts_fact = 10.0                                                                                                 */
    x2cModel.blocks.sSpeedPI.bRateLimiter.RateUp = 536871;
    x2cModel.blocks.sSpeedPI.bRateLimiter.RateDown = 536871;
    x2cModel.blocks.sSpeedPI.bRateLimiter.out_old = 0;
    x2cModel.blocks.sSpeedPI.bRateLimiter.enable_old = 0;

    /* Block: SpeedPI/Speed_error                                                                                     */

    /* Block: SpeedPI/SpeetPerturbation                                                                               */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sSpeedPI.bSpeetPerturbation.K = 0;

    /* Block: SpeedPI/TorquePerturbation                                                                              */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sSpeedPI.bTorquePerturbation.K = 0;

    /* Block: SpeedPI/torqueSetpoint                                                                                  */
    /* Value = 0.03                                                                                                   */
    x2cModel.blocks.sSpeedPI.btorqueSetpoint.K = 983;

    /* Block: SpeedPI/vPerturbation/Add                                                                               */

    /* Block: SpeedPI/vPerturbation/AutoSwitch                                                                        */
    /* Thresh_up = 0.0                                                                                                */
    /* Thresh_down = 0.0                                                                                              */
    x2cModel.blocks.sSpeedPI.svPerturbation.bAutoSwitch.Thresh_up = 0;
    x2cModel.blocks.sSpeedPI.svPerturbation.bAutoSwitch.Thresh_down = 0;
    x2cModel.blocks.sSpeedPI.svPerturbation.bAutoSwitch.Status = &RamTable_int16[514];

    /* Block: SpeedPI/vPerturbation/Constant                                                                          */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sSpeedPI.svPerturbation.bConstant.K = 32767;

    /* Block: SpeedPI/vPerturbation/Constant1                                                                         */
    /* Value = 0.01                                                                                                   */
    x2cModel.blocks.sSpeedPI.svPerturbation.bConstant1.K = 328;

    /* Block: SpeedPI/vPerturbation/Constant2                                                                         */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sSpeedPI.svPerturbation.bConstant2.K = 1;

    /* Block: SpeedPI/vPerturbation/Constant3                                                                         */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sSpeedPI.svPerturbation.bConstant3.K = 0;

    /* Block: SpeedPI/vPerturbation/Gain                                                                              */
    /* Gain = -1.0                                                                                                    */
    x2cModel.blocks.sSpeedPI.svPerturbation.bGain.V = -16384;
    x2cModel.blocks.sSpeedPI.svPerturbation.bGain.sfr = 14;

    /* Block: SpeedPI/vPerturbation/RateLimiter                                                                       */
    /* Tr = 1.0                                                                                                       */
    /* Tf = 1.0                                                                                                       */
    /* ts_fact = 10.0                                                                                                 */
    x2cModel.blocks.sSpeedPI.svPerturbation.bRateLimiter.RateUp = 1073742;
    x2cModel.blocks.sSpeedPI.svPerturbation.bRateLimiter.RateDown = 1073742;
    x2cModel.blocks.sSpeedPI.svPerturbation.bRateLimiter.out_old = 0;
    x2cModel.blocks.sSpeedPI.svPerturbation.bRateLimiter.enable_old = 0;

    /* Block: SpeedPI/vPerturbation/SinGen                                                                            */
    /* fmax = 100.0                                                                                                   */
    /* Offset = 0.0                                                                                                   */
    /* Phase = 0.0                                                                                                    */
    /* ts_fact = 10.0                                                                                                 */
    x2cModel.blocks.sSpeedPI.svPerturbation.bSinGen.delta_phi = 3277;
    x2cModel.blocks.sSpeedPI.svPerturbation.bSinGen.phase = 0;
    x2cModel.blocks.sSpeedPI.svPerturbation.bSinGen.offset = 0;
    x2cModel.blocks.sSpeedPI.svPerturbation.bSinGen.phi = 0;

    /* Block: SpeedScaling/Abs                                                                                        */

    /* Block: SpeedScaling/Add                                                                                        */

    /* Block: SpeedScaling/Average                                                                                    */
    /* n = 256                                                                                                        */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sSpeedScaling.bAverage.n = 256;
    x2cModel.blocks.sSpeedScaling.bAverage.sfrn = 8;
    x2cModel.blocks.sSpeedScaling.bAverage.sum = 0;
    x2cModel.blocks.sSpeedScaling.bAverage.count = 0;
    x2cModel.blocks.sSpeedScaling.bAverage.avg = &RamTable_int16[515];

    /* Block: SpeedScaling/Constant                                                                                   */
    /* Value = 0.05                                                                                                   */
    x2cModel.blocks.sSpeedScaling.bConstant.K = 1638;

    /* Block: SpeedScaling/Gain                                                                                       */
    /* Gain = 0.3                                                                                                     */
    x2cModel.blocks.sSpeedScaling.bGain.V = 9830;
    x2cModel.blocks.sSpeedScaling.bGain.sfr = 15;

    /* Block: VelSignalPatth                                                                                          */
    /* Toggle = 1.0                                                                                                   */
    x2cModel.blocks.bVelSignalPatth.Toggle = 1;

    /* Block: startup/Constant                                                                                        */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sstartup.bConstant.K = 0;

    /* Block: startup/Constant1                                                                                       */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sstartup.bConstant1.K = 0;

    /* Block: startup/Constant2                                                                                       */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sstartup.bConstant2.K = 0;

    /* Block: startup/Constant3                                                                                       */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sstartup.bConstant3.K = 0;

    /* Block: startup/Constant5                                                                                       */
    /* Value = 1.0                                                                                                    */
    x2cModel.blocks.sstartup.bConstant5.K = 1;

    /* Block: startup/Flux_select                                                                                     */
    /* Thresh_up = 0.5                                                                                                */
    /* Thresh_down = 0.5                                                                                              */
    x2cModel.blocks.sstartup.bFlux_select.Thresh_up = 16384;
    x2cModel.blocks.sstartup.bFlux_select.Thresh_down = 16384;
    x2cModel.blocks.sstartup.bFlux_select.Status = &RamTable_int16[771];

    /* Block: startup/Flux_select1                                                                                    */
    /* Thresh_up = 0.5                                                                                                */
    /* Thresh_down = 0.5                                                                                              */
    x2cModel.blocks.sstartup.bFlux_select1.Thresh_up = 16384;
    x2cModel.blocks.sstartup.bFlux_select1.Thresh_down = 16384;
    x2cModel.blocks.sstartup.bFlux_select1.Status = &RamTable_int16[772];

    /* Block: startup/IdRateLimiter                                                                                   */
    /* Tr = 3.0                                                                                                       */
    /* Tf = 6.0                                                                                                       */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sstartup.bIdRateLimiter.RateUp = 35791;
    x2cModel.blocks.sstartup.bIdRateLimiter.RateDown = 17896;
    x2cModel.blocks.sstartup.bIdRateLimiter.out_old = 0;
    x2cModel.blocks.sstartup.bIdRateLimiter.enable_old = 0;

    /* Block: startup/Iq_select                                                                                       */
    /* Thresh_up = 0.5                                                                                                */
    /* Thresh_down = 0.5                                                                                              */
    x2cModel.blocks.sstartup.bIq_select.Thresh_up = 16384;
    x2cModel.blocks.sstartup.bIq_select.Thresh_down = 16384;
    x2cModel.blocks.sstartup.bIq_select.Status = &RamTable_int16[773];

    /* Block: startup/LoopBreaker                                                                                     */

    /* Block: startup/LoopBreaker1                                                                                    */

    /* Block: startup/ManualSwitch                                                                                    */
    /* Toggle = 0.0                                                                                                   */
    x2cModel.blocks.sstartup.bManualSwitch.Toggle = 0;

    /* Block: startup/ManualSwitch1                                                                                   */
    /* Toggle = 0.0                                                                                                   */
    x2cModel.blocks.sstartup.bManualSwitch1.Toggle = 0;

    /* Block: startup/PI                                                                                              */
    /* Kp = 0.04                                                                                                      */
    /* Ki = 0.0                                                                                                       */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sstartup.bPI.b0 = 0;
    x2cModel.blocks.sstartup.bPI.b1 = 1311;
    x2cModel.blocks.sstartup.bPI.sfrb0 = 15;
    x2cModel.blocks.sstartup.bPI.sfrb1 = 15;
    x2cModel.blocks.sstartup.bPI.i_old = 0;
    x2cModel.blocks.sstartup.bPI.enable_old = 0;

    /* Block: startup/PosError                                                                                        */

    /* Block: startup/PosSwitch                                                                                       */
    /* Thresh_up = 0.5                                                                                                */
    /* Thresh_down = 0.5                                                                                              */
    x2cModel.blocks.sstartup.bPosSwitch.Thresh_up = 16384;
    x2cModel.blocks.sstartup.bPosSwitch.Thresh_down = 16384;
    x2cModel.blocks.sstartup.bPosSwitch.Status = &RamTable_int16[774];

    /* Block: startup/RampGen/Constant4                                                                               */
    /* Value = 0.1                                                                                                    */
    x2cModel.blocks.sstartup.sRampGen.bConstant4.K = 3277;

    /* Block: startup/RampGen/I                                                                                       */
    /* Ki = 2.0                                                                                                       */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sstartup.sRampGen.bI.b0 = 3;
    x2cModel.blocks.sstartup.sRampGen.bI.sfr = 15;
    x2cModel.blocks.sstartup.sRampGen.bI.i_old = 0;
    x2cModel.blocks.sstartup.sRampGen.bI.enable_old = 0;

    /* Block: startup/RampGen/I_Init_Zero                                                                             */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sstartup.sRampGen.bI_Init_Zero.K = 0;

    /* Block: startup/RampGen/I_Init_Zero1                                                                            */
    /* Value = 0.0                                                                                                    */
    x2cModel.blocks.sstartup.sRampGen.bI_Init_Zero1.K = 0;

    /* Block: startup/RampGen/Mult                                                                                    */

    /* Block: startup/RampGen/Ramp_Up_PositionGenerator                                                               */
    /* Ki = 200.0                                                                                                     */
    /* ts_fact = 1.0                                                                                                  */
    x2cModel.blocks.sstartup.sRampGen.bRamp_Up_PositionGenerator.b0 = 328;
    x2cModel.blocks.sstartup.sRampGen.bRamp_Up_PositionGenerator.sfr = 15;
    x2cModel.blocks.sstartup.sRampGen.bRamp_Up_PositionGenerator.i_old = 0;
    x2cModel.blocks.sstartup.sRampGen.bRamp_Up_PositionGenerator.enable_old = 0;

    /* Block: startup/RampGen/Saturation                                                                              */
    /* max = 0.4                                                                                                      */
    /* min = -0.4                                                                                                     */
    x2cModel.blocks.sstartup.sRampGen.bSaturation.max = 13107;
    x2cModel.blocks.sstartup.sRampGen.bSaturation.min = -13107;

    /* Block: startup/RampGen/Sign                                                                                    */

    /* Block: startup/RampGen/TypeConv                                                                                */

    /* Block: startup/Ramp_Up_Current                                                                                 */
    /* Value = 0.1                                                                                                    */
    x2cModel.blocks.sstartup.bRamp_Up_Current.K = 3277;

    /* Block: startup/Sequencer                                                                                       */
    /* Delay1 = 0.25                                                                                                  */
    /* Delay2 = 0.5                                                                                                   */
    /* Delay3 = 2.0                                                                                                   */
    /* Delay4 = 2.3                                                                                                   */
    /* ts_fact = 4.0                                                                                                  */
    x2cModel.blocks.sstartup.bSequencer.delay1 = 1250;
    x2cModel.blocks.sstartup.bSequencer.delay2 = 2500;
    x2cModel.blocks.sstartup.bSequencer.delay3 = 10000;
    x2cModel.blocks.sstartup.bSequencer.delay4 = 11500;
    x2cModel.blocks.sstartup.bSequencer.cnt = 0;
    x2cModel.blocks.sstartup.bSequencer.start_old = 0;

    /* Block: startup/TypeConv                                                                                        */

    /* Block: startup/TypeConv1                                                                                       */

    /* Block: startup/TypeConv2                                                                                       */


    /* Initialize RAM table content */
    initRamTables();

    /******************************************************************************************************************/
    /**                                              Initialize Inports                                              **/
    /******************************************************************************************************************/
    x2cModel.inports.bCPU_LOAD = (int16)0;
    x2cModel.inports.bI_a = (int16)0;
    x2cModel.inports.bI_b = (int16)0;
    x2cModel.inports.bI_sum = (int16)0;
    x2cModel.inports.bQEI_POS = (int16)0;
    x2cModel.inports.bQEI_VEL = (int16)0;
    x2cModel.inports.bSW1 = false;
    x2cModel.inports.bSW2 = (int16)0;
    x2cModel.inports.bV_POT = (int16)0;

    /******************************************************************************************************************/
    /**                                               Link Block Inputs                                              **/
    /******************************************************************************************************************/

    /* Block Clarke_Park_MCHP                                                                                         */
    x2cModel.blocks.sFOCmain.bClarke_Park_MCHP.a =
        &x2cModel.inports.bI_a;
    x2cModel.blocks.sFOCmain.bClarke_Park_MCHP.b =
        &x2cModel.inports.bI_b;
    x2cModel.blocks.sFOCmain.bClarke_Park_MCHP.theta =
        &x2cModel.blocks.sstartup.bPosSwitch.Out;

    /* Block Constant                                                                                                 */

    /* Block Constant1                                                                                                */

    /* Block Gain                                                                                                     */
    x2cModel.blocks.sFOCmain.bGain.In =
        &x2cModel.blocks.sstartup.bIdRateLimiter.Out;

    /* Block Gain2                                                                                                    */
    x2cModel.blocks.sFOCmain.bGain2.In =
        &x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.Valpha;

    /* Block Gain3                                                                                                    */
    x2cModel.blocks.sFOCmain.bGain3.In =
        &x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.Vbeta;

    /* Block ManualSwitch2                                                                                            */
    x2cModel.blocks.sFOCmain.bManualSwitch2.In1 =
        &x2cModel.blocks.sFOCmain.bSin3Gen.u;
    x2cModel.blocks.sFOCmain.bManualSwitch2.In2 =
        &x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.A;

    /* Block ManualSwitch3                                                                                            */
    x2cModel.blocks.sFOCmain.bManualSwitch3.In1 =
        &x2cModel.blocks.sFOCmain.bSin3Gen.v;
    x2cModel.blocks.sFOCmain.bManualSwitch3.In2 =
        &x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.B;

    /* Block ManualSwitch5                                                                                            */
    x2cModel.blocks.sFOCmain.bManualSwitch5.In1 =
        &x2cModel.blocks.sFOCmain.bSin3Gen.w;
    x2cModel.blocks.sFOCmain.bManualSwitch5.In2 =
        &x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.C;

    /* Block Not                                                                                                      */
    x2cModel.blocks.sFOCmain.bNot.In =
        &x2cModel.blocks.sstartup.bTypeConv.Out;

    /* Block PI_flux                                                                                                  */
    x2cModel.blocks.sFOCmain.bPI_flux.In =
        &x2cModel.blocks.sFOCmain.bSub_flux.Out;
    x2cModel.blocks.sFOCmain.bPI_flux.Init =
        &x2cModel.blocks.sstartup.bIdRateLimiter.Out;
    x2cModel.blocks.sFOCmain.bPI_flux.Enable =
        &x2cModel.blocks.sstartup.bTypeConv.Out;

    /* Block PI_torque                                                                                                */
    x2cModel.blocks.sFOCmain.bPI_torque.In =
        &x2cModel.blocks.sFOCmain.bSub_torque.Out;
    x2cModel.blocks.sFOCmain.bPI_torque.Init =
        &x2cModel.blocks.sstartup.bLoopBreaker.Out;
    x2cModel.blocks.sFOCmain.bPI_torque.Enable =
        &x2cModel.blocks.sstartup.bTypeConv.Out;

    /* Block Average                                                                                                  */
    x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage.In =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.bPark_MCHP.q;

    /* Block Average1                                                                                                 */
    x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage1.In =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.bPark_MCHP.d;

    /* Block BEMF_MCHP                                                                                                */
    x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP.Ialpha =
        &x2cModel.blocks.sFOCmain.bClarke_Park_MCHP.alpha;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP.Ibeta =
        &x2cModel.blocks.sFOCmain.bClarke_Park_MCHP.beta;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP.Valpha =
        &x2cModel.blocks.sFOCmain.bGain2.Out;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP.Vbeta =
        &x2cModel.blocks.sFOCmain.bGain3.Out;

    /* Block LoopBreaker                                                                                              */
    x2cModel.blocks.sFOCmain.sPLLEstimator.bLoopBreaker.In =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.buI.Out;

    /* Block Park_MCHP                                                                                                */
    x2cModel.blocks.sFOCmain.sPLLEstimator.bPark_MCHP.alpha =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP.BEMFalpha;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bPark_MCHP.beta =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP.BEMFbeta;
    x2cModel.blocks.sFOCmain.sPLLEstimator.bPark_MCHP.theta =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.bLoopBreaker.Out;

    /* Block Add                                                                                                      */
    x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bAdd.In1 =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage.Out;
    x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bAdd.In2 =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage1.Out;

    /* Block AutoSwitch                                                                                               */
    x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bAutoSwitch.In1 =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bSub.Out;
    x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bAutoSwitch.Switch =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage.Out;
    x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bAutoSwitch.In3 =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bAdd.Out;

    /* Block Gain                                                                                                     */
    x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bGain.In =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bAutoSwitch.Out;

    /* Block Sub                                                                                                      */
    x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bSub.Plus =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage.Out;
    x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bSub.Minus =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage1.Out;

    /* Block uI                                                                                                       */
    x2cModel.blocks.sFOCmain.sPLLEstimator.buI.In =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bGain.Out;
    x2cModel.blocks.sFOCmain.sPLLEstimator.buI.Init =
        &x2cModel.blocks.sstartup.bPosSwitch.Out;
    x2cModel.blocks.sFOCmain.sPLLEstimator.buI.Enable =
        &x2cModel.blocks.sstartup.bTypeConv2.Out;

    /* Block Park_Clarke_inv_SVM_MCHP                                                                                 */
    x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.d =
        &x2cModel.blocks.sFOCmain.bSaturation_Vd.Out;
    x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.q =
        &x2cModel.blocks.sFOCmain.bSaturation_Vq.Out;
    x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.theta =
        &x2cModel.blocks.sstartup.bPosSwitch.Out;
    x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.forcedMode =
        &x2cModel.blocks.sFOCmain.bNot.Out;
    x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP.forcedValue =
        &x2cModel.blocks.sFOCmain.bGain.Out;

    /* Block Saturation_Vd                                                                                            */
    x2cModel.blocks.sFOCmain.bSaturation_Vd.In =
        &x2cModel.blocks.sFOCmain.bVdOverride.Out;

    /* Block Saturation_Vq                                                                                            */
    x2cModel.blocks.sFOCmain.bSaturation_Vq.In =
        &x2cModel.blocks.sFOCmain.bVqOverride.Out;

    /* Block Sin3Gen                                                                                                  */
    x2cModel.blocks.sFOCmain.bSin3Gen.A =
        &x2cModel.blocks.sFOCmain.bConstant.Out;
    x2cModel.blocks.sFOCmain.bSin3Gen.f =
        &x2cModel.blocks.sFOCmain.bConstant1.Out;

    /* Block Sub_flux                                                                                                 */
    x2cModel.blocks.sFOCmain.bSub_flux.Plus =
        &x2cModel.blocks.sstartup.bIdRateLimiter.Out;
    x2cModel.blocks.sFOCmain.bSub_flux.Minus =
        &x2cModel.blocks.sFOCmain.bClarke_Park_MCHP.d;

    /* Block Sub_torque                                                                                               */
    x2cModel.blocks.sFOCmain.bSub_torque.Plus =
        &x2cModel.blocks.sstartup.bLoopBreaker.Out;
    x2cModel.blocks.sFOCmain.bSub_torque.Minus =
        &x2cModel.blocks.sFOCmain.bClarke_Park_MCHP.q;

    /* Block VdOverride                                                                                               */
    x2cModel.blocks.sFOCmain.bVdOverride.In1 =
        &x2cModel.blocks.sFOCmain.bVdOverrideVal.Out;
    x2cModel.blocks.sFOCmain.bVdOverride.In2 =
        &x2cModel.blocks.sFOCmain.bPI_flux.Out;

    /* Block VdOverrideVal                                                                                            */

    /* Block VqOverride                                                                                               */
    x2cModel.blocks.sFOCmain.bVqOverride.In1 =
        &x2cModel.blocks.sFOCmain.bVqOverrideVal.Out;
    x2cModel.blocks.sFOCmain.bVqOverride.In2 =
        &x2cModel.blocks.sFOCmain.bPI_torque.Out;

    /* Block VqOverrideVal                                                                                            */

    /* Block LoopBreaker                                                                                              */
    x2cModel.blocks.bLoopBreaker.In =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bGain.Out;

    /* Block LoopBreaker1                                                                                             */
    x2cModel.blocks.bLoopBreaker1.In =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.buI.Out;

    /* Block Not                                                                                                      */
    x2cModel.blocks.bNot.In =
        &x2cModel.blocks.sstartup.bTypeConv.Out;

    /* Block PosSignalPath                                                                                            */
    x2cModel.blocks.bPosSignalPath.In1 =
        &x2cModel.inports.bQEI_POS;
    x2cModel.blocks.bPosSignalPath.In2 =
        &x2cModel.blocks.bLoopBreaker1.Out;

    /* Block QEI_OFFSET1                                                                                              */

    /* Block Real2Int                                                                                                 */
    x2cModel.blocks.bReal2Int.In =
        &x2cModel.blocks.bQEI_OFFSET1.Out;

    /* Block Add                                                                                                      */
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bAdd.In1 =
        &x2cModel.blocks.sSpeedPI.bManualSwitch.Out;
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bAdd.In2 =
        &x2cModel.blocks.sSpeedPI.sIqPerturpation.bAutoSwitch.Out;

    /* Block AutoSwitch                                                                                               */
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bAutoSwitch.In1 =
        &x2cModel.blocks.sSpeedPI.bTorquePerturbation.Out;
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bAutoSwitch.Switch =
        &x2cModel.blocks.sSpeedPI.sIqPerturpation.bSinGen.u;
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bAutoSwitch.In3 =
        &x2cModel.blocks.sSpeedPI.sIqPerturpation.bGain.Out;

    /* Block Constant                                                                                                 */

    /* Block Constant1                                                                                                */

    /* Block Constant2                                                                                                */

    /* Block Constant3                                                                                                */

    /* Block Gain                                                                                                     */
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bGain.In =
        &x2cModel.blocks.sSpeedPI.bTorquePerturbation.Out;

    /* Block RateLimiter                                                                                              */
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bRateLimiter.In =
        &x2cModel.blocks.sSpeedPI.sIqPerturpation.bAdd.Out;
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bRateLimiter.Init =
        &x2cModel.blocks.sSpeedPI.sIqPerturpation.bConstant3.Out;
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bRateLimiter.Enable =
        &x2cModel.blocks.sSpeedPI.sIqPerturpation.bConstant2.Out;

    /* Block SinGen                                                                                                   */
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bSinGen.A =
        &x2cModel.blocks.sSpeedPI.sIqPerturpation.bConstant.Out;
    x2cModel.blocks.sSpeedPI.sIqPerturpation.bSinGen.f =
        &x2cModel.blocks.sSpeedPI.sIqPerturpation.bConstant1.Out;

    /* Block ManualSwitch                                                                                             */
    x2cModel.blocks.sSpeedPI.bManualSwitch.In1 =
        &x2cModel.blocks.sSpeedPI.bPI_speed.Out;
    x2cModel.blocks.sSpeedPI.bManualSwitch.In2 =
        &x2cModel.blocks.sSpeedPI.btorqueSetpoint.Out;

    /* Block PI_speed                                                                                                 */
    x2cModel.blocks.sSpeedPI.bPI_speed.In =
        &x2cModel.blocks.sSpeedPI.bSpeed_error.Out;
    x2cModel.blocks.sSpeedPI.bPI_speed.Init =
        &x2cModel.blocks.sstartup.bLoopBreaker.Out;
    x2cModel.blocks.sSpeedPI.bPI_speed.Enable =
        &x2cModel.blocks.sstartup.bLoopBreaker1.Out;

    /* Block RateLimiter                                                                                              */
    x2cModel.blocks.sSpeedPI.bRateLimiter.In =
        &x2cModel.blocks.sSpeedPI.svPerturbation.bRateLimiter.Out;
    x2cModel.blocks.sSpeedPI.bRateLimiter.Init =
        &x2cModel.blocks.bVelSignalPatth.Out;
    x2cModel.blocks.sSpeedPI.bRateLimiter.Enable =
        &x2cModel.blocks.sstartup.bLoopBreaker1.Out;

    /* Block Speed_error                                                                                              */
    x2cModel.blocks.sSpeedPI.bSpeed_error.Plus =
        &x2cModel.blocks.sSpeedPI.bRateLimiter.Out;
    x2cModel.blocks.sSpeedPI.bSpeed_error.Minus =
        &x2cModel.blocks.bVelSignalPatth.Out;

    /* Block SpeetPerturbation                                                                                        */

    /* Block TorquePerturbation                                                                                       */

    /* Block torqueSetpoint                                                                                           */

    /* Block Add                                                                                                      */
    x2cModel.blocks.sSpeedPI.svPerturbation.bAdd.In1 =
        &x2cModel.blocks.sSpeedScaling.bAdd.Out;
    x2cModel.blocks.sSpeedPI.svPerturbation.bAdd.In2 =
        &x2cModel.blocks.sSpeedPI.svPerturbation.bAutoSwitch.Out;

    /* Block AutoSwitch                                                                                               */
    x2cModel.blocks.sSpeedPI.svPerturbation.bAutoSwitch.In1 =
        &x2cModel.blocks.sSpeedPI.bSpeetPerturbation.Out;
    x2cModel.blocks.sSpeedPI.svPerturbation.bAutoSwitch.Switch =
        &x2cModel.blocks.sSpeedPI.svPerturbation.bSinGen.u;
    x2cModel.blocks.sSpeedPI.svPerturbation.bAutoSwitch.In3 =
        &x2cModel.blocks.sSpeedPI.svPerturbation.bGain.Out;

    /* Block Constant                                                                                                 */

    /* Block Constant1                                                                                                */

    /* Block Constant2                                                                                                */

    /* Block Constant3                                                                                                */

    /* Block Gain                                                                                                     */
    x2cModel.blocks.sSpeedPI.svPerturbation.bGain.In =
        &x2cModel.blocks.sSpeedPI.bSpeetPerturbation.Out;

    /* Block RateLimiter                                                                                              */
    x2cModel.blocks.sSpeedPI.svPerturbation.bRateLimiter.In =
        &x2cModel.blocks.sSpeedPI.svPerturbation.bAdd.Out;
    x2cModel.blocks.sSpeedPI.svPerturbation.bRateLimiter.Init =
        &x2cModel.blocks.sSpeedPI.svPerturbation.bConstant3.Out;
    x2cModel.blocks.sSpeedPI.svPerturbation.bRateLimiter.Enable =
        &x2cModel.blocks.sSpeedPI.svPerturbation.bConstant2.Out;

    /* Block SinGen                                                                                                   */
    x2cModel.blocks.sSpeedPI.svPerturbation.bSinGen.A =
        &x2cModel.blocks.sSpeedPI.svPerturbation.bConstant.Out;
    x2cModel.blocks.sSpeedPI.svPerturbation.bSinGen.f =
        &x2cModel.blocks.sSpeedPI.svPerturbation.bConstant1.Out;

    /* Block Abs                                                                                                      */
    x2cModel.blocks.sSpeedScaling.bAbs.In =
        &x2cModel.blocks.sSpeedScaling.bAverage.Out;

    /* Block Add                                                                                                      */
    x2cModel.blocks.sSpeedScaling.bAdd.In1 =
        &x2cModel.blocks.sSpeedScaling.bGain.Out;
    x2cModel.blocks.sSpeedScaling.bAdd.In2 =
        &x2cModel.blocks.sSpeedScaling.bConstant.Out;

    /* Block Average                                                                                                  */
    x2cModel.blocks.sSpeedScaling.bAverage.In =
        &x2cModel.inports.bV_POT;

    /* Block Constant                                                                                                 */

    /* Block Gain                                                                                                     */
    x2cModel.blocks.sSpeedScaling.bGain.In =
        &x2cModel.blocks.sSpeedScaling.bAbs.Out;

    /* Block VelSignalPatth                                                                                           */
    x2cModel.blocks.bVelSignalPatth.In1 =
        &x2cModel.inports.bQEI_VEL;
    x2cModel.blocks.bVelSignalPatth.In2 =
        &x2cModel.blocks.bLoopBreaker.Out;

    /* Block Constant                                                                                                 */

    /* Block Constant1                                                                                                */

    /* Block Constant2                                                                                                */

    /* Block Constant3                                                                                                */

    /* Block Constant5                                                                                                */

    /* Block Flux_select                                                                                              */
    x2cModel.blocks.sstartup.bFlux_select.In1 =
        &x2cModel.blocks.sstartup.bRamp_Up_Current.Out;
    x2cModel.blocks.sstartup.bFlux_select.Switch =
        &x2cModel.blocks.sstartup.bSequencer.Out1;
    x2cModel.blocks.sstartup.bFlux_select.In3 =
        &x2cModel.blocks.sstartup.bConstant3.Out;

    /* Block Flux_select1                                                                                             */
    x2cModel.blocks.sstartup.bFlux_select1.In1 =
        &x2cModel.blocks.sstartup.bConstant3.Out;
    x2cModel.blocks.sstartup.bFlux_select1.Switch =
        &x2cModel.blocks.sstartup.bManualSwitch1.Out;
    x2cModel.blocks.sstartup.bFlux_select1.In3 =
        &x2cModel.blocks.sstartup.bFlux_select.Out;

    /* Block IdRateLimiter                                                                                            */
    x2cModel.blocks.sstartup.bIdRateLimiter.In =
        &x2cModel.blocks.sstartup.bFlux_select1.Out;
    x2cModel.blocks.sstartup.bIdRateLimiter.Init =
        &x2cModel.blocks.sstartup.bConstant3.Out;
    x2cModel.blocks.sstartup.bIdRateLimiter.Enable =
        &x2cModel.blocks.sstartup.bConstant5.Out;

    /* Block Iq_select                                                                                                */
    x2cModel.blocks.sstartup.bIq_select.In1 =
        &x2cModel.blocks.sSpeedPI.sIqPerturpation.bRateLimiter.Out;
    x2cModel.blocks.sstartup.bIq_select.Switch =
        &x2cModel.blocks.sstartup.bManualSwitch.Out;
    x2cModel.blocks.sstartup.bIq_select.In3 =
        &x2cModel.blocks.sstartup.bPI.Out;

    /* Block LoopBreaker                                                                                              */
    x2cModel.blocks.sstartup.bLoopBreaker.In =
        &x2cModel.blocks.sstartup.bIq_select.Out;

    /* Block LoopBreaker1                                                                                             */
    x2cModel.blocks.sstartup.bLoopBreaker1.In =
        &x2cModel.blocks.sstartup.bTypeConv1.Out;

    /* Block ManualSwitch                                                                                             */
    x2cModel.blocks.sstartup.bManualSwitch.In1 =
        &x2cModel.blocks.sstartup.bSequencer.Out4;
    x2cModel.blocks.sstartup.bManualSwitch.In2 =
        &x2cModel.blocks.sstartup.bConstant.Out;

    /* Block ManualSwitch1                                                                                            */
    x2cModel.blocks.sstartup.bManualSwitch1.In1 =
        &x2cModel.blocks.sstartup.bSequencer.Out3;
    x2cModel.blocks.sstartup.bManualSwitch1.In2 =
        &x2cModel.blocks.sstartup.bConstant2.Out;

    /* Block PI                                                                                                       */
    x2cModel.blocks.sstartup.bPI.In =
        &x2cModel.blocks.sstartup.bPosError.Out;
    x2cModel.blocks.sstartup.bPI.Init =
        &x2cModel.blocks.sstartup.bConstant1.Out;
    x2cModel.blocks.sstartup.bPI.Enable =
        &x2cModel.blocks.sstartup.bTypeConv2.Out;

    /* Block PosError                                                                                                 */
    x2cModel.blocks.sstartup.bPosError.Plus =
        &x2cModel.blocks.sstartup.sRampGen.bRamp_Up_PositionGenerator.Out;
    x2cModel.blocks.sstartup.bPosError.Minus =
        &x2cModel.blocks.bPosSignalPath.Out;

    /* Block PosSwitch                                                                                                */
    x2cModel.blocks.sstartup.bPosSwitch.In1 =
        &x2cModel.blocks.bPosSignalPath.Out;
    x2cModel.blocks.sstartup.bPosSwitch.Switch =
        &x2cModel.blocks.sstartup.bManualSwitch.Out;
    x2cModel.blocks.sstartup.bPosSwitch.In3 =
        &x2cModel.blocks.sstartup.sRampGen.bRamp_Up_PositionGenerator.Out;

    /* Block Constant4                                                                                                */

    /* Block I                                                                                                        */
    x2cModel.blocks.sstartup.sRampGen.bI.In =
        &x2cModel.blocks.sstartup.sRampGen.bMult.Out;
    x2cModel.blocks.sstartup.sRampGen.bI.I0 =
        &x2cModel.blocks.sstartup.sRampGen.bI_Init_Zero.Out;
    x2cModel.blocks.sstartup.sRampGen.bI.Enable =
        &x2cModel.blocks.sstartup.sRampGen.bTypeConv.Out;

    /* Block I_Init_Zero                                                                                              */

    /* Block I_Init_Zero1                                                                                             */

    /* Block Mult                                                                                                     */
    x2cModel.blocks.sstartup.sRampGen.bMult.In1 =
        &x2cModel.blocks.sstartup.sRampGen.bConstant4.Out;
    x2cModel.blocks.sstartup.sRampGen.bMult.In2 =
        &x2cModel.blocks.sstartup.sRampGen.bSign.Out;

    /* Block Ramp_Up_PositionGenerator                                                                                */
    x2cModel.blocks.sstartup.sRampGen.bRamp_Up_PositionGenerator.In =
        &x2cModel.blocks.sstartup.sRampGen.bSaturation.Out;
    x2cModel.blocks.sstartup.sRampGen.bRamp_Up_PositionGenerator.Init =
        &x2cModel.blocks.sstartup.sRampGen.bI_Init_Zero1.Out;
    x2cModel.blocks.sstartup.sRampGen.bRamp_Up_PositionGenerator.Enable =
        &x2cModel.blocks.sstartup.sRampGen.bTypeConv.Out;

    /* Block Saturation                                                                                               */
    x2cModel.blocks.sstartup.sRampGen.bSaturation.In =
        &x2cModel.blocks.sstartup.sRampGen.bI.Out;

    /* Block Sign                                                                                                     */
    x2cModel.blocks.sstartup.sRampGen.bSign.In =
        &x2cModel.blocks.sSpeedScaling.bAdd.Out;

    /* Block TypeConv                                                                                                 */
    x2cModel.blocks.sstartup.sRampGen.bTypeConv.In =
        &x2cModel.blocks.sstartup.bSequencer.Out2;

    /* Block Ramp_Up_Current                                                                                          */

    /* Block Sequencer                                                                                                */
    x2cModel.blocks.sstartup.bSequencer.Start =
        &x2cModel.inports.bSW2;

    /* Block TypeConv                                                                                                 */
    x2cModel.blocks.sstartup.bTypeConv.In =
        &x2cModel.blocks.sstartup.bSequencer.Out2;

    /* Block TypeConv1                                                                                                */
    x2cModel.blocks.sstartup.bTypeConv1.In =
        &x2cModel.blocks.sstartup.bManualSwitch.Out;

    /* Block TypeConv2                                                                                                */
    x2cModel.blocks.sstartup.bTypeConv2.In =
        &x2cModel.blocks.sstartup.bManualSwitch1.Out;

    /******************************************************************************************************************/
    /**                                                 Link Outports                                                **/
    /******************************************************************************************************************/
    x2cModel.outports.sFOCmain.bEstimated_angle =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.buI.Out;
    x2cModel.outports.sFOCmain.bEstimated_speed =
        &x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bGain.Out;
    x2cModel.outports.bHOME_INIT =
        &x2cModel.blocks.bNot.Out;
    x2cModel.outports.bLED1 =
        &x2cModel.inports.bSW1;
    x2cModel.outports.bLED2 =
        &x2cModel.inports.bSW2;
    x2cModel.outports.bPWM1 =
        &x2cModel.blocks.sFOCmain.bManualSwitch2.Out;
    x2cModel.outports.bPWM2 =
        &x2cModel.blocks.sFOCmain.bManualSwitch3.Out;
    x2cModel.outports.bPWM3 =
        &x2cModel.blocks.sFOCmain.bManualSwitch5.Out;
    x2cModel.outports.bQEI_OFFSET =
        &x2cModel.blocks.bReal2Int.Out;

    /******************************************************************************************************************/
    /**                                           Run Block Init Functions                                           **/
    /******************************************************************************************************************/
    Clarke_Park_MCHP_FiP16_Init(&x2cModel.blocks.sFOCmain.bClarke_Park_MCHP);
    Constant_FiP16_Init(&x2cModel.blocks.sFOCmain.bConstant);
    Constant_FiP16_Init(&x2cModel.blocks.sFOCmain.bConstant1);
    Gain_FiP16_Init(&x2cModel.blocks.sFOCmain.bGain);
    Gain_FiP16_Init(&x2cModel.blocks.sFOCmain.bGain2);
    Gain_FiP16_Init(&x2cModel.blocks.sFOCmain.bGain3);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sFOCmain.bManualSwitch2);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sFOCmain.bManualSwitch3);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sFOCmain.bManualSwitch5);
    Not_Bool_Init(&x2cModel.blocks.sFOCmain.bNot);
    PI_FiP16_Init(&x2cModel.blocks.sFOCmain.bPI_flux);
    PI_FiP16_Init(&x2cModel.blocks.sFOCmain.bPI_torque);
    Average_FiP16_Init(&x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage);
    Average_FiP16_Init(&x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage1);
    BEMF_MCHP_FiP16_Init(&x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP);
    LoopBreaker_FiP16_Init(&x2cModel.blocks.sFOCmain.sPLLEstimator.bLoopBreaker);
    Park_MCHP_FiP16_Init(&x2cModel.blocks.sFOCmain.sPLLEstimator.bPark_MCHP);
    Add_FiP16_Init(&x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bAdd);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bAutoSwitch);
    Gain_FiP16_Init(&x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bGain);
    Sub_FiP16_Init(&x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bSub);
    uI_FiP16_Init(&x2cModel.blocks.sFOCmain.sPLLEstimator.buI);
    Park_Clarke_inv_SVM_MCHP_FiP16_Init(&x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP);
    Saturation_FiP16_Init(&x2cModel.blocks.sFOCmain.bSaturation_Vd);
    Saturation_FiP16_Init(&x2cModel.blocks.sFOCmain.bSaturation_Vq);
    Sin3Gen_FiP16_Init(&x2cModel.blocks.sFOCmain.bSin3Gen);
    Sub_FiP16_Init(&x2cModel.blocks.sFOCmain.bSub_flux);
    Sub_FiP16_Init(&x2cModel.blocks.sFOCmain.bSub_torque);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sFOCmain.bVdOverride);
    Constant_FiP16_Init(&x2cModel.blocks.sFOCmain.bVdOverrideVal);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sFOCmain.bVqOverride);
    Constant_FiP16_Init(&x2cModel.blocks.sFOCmain.bVqOverrideVal);
    LoopBreaker_FiP16_Init(&x2cModel.blocks.bLoopBreaker);
    LoopBreaker_FiP16_Init(&x2cModel.blocks.bLoopBreaker1);
    Not_Bool_Init(&x2cModel.blocks.bNot);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.bPosSignalPath);
    Constant_Float32_Init(&x2cModel.blocks.bQEI_OFFSET1);
    Real2Int_Float32_FiP16_Init(&x2cModel.blocks.bReal2Int);
    Add_FiP16_Init(&x2cModel.blocks.sSpeedPI.sIqPerturpation.bAdd);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.sSpeedPI.sIqPerturpation.bAutoSwitch);
    Constant_FiP16_Init(&x2cModel.blocks.sSpeedPI.sIqPerturpation.bConstant);
    Constant_FiP16_Init(&x2cModel.blocks.sSpeedPI.sIqPerturpation.bConstant1);
    Constant_Bool_Init(&x2cModel.blocks.sSpeedPI.sIqPerturpation.bConstant2);
    Constant_FiP16_Init(&x2cModel.blocks.sSpeedPI.sIqPerturpation.bConstant3);
    Gain_FiP16_Init(&x2cModel.blocks.sSpeedPI.sIqPerturpation.bGain);
    RateLimiter_FiP16_Init(&x2cModel.blocks.sSpeedPI.sIqPerturpation.bRateLimiter);
    SinGen_FiP16_Init(&x2cModel.blocks.sSpeedPI.sIqPerturpation.bSinGen);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sSpeedPI.bManualSwitch);
    PI_FiP16_Init(&x2cModel.blocks.sSpeedPI.bPI_speed);
    RateLimiter_FiP16_Init(&x2cModel.blocks.sSpeedPI.bRateLimiter);
    Sub_FiP16_Init(&x2cModel.blocks.sSpeedPI.bSpeed_error);
    Constant_FiP16_Init(&x2cModel.blocks.sSpeedPI.bSpeetPerturbation);
    Constant_FiP16_Init(&x2cModel.blocks.sSpeedPI.bTorquePerturbation);
    Constant_FiP16_Init(&x2cModel.blocks.sSpeedPI.btorqueSetpoint);
    Add_FiP16_Init(&x2cModel.blocks.sSpeedPI.svPerturbation.bAdd);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.sSpeedPI.svPerturbation.bAutoSwitch);
    Constant_FiP16_Init(&x2cModel.blocks.sSpeedPI.svPerturbation.bConstant);
    Constant_FiP16_Init(&x2cModel.blocks.sSpeedPI.svPerturbation.bConstant1);
    Constant_Bool_Init(&x2cModel.blocks.sSpeedPI.svPerturbation.bConstant2);
    Constant_FiP16_Init(&x2cModel.blocks.sSpeedPI.svPerturbation.bConstant3);
    Gain_FiP16_Init(&x2cModel.blocks.sSpeedPI.svPerturbation.bGain);
    RateLimiter_FiP16_Init(&x2cModel.blocks.sSpeedPI.svPerturbation.bRateLimiter);
    SinGen_FiP16_Init(&x2cModel.blocks.sSpeedPI.svPerturbation.bSinGen);
    Abs_FiP16_Init(&x2cModel.blocks.sSpeedScaling.bAbs);
    Add_FiP16_Init(&x2cModel.blocks.sSpeedScaling.bAdd);
    Average_FiP16_Init(&x2cModel.blocks.sSpeedScaling.bAverage);
    Constant_FiP16_Init(&x2cModel.blocks.sSpeedScaling.bConstant);
    Gain_FiP16_Init(&x2cModel.blocks.sSpeedScaling.bGain);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.bVelSignalPatth);
    Constant_FiP16_Init(&x2cModel.blocks.sstartup.bConstant);
    Constant_FiP16_Init(&x2cModel.blocks.sstartup.bConstant1);
    Constant_FiP16_Init(&x2cModel.blocks.sstartup.bConstant2);
    Constant_FiP16_Init(&x2cModel.blocks.sstartup.bConstant3);
    Constant_Bool_Init(&x2cModel.blocks.sstartup.bConstant5);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.sstartup.bFlux_select);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.sstartup.bFlux_select1);
    RateLimiter_FiP16_Init(&x2cModel.blocks.sstartup.bIdRateLimiter);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.sstartup.bIq_select);
    LoopBreaker_FiP16_Init(&x2cModel.blocks.sstartup.bLoopBreaker);
    LoopBreaker_Bool_Init(&x2cModel.blocks.sstartup.bLoopBreaker1);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sstartup.bManualSwitch);
    ManualSwitch_FiP16_Init(&x2cModel.blocks.sstartup.bManualSwitch1);
    PI_FiP16_Init(&x2cModel.blocks.sstartup.bPI);
    uSub_FiP16_Init(&x2cModel.blocks.sstartup.bPosError);
    AutoSwitch_FiP16_Init(&x2cModel.blocks.sstartup.bPosSwitch);
    Constant_FiP16_Init(&x2cModel.blocks.sstartup.sRampGen.bConstant4);
    I_FiP16_Init(&x2cModel.blocks.sstartup.sRampGen.bI);
    Constant_FiP16_Init(&x2cModel.blocks.sstartup.sRampGen.bI_Init_Zero);
    Constant_FiP16_Init(&x2cModel.blocks.sstartup.sRampGen.bI_Init_Zero1);
    Mult_FiP16_Init(&x2cModel.blocks.sstartup.sRampGen.bMult);
    uI_FiP16_Init(&x2cModel.blocks.sstartup.sRampGen.bRamp_Up_PositionGenerator);
    Saturation_FiP16_Init(&x2cModel.blocks.sstartup.sRampGen.bSaturation);
    Sign_FiP16_Init(&x2cModel.blocks.sstartup.sRampGen.bSign);
    TypeConv_FiP16_Bool_Init(&x2cModel.blocks.sstartup.sRampGen.bTypeConv);
    Constant_FiP16_Init(&x2cModel.blocks.sstartup.bRamp_Up_Current);
    Sequencer_FiP16_Init(&x2cModel.blocks.sstartup.bSequencer);
    TypeConv_FiP16_Bool_Init(&x2cModel.blocks.sstartup.bTypeConv);
    TypeConv_FiP16_Bool_Init(&x2cModel.blocks.sstartup.bTypeConv1);
    TypeConv_FiP16_Bool_Init(&x2cModel.blocks.sstartup.bTypeConv2);
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
static uint16 cnt_4 = X2C_UPDATE_4_DIVIDER - 1u;
static uint16 cnt_10 = X2C_UPDATE_10_DIVIDER - 1u;
void X2C_Update(void)
{
    X2C_Update_1();
    if (cnt_4 == 0u)
    {
        cnt_4 = X2C_UPDATE_4_DIVIDER;
        X2C_Update_4();
    }
    if (cnt_10 == 0u)
    {
        cnt_10 = X2C_UPDATE_10_DIVIDER;
        X2C_Update_10();
    }

    cnt_4--;
    cnt_10--;
}

/* X2C_Update for blocks with 1*Ts                                                                                    */
void X2C_Update_1(void)
{
    LoopBreaker_FiP16_Update(&x2cModel.blocks.sFOCmain.sPLLEstimator.bLoopBreaker);
    LoopBreaker_FiP16_Update(&x2cModel.blocks.bLoopBreaker1);
    LoopBreaker_FiP16_Update(&x2cModel.blocks.sstartup.bLoopBreaker);
    Average_FiP16_Update(&x2cModel.blocks.sSpeedScaling.bAverage);
    Abs_FiP16_Update(&x2cModel.blocks.sSpeedScaling.bAbs);
    Gain_FiP16_Update(&x2cModel.blocks.sSpeedScaling.bGain);
    Add_FiP16_Update(&x2cModel.blocks.sSpeedScaling.bAdd);
    Sign_FiP16_Update(&x2cModel.blocks.sstartup.sRampGen.bSign);
    Mult_FiP16_Update(&x2cModel.blocks.sstartup.sRampGen.bMult);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.bPosSignalPath);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.sstartup.bFlux_select);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sstartup.bManualSwitch);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sstartup.bManualSwitch1);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.sstartup.bFlux_select1);
    I_FiP16_Update(&x2cModel.blocks.sstartup.sRampGen.bI);
    RateLimiter_FiP16_Update(&x2cModel.blocks.sstartup.bIdRateLimiter);
    Saturation_FiP16_Update(&x2cModel.blocks.sstartup.sRampGen.bSaturation);
    Gain_FiP16_Update(&x2cModel.blocks.sFOCmain.bGain);
    uI_FiP16_Update(&x2cModel.blocks.sstartup.sRampGen.bRamp_Up_PositionGenerator);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.sstartup.bPosSwitch);
    Clarke_Park_MCHP_FiP16_Update(&x2cModel.blocks.sFOCmain.bClarke_Park_MCHP);
    Sub_FiP16_Update(&x2cModel.blocks.sFOCmain.bSub_flux);
    Sub_FiP16_Update(&x2cModel.blocks.sFOCmain.bSub_torque);
    PI_FiP16_Update(&x2cModel.blocks.sFOCmain.bPI_flux);
    PI_FiP16_Update(&x2cModel.blocks.sFOCmain.bPI_torque);
    uSub_FiP16_Update(&x2cModel.blocks.sstartup.bPosError);
    Sin3Gen_FiP16_Update(&x2cModel.blocks.sFOCmain.bSin3Gen);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sFOCmain.bVdOverride);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sFOCmain.bVqOverride);
    TypeConv_FiP16_Bool_Update(&x2cModel.blocks.sstartup.bTypeConv2);
    Saturation_FiP16_Update(&x2cModel.blocks.sFOCmain.bSaturation_Vd);
    Saturation_FiP16_Update(&x2cModel.blocks.sFOCmain.bSaturation_Vq);
    Real2Int_Float32_FiP16_Update(&x2cModel.blocks.bReal2Int);
    PI_FiP16_Update(&x2cModel.blocks.sstartup.bPI);
    Park_Clarke_inv_SVM_MCHP_FiP16_Update(&x2cModel.blocks.sFOCmain.bPark_Clarke_inv_SVM_MCHP);
    Gain_FiP16_Update(&x2cModel.blocks.sFOCmain.bGain2);
    Gain_FiP16_Update(&x2cModel.blocks.sFOCmain.bGain3);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sFOCmain.bManualSwitch2);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sFOCmain.bManualSwitch3);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sFOCmain.bManualSwitch5);
    BEMF_MCHP_FiP16_Update(&x2cModel.blocks.sFOCmain.sPLLEstimator.bBEMF_MCHP);
    Park_MCHP_FiP16_Update(&x2cModel.blocks.sFOCmain.sPLLEstimator.bPark_MCHP);
    Average_FiP16_Update(&x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage);
    Average_FiP16_Update(&x2cModel.blocks.sFOCmain.sPLLEstimator.bAverage1);
    Add_FiP16_Update(&x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bAdd);
    Sub_FiP16_Update(&x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bSub);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bAutoSwitch);
    Gain_FiP16_Update(&x2cModel.blocks.sFOCmain.sPLLEstimator.sSuperBlock.bGain);
    uI_FiP16_Update(&x2cModel.blocks.sFOCmain.sPLLEstimator.buI);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.sstartup.bIq_select);
    Scope_Main_Update(&x2cScope);
}

/* X2C_Update for blocks with 4*Ts                                                                                    */
void X2C_Update_4(void)
{
    Sequencer_FiP16_Update(&x2cModel.blocks.sstartup.bSequencer);
    TypeConv_FiP16_Bool_Update(&x2cModel.blocks.sstartup.sRampGen.bTypeConv);
    TypeConv_FiP16_Bool_Update(&x2cModel.blocks.sstartup.bTypeConv);
    Not_Bool_Update(&x2cModel.blocks.sFOCmain.bNot);
    Not_Bool_Update(&x2cModel.blocks.bNot);
}

/* X2C_Update for blocks with 10*Ts                                                                                   */
void X2C_Update_10(void)
{
    LoopBreaker_FiP16_Update(&x2cModel.blocks.bLoopBreaker);
    LoopBreaker_Bool_Update(&x2cModel.blocks.sstartup.bLoopBreaker1);
    SinGen_FiP16_Update(&x2cModel.blocks.sSpeedPI.svPerturbation.bSinGen);
    Gain_FiP16_Update(&x2cModel.blocks.sSpeedPI.svPerturbation.bGain);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.sSpeedPI.svPerturbation.bAutoSwitch);
    Add_FiP16_Update(&x2cModel.blocks.sSpeedPI.svPerturbation.bAdd);
    RateLimiter_FiP16_Update(&x2cModel.blocks.sSpeedPI.svPerturbation.bRateLimiter);
    SinGen_FiP16_Update(&x2cModel.blocks.sSpeedPI.sIqPerturpation.bSinGen);
    Gain_FiP16_Update(&x2cModel.blocks.sSpeedPI.sIqPerturpation.bGain);
    AutoSwitch_FiP16_Update(&x2cModel.blocks.sSpeedPI.sIqPerturpation.bAutoSwitch);
    TypeConv_FiP16_Bool_Update(&x2cModel.blocks.sstartup.bTypeConv1);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.bVelSignalPatth);
    RateLimiter_FiP16_Update(&x2cModel.blocks.sSpeedPI.bRateLimiter);
    Sub_FiP16_Update(&x2cModel.blocks.sSpeedPI.bSpeed_error);
    PI_FiP16_Update(&x2cModel.blocks.sSpeedPI.bPI_speed);
    ManualSwitch_FiP16_Update(&x2cModel.blocks.sSpeedPI.bManualSwitch);
    Add_FiP16_Update(&x2cModel.blocks.sSpeedPI.sIqPerturpation.bAdd);
    RateLimiter_FiP16_Update(&x2cModel.blocks.sSpeedPI.sIqPerturpation.bRateLimiter);
}

