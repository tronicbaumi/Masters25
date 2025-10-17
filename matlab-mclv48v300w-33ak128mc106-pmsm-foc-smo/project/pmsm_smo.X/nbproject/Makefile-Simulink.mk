#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-Simulink.mk)" "nbproject/Makefile-local-Simulink.mk"
include nbproject/Makefile-local-Simulink.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=Simulink
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/pmsm_smo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/pmsm_smo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=MCHP_UART1_Rx_Interrupt.c MCHP_UART1_Tx_Interrupt.c MCHP_UART2_Rx_Interrupt.c MCHP_UART2_Tx_Interrupt.c pmsm_smo.c pmsm_smo_data.c pmsm_smo_main.c rtGetInf.c rtGetNaN.c rt_nonfinite.c rt_r32zcfcn.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/MCHP_UART1_Rx_Interrupt.o ${OBJECTDIR}/MCHP_UART1_Tx_Interrupt.o ${OBJECTDIR}/MCHP_UART2_Rx_Interrupt.o ${OBJECTDIR}/MCHP_UART2_Tx_Interrupt.o ${OBJECTDIR}/pmsm_smo.o ${OBJECTDIR}/pmsm_smo_data.o ${OBJECTDIR}/pmsm_smo_main.o ${OBJECTDIR}/rtGetInf.o ${OBJECTDIR}/rtGetNaN.o ${OBJECTDIR}/rt_nonfinite.o ${OBJECTDIR}/rt_r32zcfcn.o
POSSIBLE_DEPFILES=${OBJECTDIR}/MCHP_UART1_Rx_Interrupt.o.d ${OBJECTDIR}/MCHP_UART1_Tx_Interrupt.o.d ${OBJECTDIR}/MCHP_UART2_Rx_Interrupt.o.d ${OBJECTDIR}/MCHP_UART2_Tx_Interrupt.o.d ${OBJECTDIR}/pmsm_smo.o.d ${OBJECTDIR}/pmsm_smo_data.o.d ${OBJECTDIR}/pmsm_smo_main.o.d ${OBJECTDIR}/rtGetInf.o.d ${OBJECTDIR}/rtGetNaN.o.d ${OBJECTDIR}/rt_nonfinite.o.d ${OBJECTDIR}/rt_r32zcfcn.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/MCHP_UART1_Rx_Interrupt.o ${OBJECTDIR}/MCHP_UART1_Tx_Interrupt.o ${OBJECTDIR}/MCHP_UART2_Rx_Interrupt.o ${OBJECTDIR}/MCHP_UART2_Tx_Interrupt.o ${OBJECTDIR}/pmsm_smo.o ${OBJECTDIR}/pmsm_smo_data.o ${OBJECTDIR}/pmsm_smo_main.o ${OBJECTDIR}/rtGetInf.o ${OBJECTDIR}/rtGetNaN.o ${OBJECTDIR}/rt_nonfinite.o ${OBJECTDIR}/rt_r32zcfcn.o

