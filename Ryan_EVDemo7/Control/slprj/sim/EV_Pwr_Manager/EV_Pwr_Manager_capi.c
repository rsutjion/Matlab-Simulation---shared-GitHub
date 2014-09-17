#include "__cf_EV_Pwr_Manager.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "EV_Pwr_Manager_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "EV_Pwr_Manager.h"
#include "EV_Pwr_Manager_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static rtwCAPI_States rtBlockStates [ ] = { { 0 , - 1
, TARGET_STRING ( "EV_Pwr_Manager/Power_Control/Unit Delay1" ) ,
TARGET_STRING ( "" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 } , { 1 , - 1 ,
TARGET_STRING ( "EV_Pwr_Manager/Power_Control/Unit Delay2" ) , TARGET_STRING
( "" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 } , { 2 , - 1 , TARGET_STRING (
 "EV_Pwr_Manager/Power_Control/2nd Order \nLP Filter\n (Butterworth)/Discrete-Time\nIntegrator"
) , TARGET_STRING ( "" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 } , { 3 , - 1 ,
TARGET_STRING (
 "EV_Pwr_Manager/Power_Control/2nd Order \nLP Filter\n (Butterworth)/Discrete-Time\nIntegrator1"
) , TARGET_STRING ( "" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 } , { 4 , - 1 ,
TARGET_STRING (
 "EV_Pwr_Manager/Power_Control/2nd Order \nLP Filter\n (Butterworth)1/Discrete-Time\nIntegrator"
) , TARGET_STRING ( "" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 } , { 5 , - 1 ,
TARGET_STRING (
 "EV_Pwr_Manager/Power_Control/2nd Order \nLP Filter\n (Butterworth)1/Discrete-Time\nIntegrator1"
) , TARGET_STRING ( "" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 } , { 6 , - 1 ,
TARGET_STRING (
"EV_Pwr_Manager/Power_Control/Charge Power Limit Control/Unit Delay" ) ,
TARGET_STRING ( "" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 } , { 7 , - 1 ,
TARGET_STRING (
"EV_Pwr_Manager/Power_Control/Discharge Power Limit Control/Unit Delay" ) ,
TARGET_STRING ( "" ) , "" , 0 , 0 , 0 , 0 , 0 , 0 } , { 0 , - 1 , ( NULL ) ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void EV_Pwr_Manager_InitializeDataAddr ( void * dataAddr [ ] ,
dtjshe2cwg * localDW ) { dataAddr [ 0 ] = ( void * ) ( & localDW ->
heu3d34m3z ) ; dataAddr [ 1 ] = ( void * ) ( & localDW -> pbb0ig35w2 ) ;
dataAddr [ 2 ] = ( void * ) ( & localDW -> l31ny3wb0n ) ; dataAddr [ 3 ] = (
void * ) ( & localDW -> j5alip3vtm ) ; dataAddr [ 4 ] = ( void * ) ( &
localDW -> mgnqiepkj2 ) ; dataAddr [ 5 ] = ( void * ) ( & localDW ->
ddrzlksjxq ) ; dataAddr [ 6 ] = ( void * ) ( & localDW -> g1uixdnzvf ) ;
dataAddr [ 7 ] = ( void * ) ( & localDW -> cjuyue4kjn ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void EV_Pwr_Manager_InitializeVarDimsAddr ( int32_T * vardimsAddr [ ]
) { vardimsAddr [ 0 ] = ( NULL ) ; }
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "float" ,
"real32_T" , 0 , 0 , sizeof ( real32_T ) , SS_SINGLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static uint_T rtDimensionArray [ ] = { 1 , 1
} ; static const real_T rtcapiStoredFloats [ ] = { 0.001 , 0.0 } ; static
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 1 ] , 0 , 0 } } ; static int_T
rtContextSystems [ 20 ] ; static rtwCAPI_LoggingMetaInfo loggingMetaInfo [ ]
= { { 0 , 0 , "" , 0 } } ; static rtwCAPI_ModelMapLoggingStaticInfo
mmiStaticInfoLogging = { 20 , rtContextSystems , loggingMetaInfo , 0 , NULL ,
{ 0 , NULL , NULL } , 0 , ( NULL ) } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 0 , ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL
) , 0 , ( NULL ) , 0 } , { rtBlockStates , 8 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , & mmiStaticInfoLogging , 0 , } ; const
rtwCAPI_ModelMappingStaticInfo * EV_Pwr_Manager_GetCAPIStaticMap ( ) { return
& mmiStatic ; } static void EV_Pwr_Manager_InitializeSystemRan ( dk515r3a3r *
const ez1amjfhle , sysRanDType * systemRan [ ] , dtjshe2cwg * localDW , int_T
systemTid [ ] , void * rootSysRanPtr , int rootTid ) { systemRan [ 0 ] = (
sysRanDType * ) rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ; systemRan [ 2 ]
= ( NULL ) ; systemRan [ 3 ] = ( NULL ) ; systemRan [ 4 ] = ( NULL ) ;
systemRan [ 5 ] = ( NULL ) ; systemRan [ 6 ] = ( NULL ) ; systemRan [ 7 ] = (
NULL ) ; systemRan [ 8 ] = ( NULL ) ; systemRan [ 9 ] = ( NULL ) ; systemRan
[ 10 ] = ( NULL ) ; systemRan [ 11 ] = ( NULL ) ; systemRan [ 12 ] = ( NULL )
; systemRan [ 13 ] = ( NULL ) ; systemRan [ 14 ] = ( NULL ) ; systemRan [ 15
] = ( NULL ) ; systemRan [ 16 ] = ( NULL ) ; systemRan [ 17 ] = ( NULL ) ;
systemRan [ 18 ] = ( NULL ) ; systemRan [ 19 ] = ( NULL ) ; systemTid [ 1 ] =
c5bw2jg1mz [ 0 ] ; systemTid [ 2 ] = c5bw2jg1mz [ 0 ] ; systemTid [ 3 ] =
c5bw2jg1mz [ 0 ] ; systemTid [ 4 ] = c5bw2jg1mz [ 0 ] ; systemTid [ 5 ] =
c5bw2jg1mz [ 0 ] ; systemTid [ 6 ] = c5bw2jg1mz [ 0 ] ; systemTid [ 7 ] =
c5bw2jg1mz [ 0 ] ; systemTid [ 8 ] = c5bw2jg1mz [ 0 ] ; systemTid [ 9 ] =
c5bw2jg1mz [ 0 ] ; systemTid [ 10 ] = c5bw2jg1mz [ 0 ] ; systemTid [ 11 ] =
c5bw2jg1mz [ 0 ] ; systemTid [ 12 ] = c5bw2jg1mz [ 0 ] ; systemTid [ 13 ] =
c5bw2jg1mz [ 0 ] ; systemTid [ 14 ] = c5bw2jg1mz [ 0 ] ; systemTid [ 15 ] =
c5bw2jg1mz [ 0 ] ; systemTid [ 16 ] = c5bw2jg1mz [ 0 ] ; systemTid [ 17 ] =
c5bw2jg1mz [ 0 ] ; systemTid [ 18 ] = c5bw2jg1mz [ 0 ] ; systemTid [ 19 ] =
c5bw2jg1mz [ 0 ] ; systemTid [ 0 ] = rootTid ; rtContextSystems [ 0 ] = 0 ;
rtContextSystems [ 1 ] = 0 ; rtContextSystems [ 2 ] = 0 ; rtContextSystems [
3 ] = 0 ; rtContextSystems [ 4 ] = 0 ; rtContextSystems [ 5 ] = 0 ;
rtContextSystems [ 6 ] = 0 ; rtContextSystems [ 7 ] = 0 ; rtContextSystems [
8 ] = 0 ; rtContextSystems [ 9 ] = 0 ; rtContextSystems [ 10 ] = 0 ;
rtContextSystems [ 11 ] = 0 ; rtContextSystems [ 12 ] = 0 ; rtContextSystems
[ 13 ] = 0 ; rtContextSystems [ 14 ] = 0 ; rtContextSystems [ 15 ] = 0 ;
rtContextSystems [ 16 ] = 0 ; rtContextSystems [ 17 ] = 0 ; rtContextSystems
[ 18 ] = 0 ; rtContextSystems [ 19 ] = 0 ; }
#ifndef HOST_CAPI_BUILD
void EV_Pwr_Manager_InitializeDataMapInfo ( dk515r3a3r * const ez1amjfhle ,
dtjshe2cwg * localDW , void * sysRanPtr , int contextTid ) {
rtwCAPI_SetVersion ( ez1amjfhle -> DataMapInfo . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ez1amjfhle -> DataMapInfo . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ez1amjfhle -> DataMapInfo . mmi , &
mmiStaticInfoLogging ) ; EV_Pwr_Manager_InitializeDataAddr ( ez1amjfhle ->
DataMapInfo . dataAddress , localDW ) ; rtwCAPI_SetDataAddressMap (
ez1amjfhle -> DataMapInfo . mmi , ez1amjfhle -> DataMapInfo . dataAddress ) ;
EV_Pwr_Manager_InitializeVarDimsAddr ( ez1amjfhle -> DataMapInfo .
vardimsAddress ) ; rtwCAPI_SetVarDimsAddressMap ( ez1amjfhle -> DataMapInfo .
mmi , ez1amjfhle -> DataMapInfo . vardimsAddress ) ; rtwCAPI_SetPath (
ez1amjfhle -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetFullPath (
ez1amjfhle -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetInstanceLoggingInfo
( ez1amjfhle -> DataMapInfo . mmi , & ez1amjfhle -> DataMapInfo .
mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray ( ez1amjfhle -> DataMapInfo .
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ez1amjfhle -> DataMapInfo .
mmi , 0 ) ; EV_Pwr_Manager_InitializeSystemRan ( ez1amjfhle , ez1amjfhle ->
DataMapInfo . systemRan , localDW , ez1amjfhle -> DataMapInfo . systemTid ,
sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan ( ez1amjfhle -> DataMapInfo .
mmi , ez1amjfhle -> DataMapInfo . systemRan ) ; rtwCAPI_SetSystemTid (
ez1amjfhle -> DataMapInfo . mmi , ez1amjfhle -> DataMapInfo . systemTid ) ;
rtwCAPI_SetGlobalTIDMap ( ez1amjfhle -> DataMapInfo . mmi , & c5bw2jg1mz [ 0
] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void EV_Pwr_Manager_host_InitializeDataMapInfo (
EV_Pwr_Manager_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
