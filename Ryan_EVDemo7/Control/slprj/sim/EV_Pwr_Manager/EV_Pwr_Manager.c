#include "__cf_EV_Pwr_Manager.h"
#include "EV_Pwr_Manager_capi.h"
#include "EV_Pwr_Manager.h"
#include "EV_Pwr_Manager_private.h"
#define fmde5mabq4 ((uint8_T)4U)
#define hnzgpj3qof ((uint8_T)0U)
#define isso4cxiv5 ((uint8_T)1U)
#define m1ma5rlgf4 ((uint8_T)2U)
#define pibm52qpjw ((uint8_T)3U)
int_T c5bw2jg1mz [ 1 ] ; static RegMdlInfo rtMdlInfo_EV_Pwr_Manager [ 34 ] =
{ { "kds0y0wo0qd" , MDL_INFO_NAME_MDLREF_DWORK , 0 , - 1 , ( void * )
"EV_Pwr_Manager" } , { "kds0y0wo0q" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "EV_Pwr_Manager" } , { "kyc5sicvgv" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "EV_Pwr_Manager" } ,
{ "fdxegfixnj" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EV_Pwr_Manager" } , { "lk3e30cmzv" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "EV_Pwr_Manager" } , { "hn2vj14mkh" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "EV_Pwr_Manager" } ,
{ "olqwtn1v10" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EV_Pwr_Manager" } , { "o30vos5vuc" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "EV_Pwr_Manager" } , { "onhrhdicjz" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "EV_Pwr_Manager" } ,
{ "bukih13a2g" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EV_Pwr_Manager" } , { "legzt4ewme" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "EV_Pwr_Manager" } , { "dtjshe2cwg" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "EV_Pwr_Manager" } ,
{ "ok2gmvqo2d" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EV_Pwr_Manager" } , { "gq05ylab45" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "EV_Pwr_Manager" } , { "fyhjfwmrbq" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "EV_Pwr_Manager" } ,
{ "n33z1hjscv" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EV_Pwr_Manager" } , { "dtwwh0tjow" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "EV_Pwr_Manager" } , { "ks1vmf3v3l" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "EV_Pwr_Manager" } ,
{ "m5qxfl4qfp" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EV_Pwr_Manager" } , { "EV_Pwr_Manager" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT ,
0 , 0 , ( NULL ) } , { "mosqho0eozz" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "EV_Pwr_Manager" } , { "fkbdiltexa" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "EV_Pwr_Manager" } ,
{ "dk515r3a3r" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EV_Pwr_Manager" } , { "c5bw2jg1mz" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "EV_Pwr_Manager" } , { "aea35hex45z" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "EV_Pwr_Manager" } ,
{ "h25ojwebdzv" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * )
"EV_Pwr_Manager" } , { "aea35hex45" , MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 ,
- 1 , ( void * ) "EV_Pwr_Manager" } , { "h25ojwebdz" ,
MDL_INFO_ID_GLOBAL_RTW_CONSTRUCT , 0 , - 1 , ( void * ) "EV_Pwr_Manager" } ,
{ "Cntrl_Status" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } , {
"Motor_Cmds" , MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } , { "Power_Lims"
, MDL_INFO_ID_DATA_TYPE , 0 , - 1 , ( NULL ) } , { "power_error" ,
MDL_INFO_ID_SIGNAL , 0 , 0 , ( void * )
"EV_Pwr_Manager/Power_Control/Error Sum" } , { "EV_Pwr_Manager.h" ,
MDL_INFO_MODEL_FILENAME , 0 , 0 , ( NULL ) } , { "EV_Pwr_Manager.c" ,
MDL_INFO_MODEL_FILENAME , 0 , 0 , ( void * ) "EV_Pwr_Manager" } } ;
kds0y0wo0qd kds0y0wo0q ; void dtwwh0tjow ( void ) { ok2gmvqo2d * localB = & (
kds0y0wo0q . rtb ) ; dtjshe2cwg * localDW = & ( kds0y0wo0q . rtdw ) ; localDW
-> ltlvxmlb54 = 0U ; localDW -> cxjr0g5zl4 = hnzgpj3qof ; localB ->
pdfhzzdq1g = 0U ; localB -> j2zquky0di = FALSE ; localDW -> j5alip3vtm = 0.0F
; localDW -> idy33up5mm = 2 ; localDW -> pbb0ig35w2 = 0.0F ; localDW ->
cjuyue4kjn = 0.0F ; localDW -> ddrzlksjxq = 0.0F ; localDW -> mtw0f42tjh = 2
; localDW -> izc4slqght = 0.0F ; localDW -> heu3d34m3z = 0.0F ; localDW ->
g1uixdnzvf = 0.0F ; localDW -> a1mgbam2ki = 0.0F ; localDW -> l31ny3wb0n =
0.0F ; localDW -> f0asy5zk2w = 2 ; localDW -> mgnqiepkj2 = 0.0F ; localDW ->
dj0uicp1t0 = 2 ; } void EV_Pwr_Manager ( const real32_T * djdzpwfkwj , const
real32_T * p1ngcukgzs , const real32_T * dsdwkmzwap , const real32_T *
a5q2wqmsjc , const real32_T * aotouh325l , const real32_T * nybs5xslfp ,
Cntrl_Status * c0wcx25ekz , Motor_Cmds * nlhg44sptq , real32_T * gnnw2ivxem )
{ ok2gmvqo2d * localB = & ( kds0y0wo0q . rtb ) ; dtjshe2cwg * localDW = & (
kds0y0wo0q . rtdw ) ; real_T hcq40kzcxc [ 3 ] ; real32_T gqixga54yv ;
boolean_T gqr1wgtvea ; real32_T f2zjgi1q5x ; real32_T b00d1fd4md ; real32_T
bbd1hzxsqs ; real32_T legm5r5env ; real32_T af2uqcclha ; boolean_T hquglmrgpl
; real32_T gnonc0tkhs ; real32_T dp0f2uwajs ; real32_T emmbx0bbcm ; real32_T
it1kcvniv5 ; boolean_T m5reecxrys ; boolean_T gxq3wjrqeq ; real32_T
niak5hlim5 ; real32_T icbo41v4rs ; real32_T ljirye0lqy ; real32_T d35q1rj4rd
; real32_T ordvou43iu ; real32_T fljabxx3pd ; real32_T ksj3veei0e ; real32_T
bszqyqa33p ; real32_T lvexpo1aor ; real32_T esqdzuhcyp ; real32_T hbrszr45an
; gqixga54yv = muSingleScalarAbs ( * djdzpwfkwj ) ; if ( localDW ->
ltlvxmlb54 == 0U ) { localDW -> ltlvxmlb54 = 1U ; localDW -> cxjr0g5zl4 =
fmde5mabq4 ; } else { switch ( localDW -> cxjr0g5zl4 ) { case isso4cxiv5 : if
( * p1ngcukgzs < 0.5F ) { localDW -> cxjr0g5zl4 = m1ma5rlgf4 ; } else {
localB -> pdfhzzdq1g = 1U ; } break ; case m1ma5rlgf4 : if ( gqixga54yv >
1.0F ) { localDW -> cxjr0g5zl4 = pibm52qpjw ; } else if ( * p1ngcukgzs > 1.0F
) { localDW -> cxjr0g5zl4 = isso4cxiv5 ; } else if ( * dsdwkmzwap < 0.05 ) {
localDW -> cxjr0g5zl4 = fmde5mabq4 ; } else { localB -> pdfhzzdq1g = 2U ; }
break ; case pibm52qpjw : if ( * dsdwkmzwap < 0.05 ) { localDW -> cxjr0g5zl4
= fmde5mabq4 ; } else if ( gqixga54yv < 0.5F ) { localDW -> cxjr0g5zl4 =
m1ma5rlgf4 ; } else { localB -> pdfhzzdq1g = 3U ; } break ; default : if ( *
p1ngcukgzs > 0.0F ) { localB -> j2zquky0di = FALSE ; localDW -> cxjr0g5zl4 =
isso4cxiv5 ; } else { localB -> pdfhzzdq1g = 0U ; localB -> j2zquky0di = TRUE
; } break ; } } switch ( localB -> pdfhzzdq1g ) { case 0 : f2zjgi1q5x = 0.0F
; break ; case 1 : ordvou43iu = look1_iflf_pbinlxpw ( * p1ngcukgzs ,
h25ojwebdzv . fkulgdgcec , h25ojwebdzv . fq13oswec0 , & localDW -> l4zlhx4wa0
, 1U ) ; f2zjgi1q5x = 0.104719758F * ordvou43iu ; break ; case 2 : f2zjgi1q5x
= * a5q2wqmsjc ; break ; default : f2zjgi1q5x = look1_iflf_pbinlxpw (
muSingleScalarAbs ( * djdzpwfkwj ) , h25ojwebdzv . fkulgdgcec , h25ojwebdzv .
fq13oswec0 , & localDW -> pdbcgeaq02 , 1U ) ; break ; } hbrszr45an =
look1_iflf_pbinlxpw ( * aotouh325l , h25ojwebdzv . ocs12k3vvg , h25ojwebdzv .
gvdh5nbhqr , & localDW -> heqy4wnob3 , 9U ) ; if ( ( mosqho0eozz . ju3fvjaoqq
> 0 ) && ( localDW -> idy33up5mm <= 0 ) ) { localDW -> j5alip3vtm = 0.0F ; }
b00d1fd4md = localDW -> j5alip3vtm ; bbd1hzxsqs = 1000.0F * localDW ->
j5alip3vtm ; if ( bbd1hzxsqs >= 100000.0F ) { icbo41v4rs = 100000.0F ; } else
if ( bbd1hzxsqs <= 0.0F ) { icbo41v4rs = 0.0F ; } else { icbo41v4rs =
bbd1hzxsqs ; } legm5r5env = muSingleScalarMax ( hbrszr45an , icbo41v4rs ) ;
d35q1rj4rd = localDW -> pbb0ig35w2 ; if ( localDW -> pbb0ig35w2 > 0.0F ) {
fljabxx3pd = 0.1F * localDW -> pbb0ig35w2 ; } else { fljabxx3pd = 0.02F *
localDW -> pbb0ig35w2 ; } ksj3veei0e = localDW -> cjuyue4kjn ; af2uqcclha =
fljabxx3pd + localDW -> cjuyue4kjn ; gqr1wgtvea = ( af2uqcclha > 120000.0F )
; hquglmrgpl = ( af2uqcclha < mosqho0eozz . iwl1uywwej ) ; if ( gqr1wgtvea )
{ icbo41v4rs = 120000.0F ; } else if ( hquglmrgpl ) { icbo41v4rs =
mosqho0eozz . iwl1uywwej ; } else { icbo41v4rs = af2uqcclha ; } bszqyqa33p =
legm5r5env + icbo41v4rs ; if ( ( mosqho0eozz . pwcnfkuazh > 0 ) && ( localDW
-> mtw0f42tjh <= 0 ) ) { localDW -> ddrzlksjxq = 0.0F ; } gnonc0tkhs =
localDW -> ddrzlksjxq ; dp0f2uwajs = muSingleScalarMax ( localDW ->
ddrzlksjxq , 10.4719753F ) ; switch ( localB -> pdfhzzdq1g ) { case 0 :
emmbx0bbcm = 0.0F ; break ; case 1 : if ( bszqyqa33p > 120000.0F ) {
icbo41v4rs = 120000.0F ; } else if ( bszqyqa33p < hbrszr45an ) { icbo41v4rs =
hbrszr45an ; } else { icbo41v4rs = bszqyqa33p ; } emmbx0bbcm = icbo41v4rs /
dp0f2uwajs + 600.0F ; break ; case 2 : emmbx0bbcm = 15.0F ; break ; default :
emmbx0bbcm = 0.0F ; break ; } ordvou43iu = emmbx0bbcm - localDW -> izc4slqght
; if ( ordvou43iu > 1.05F ) { emmbx0bbcm = localDW -> izc4slqght + 1.05F ; }
else { if ( ordvou43iu < - 1.05F ) { emmbx0bbcm = localDW -> izc4slqght + -
1.05F ; } } localDW -> izc4slqght = emmbx0bbcm ; if ( bbd1hzxsqs >= 0.0F ) {
bbd1hzxsqs = 0.0F ; } else { if ( bbd1hzxsqs <= - 100000.0F ) { bbd1hzxsqs =
- 100000.0F ; } } bbd1hzxsqs = muSingleScalarAbs ( bbd1hzxsqs ) ; esqdzuhcyp
= look1_iflf_pbinlxpw ( * aotouh325l , h25ojwebdzv . ocs12k3vvg , h25ojwebdzv
. iuw5szc5rm , & localDW -> cltogzzvkd , 9U ) ; bbd1hzxsqs =
muSingleScalarMax ( bbd1hzxsqs , esqdzuhcyp ) ; if ( localDW -> heu3d34m3z >
0.0F ) { lvexpo1aor = 0.1F * localDW -> heu3d34m3z ; } else { lvexpo1aor =
0.02F * localDW -> heu3d34m3z ; } it1kcvniv5 = lvexpo1aor + localDW ->
g1uixdnzvf ; m5reecxrys = ( it1kcvniv5 > 60000.0F ) ; gxq3wjrqeq = (
it1kcvniv5 < mosqho0eozz . o5vlpsm2jf ) ; if ( m5reecxrys ) { icbo41v4rs =
60000.0F ; } else if ( gxq3wjrqeq ) { icbo41v4rs = mosqho0eozz . o5vlpsm2jf ;
} else { icbo41v4rs = it1kcvniv5 ; } niak5hlim5 = bbd1hzxsqs + icbo41v4rs ;
if ( niak5hlim5 > 60000.0F ) { ljirye0lqy = 60000.0F ; } else if ( niak5hlim5
< esqdzuhcyp ) { ljirye0lqy = esqdzuhcyp ; } else { ljirye0lqy = niak5hlim5 ;
} switch ( localB -> pdfhzzdq1g ) { case 0 : icbo41v4rs = 0.0F ; break ; case
1 : icbo41v4rs = 0.0F ; break ; case 2 : icbo41v4rs = 15.0F ; break ; default
: icbo41v4rs = - ( ljirye0lqy / dp0f2uwajs ) - 600.0F ; break ; } ordvou43iu
= icbo41v4rs - localDW -> a1mgbam2ki ; if ( ordvou43iu > 1.05F ) { icbo41v4rs
= localDW -> a1mgbam2ki + 1.05F ; } else { if ( ordvou43iu < - 1.05F ) {
icbo41v4rs = localDW -> a1mgbam2ki + - 1.05F ; } } localDW -> a1mgbam2ki =
icbo41v4rs ; ordvou43iu = 0.001F * ljirye0lqy ; c0wcx25ekz -> Motor_Cmds .
Motor_Limits . Motor_T_Lim = emmbx0bbcm ; c0wcx25ekz -> Motor_Cmds .
Motor_Limits . Regen_T_Lim = icbo41v4rs ; c0wcx25ekz -> Motor_Cmds .
Motor_Limits . Regen_P_Lim = - ordvou43iu ; c0wcx25ekz -> Motor_Cmds .
Motor_Spd_Ref_radps = f2zjgi1q5x ; c0wcx25ekz -> Cntrl_Mode = localB ->
pdfhzzdq1g ; nlhg44sptq -> Motor_Limits . Motor_T_Lim = emmbx0bbcm ;
nlhg44sptq -> Motor_Limits . Regen_T_Lim = icbo41v4rs ; nlhg44sptq ->
Motor_Limits . Regen_P_Lim = - ordvou43iu ; nlhg44sptq -> Motor_Spd_Ref_radps
= f2zjgi1q5x ; if ( ( mosqho0eozz . ju3fvjaoqq > 0 ) && ( localDW ->
f0asy5zk2w <= 0 ) ) { localDW -> l31ny3wb0n = 0.0F ; } localB -> g2zd0nqunf =
localDW -> l31ny3wb0n ; localB -> axjvrmmj4t = ( localB -> g2zd0nqunf /
mosqho0eozz . pbwpcarvi2 * - 1.4142F + ( * nybs5xslfp + - b00d1fd4md ) ) *
mosqho0eozz . hbfez2cbe2 ; if ( ( mosqho0eozz . pwcnfkuazh > 0 ) && ( localDW
-> dj0uicp1t0 <= 0 ) ) { localDW -> mgnqiepkj2 = 0.0F ; } localB ->
n0mdxvhsbb = localDW -> mgnqiepkj2 ; localB -> e2dxqfaro1 = ( localB ->
n0mdxvhsbb / mosqho0eozz . irqplmodct * - 1.4142F + ( * a5q2wqmsjc + -
gnonc0tkhs ) ) * mosqho0eozz . ovkyofs1lh ; hcq40kzcxc [ 0 ] = bbd1hzxsqs ;
hcq40kzcxc [ 1 ] = lvexpo1aor ; hcq40kzcxc [ 2 ] = localDW -> g1uixdnzvf ; if
( localDW -> heu3d34m3z > 0.0F ) { icbo41v4rs = 0.001F ; } else { icbo41v4rs
= 0.00025F ; } ordvou43iu = icbo41v4rs * localDW -> heu3d34m3z ; if ( ( ! (
boolean_T ) ( ( ordvou43iu <= 0.0F ) ^ ( it1kcvniv5 <= 0.0F ) ) ) && (
m5reecxrys || gxq3wjrqeq ) ) { ordvou43iu = 0.0F ; } localB -> irjtom5n0l =
ordvou43iu + localDW -> g1uixdnzvf ; hcq40kzcxc [ 0 ] = legm5r5env ;
hcq40kzcxc [ 1 ] = fljabxx3pd ; hcq40kzcxc [ 2 ] = ksj3veei0e ; gqr1wgtvea =
( gqr1wgtvea || hquglmrgpl ) ; if ( d35q1rj4rd > 0.0F ) { icbo41v4rs = 0.001F
; } else { icbo41v4rs = 0.00025F ; } ordvou43iu = icbo41v4rs * d35q1rj4rd ;
if ( ( ! ( boolean_T ) ( ( ordvou43iu <= 0.0F ) ^ ( af2uqcclha <= 0.0F ) ) )
&& gqr1wgtvea ) { ordvou43iu = 0.0F ; } localB -> g2n1w33fwo = ordvou43iu +
ksj3veei0e ; localB -> ogygcnhre1 = esqdzuhcyp - niak5hlim5 ; localB ->
fx1ty2zim0 = hbrszr45an - bszqyqa33p ; if ( localB -> j2zquky0di ) { *
gnnw2ivxem = 500.0F ; } else { ordvou43iu = look2_iflf_binlcapw ( 0.0F ,
muSingleScalarAbs ( * djdzpwfkwj ) , h25ojwebdzv . pdscf4iywo , h25ojwebdzv .
c1wwjmuta5 , h25ojwebdzv . p0dz5mfakm , h25ojwebdzv . ojkcnsn5jw , 11U ) ; *
gnnw2ivxem = 0.0F * ordvou43iu ; } } void n33z1hjscv ( void ) { ok2gmvqo2d *
localB = & ( kds0y0wo0q . rtb ) ; dtjshe2cwg * localDW = & ( kds0y0wo0q .
rtdw ) ; localDW -> j5alip3vtm += 0.001F * localB -> g2zd0nqunf ; if (
mosqho0eozz . ju3fvjaoqq > 0 ) { localDW -> idy33up5mm = 1 ; } else { localDW
-> idy33up5mm = 0 ; } localDW -> pbb0ig35w2 = localB -> fx1ty2zim0 ; localDW
-> cjuyue4kjn = localB -> g2n1w33fwo ; localDW -> ddrzlksjxq += 0.001F *
localB -> n0mdxvhsbb ; if ( mosqho0eozz . pwcnfkuazh > 0 ) { localDW ->
mtw0f42tjh = 1 ; } else { localDW -> mtw0f42tjh = 0 ; } localDW -> heu3d34m3z
= localB -> ogygcnhre1 ; localDW -> g1uixdnzvf = localB -> irjtom5n0l ;
localDW -> l31ny3wb0n += 0.001F * localB -> axjvrmmj4t ; if ( mosqho0eozz .
ju3fvjaoqq > 0 ) { localDW -> f0asy5zk2w = 1 ; } else { localDW -> f0asy5zk2w
= 0 ; } localDW -> mgnqiepkj2 += 0.001F * localB -> e2dxqfaro1 ; if (
mosqho0eozz . pwcnfkuazh > 0 ) { localDW -> dj0uicp1t0 = 1 ; } else { localDW
-> dj0uicp1t0 = 0 ; } } void ks1vmf3v3l ( SimStruct * _mdlRefSfcnS , int_T
mdlref_TID0 , void * sysRanPtr , int contextTid , rtwCAPI_ModelMappingInfo *
rt_ParentMMI , const char_T * rt_ChildPath , int_T rt_ChildMMIIdx , int_T
rt_CSTATEIdx ) { dk515r3a3r * const ez1amjfhle = & ( kds0y0wo0q . rtm ) ;
ok2gmvqo2d * localB = & ( kds0y0wo0q . rtb ) ; dtjshe2cwg * localDW = & (
kds0y0wo0q . rtdw ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( void )
memset ( ( void * ) ez1amjfhle , 0 , sizeof ( dk515r3a3r ) ) ; c5bw2jg1mz [ 0
] = mdlref_TID0 ; ez1amjfhle -> _mdlRefSfcnS = ( _mdlRefSfcnS ) ; ( void )
memset ( ( ( void * ) localB ) , 0 , sizeof ( ok2gmvqo2d ) ) ; { localB ->
g2zd0nqunf = 0.0F ; localB -> axjvrmmj4t = 0.0F ; localB -> n0mdxvhsbb = 0.0F
; localB -> e2dxqfaro1 = 0.0F ; localB -> irjtom5n0l = 0.0F ; localB ->
g2n1w33fwo = 0.0F ; localB -> ogygcnhre1 = 0.0F ; localB -> fx1ty2zim0 = 0.0F
; } ( void ) memset ( ( void * ) localDW , 0 , sizeof ( dtjshe2cwg ) ) ;
localDW -> j5alip3vtm = 0.0F ; localDW -> pbb0ig35w2 = 0.0F ; localDW ->
cjuyue4kjn = 0.0F ; localDW -> ddrzlksjxq = 0.0F ; localDW -> heu3d34m3z =
0.0F ; localDW -> g1uixdnzvf = 0.0F ; localDW -> l31ny3wb0n = 0.0F ; localDW
-> mgnqiepkj2 = 0.0F ; localDW -> izc4slqght = 0.0F ; localDW -> a1mgbam2ki =
0.0F ; EV_Pwr_Manager_InitializeDataMapInfo ( ez1amjfhle , localDW ,
sysRanPtr , contextTid ) ; if ( ( rt_ParentMMI != ( NULL ) ) && (
rt_ChildPath != ( NULL ) ) ) { rtwCAPI_SetChildMMI ( * rt_ParentMMI ,
rt_ChildMMIIdx , & ( ez1amjfhle -> DataMapInfo . mmi ) ) ; rtwCAPI_SetPath (
ez1amjfhle -> DataMapInfo . mmi , rt_ChildPath ) ;
rtwCAPI_MMISetContStateStartIndex ( ez1amjfhle -> DataMapInfo . mmi ,
rt_CSTATEIdx ) ; } } void mr_EV_Pwr_Manager_MdlInfoRegFcn ( SimStruct *
mdlRefSfcnS , char_T * modelName , int_T * retVal ) { * retVal = 0 ; * retVal
= 0 ; ssRegModelRefMdlInfo ( mdlRefSfcnS , modelName ,
rtMdlInfo_EV_Pwr_Manager , 34 ) ; * retVal = 1 ; }
