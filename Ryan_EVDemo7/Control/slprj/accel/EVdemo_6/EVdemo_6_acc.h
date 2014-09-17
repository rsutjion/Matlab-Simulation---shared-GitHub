#include "__cf_EVdemo_6.h"
#ifndef RTW_HEADER_EVdemo_6_acc_h_
#define RTW_HEADER_EVdemo_6_acc_h_
#ifndef EVdemo_6_acc_COMMON_INCLUDES_
#define EVdemo_6_acc_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif
#include "EVdemo_6_acc_types.h"
#define EV_Pwr_Manager_MDLREF_HIDE_CHILD_
#include "EV_Pwr_Manager.h"
typedef struct { Cntrl_Status B_4_46_0 ; Motor_Cmds B_4_46_1 ; real_T B_4_9_0
; real_T B_4_10_0 [ 4 ] ; real_T B_4_11_0 ; real_T B_4_12_0 [ 4 ] ; real_T
B_4_13_0 ; real_T B_4_14_0 [ 4 ] ; real_T B_4_15_0 ; real_T B_4_16_0 ; real_T
B_4_17_0 [ 4 ] ; real_T B_4_18_0 ; real_T B_4_19_0 [ 4 ] ; real_T B_4_22_0 ;
real_T B_4_32_0 ; real_T B_4_33_0 [ 4 ] ; real_T B_4_34_0 [ 78 ] ; real_T
B_4_36_0 ; real_T B_4_37_0 [ 4 ] ; real_T B_4_38_0 ; real_T B_4_39_0 [ 4 ] ;
real_T B_4_48_0 ; real_T B_4_49_0 [ 4 ] ; real_T B_4_50_0 [ 92 ] ; real_T
B_4_51_0 [ 13 ] ; real_T B_4_67_0 ; real_T B_4_72_0 ; real_T B_4_75_0 ;
real_T B_4_78_0 ; real_T B_4_83_0 ; real_T B_4_84_0 ; real_T B_4_88_0 ;
real_T B_4_96_0 ; real_T B_4_100_0 ; real_T B_4_106_0 ; real_T B_4_107_0 ;
real_T B_4_108_0 ; real_T B_4_111_0 ; real_T B_4_112_0 ; real_T B_4_113_0 ;
real_T B_4_117_0 ; real_T B_4_118_0 ; real_T B_4_127_0 ; real_T B_4_130_0 ;
real_T B_4_131_0 ; real_T B_4_134_0 ; real_T B_4_136_0 ; real_T B_4_137_0 ;
real_T B_4_141_0 ; real_T B_4_149_0 ; real_T B_4_151_0 ; real_T B_4_155_0 ;
real_T B_4_156_0 [ 4 ] ; real_T B_4_159_0 ; real_T B_4_160_0 [ 4 ] ; real_T
B_4_317_0 ; real_T B_4_354_0 ; real_T B_4_357_0 ; real_T B_4_359_0 ; real_T
B_4_361_0 ; real_T B_4_429_0 ; real_T B_4_521_0 ; real_T B_4_528_0 ; real_T
B_0_0_0 ; real_T B_0_1_0 [ 4 ] ; real_T B_0_2_0 [ 901 ] ; real_T B_0_3_0 [ 7
] ; real_T B_0_4_0 ; real_T B_0_5_0 ; real_T B_4_5_0 ; real_T B_4_25_0 ;
real_T B_4_35_0 [ 4 ] ; real_T B_4_64_0 ; real_T B_4_99_0 [ 2 ] ; real_T
B_4_125_0 [ 13 ] ; real_T B_4_95_0 ; real32_T B_4_3_0 ; real32_T B_4_7_0 ;
real32_T B_4_40_0 ; real32_T B_4_41_0 ; real32_T B_4_42_0 ; real32_T B_4_43_0
; real32_T B_4_44_0 ; real32_T B_4_45_0 ; real32_T B_4_46_2 ; real32_T
B_4_54_0 ; real32_T B_4_57_0 ; real32_T B_4_60_0 ; real32_T B_4_94_0 ;
real32_T B_4_293_0 ; real32_T B_4_314_0 ; real32_T B_4_355_0 ; real32_T
B_4_356_0 ; real32_T B_4_358_0 ; real32_T B_4_360_0 ; real32_T B_4_362_0 ;
real32_T B_4_363_0 ; real32_T B_4_364_0 ; real32_T B_4_365_0 ; real32_T
B_4_366_0 ; real32_T B_4_367_0 ; real32_T B_4_368_0 ; real32_T B_4_368_1 ;
real32_T B_4_368_2 ; real32_T B_4_371_0 ; real32_T B_4_372_0 ; real32_T
B_4_375_0 ; real32_T B_4_376_0 ; real32_T B_4_377_0 ; real32_T B_4_453_0 ;
real32_T B_4_454_0 ; real32_T B_3_31_0 ; real32_T B_3_35_0 ; real32_T
B_2_28_0 ; real32_T B_2_33_0 ; real32_T B_4_26_0 ; real32_T B_4_97_0 [ 2 ] ;
real32_T B_4_165_0 ; real32_T B_4_166_0 ; real32_T B_4_167_0 ; real32_T
B_4_442_0 ; real32_T B_3_1_0 ; real32_T B_3_2_0 ; real32_T B_3_10_0 ;
real32_T B_2_1_0 ; real32_T B_2_2_0 ; real32_T B_2_3_0 ; real32_T B_4_128_0 ;
real32_T B_4_162_0 ; real32_T B_4_142_0 ; uint8_T B_1_0_1 ; boolean_T B_1_0_2
; char pad_B_1_0_2 [ 2 ] ; } B_EVdemo_6_T ; typedef struct { real_T
DiscreteTimeIntegrator_DSTATE ; real_T UnitDelay_DSTATE ; real_T
EXEC_INPUT_1_DiscStates ; real_T UnitDelay_DSTATE_h ; real_T
EXEC_INPUT_1_DiscStates_j ; real_T UnitDelay_DSTATE_o ; real_T
EXEC_INPUT_1_DiscStates_c ; real_T EXEC_INPUT_1_DiscStates_l ; real_T
EXEC_INPUT_1_DiscStates_p ; real_T EXEC_INPUT_1_DiscStates_k ; real_T
EXEC_STATE_1_DiscStates [ 21 ] ; real_T EXEC_INPUT_1_DiscStates_e ; real_T
EXEC_INPUT_1_DiscStates_b ; real_T EXEC_INPUT_1_DiscStates_j1 ; real_T
EXEC_STATE_1_DiscStates_e [ 42 ] ; real_T DiscreteTimeIntegrator_DSTATE_h ;
real_T DiscreteTimeIntegrator2_DSTATE ; real_T
DiscreteTimeIntegrator2_DSTATE_l ; real_T EXEC_INPUT_1_DiscStates_m ; real_T
EXEC_INPUT_1_DiscStates_eh ; real_T EXEC_INPUT_1_DiscStates_bl ; real_T
EXEC_STATE_1_DiscStates_o [ 94 ] ; real_T RateTransition_Buffer0 ; real_T
RateTransition_Buffer0_l ; real_T ErrorSum_DWORK1 ; real_T
MotorOnRateTransition1_Buffer [ 2 ] ; real_T MotorOnRateTransition3_Buffer0 ;
real_T RateTransition2_Buffer0 ; real_T RateTransition7_Buffer0 ; real_T
RateTransition4_Buffer0 ; real_T RateTransition1_Buffer0 ; real_T Sum_DWORK1
; real_T PrevY ; void * FTP75_PWORK [ 3 ] ; void *
HiddenToWks_InsertedFor_BusSelector1_at_outport_0_PWORK ; void *
EXEC_INPUT_1_Simulator ; void * EXEC_INPUT_1_SimData ; void *
EXEC_INPUT_1_DiagMgr ; void * EXEC_INPUT_1_Logger ; void *
EXEC_INPUT_1_SampleTimeIdx ; void * EXEC_INPUT_1_Simulator_i ; void *
EXEC_INPUT_1_SimData_f ; void * EXEC_INPUT_1_DiagMgr_k ; void *
EXEC_INPUT_1_Logger_i ; void * EXEC_INPUT_1_SampleTimeIdx_b ; void *
EXEC_INPUT_1_Simulator_n ; void * EXEC_INPUT_1_SimData_n ; void *
EXEC_INPUT_1_DiagMgr_m ; void * EXEC_INPUT_1_Logger_f ; void *
EXEC_INPUT_1_SampleTimeIdx_i ; void * EXEC_INPUT_1_Simulator_e ; void *
EXEC_INPUT_1_SimData_g ; void * EXEC_INPUT_1_DiagMgr_h ; void *
EXEC_INPUT_1_Logger_d ; void * EXEC_INPUT_1_SampleTimeIdx_o ; void *
EXEC_INPUT_1_Simulator_j ; void * EXEC_INPUT_1_SimData_fh ; void *
EXEC_INPUT_1_DiagMgr_l ; void * EXEC_INPUT_1_Logger_ig ; void *
EXEC_INPUT_1_SampleTimeIdx_f ; void * EXEC_INPUT_1_Simulator_c ; void *
EXEC_INPUT_1_SimData_d ; void * EXEC_INPUT_1_DiagMgr_hr ; void *
EXEC_INPUT_1_Logger_dn ; void * EXEC_INPUT_1_SampleTimeIdx_k ; void *
EXEC_STATE_1_Simulator ; void * EXEC_STATE_1_SimData ; void *
EXEC_STATE_1_DiagMgr ; void * EXEC_STATE_1_Logger ; void *
EXEC_STATE_1_SampleTimeIdx ; void * EXEC_OUTPUT_5_Simulator ; void *
EXEC_OUTPUT_5_SimData ; void * EXEC_OUTPUT_5_DiagMgr ; void *
EXEC_OUTPUT_5_Logger ; void * EXEC_OUTPUT_5_SampleTimeIdx ; void *
EXEC_INPUT_1_Simulator_e5 ; void * EXEC_INPUT_1_SimData_e ; void *
EXEC_INPUT_1_DiagMgr_d ; void * EXEC_INPUT_1_Logger_f4 ; void *
EXEC_INPUT_1_SampleTimeIdx_p ; void * EXEC_INPUT_1_Simulator_l ; void *
EXEC_INPUT_1_SimData_o ; void * EXEC_INPUT_1_DiagMgr_k1 ; void *
EXEC_INPUT_1_Logger_ix ; void * EXEC_INPUT_1_SampleTimeIdx_fx ; void *
EXEC_INPUT_1_Simulator_a ; void * EXEC_INPUT_1_SimData_fu ; void *
EXEC_INPUT_1_DiagMgr_e ; void * EXEC_INPUT_1_Logger_n ; void *
EXEC_INPUT_1_SampleTimeIdx_pq ; void * EXEC_STATE_1_Simulator_m ; void *
EXEC_STATE_1_SimData_d ; void * EXEC_STATE_1_DiagMgr_d ; void *
EXEC_STATE_1_Logger_f ; void * EXEC_STATE_1_SampleTimeIdx_c ; void *
EXEC_OUTPUT_5_Simulator_p ; void * EXEC_OUTPUT_5_SimData_i ; void *
EXEC_OUTPUT_5_DiagMgr_m ; void * EXEC_OUTPUT_5_Logger_f ; void *
EXEC_OUTPUT_5_SampleTimeIdx_a ; void *
HiddenToWks_InsertedFor_BusSelector8_at_outport_0_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector8_at_outport_1_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector8_at_outport_2_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector8_at_outport_3_PWORK ; void *
HiddenToWks_InsertedFor_DataTypeConversion16_at_outport_0_PWORK ; void *
HiddenToWks_InsertedFor_opitscale_at_outport_0_PWORK ; struct { void *
LoggedData ; } VehSpdBrakePwrBrakeTorque_PWORK ; struct { void * LoggedData ;
} VehicleSpeedskph_PWORK ; struct { void * LoggedData ; }
DirectandQuadratureCurrentsA_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector5_at_outport_0_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector7_at_outport_0_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector9_at_outport_0_PWORK ; struct { void *
LoggedData ; } Mech_Power_kW_PWORK ; struct { void * LoggedData ; }
MotorTorqueNmandSpeedRPM_PWORK ; struct { void * LoggedData ; }
PhaseACurrent_PWORK ; struct { void * LoggedData ; } RotorVelocitiesRPM_PWORK
; void * EXEC_OUTPUT_3_Simulator ; void * EXEC_OUTPUT_3_SimData ; void *
EXEC_OUTPUT_3_DiagMgr ; void * EXEC_OUTPUT_3_Logger ; void *
EXEC_OUTPUT_3_SampleTimeIdx ; struct { void * LoggedData ; }
RotorVelocityRPMandPhaseVoltages_PWORK ; void *
HiddenToWks_InsertedFor_rad_per_sec_to_rpm_command_at_outport_0_PWORK ; void
* HiddenToWks_InsertedFor_rad_per_sec_to_rpm_measured_at_outport_0_PWORK ;
struct { void * LoggedData ; } BusCurrentVoltagePower_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector6_at_outport_0_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector6_at_outport_1_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector6_at_outport_2_PWORK ; void *
EXEC_OUTPUT_3_Simulator_n ; void * EXEC_OUTPUT_3_SimData_b ; void *
EXEC_OUTPUT_3_DiagMgr_m ; void * EXEC_OUTPUT_3_Logger_m ; void *
EXEC_OUTPUT_3_SampleTimeIdx_n ; struct { void * LoggedData ; }
BatteryCurrentVoltageandSOC_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector3_at_outport_0_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector3_at_outport_1_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector3_at_outport_2_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector3_at_outport_3_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector3_at_outport_4_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector3_at_outport_5_PWORK ; void *
HiddenToWks_InsertedFor_BusSelector3_at_outport_6_PWORK ; void *
HiddenToWks_InsertedFor_From3_at_outport_0_PWORK ; void *
EXEC_INPUT_1_Simulator_m ; void * EXEC_INPUT_1_SimData_m ; void *
EXEC_INPUT_1_DiagMgr_eg ; void * EXEC_INPUT_1_Logger_l ; void *
EXEC_INPUT_1_SampleTimeIdx_h ; void * EXEC_INPUT_1_Simulator_mb ; void *
EXEC_INPUT_1_SimData_a ; void * EXEC_INPUT_1_DiagMgr_n ; void *
EXEC_INPUT_1_Logger_lm ; void * EXEC_INPUT_1_SampleTimeIdx_kw ; void *
Synthesized_Atomic_Subsystem_For_Alg_Loop_1_AlgLoopData ; struct { void *
LoggedData ; } TempsCooling_PWORK ; void * EXEC_SINK_2_Simulator ; void *
EXEC_SINK_2_SimData ; void * EXEC_SINK_2_DiagMgr ; void * EXEC_SINK_2_Logger
; void * EXEC_SINK_2_SampleTimeIdx ; void *
HiddenToWks_InsertedFor_RateTransition1_at_outport_0_PWORK ; struct { void *
LoggedData ; } Scope1_PWORK ; struct { void * LoggedData ; } Scope1_PWORK_h ;
struct { void * LoggedData ; } Scope2_PWORK ; struct { void * LoggedData ; }
Scope3_PWORK ; void * EXEC_SINK_2_Simulator_b ; void * EXEC_SINK_2_SimData_b
; void * EXEC_SINK_2_DiagMgr_k ; void * EXEC_SINK_2_Logger_j ; void *
EXEC_SINK_2_SampleTimeIdx_f ; void * EXEC_OUTPUT_7_Simulator ; void *
EXEC_OUTPUT_7_SimData ; void * EXEC_OUTPUT_7_DiagMgr ; void *
EXEC_OUTPUT_7_Logger ; void * EXEC_OUTPUT_7_SampleTimeIdx ; void *
EXEC_SINK_2_Simulator_k ; void * EXEC_SINK_2_SimData_k ; void *
EXEC_SINK_2_DiagMgr_kg ; void * EXEC_SINK_2_Logger_o ; void *
EXEC_SINK_2_SampleTimeIdx_k ; struct { void * LoggedData ; } Scope_PWORK ;
struct { void * LoggedData ; } Scope_PWORK_i ; void *
EXEC_INPUT_1_Simulator_k ; void * EXEC_INPUT_1_SimData_k ; void *
EXEC_INPUT_1_DiagMgr_i ; void * EXEC_INPUT_1_Logger_id ; void *
EXEC_INPUT_1_SampleTimeIdx_l ; void * EXEC_STATE_1_Simulator_j ; void *
EXEC_STATE_1_SimData_h ; void * EXEC_STATE_1_DiagMgr_m ; void *
EXEC_STATE_1_Logger_fw ; void * EXEC_STATE_1_SampleTimeIdx_a ; void *
EXEC_OUTPUT_3_Simulator_c ; void * EXEC_OUTPUT_3_SimData_j ; void *
EXEC_OUTPUT_3_DiagMgr_d ; void * EXEC_OUTPUT_3_Logger_d ; void *
EXEC_OUTPUT_3_SampleTimeIdx_a ; real32_T UnitDelay_DSTATE_oh ; real32_T
UnitDelay_DSTATE_n ; real32_T UnitDelay_DSTATE_j ; real32_T UnitDelay1_DSTATE
; real32_T UnitDelay3_DSTATE ; real32_T UnitDelay7_DSTATE ; real32_T
UnitDelay4_DSTATE ; real32_T UnitDelay5_DSTATE ; real32_T UnitDelay_DSTATE_i
; real32_T UnitDelay2_DSTATE ; real32_T UnitDelay6_DSTATE ; real32_T
DiscreteTimeIntegrator2_DSTATE_f ; real32_T DiscreteTimeIntegrator2_DSTATE_l5
; real32_T UnitDelay_DSTATE_n3 ; real32_T UnitDelay_DSTATE_g ; real32_T
MotorOnRateTransition2_Buffer [ 2 ] ; real32_T MotorOnRateTransition3_Buffer
[ 2 ] ; real32_T MotorOnRateTransition4_Buffer [ 2 ] ; real32_T
MotorOnRateTransition1_Buffer_h [ 2 ] ; real32_T RateTransition1_Buffer0_o ;
real32_T RateTransition3_Buffer0 ; real32_T RateTransition8_Buffer0 ; int_T
FTP75_IWORK ; int_T EXEC_STATE_1_Modes [ 57 ] ; int_T EXEC_STATE_1_Modes_p [
50 ] ; int_T EXEC_STATE_1_Modes_m [ 807 ] ; int8_T
MotorOnRateTransition1_ActiveBufIdx ; int8_T
MotorOnRateTransition3_semaphoreTaken ; int8_T
MotorOnRateTransition2_ActiveBufIdx ; int8_T
MotorOnRateTransition3_ActiveBufIdx ; int8_T
MotorOnRateTransition4_ActiveBufIdx ; int8_T
MotorOnRateTransition1_ActiveBufIdx_o ; uint8_T
DiscreteTimeIntegrator2_SYSTEM_ENABLE ; uint8_T
DiscreteTimeIntegrator2_SYSTEM_ENABLE_b ; uint8_T
DiscreteTimeIntegrator2_SYSTEM_ENABLE_n ; uint8_T
DiscreteTimeIntegrator2_SYSTEM_ENABLE_o ; boolean_T Relay_Mode ; char
pad_Relay_Mode ; } DW_EVdemo_6_T ; typedef struct { const real_T B_4_20_0 ;
const real_T B_4_21_0 ; const real_T B_4_29_0 ; const real_T B_4_124_0 ;
const real_T B_4_139_0 ; const real_T B_4_157_0 ; const real_T B_4_158_0 ;
const real_T B_4_424_0 ; const real_T B_4_425_0 ; const real_T B_4_426_0 ;
const real_T B_4_447_0 ; const real_T B_3_3_0 ; const real_T B_3_6_0 ; const
real_T B_3_24_0 ; const real_T B_2_17_0 ; const real_T B_2_20_0 ; const
real_T B_2_22_0 ; const real32_T B_4_296_0 ; const real32_T B_4_301_0 ; const
real32_T B_4_306_0 ; const real32_T B_4_444_0 ; const real32_T B_4_445_0 ;
const real32_T B_3_22_0 ; const real32_T B_2_14_0 ; const uint8_T B_3_12_0 ;
const uint8_T B_2_5_0 ; char pad_B_2_5_0 [ 2 ] ; } ConstB_EVdemo_6_T ;
#define EVdemo_6_rtC(S) ((ConstB_EVdemo_6_T *) _ssGetConstBlockIO(S))
typedef struct { real_T pooled1 ; real_T RateLimiter_FallingLim ; real_T
pooled2 ; real_T Relay_OnVal ; real_T Relay_OffVal ; real_T pooled3 ; real_T
P_Gain_Gain ; real_T Constant1_Value ; real_T PI_Sat_Value ; real_T
PI_Sat_Value_k ; real_T DiscreteTimeIntegrator_gainval ; real_T
UnitDelay_InitialCondition ; real_T Thermal_Divider_Gain ; real_T
PI_Sat_Value_n ; real_T Constant_Value ; real_T P_Gain_Gain_f ; real_T
PI_Sat1_Value ; real_T mstokmh_Gain ; real_T DiscreteTimeIntegrator_gainval_n
; real_T opitscale_Gain ; real_T pooled4 ; real_T
rad_per_sec_to_rpm_measured_Gain ; real_T pooled5 ; real_T pooled6 ; real_T
pooled7 ; real_T Gain_Gain ; real_T h_Fan_On_Value ; real_T h_Fan_Off_Value ;
real_T Gain_Gain_e ; real_T kwAccessoryLoad_Value ; real_T pooled8 ; real32_T
pooled9 ; real32_T pooled10 ; real32_T Saturation_LowerSat ; real32_T
kph2kmps_Gain ; real32_T UnitDelay_InitialCondition_f ; real32_T pooled11 ;
real32_T Constant2_Value ; real32_T pooled12 ; real32_T pooled13 ; real32_T
Constant2_Value_m ; uint8_T Constant_Value_n ; uint8_T Constant_Value_b ;
char pad_Constant_Value_b [ 6 ] ; } ConstP_EVdemo_6_T ; struct P_EVdemo_6_T_
{ real32_T paramVelocityI ; real32_T paramVelocityP ; } ; extern P_EVdemo_6_T
EVdemo_6_DefaultP ; extern const ConstB_EVdemo_6_T EVdemo_6_Invariant ;
extern const ConstP_EVdemo_6_T EVdemo_6_ConstP ;
#endif
