#include "__cf_EVdemo_6.h"
#include <math.h>
#include "EVdemo_6_acc.h"
#include "EVdemo_6_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
static void mdlOutputs ( SimStruct * S , int_T tid ) { real32_T rtb_B_4_59_0
; real32_T rtb_B_4_6_0 ; real32_T rtb_B_4_24_0 ; real_T rtb_B_4_27_0 ;
boolean_T rtb_B_4_28_0 ; boolean_T rtb_B_4_30_0 ; real_T rtb_B_4_438_0 ;
boolean_T rtb_B_4_309_0 ; boolean_T rtb_B_4_310_0 ; real_T rtb_B_2_0_0 ;
boolean_T rtb_B_2_23_0 ; int32_T tmp ; B_EVdemo_6_T * _rtB ; P_EVdemo_6_T *
_rtP ; DW_EVdemo_6_T * _rtDW ; _rtDW = ( ( DW_EVdemo_6_T * ) ssGetRootDWork (
S ) ) ; _rtP = ( ( P_EVdemo_6_T * ) ssGetDefaultParam ( S ) ) ; _rtB = ( (
B_EVdemo_6_T * ) _ssGetBlockIO ( S ) ) ; if ( ssIsSampleHit ( S , 4 , 0 ) ) {
rtb_B_4_59_0 = ( real32_T ) _rtDW -> DiscreteTimeIntegrator_DSTATE ;
rtb_B_4_59_0 *= 0.001F ; if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_3_0
= rtb_B_4_59_0 ; } } if ( ssIsSampleHit ( S , 5 , 0 ) ) { ssCallAccelRunBlock
( S , 4 , 4 , SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 4 , 5 ,
SS_CALL_MDL_OUTPUTS ) ; rtb_B_4_6_0 = ( real32_T ) _rtB -> B_4_5_0 ; if (
ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_7_0 = rtb_B_4_6_0 ;
ssCallAccelRunBlock ( S , 4 , 8 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 4 , 0 ) ) { _rtB -> B_4_9_0 = _rtDW -> UnitDelay_DSTATE ;
ssCallAccelRunBlock ( S , 4 , 10 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_4_11_0 =
_rtDW -> UnitDelay_DSTATE_h ; ssCallAccelRunBlock ( S , 4 , 12 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
B_4_13_0 = _rtDW -> UnitDelay_DSTATE_o ; ssCallAccelRunBlock ( S , 4 , 14 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_15_0
= _rtDW -> RateTransition_Buffer0 ; } _rtB -> B_4_16_0 = 0.005208333333333333
* _rtB -> B_4_15_0 ; ssCallAccelRunBlock ( S , 4 , 17 , SS_CALL_MDL_OUTPUTS )
; if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_18_0 = _rtDW ->
RateTransition_Buffer0_l ; } ssCallAccelRunBlock ( S , 4 , 19 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_4_22_0 = 650.0 ; rtb_B_4_24_0 = ( real32_T
) ( _rtB -> B_4_22_0 - _rtDW -> UnitDelay_DSTATE_oh ) ; _rtB -> B_4_25_0 =
2.0 * rtb_B_4_24_0 ; _rtB -> B_4_26_0 = _rtDW -> UnitDelay_DSTATE_n ;
rtb_B_4_27_0 = _rtB -> B_4_25_0 + _rtB -> B_4_26_0 ; rtb_B_4_28_0 = (
rtb_B_4_27_0 > 800.0 ) ; rtb_B_4_30_0 = ( rtb_B_4_27_0 < 12.0 ) ; if (
rtb_B_4_30_0 ) { rtb_B_4_438_0 = 12.0 ; } else { rtb_B_4_438_0 = rtb_B_4_27_0
; } if ( rtb_B_4_28_0 ) { _rtB -> B_4_32_0 = 800.0 ; } else { _rtB ->
B_4_32_0 = rtb_B_4_438_0 ; } ssCallAccelRunBlock ( S , 4 , 33 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 34 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 35 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 4 , 0 ) ) { _rtB -> B_4_36_0
= _rtB -> B_4_35_0 [ 3 ] ; } } if ( ssIsSampleHit ( S , 4 , 0 ) ) {
ssCallAccelRunBlock ( S , 4 , 37 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_4_38_0 =
_rtDW -> MotorOnRateTransition1_Buffer [ _rtDW ->
MotorOnRateTransition1_ActiveBufIdx ] ; ssCallAccelRunBlock ( S , 4 , 39 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtB ->
B_4_40_0 = _rtDW -> UnitDelay_DSTATE_j ; _rtB -> B_4_41_0 = _rtDW ->
UnitDelay1_DSTATE ; _rtB -> B_4_42_0 = _rtDW -> UnitDelay3_DSTATE ; _rtB ->
B_4_43_0 = _rtDW -> UnitDelay7_DSTATE ; _rtB -> B_4_44_0 = _rtDW ->
UnitDelay4_DSTATE ; _rtB -> B_4_45_0 = _rtDW -> UnitDelay5_DSTATE ;
ssCallAccelRunBlock ( S , 4 , 46 , SS_CALL_MDL_OUTPUTS ) ; rtb_B_4_438_0 =
_rtB -> B_4_46_2 ; if ( ! ( _rtDW -> MotorOnRateTransition3_semaphoreTaken !=
0 ) ) { _rtDW -> MotorOnRateTransition3_Buffer0 = rtb_B_4_438_0 ; } } if (
ssIsSampleHit ( S , 4 , 0 ) ) { _rtDW ->
MotorOnRateTransition3_semaphoreTaken = 1 ; _rtB -> B_4_48_0 = _rtDW ->
MotorOnRateTransition3_Buffer0 ; _rtDW ->
MotorOnRateTransition3_semaphoreTaken = 0 ; ssCallAccelRunBlock ( S , 4 , 49
, SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 50 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 51 ,
SS_CALL_MDL_OUTPUTS ) ; rtb_B_4_59_0 = ( real32_T ) ( 3.6 * _rtB -> B_4_51_0
[ 10 ] ) ; if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_54_0 =
rtb_B_4_59_0 ; } } if ( ssIsSampleHit ( S , 5 , 0 ) ) { ssCallAccelRunBlock (
S , 4 , 55 , SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 4 , 0 ) ) {
rtb_B_4_59_0 = ( real32_T ) _rtB -> B_4_51_0 [ 9 ] ; if ( ssIsSampleHit ( S ,
5 , 0 ) ) { _rtB -> B_4_57_0 = rtb_B_4_59_0 ; } } if ( ssIsSampleHit ( S , 5
, 0 ) ) { ssCallAccelRunBlock ( S , 4 , 58 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 4 , 0 ) ) { rtb_B_4_59_0 = ( real32_T ) _rtB -> B_4_51_0
[ 7 ] ; if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_60_0 = rtb_B_4_59_0
; } } if ( ssIsSampleHit ( S , 5 , 0 ) ) { ssCallAccelRunBlock ( S , 4 , 61 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 62 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_4_64_0 = _rtB -> B_4_7_0 - _rtB -> B_4_54_0
; ssCallAccelRunBlock ( S , 4 , 65 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_4_95_0
= _rtDW -> DiscreteTimeIntegrator_DSTATE_h ; _rtB -> B_4_67_0 = 1.0E-5 * _rtB
-> B_4_95_0 ; ssCallAccelRunBlock ( S , 4 , 68 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 69 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 70 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 71 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_4_72_0 =
_rtB -> B_4_64_0 * _rtB -> B_4_64_0 ; _rtB -> B_4_162_0 = 0.0F ; } if (
ssIsSampleHit ( S , 4 , 0 ) && ssIsSampleHit ( S , 5 , 0 ) ) { _rtB ->
B_4_75_0 = _rtB -> B_4_51_0 [ 0 ] ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) {
_rtB -> B_4_142_0 = ( real32_T ) _rtB -> B_4_75_0 ; ssCallAccelRunBlock ( S ,
4 , 77 , SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 4 , 0 ) &&
ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_78_0 = _rtB -> B_4_51_0 [ 4 ] ; }
if ( ssIsSampleHit ( S , 5 , 0 ) ) { ssCallAccelRunBlock ( S , 4 , 79 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_4_95_0 = 0.0 ; ssCallAccelRunBlock ( S , 4
, 81 , SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 4 , 0 ) ) { _rtB ->
B_4_83_0 = _rtB -> B_4_51_0 [ 4 ] * _rtB -> B_4_51_0 [ 2 ] * 0.001 ; if (
ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_84_0 = _rtB -> B_4_83_0 ; } } if
( ssIsSampleHit ( S , 5 , 0 ) ) { ssCallAccelRunBlock ( S , 4 , 85 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 86 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_4_142_0 = ( real32_T ) _rtB -> B_4_78_0 ; }
if ( ssIsSampleHit ( S , 4 , 0 ) && ssIsSampleHit ( S , 5 , 0 ) ) { _rtB ->
B_4_88_0 = _rtB -> B_4_51_0 [ 2 ] ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) {
_rtB -> B_4_162_0 = 9.54929638F * ( real32_T ) _rtB -> B_4_88_0 ;
ssCallAccelRunBlock ( S , 4 , 91 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 92 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 3 , 0 ) && ssIsSampleHit ( S , 5 , 0 ) ) { _rtB ->
B_4_94_0 = _rtB -> B_4_46_0 . Motor_Cmds . Motor_Spd_Ref_radps ; } if (
ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_95_0 = 9.5492963790893555 * _rtB
-> B_4_94_0 ; _rtB -> B_4_96_0 = 9.5492965855137211 * _rtB -> B_4_88_0 ; _rtB
-> B_4_97_0 [ 0 ] = ( real32_T ) _rtB -> B_4_95_0 ; _rtB -> B_4_97_0 [ 1 ] =
( real32_T ) _rtB -> B_4_96_0 ; ssCallAccelRunBlock ( S , 4 , 98 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 4 , 0 ) ) {
ssCallAccelRunBlock ( S , 4 , 99 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit
( S , 5 , 0 ) ) { _rtB -> B_4_100_0 = _rtB -> B_4_99_0 [ 1 ] ; } } if (
ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_142_0 = ( real32_T ) _rtB ->
B_4_100_0 ; ssCallAccelRunBlock ( S , 4 , 102 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 103 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 104 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> B_4_106_0 = ( _rtB -> B_4_35_0 [ 1 ]
- _rtDW -> DiscreteTimeIntegrator2_DSTATE ) * 1570.7963267948965 ; if ( _rtDW
-> DiscreteTimeIntegrator2_SYSTEM_ENABLE != 0 ) { _rtB -> B_4_107_0 = _rtDW
-> DiscreteTimeIntegrator2_DSTATE ; } else { _rtB -> B_4_107_0 = 0.0001 *
_rtB -> B_4_106_0 + _rtDW -> DiscreteTimeIntegrator2_DSTATE ; } if (
ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_108_0 = _rtB -> B_4_107_0 ; } }
if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_142_0 = ( real32_T ) _rtB ->
B_4_108_0 ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB -> B_4_111_0 = ( _rtB
-> B_4_35_0 [ 0 ] - _rtDW -> DiscreteTimeIntegrator2_DSTATE_l ) *
1570.7963267948965 ; if ( _rtDW -> DiscreteTimeIntegrator2_SYSTEM_ENABLE_b !=
0 ) { _rtB -> B_4_112_0 = _rtDW -> DiscreteTimeIntegrator2_DSTATE_l ; } else
{ _rtB -> B_4_112_0 = 0.0001 * _rtB -> B_4_111_0 + _rtDW ->
DiscreteTimeIntegrator2_DSTATE_l ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) {
_rtB -> B_4_113_0 = _rtB -> B_4_112_0 ; } } if ( ssIsSampleHit ( S , 5 , 0 )
) { _rtB -> B_4_162_0 = ( real32_T ) _rtB -> B_4_113_0 ; } if ( ssIsSampleHit
( S , 2 , 0 ) ) { rtb_B_4_438_0 = _rtB -> B_4_112_0 * _rtB -> B_4_107_0 *
0.001 ; if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtB -> B_4_117_0 =
rtb_B_4_438_0 ; } } if ( ssIsSampleHit ( S , 3 , 0 ) && ssIsSampleHit ( S , 5
, 0 ) ) { _rtB -> B_4_118_0 = _rtB -> B_4_117_0 ; } if ( ssIsSampleHit ( S ,
5 , 0 ) ) { _rtB -> B_4_128_0 = ( real32_T ) _rtB -> B_4_118_0 ;
ssCallAccelRunBlock ( S , 4 , 120 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 121 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 122 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 123 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 4 , 125 ,
SS_CALL_MDL_OUTPUTS ) ; rtb_B_4_438_0 = - 273.15 + _rtB -> B_4_125_0 [ 5 ] ;
if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_127_0 = rtb_B_4_438_0 ; } }
if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_128_0 = ( real32_T ) _rtB ->
B_4_127_0 ; ssCallAccelRunBlock ( S , 4 , 129 , SS_CALL_MDL_OUTPUTS ) ; } if
( ssIsSampleHit ( S , 2 , 0 ) ) { if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtB
-> B_4_130_0 = _rtB -> B_4_125_0 [ 3 ] ; _rtB -> B_4_131_0 = _rtB ->
B_4_125_0 [ 4 ] ; } rtb_B_4_438_0 = _rtB -> B_4_125_0 [ 3 ] * _rtB ->
B_4_125_0 [ 4 ] * 0.001 ; if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtB ->
B_4_134_0 = rtb_B_4_438_0 ; } rtb_B_4_438_0 = 105.48523206751055 * _rtB ->
B_4_125_0 [ 1 ] ; if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtB -> B_4_136_0 =
rtb_B_4_438_0 ; } } if ( ssIsSampleHit ( S , 3 , 0 ) && ssIsSampleHit ( S , 5
, 0 ) ) { _rtB -> B_4_137_0 = _rtB -> B_4_136_0 ; } if ( ssIsSampleHit ( S ,
5 , 0 ) ) { ssCallAccelRunBlock ( S , 4 , 138 , SS_CALL_MDL_OUTPUTS ) ; } if
( ssIsSampleHit ( S , 2 , 0 ) ) { rtb_B_4_438_0 = - 273.15 + _rtB ->
B_4_125_0 [ 11 ] ; if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_141_0 =
rtb_B_4_438_0 ; } } if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_142_0 =
( real32_T ) _rtB -> B_4_141_0 ; ssCallAccelRunBlock ( S , 4 , 143 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 144 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 145 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 146 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 147 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { rtb_B_4_438_0
= 0.001 * _rtB -> B_4_125_0 [ 2 ] ; if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtB
-> B_4_149_0 = rtb_B_4_438_0 ; } } if ( ssIsSampleHit ( S , 5 , 0 ) ) {
ssCallAccelRunBlock ( S , 4 , 150 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 2 , 0 ) && ssIsSampleHit ( S , 5 , 0 ) ) { _rtB ->
B_4_151_0 = _rtB -> B_4_125_0 [ 0 ] ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) {
ssCallAccelRunBlock ( S , 4 , 152 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 153 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 154 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 2 , 0 ) && ssIsSampleHit ( S , 5 , 0 ) ) { _rtB ->
B_4_155_0 = _rtB -> B_4_125_0 [ 7 ] ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) {
ssCallAccelRunBlock ( S , 4 , 156 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 2 , 0 ) && ssIsSampleHit ( S , 5 , 0 ) ) { _rtB ->
B_4_159_0 = _rtB -> B_4_125_0 [ 8 ] ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) {
ssCallAccelRunBlock ( S , 4 , 160 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 161 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_4_162_0
= ( real32_T ) _rtB -> B_0_3_0 [ 1 ] ; ssCallAccelRunBlock ( S , 4 , 163 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 164 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_4_165_0 = ( real32_T ) _rtB -> B_0_3_0 [ 2
] ; _rtB -> B_4_166_0 = ( real32_T ) _rtB -> B_0_3_0 [ 5 ] ; _rtB ->
B_4_167_0 = ( real32_T ) _rtB -> B_0_3_0 [ 4 ] ; ssCallAccelRunBlock ( S , 4
, 168 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 271 ,
SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 4 , 0 ) ) { _rtB ->
B_4_293_0 = ( real32_T ) _rtB -> B_4_51_0 [ 2 ] ; } rtb_B_4_59_0 = _rtDW ->
MotorOnRateTransition3_Buffer [ _rtDW -> MotorOnRateTransition3_ActiveBufIdx
] - _rtDW -> MotorOnRateTransition1_Buffer_h [ _rtDW ->
MotorOnRateTransition1_ActiveBufIdx_o ] ; rtb_B_4_6_0 = _rtP ->
paramVelocityI * 4.0E-5F * rtb_B_4_59_0 ; rtb_B_4_59_0 = _rtP ->
paramVelocityP * rtb_B_4_59_0 + _rtDW -> UnitDelay_DSTATE_i ; rtb_B_4_309_0 =
( rtb_B_4_59_0 > _rtDW -> MotorOnRateTransition2_Buffer [ _rtDW ->
MotorOnRateTransition2_ActiveBufIdx ] ) ; rtb_B_4_310_0 = ( rtb_B_4_59_0 <
_rtDW -> MotorOnRateTransition4_Buffer [ _rtDW ->
MotorOnRateTransition4_ActiveBufIdx ] ) ; if ( ( ! ( boolean_T ) ( (
rtb_B_4_6_0 <= 0.0F ) ^ ( rtb_B_4_59_0 <= 0.0F ) ) ) && ( rtb_B_4_309_0 ||
rtb_B_4_310_0 ) ) { rtb_B_4_6_0 = 0.0F ; } _rtB -> B_4_314_0 = rtb_B_4_6_0 +
_rtDW -> UnitDelay_DSTATE_i ; if ( rtb_B_4_310_0 ) { rtb_B_4_59_0 = _rtDW ->
MotorOnRateTransition4_Buffer [ _rtDW -> MotorOnRateTransition4_ActiveBufIdx
] ; } if ( rtb_B_4_309_0 ) { rtb_B_4_59_0 = _rtDW ->
MotorOnRateTransition2_Buffer [ _rtDW -> MotorOnRateTransition2_ActiveBufIdx
] ; } _rtB -> B_4_317_0 = rtb_B_4_59_0 ; if ( ssIsSampleHit ( S , 5 , 0 ) ) {
_rtB -> B_4_354_0 = 0.0 ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) { if (
ssIsSampleHit ( S , 5 , 0 ) ) { _rtB -> B_4_355_0 = _rtDW ->
RateTransition1_Buffer0_o ; _rtB -> B_4_356_0 = _rtDW ->
RateTransition3_Buffer0 ; } if ( ssIsSampleHit ( S , 4 , 0 ) ) { _rtB ->
B_4_357_0 = _rtDW -> RateTransition2_Buffer0 ; } _rtB -> B_4_358_0 = (
real32_T ) _rtB -> B_4_357_0 ; if ( ssIsSampleHit ( S , 4 , 0 ) ) { _rtB ->
B_4_359_0 = _rtDW -> RateTransition7_Buffer0 ; } _rtB -> B_4_360_0 = (
real32_T ) _rtB -> B_4_359_0 ; if ( ssIsSampleHit ( S , 4 , 0 ) ) { _rtB ->
B_4_361_0 = _rtDW -> RateTransition4_Buffer0 ; } _rtB -> B_4_362_0 = (
real32_T ) _rtB -> B_4_361_0 ; _rtB -> B_4_363_0 = _rtDW -> UnitDelay2_DSTATE
; _rtB -> B_4_364_0 = _rtDW -> UnitDelay6_DSTATE ; if ( ssIsSampleHit ( S , 5
, 0 ) ) { _rtB -> B_4_365_0 = _rtDW -> RateTransition8_Buffer0 ; } _rtB ->
B_4_366_0 = ( real32_T ) _rtB -> B_4_136_0 ; _rtB -> B_4_367_0 = ( real32_T )
_rtB -> B_4_117_0 ; _rtB -> B_4_368_0 = _rtB -> B_4_46_1 .
Motor_Spd_Ref_radps ; _rtB -> B_4_368_1 = _rtB -> B_4_46_1 . Motor_Limits .
Motor_T_Lim ; _rtB -> B_4_368_2 = _rtB -> B_4_46_1 . Motor_Limits .
Regen_T_Lim ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) { ssCallAccelRunBlock ( S
, 4 , 369 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_4_371_0 = ( _rtB -> B_4_7_0 -
_rtDW -> DiscreteTimeIntegrator2_DSTATE_f ) * 188.49556F ; if ( _rtDW ->
DiscreteTimeIntegrator2_SYSTEM_ENABLE_n != 0 ) { _rtB -> B_4_372_0 = _rtDW ->
DiscreteTimeIntegrator2_DSTATE_f ; } else { _rtB -> B_4_372_0 = 0.005F * _rtB
-> B_4_371_0 + _rtDW -> DiscreteTimeIntegrator2_DSTATE_f ; } rtb_B_4_438_0 =
0.02 * _rtB -> B_4_372_0 ; _rtB -> B_4_375_0 = ( _rtB -> B_4_54_0 - _rtDW ->
DiscreteTimeIntegrator2_DSTATE_l5 ) * 188.49556F ; if ( _rtDW ->
DiscreteTimeIntegrator2_SYSTEM_ENABLE_o != 0 ) { _rtB -> B_4_376_0 = _rtDW ->
DiscreteTimeIntegrator2_DSTATE_l5 ; } else { _rtB -> B_4_376_0 = 0.005F *
_rtB -> B_4_375_0 + _rtDW -> DiscreteTimeIntegrator2_DSTATE_l5 ; } _rtB ->
B_4_377_0 = _rtB -> B_4_372_0 - _rtB -> B_4_376_0 ; ssCallAccelRunBlock ( S ,
1 , 0 , SS_CALL_MDL_OUTPUTS ) ; rtb_B_2_0_0 = 0.09 * _rtB -> B_4_377_0 ; _rtB
-> B_2_1_0 = ( real32_T ) rtb_B_2_0_0 ; _rtB -> B_2_2_0 = _rtDW ->
UnitDelay_DSTATE_g ; _rtB -> B_2_3_0 = ( real32_T ) rtb_B_4_438_0 ;
ssCallAccelRunBlock ( S , 2 , 4 , SS_CALL_MDL_OUTPUTS ) ; rtb_B_4_309_0 = (
_rtB -> B_1_0_1 != 1 ) ; rtb_B_4_59_0 = _rtB -> B_4_377_0 * 0.00125F ;
rtb_B_4_438_0 += rtb_B_2_0_0 + _rtB -> B_2_2_0 ; rtb_B_4_310_0 = (
rtb_B_4_438_0 > 4.0 ) ; rtb_B_2_23_0 = ( rtb_B_4_438_0 < 0.0 ) ; if (
rtb_B_4_309_0 || ( ( ! ( boolean_T ) ( ( rtb_B_4_59_0 <= 0.0F ) ^ (
rtb_B_4_438_0 <= 0.0 ) ) ) && ( rtb_B_4_310_0 || rtb_B_2_23_0 ) ) ) {
rtb_B_4_59_0 = 0.0F ; } if ( rtb_B_4_309_0 ) { rtb_B_4_6_0 = _rtB -> B_2_2_0
; } else { rtb_B_4_6_0 = 0.0F ; } _rtB -> B_2_28_0 = ( rtb_B_4_59_0 -
rtb_B_4_6_0 ) + _rtB -> B_2_2_0 ; if ( rtb_B_2_23_0 ) { rtb_B_4_438_0 = 0.0 ;
} if ( rtb_B_4_310_0 ) { rtb_B_4_438_0 = 4.0 ; } if ( rtb_B_4_309_0 ) { _rtB
-> B_2_33_0 = 0.0F ; } else { _rtB -> B_2_33_0 = ( real32_T ) rtb_B_4_438_0 ;
} rtb_B_4_438_0 = 0.5 * _rtB -> B_4_377_0 ; _rtB -> B_3_1_0 = ( real32_T )
rtb_B_4_438_0 ; _rtB -> B_3_2_0 = _rtDW -> UnitDelay_DSTATE_n3 ; rtb_B_2_0_0
= rtb_B_4_438_0 + _rtB -> B_3_2_0 ; rtb_B_4_309_0 = ( rtb_B_2_0_0 > 0.0 ) ;
rtb_B_4_310_0 = ( rtb_B_2_0_0 < - 8.0 ) ; if ( rtb_B_4_309_0 ) {
rtb_B_4_438_0 = 0.0 ; } else if ( rtb_B_4_310_0 ) { rtb_B_4_438_0 = - 8.0 ; }
else { rtb_B_4_438_0 = rtb_B_2_0_0 ; } _rtB -> B_3_10_0 = ( real32_T )
rtb_B_4_438_0 ; ssCallAccelRunBlock ( S , 3 , 11 , SS_CALL_MDL_OUTPUTS ) ;
rtb_B_2_23_0 = ( _rtB -> B_1_0_1 != 2 ) ; rtb_B_4_59_0 = _rtB -> B_4_377_0 *
0.01F ; if ( rtb_B_2_23_0 || ( ( ! ( boolean_T ) ( ( rtb_B_4_59_0 <= 0.0F ) ^
( rtb_B_2_0_0 <= 0.0 ) ) ) && ( rtb_B_4_309_0 || rtb_B_4_310_0 ) ) ) {
rtb_B_4_59_0 = 0.0F ; } if ( rtb_B_2_23_0 ) { rtb_B_4_6_0 = _rtB -> B_3_2_0 ;
} else { rtb_B_4_6_0 = 0.0F ; } _rtB -> B_3_31_0 = ( rtb_B_4_59_0 -
rtb_B_4_6_0 ) + _rtB -> B_3_2_0 ; if ( rtb_B_2_23_0 ) { _rtB -> B_3_35_0 =
0.0F ; } else { _rtB -> B_3_35_0 = ( real32_T ) rtb_B_4_438_0 ; } if ( _rtB
-> B_3_35_0 >= 0.0F ) { _rtB -> B_3_35_0 = 0.0F ; } else { if ( _rtB ->
B_3_35_0 <= - 20.0F ) { _rtB -> B_3_35_0 = - 20.0F ; } } ssCallAccelRunBlock
( S , 4 , 381 , SS_CALL_MDL_OUTPUTS ) ; } if ( ssIsSampleHit ( S , 4 , 0 ) )
{ if ( _rtB -> B_4_99_0 [ 0 ] > 20.0 ) { tmp = 2000 ; } else { tmp = 0 ; }
_rtB -> B_4_429_0 = ( real_T ) tmp / muDoubleScalarMax ( _rtB -> B_4_99_0 [ 0
] , 20.0 ) ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S ,
4 , 436 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 4 , 437 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_4_442_0 = rtb_B_4_24_0 * 0.000999999931F ;
ssCallAccelRunBlock ( S , 4 , 443 , SS_CALL_MDL_OUTPUTS ) ; if ( ( ! (
boolean_T ) ( ( _rtB -> B_4_442_0 <= 0.0F ) ^ ( rtb_B_4_27_0 <= 0.0 ) ) ) &&
( rtb_B_4_28_0 || rtb_B_4_30_0 ) ) { rtb_B_4_59_0 = 0.0F ; } else {
rtb_B_4_59_0 = _rtB -> B_4_442_0 ; } _rtB -> B_4_453_0 = rtb_B_4_59_0 + _rtB
-> B_4_26_0 ; _rtB -> B_4_454_0 = ( real32_T ) _rtB -> B_4_35_0 [ 2 ] ; if (
ssIsSampleHit ( S , 4 , 0 ) ) { _rtB -> B_4_521_0 = _rtDW ->
RateTransition1_Buffer0 ; } } if ( ssIsSampleHit ( S , 4 , 0 ) ) {
ssCallAccelRunBlock ( S , 4 , 527 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 528 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { ssCallAccelRunBlock ( S , 4 , 530 ,
SS_CALL_MDL_OUTPUTS ) ; } UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { B_EVdemo_6_T * _rtB ;
DW_EVdemo_6_T * _rtDW ; _rtDW = ( ( DW_EVdemo_6_T * ) ssGetRootDWork ( S ) )
; _rtB = ( ( B_EVdemo_6_T * ) _ssGetBlockIO ( S ) ) ; if ( ssIsSampleHit ( S
, 4 , 0 ) ) { _rtDW -> DiscreteTimeIntegrator_DSTATE += 0.002 * _rtB ->
B_4_51_0 [ 10 ] ; _rtDW -> UnitDelay_DSTATE = _rtB -> B_4_429_0 ; _rtDW ->
UnitDelay_DSTATE_h = _rtB -> B_4_317_0 ; } if ( ssIsSampleHit ( S , 2 , 0 ) )
{ _rtDW -> UnitDelay_DSTATE_o = _rtB -> B_4_521_0 ; } if ( ssIsSampleHit ( S
, 5 , 0 ) ) { _rtDW -> RateTransition_Buffer0 = _rtB -> B_0_3_0 [ 0 ] ; _rtDW
-> RateTransition_Buffer0_l = _rtB -> B_0_3_0 [ 3 ] ; } if ( ssIsSampleHit (
S , 2 , 0 ) ) { _rtDW -> UnitDelay_DSTATE_oh = _rtB -> B_4_454_0 ; _rtDW ->
UnitDelay_DSTATE_n = _rtB -> B_4_453_0 ; ssCallAccelRunBlock ( S , 4 , 34 ,
SS_CALL_MDL_UPDATE ) ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtDW ->
MotorOnRateTransition1_Buffer [ _rtDW -> MotorOnRateTransition1_ActiveBufIdx
== 0 ] = _rtB -> B_4_354_0 ; _rtDW -> MotorOnRateTransition1_ActiveBufIdx = (
int8_T ) ( _rtDW -> MotorOnRateTransition1_ActiveBufIdx == 0 ) ; } if (
ssIsSampleHit ( S , 3 , 0 ) ) { _rtDW -> UnitDelay_DSTATE_j = _rtB ->
B_4_356_0 ; _rtDW -> UnitDelay1_DSTATE = _rtB -> B_4_355_0 ; _rtDW ->
UnitDelay3_DSTATE = _rtB -> B_4_362_0 ; _rtDW -> UnitDelay7_DSTATE = _rtB ->
B_4_365_0 ; _rtDW -> UnitDelay4_DSTATE = _rtB -> B_4_366_0 ; _rtDW ->
UnitDelay5_DSTATE = _rtB -> B_4_367_0 ; ssCallAccelRunBlock ( S , 4 , 46 ,
SS_CALL_MDL_UPDATE ) ; } if ( ssIsSampleHit ( S , 4 , 0 ) ) {
ssCallAccelRunBlock ( S , 4 , 50 , SS_CALL_MDL_UPDATE ) ; } if (
ssIsSampleHit ( S , 5 , 0 ) ) { _rtDW -> DiscreteTimeIntegrator_DSTATE_h +=
0.01 * _rtB -> B_4_72_0 ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW ->
DiscreteTimeIntegrator2_SYSTEM_ENABLE = 0U ; _rtDW ->
DiscreteTimeIntegrator2_DSTATE = 0.0001 * _rtB -> B_4_106_0 + _rtB ->
B_4_107_0 ; _rtDW -> DiscreteTimeIntegrator2_SYSTEM_ENABLE_b = 0U ; _rtDW ->
DiscreteTimeIntegrator2_DSTATE_l = 0.0001 * _rtB -> B_4_111_0 + _rtB ->
B_4_112_0 ; } if ( ssIsSampleHit ( S , 5 , 0 ) ) { ssCallAccelRunBlock ( S ,
0 , 2 , SS_CALL_MDL_UPDATE ) ; } if ( ssIsSampleHit ( S , 3 , 0 ) ) { _rtDW
-> MotorOnRateTransition2_Buffer [ _rtDW ->
MotorOnRateTransition2_ActiveBufIdx == 0 ] = _rtB -> B_4_368_1 ; _rtDW ->
MotorOnRateTransition2_ActiveBufIdx = ( int8_T ) ( _rtDW ->
MotorOnRateTransition2_ActiveBufIdx == 0 ) ; _rtDW ->
MotorOnRateTransition3_Buffer [ _rtDW -> MotorOnRateTransition3_ActiveBufIdx
== 0 ] = _rtB -> B_4_368_0 ; _rtDW -> MotorOnRateTransition3_ActiveBufIdx = (
int8_T ) ( _rtDW -> MotorOnRateTransition3_ActiveBufIdx == 0 ) ; _rtDW ->
MotorOnRateTransition4_Buffer [ _rtDW -> MotorOnRateTransition4_ActiveBufIdx
== 0 ] = _rtB -> B_4_368_2 ; _rtDW -> MotorOnRateTransition4_ActiveBufIdx = (
int8_T ) ( _rtDW -> MotorOnRateTransition4_ActiveBufIdx == 0 ) ; } if (
ssIsSampleHit ( S , 4 , 0 ) ) { _rtDW -> MotorOnRateTransition1_Buffer_h [
_rtDW -> MotorOnRateTransition1_ActiveBufIdx_o == 0 ] = _rtB -> B_4_293_0 ;
_rtDW -> MotorOnRateTransition1_ActiveBufIdx_o = ( int8_T ) ( _rtDW ->
MotorOnRateTransition1_ActiveBufIdx_o == 0 ) ; } _rtDW -> UnitDelay_DSTATE_i
= _rtB -> B_4_314_0 ; if ( ssIsSampleHit ( S , 5 , 0 ) ) { _rtDW ->
RateTransition1_Buffer0_o = _rtB -> B_2_33_0 ; _rtDW ->
RateTransition3_Buffer0 = _rtB -> B_3_35_0 ; } if ( ssIsSampleHit ( S , 4 , 0
) ) { _rtDW -> RateTransition2_Buffer0 = _rtB -> B_4_83_0 ; _rtDW ->
RateTransition7_Buffer0 = _rtB -> B_4_51_0 [ 4 ] ; _rtDW ->
RateTransition4_Buffer0 = _rtB -> B_4_51_0 [ 2 ] ; } if ( ssIsSampleHit ( S ,
3 , 0 ) ) { _rtDW -> UnitDelay2_DSTATE = _rtB -> B_4_358_0 ; _rtDW ->
UnitDelay6_DSTATE = _rtB -> B_4_360_0 ; } if ( ssIsSampleHit ( S , 5 , 0 ) )
{ _rtDW -> RateTransition8_Buffer0 = _rtB -> B_4_54_0 ; _rtDW ->
DiscreteTimeIntegrator2_SYSTEM_ENABLE_n = 0U ; _rtDW ->
DiscreteTimeIntegrator2_DSTATE_f = 0.005F * _rtB -> B_4_371_0 + _rtB ->
B_4_372_0 ; _rtDW -> DiscreteTimeIntegrator2_SYSTEM_ENABLE_o = 0U ; _rtDW ->
DiscreteTimeIntegrator2_DSTATE_l5 = 0.005F * _rtB -> B_4_375_0 + _rtB ->
B_4_376_0 ; _rtDW -> UnitDelay_DSTATE_g = _rtB -> B_2_28_0 ; _rtDW ->
UnitDelay_DSTATE_n3 = _rtB -> B_3_31_0 ; } if ( ssIsSampleHit ( S , 4 , 0 ) )
{ _rtDW -> RateTransition1_Buffer0 = _rtB -> B_4_528_0 ; } UNUSED_PARAMETER (
tid ) ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal
( S , 0 , 3611371393U ) ; ssSetChecksumVal ( S , 1 , 3908395044U ) ;
ssSetChecksumVal ( S , 2 , 47774981U ) ; ssSetChecksumVal ( S , 3 ,
2933702803U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.2" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
DW_EVdemo_6_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_EVdemo_6_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_EVdemo_6_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & EVdemo_6_DefaultP ) ; _ssSetConstBlockIO ( S , &
EVdemo_6_Invariant ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS ;
SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