# Source Files
SOURCEFILES=MCHP_UART1_Rx_Interrupt.c MCHP_UART1_Tx_Interrupt.c MCHP_UART2_Rx_Interrupt.c MCHP_UART2_Tx_Interrupt.c pmsm_smo.c pmsm_smo_data.c pmsm_smo_main.c rtGetInf.c rtGetNaN.c rt_nonfinite.c rt_r32zcfcn.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-Simulink.mk ${DISTDIR}/pmsm_smo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33AK128MC106
MP_LINKER_FILE_OPTION=,--script=p33AK128MC106.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/MCHP_UART1_Rx_Interrupt.o: MCHP_UART1_Rx_Interrupt.c  .generated_files/flags/Simulink/c8b4670c27df4673d85216a58af3418d5e24de3 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MCHP_UART1_Rx_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCHP_UART1_Rx_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MCHP_UART1_Rx_Interrupt.c  -o ${OBJECTDIR}/MCHP_UART1_Rx_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/MCHP_UART1_Rx_Interrupt.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/MCHP_UART1_Tx_Interrupt.o: MCHP_UART1_Tx_Interrupt.c  .generated_files/flags/Simulink/274b3bb9c53c7c775e568e0549d4fb9cb04282d9 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MCHP_UART1_Tx_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCHP_UART1_Tx_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MCHP_UART1_Tx_Interrupt.c  -o ${OBJECTDIR}/MCHP_UART1_Tx_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/MCHP_UART1_Tx_Interrupt.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/MCHP_UART2_Rx_Interrupt.o: MCHP_UART2_Rx_Interrupt.c  .generated_files/flags/Simulink/ecdc22c3b1e54843efcd9fb5b34e26235ad35a27 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MCHP_UART2_Rx_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCHP_UART2_Rx_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MCHP_UART2_Rx_Interrupt.c  -o ${OBJECTDIR}/MCHP_UART2_Rx_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/MCHP_UART2_Rx_Interrupt.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/MCHP_UART2_Tx_Interrupt.o: MCHP_UART2_Tx_Interrupt.c  .generated_files/flags/Simulink/7e9b1e90cacc42b281ffc4a9fd4538c1ce6867ac .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MCHP_UART2_Tx_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCHP_UART2_Tx_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MCHP_UART2_Tx_Interrupt.c  -o ${OBJECTDIR}/MCHP_UART2_Tx_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/MCHP_UART2_Tx_Interrupt.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pmsm_smo.o: pmsm_smo.c  .generated_files/flags/Simulink/78e37db9b1808b6237ef9666ba592cb6d0adab78 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pmsm_smo.o.d 
	@${RM} ${OBJECTDIR}/pmsm_smo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pmsm_smo.c  -o ${OBJECTDIR}/pmsm_smo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pmsm_smo.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pmsm_smo_data.o: pmsm_smo_data.c  .generated_files/flags/Simulink/5932842ccc67482b2e51965183fd46afff249758 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pmsm_smo_data.o.d 
	@${RM} ${OBJECTDIR}/pmsm_smo_data.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pmsm_smo_data.c  -o ${OBJECTDIR}/pmsm_smo_data.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pmsm_smo_data.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pmsm_smo_main.o: pmsm_smo_main.c  .generated_files/flags/Simulink/cf854f481e48983db2ee400d53361c69df13f1d3 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pmsm_smo_main.o.d 
	@${RM} ${OBJECTDIR}/pmsm_smo_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pmsm_smo_main.c  -o ${OBJECTDIR}/pmsm_smo_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pmsm_smo_main.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/rtGetInf.o: rtGetInf.c  .generated_files/flags/Simulink/f0f9cfb2aeffe9e06bddfbcad78d272e4964ee59 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rtGetInf.o.d 
	@${RM} ${OBJECTDIR}/rtGetInf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rtGetInf.c  -o ${OBJECTDIR}/rtGetInf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/rtGetInf.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/rtGetNaN.o: rtGetNaN.c  .generated_files/flags/Simulink/365c57104dd689b2979250f8a5d170795f29d2f0 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rtGetNaN.o.d 
	@${RM} ${OBJECTDIR}/rtGetNaN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rtGetNaN.c  -o ${OBJECTDIR}/rtGetNaN.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/rtGetNaN.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/rt_nonfinite.o: rt_nonfinite.c  .generated_files/flags/Simulink/1e5b7134c28560dfbbac4ae9664108e705dcdec3 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rt_nonfinite.o.d 
	@${RM} ${OBJECTDIR}/rt_nonfinite.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rt_nonfinite.c  -o ${OBJECTDIR}/rt_nonfinite.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/rt_nonfinite.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/rt_r32zcfcn.o: rt_r32zcfcn.c  .generated_files/flags/Simulink/e70a0591da3c7090d6804f54c5b9641e937ed912 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rt_r32zcfcn.o.d 
	@${RM} ${OBJECTDIR}/rt_r32zcfcn.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rt_r32zcfcn.c  -o ${OBJECTDIR}/rt_r32zcfcn.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/rt_r32zcfcn.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/MCHP_UART1_Rx_Interrupt.o: MCHP_UART1_Rx_Interrupt.c  .generated_files/flags/Simulink/2f31cee07cafc3d128220c91f3dd5f8a893527d3 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MCHP_UART1_Rx_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCHP_UART1_Rx_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MCHP_UART1_Rx_Interrupt.c  -o ${OBJECTDIR}/MCHP_UART1_Rx_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/MCHP_UART1_Rx_Interrupt.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/MCHP_UART1_Tx_Interrupt.o: MCHP_UART1_Tx_Interrupt.c  .generated_files/flags/Simulink/76d8d75871cf5830f01d5b1fd3a2b97f0e70113c .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MCHP_UART1_Tx_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCHP_UART1_Tx_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MCHP_UART1_Tx_Interrupt.c  -o ${OBJECTDIR}/MCHP_UART1_Tx_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/MCHP_UART1_Tx_Interrupt.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/MCHP_UART2_Rx_Interrupt.o: MCHP_UART2_Rx_Interrupt.c  .generated_files/flags/Simulink/dbfad281108e686fe0b07fa848f03f3e12dde449 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MCHP_UART2_Rx_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCHP_UART2_Rx_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MCHP_UART2_Rx_Interrupt.c  -o ${OBJECTDIR}/MCHP_UART2_Rx_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/MCHP_UART2_Rx_Interrupt.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/MCHP_UART2_Tx_Interrupt.o: MCHP_UART2_Tx_Interrupt.c  .generated_files/flags/Simulink/f10e50227c33850ad7fa51b6ee15899b99f228c0 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MCHP_UART2_Tx_Interrupt.o.d 
	@${RM} ${OBJECTDIR}/MCHP_UART2_Tx_Interrupt.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MCHP_UART2_Tx_Interrupt.c  -o ${OBJECTDIR}/MCHP_UART2_Tx_Interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/MCHP_UART2_Tx_Interrupt.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pmsm_smo.o: pmsm_smo.c  .generated_files/flags/Simulink/20981e02dd8541d668131b74b92a296f99d36059 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pmsm_smo.o.d 
	@${RM} ${OBJECTDIR}/pmsm_smo.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pmsm_smo.c  -o ${OBJECTDIR}/pmsm_smo.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pmsm_smo.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pmsm_smo_data.o: pmsm_smo_data.c  .generated_files/flags/Simulink/7c03a1338c15987faca59bd632d6e3ae3a734dff .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pmsm_smo_data.o.d 
	@${RM} ${OBJECTDIR}/pmsm_smo_data.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pmsm_smo_data.c  -o ${OBJECTDIR}/pmsm_smo_data.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pmsm_smo_data.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/pmsm_smo_main.o: pmsm_smo_main.c  .generated_files/flags/Simulink/7f0c388202138310b98add92d8356c1a3b0b1a6 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pmsm_smo_main.o.d 
	@${RM} ${OBJECTDIR}/pmsm_smo_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  pmsm_smo_main.c  -o ${OBJECTDIR}/pmsm_smo_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pmsm_smo_main.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/rtGetInf.o: rtGetInf.c  .generated_files/flags/Simulink/d9fe7402e553aecf73def7322f654d9c9fb566e7 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rtGetInf.o.d 
	@${RM} ${OBJECTDIR}/rtGetInf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rtGetInf.c  -o ${OBJECTDIR}/rtGetInf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/rtGetInf.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/rtGetNaN.o: rtGetNaN.c  .generated_files/flags/Simulink/12a61391c2b940d24356d8038633d8e601acee20 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rtGetNaN.o.d 
	@${RM} ${OBJECTDIR}/rtGetNaN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rtGetNaN.c  -o ${OBJECTDIR}/rtGetNaN.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/rtGetNaN.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/rt_nonfinite.o: rt_nonfinite.c  .generated_files/flags/Simulink/e80cf9272329e5204eb5421ab3df7b92b5f94451 .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rt_nonfinite.o.d 
	@${RM} ${OBJECTDIR}/rt_nonfinite.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rt_nonfinite.c  -o ${OBJECTDIR}/rt_nonfinite.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/rt_nonfinite.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/rt_r32zcfcn.o: rt_r32zcfcn.c  .generated_files/flags/Simulink/abf82d4e88b808f29346477b22be59a26abd30da .generated_files/flags/Simulink/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rt_r32zcfcn.o.d 
	@${RM} ${OBJECTDIR}/rt_r32zcfcn.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  rt_r32zcfcn.c  -o ${OBJECTDIR}/rt_r32zcfcn.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/rt_r32zcfcn.o.d"        -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -O2 -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project" -I"C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src" -I"C:/Program Files/MATLAB/R2024b/simulink/src" -I"C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src" -I"C:/Program Files/MATLAB/R2024b/extern/include" -I"C:/Program Files/MATLAB/R2024b/simulink/include" -I"C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/R2024b/rtw/c/ert" -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1 -msmart-io=1 -Wall -msfr-warn=off   -DMODEL=pmsm_smo -DNUMST=6 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1  -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/pmsm_smo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/pmsm_smo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--heap=1024,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--stackguard=16,--library-path="C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project",--library-path="C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X",--library-path="C:/Program Files/MATLAB/R2024b/rtw/c/src",--library-path="C:/Program Files/MATLAB/R2024b/simulink/src",--library-path="C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src",--library-path="C:/Program Files/MATLAB/R2024b/extern/include",--library-path="C:/Program Files/MATLAB/R2024b/simulink/include",--library-path="C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common",--library-path="C:/Program Files/MATLAB/R2024b/rtw/c/ert",--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml,"--report-mem,-Map=pmsm_smo.map,-cref,-lq-dsp,--memorysummary,memoryfile.xml"$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/pmsm_smo.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/pmsm_smo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_Simulink=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--heap=1024,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--stackguard=16,--library-path="C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project",--library-path="C:/_GIT/matlab-mclv48v300w-33ak128mc106-pmsm-foc-smo/project/pmsm_smo.X",--library-path="C:/Program Files/MATLAB/R2024b/rtw/c/src",--library-path="C:/Program Files/MATLAB/R2024b/simulink/src",--library-path="C:/Program Files/MATLAB/R2024b/toolbox/simulink/blocks/src",--library-path="C:/Program Files/MATLAB/R2024b/extern/include",--library-path="C:/Program Files/MATLAB/R2024b/simulink/include",--library-path="C:/Program Files/MATLAB/R2024b/rtw/c/src/ext_mode/common",--library-path="C:/Program Files/MATLAB/R2024b/rtw/c/ert",--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml,"--report-mem,-Map=pmsm_smo.map,-cref,-lq-dsp,--memorysummary,memoryfile.xml"$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc-dsc-bin2hex ${DISTDIR}/pmsm_smo.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
