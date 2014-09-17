#include "__cf_EV_Pwr_Manager.h"
#ifndef RTW_HEADER_EV_Pwr_Manager_h_
#define RTW_HEADER_EV_Pwr_Manager_h_
#include "rtw_modelmap.h"
#ifndef EV_Pwr_Manager_COMMON_INCLUDES_
#define EV_Pwr_Manager_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rtw_shared_utils.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#endif
#include "EV_Pwr_Manager_types.h"
#ifndef EV_Pwr_Manager_MDLREF_HIDE_CHILD_
typedef struct { real32_T g2zd0nqunf ; real32_T axjvrmmj4t ; real32_T
n0mdxvhsbb ; real32_T e2dxqfaro1 ; real32_T irjtom5n0l ; real32_T g2n1w33fwo
; real32_T ogygcnhre1 ; real32_T fx1ty2zim0 ; uint8_T pdfhzzdq1g ; boolean_T
j2zquky0di ; } ok2gmvqo2d ;
#endif
#ifndef EV_Pwr_Manager_MDLREF_HIDE_CHILD_
typedef struct { struct { void * LoggedData ; } bz3iykbqqg ; struct { void *
LoggedData ; } fwr5c5di1g ; struct { void * LoggedData ; } eb0qflube5 ;
struct { void * LoggedData ; } kh5jyy3lej ; real32_T j5alip3vtm ; real32_T
pbb0ig35w2 ; real32_T cjuyue4kjn ; real32_T ddrzlksjxq ; real32_T heu3d34m3z
; real32_T g1uixdnzvf ; real32_T l31ny3wb0n ; real32_T mgnqiepkj2 ; real32_T
izc4slqght ; real32_T a1mgbam2ki ; uint32_T heqy4wnob3 ; uint32_T cltogzzvkd
; uint32_T l4zlhx4wa0 ; uint32_T pdbcgeaq02 ; int8_T idy33up5mm ; int8_T
mtw0f42tjh ; int8_T f0asy5zk2w ; int8_T dj0uicp1t0 ; uint8_T ltlvxmlb54 ;
uint8_T cxjr0g5zl4 ; } dtjshe2cwg ;
#endif
#ifndef EV_Pwr_Manager_MDLREF_HIDE_CHILD_
typedef struct { const real32_T pbwpcarvi2 ; const real32_T hbfez2cbe2 ;
const real32_T iwl1uywwej ; const real32_T irqplmodct ; const real32_T
ovkyofs1lh ; const real32_T o5vlpsm2jf ; const uint8_T ju3fvjaoqq ; const
uint8_T pwcnfkuazh ; } bukih13a2g ;
#endif
#ifndef EV_Pwr_Manager_MDLREF_HIDE_CHILD_
struct fkbdiltexa { struct SimStruct_tag * _mdlRefSfcnS ; struct {
rtwCAPI_ModelMappingInfo mmi ; rtwCAPI_ModelMapLoggingInstanceInfo
mmiLogInstanceInfo ; void * dataAddress [ 8 ] ; int32_T * vardimsAddress [ 8
] ; sysRanDType * systemRan [ 20 ] ; int_T systemTid [ 20 ] ; } DataMapInfo ;
} ;
#endif
#ifndef EV_Pwr_Manager_MDLREF_HIDE_CHILD_
typedef struct { ok2gmvqo2d rtb ; dtjshe2cwg rtdw ; dk515r3a3r rtm ; }
kds0y0wo0qd ;
#endif
extern void dtwwh0tjow ( void ) ; extern void n33z1hjscv ( void ) ; extern
void EV_Pwr_Manager ( const real32_T * djdzpwfkwj , const real32_T *
p1ngcukgzs , const real32_T * dsdwkmzwap , const real32_T * a5q2wqmsjc ,
const real32_T * aotouh325l , const real32_T * nybs5xslfp , Cntrl_Status *
c0wcx25ekz , Motor_Cmds * nlhg44sptq , real32_T * gnnw2ivxem ) ; extern void
ks1vmf3v3l ( SimStruct * _mdlRefSfcnS , int_T mdlref_TID0 , void * sysRanPtr
, int contextTid , rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T *
rt_ChildPath , int_T rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_EV_Pwr_Manager_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern const rtwCAPI_ModelMappingStaticInfo *
EV_Pwr_Manager_GetCAPIStaticMap ( void ) ;
#ifndef EV_Pwr_Manager_MDLREF_HIDE_CHILD_
extern kds0y0wo0qd kds0y0wo0q ;
#endif
#endif
