#include "__cf_EV_Pwr_Manager.h"
#ifndef RTW_HEADER_EV_Pwr_Manager_types_h_
#define RTW_HEADER_EV_Pwr_Manager_types_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef _DEFINED_TYPEDEF_FOR_Power_Lims_
#define _DEFINED_TYPEDEF_FOR_Power_Lims_
typedef struct { real32_T Motor_T_Lim ; real32_T Regen_T_Lim ; real32_T
Regen_P_Lim ; uint8_T sl_padding0 [ 4 ] ; } Power_Lims ;
#endif
#ifndef _DEFINED_TYPEDEF_FOR_Motor_Cmds_
#define _DEFINED_TYPEDEF_FOR_Motor_Cmds_
typedef struct { real32_T Motor_Spd_Ref_radps ; uint8_T sl_padding0 [ 4 ] ;
Power_Lims Motor_Limits ; } Motor_Cmds ;
#endif
#ifndef _DEFINED_TYPEDEF_FOR_Cntrl_Status_
#define _DEFINED_TYPEDEF_FOR_Cntrl_Status_
typedef struct { uint8_T Cntrl_Mode ; uint8_T sl_padding0 [ 7 ] ; Motor_Cmds
Motor_Cmds ; } Cntrl_Status ;
#endif
typedef struct fkbdiltexa dk515r3a3r ;
#endif
