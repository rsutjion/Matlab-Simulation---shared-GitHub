#include "__cf_EVdemo_6.h"
#ifndef RTW_HEADER_EVdemo_6_acc_types_h_
#define RTW_HEADER_EVdemo_6_acc_types_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef _DEFINED_TYPEDEF_FOR_struct_oNiebMRgDsBfWcA0NQUKWH_
#define _DEFINED_TYPEDEF_FOR_struct_oNiebMRgDsBfWcA0NQUKWH_
typedef struct { real_T SOC_LUT [ 7 ] ; real_T Temperature_LUT [ 3 ] ; real_T
Capacity_LUT [ 3 ] ; real_T Em_LUT [ 21 ] ; real_T R0_LUT [ 21 ] ; real_T
R1_LUT [ 21 ] ; real_T C1_LUT [ 21 ] ; real_T cell_mass ; real_T cell_rho_Cp
; real_T cell_Cp_heat ; real_T T_init ; real_T Qe_init ; }
struct_oNiebMRgDsBfWcA0NQUKWH ;
#endif
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
#ifndef _DEFINED_TYPEDEF_FOR_Veh_Cmds_
#define _DEFINED_TYPEDEF_FOR_Veh_Cmds_
typedef struct { real32_T Brake_Force_N ; uint8_T sl_padding0 [ 4 ] ; }
Veh_Cmds ;
#endif
typedef struct P_EVdemo_6_T_ P_EVdemo_6_T ;
#endif
