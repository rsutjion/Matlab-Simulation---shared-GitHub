/* Include files */

#include <stddef.h>
#include "blas.h"
#include "EV_Pwr_Manager_sfun.h"
#include "c2_EV_Pwr_Manager.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EV_Pwr_Manager_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c2_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c2_IN_Accel                    ((uint8_T)1U)
#define c2_IN_Coast                    ((uint8_T)2U)
#define c2_IN_Decel                    ((uint8_T)3U)
#define c2_IN_Stop                     ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c2_EV_Pwr_Manager(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance);
static void initialize_params_c2_EV_Pwr_Manager
  (SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance);
static void enable_c2_EV_Pwr_Manager(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance);
static void disable_c2_EV_Pwr_Manager(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_EV_Pwr_Manager
  (SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_EV_Pwr_Manager
  (SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance);
static void set_sim_state_c2_EV_Pwr_Manager(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void c2_set_sim_state_side_effects_c2_EV_Pwr_Manager
  (SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance);
static void finalize_c2_EV_Pwr_Manager(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance);
static void sf_c2_EV_Pwr_Manager(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance);
static void c2_chartstep_c2_EV_Pwr_Manager(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance);
static void initSimStructsc2_EV_Pwr_Manager(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance);
static void c2_Accel(SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static int32_T c2_emlrt_marshallIn(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static uint8_T c2_b_emlrt_marshallIn(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance, const mxArray *c2_b_tp_Stop, const char_T *c2_identifier);
static uint8_T c2_c_emlrt_marshallIn(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static boolean_T c2_d_emlrt_marshallIn(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance, const mxArray *c2_BrakeSet, const char_T *c2_identifier);
static boolean_T c2_e_emlrt_marshallIn(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_emlrt_marshallIn(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier);
static const mxArray *c2_g_emlrt_marshallIn(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_EV_Pwr_Manager(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance)
{
  uint8_T *c2_Mode;
  boolean_T *c2_BrakeSet;
  c2_BrakeSet = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Mode = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_doSetSimStateSideEffects = 0U;
  chartInstance->c2_setSimStateSideEffectsInfo = NULL;
  chartInstance->c2_tp_Accel = 0U;
  chartInstance->c2_tp_Coast = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_Decel = 0U;
  chartInstance->c2_temporalCounter_i1 = 0U;
  chartInstance->c2_tp_Stop = 0U;
  chartInstance->c2_is_active_c2_EV_Pwr_Manager = 0U;
  chartInstance->c2_is_c2_EV_Pwr_Manager = c2_IN_NO_ACTIVE_CHILD;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c2_Mode = 0U;
  }

  if (!(cdrGetOutputPortReusable(chartInstance->S, 2) != 0)) {
    *c2_BrakeSet = FALSE;
  }
}

static void initialize_params_c2_EV_Pwr_Manager
  (SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance)
{
}

static void enable_c2_EV_Pwr_Manager(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_EV_Pwr_Manager(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_EV_Pwr_Manager
  (SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance)
{
  uint32_T c2_prevAniVal;
  c2_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c2_is_active_c2_EV_Pwr_Manager == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_EV_Pwr_Manager == c2_IN_Stop) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_EV_Pwr_Manager == c2_IN_Accel) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_EV_Pwr_Manager == c2_IN_Coast) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
  }

  if (chartInstance->c2_is_c2_EV_Pwr_Manager == c2_IN_Decel) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
  }

  _SFD_SET_ANIMATION(c2_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c2_EV_Pwr_Manager
  (SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  boolean_T c2_hoistedGlobal;
  boolean_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_d_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  uint8_T c2_e_hoistedGlobal;
  uint8_T c2_e_u;
  const mxArray *c2_f_y = NULL;
  boolean_T *c2_BrakeSet;
  uint8_T *c2_Mode;
  c2_BrakeSet = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Mode = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(5), FALSE);
  c2_hoistedGlobal = *c2_BrakeSet;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_Mode;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = chartInstance->c2_is_active_c2_EV_Pwr_Manager;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = chartInstance->c2_is_c2_EV_Pwr_Manager;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  c2_e_hoistedGlobal = chartInstance->c2_temporalCounter_i1;
  c2_e_u = c2_e_hoistedGlobal;
  c2_f_y = NULL;
  sf_mex_assign(&c2_f_y, sf_mex_create("y", &c2_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 4, c2_f_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_EV_Pwr_Manager(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  boolean_T *c2_BrakeSet;
  uint8_T *c2_Mode;
  c2_BrakeSet = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Mode = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_u = sf_mex_dup(c2_st);
  *c2_BrakeSet = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 0)), "BrakeSet");
  *c2_Mode = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    1)), "Mode");
  chartInstance->c2_is_active_c2_EV_Pwr_Manager = c2_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
     "is_active_c2_EV_Pwr_Manager");
  chartInstance->c2_is_c2_EV_Pwr_Manager = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 3)), "is_c2_EV_Pwr_Manager");
  chartInstance->c2_temporalCounter_i1 = c2_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c2_u, 4)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c2_setSimStateSideEffectsInfo,
                c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 5)), "setSimStateSideEffectsInfo"), TRUE);
  sf_mex_destroy(&c2_u);
  chartInstance->c2_doSetSimStateSideEffects = 1U;
  c2_update_debugger_state_c2_EV_Pwr_Manager(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void c2_set_sim_state_side_effects_c2_EV_Pwr_Manager
  (SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance)
{
  if ((int16_T)chartInstance->c2_doSetSimStateSideEffects != 0) {
    if (chartInstance->c2_is_c2_EV_Pwr_Manager == c2_IN_Accel) {
      chartInstance->c2_tp_Accel = 1U;
    } else {
      chartInstance->c2_tp_Accel = 0U;
    }

    if (chartInstance->c2_is_c2_EV_Pwr_Manager == c2_IN_Coast) {
      chartInstance->c2_tp_Coast = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_Coast = 0U;
    }

    if (chartInstance->c2_is_c2_EV_Pwr_Manager == c2_IN_Decel) {
      chartInstance->c2_tp_Decel = 1U;
      if (sf_mex_sub(chartInstance->c2_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c2_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c2_tp_Decel = 0U;
    }

    if (chartInstance->c2_is_c2_EV_Pwr_Manager == c2_IN_Stop) {
      chartInstance->c2_tp_Stop = 1U;
    } else {
      chartInstance->c2_tp_Stop = 0U;
    }

    chartInstance->c2_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c2_EV_Pwr_Manager(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c2_setSimStateSideEffectsInfo);
}

static void sf_c2_EV_Pwr_Manager(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance)
{
  c2_set_sim_state_side_effects_c2_EV_Pwr_Manager(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  chartInstance->c2_sfEvent = CALL_EVENT;
  if (chartInstance->c2_temporalCounter_i1 < 255U) {
    chartInstance->c2_temporalCounter_i1 = (uint8_T)(int16_T)
      (chartInstance->c2_temporalCounter_i1 + 1);
  }

  c2_chartstep_c2_EV_Pwr_Manager(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_EV_Pwr_ManagerMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_EV_Pwr_Manager(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance)
{
  boolean_T c2_out;
  boolean_T c2_b_out;
  boolean_T c2_c_out;
  boolean_T c2_temp;
  boolean_T c2_b_temp;
  boolean_T c2_c_temp;
  boolean_T c2_d_out;
  boolean_T c2_d_temp;
  boolean_T c2_e_out;
  boolean_T c2_f_out;
  boolean_T c2_g_out;
  boolean_T c2_e_temp;
  boolean_T c2_h_out;
  boolean_T c2_i_out;
  boolean_T c2_f_temp;
  boolean_T c2_g_temp;
  boolean_T c2_j_out;
  boolean_T c2_k_out;
  real32_T *c2_Decel_Cmd;
  real32_T *c2_veh_spd;
  real32_T *c2_Accel_Cmd;
  uint8_T *c2_Mode;
  boolean_T *c2_BrakeSet;
  c2_BrakeSet = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_veh_spd = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_Decel_Cmd = (real32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_Accel_Cmd = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_Mode = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  if (chartInstance->c2_is_active_c2_EV_Pwr_Manager == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_active_c2_EV_Pwr_Manager = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_EV_Pwr_Manager = c2_IN_Stop;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_Stop = 1U;
    *c2_Mode = 0U;
    *c2_BrakeSet = TRUE;
  } else {
    switch (chartInstance->c2_is_c2_EV_Pwr_Manager) {
     case c2_IN_Accel:
      CV_CHART_EVAL(0, 0, 1);
      c2_Accel(chartInstance);
      break;

     case c2_IN_Coast:
      CV_CHART_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c2_sfEvent);
      c2_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0, (real_T)
                  *c2_Decel_Cmd > 0.25 * (real_T)*c2_veh_spd / 100.0 != 0U,
                  chartInstance->c2_sfEvent)) != 0);
      if (c2_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[2];
          unsigned int numTransitions = 1;
          transitionList[0] = 3;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          c2_b_out = ((real_T)*c2_Accel_Cmd > 0.25 * (real_T)*c2_veh_spd / 50.0);
          if (c2_b_out) {
            transitionList[numTransitions] = 6;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Coast = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_EV_Pwr_Manager = c2_IN_Decel;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        chartInstance->c2_temporalCounter_i1 = 0U;
        chartInstance->c2_tp_Decel = 1U;
        *c2_Mode = 3U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                     chartInstance->c2_sfEvent);
        c2_c_out = (CV_TRANSITION_EVAL(6U, (int32_T)_SFD_CCP_CALL(6U, 0, (real_T)*
          c2_Accel_Cmd > 0.25 * (real_T)*c2_veh_spd / 50.0 != 0U,
          chartInstance->c2_sfEvent)) != 0);
        if (c2_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_Coast = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_c2_EV_Pwr_Manager = c2_IN_Accel;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_Accel = 1U;
          *c2_Mode = 1U;
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                       chartInstance->c2_sfEvent);
          c2_temp = (_SFD_CCP_CALL(7U, 0, (real_T)*c2_veh_spd < 0.05 != 0U,
                      chartInstance->c2_sfEvent) != 0);
          if (c2_temp) {
            c2_temp = (_SFD_CCP_CALL(7U, 1, (real_T)*c2_Decel_Cmd < 0.05 != 0U,
                        chartInstance->c2_sfEvent) != 0);
          }

          c2_b_temp = c2_temp;
          if (c2_b_temp) {
            c2_b_temp = (_SFD_CCP_CALL(7U, 2, (real_T)*c2_Accel_Cmd <= 0.05 !=
              0U, chartInstance->c2_sfEvent) != 0);
          }

          c2_c_temp = c2_b_temp;
          if (c2_c_temp) {
            c2_c_temp = (_SFD_CCP_CALL(7U, 3,
              chartInstance->c2_temporalCounter_i1 >= 200 != 0U,
              chartInstance->c2_sfEvent) != 0);
          }

          c2_d_out = (CV_TRANSITION_EVAL(7U, (int32_T)c2_c_temp) != 0);
          if (c2_d_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_Coast = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
            chartInstance->c2_is_c2_EV_Pwr_Manager = c2_IN_Stop;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_Stop = 1U;
            *c2_Mode = 0U;
            *c2_BrakeSet = TRUE;
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                         chartInstance->c2_sfEvent);
          }
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_Decel:
      CV_CHART_EVAL(0, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c2_sfEvent);
      c2_d_temp = (_SFD_CCP_CALL(4U, 0, (real_T)*c2_veh_spd < 0.05 != 0U,
        chartInstance->c2_sfEvent) != 0);
      if (c2_d_temp) {
        c2_d_temp = (_SFD_CCP_CALL(4U, 1, chartInstance->c2_temporalCounter_i1 >=
          200 != 0U, chartInstance->c2_sfEvent) != 0);
      }

      c2_e_out = (CV_TRANSITION_EVAL(4U, (int32_T)c2_d_temp) != 0);
      if (c2_e_out) {
        if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
          unsigned int transitionList[3];
          unsigned int numTransitions = 1;
          transitionList[0] = 4;
          _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
          c2_f_out = (((real_T)*c2_Decel_Cmd < 0.125 * (real_T)*c2_veh_spd /
                       100.0) && (*c2_Accel_Cmd == 0.0F));
          if (c2_f_out) {
            transitionList[numTransitions] = 5;
            numTransitions++;
          }

          c2_g_out = ((*c2_Accel_Cmd > 0.0F) && (*c2_Decel_Cmd == 0.0F) &&
                      (*c2_veh_spd > 1.0F));
          if (c2_g_out) {
            transitionList[numTransitions] = 10;
            numTransitions++;
          }

          _SFD_TRANSITION_CONFLICT_CHECK_END();
          if (numTransitions > 1) {
            _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
          }
        }

        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Decel = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_EV_Pwr_Manager = c2_IN_Stop;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Stop = 1U;
        *c2_Mode = 0U;
        *c2_BrakeSet = TRUE;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                     chartInstance->c2_sfEvent);
        c2_e_temp = (_SFD_CCP_CALL(5U, 0, (real_T)*c2_Decel_Cmd < 0.125 *
          (real_T)*c2_veh_spd / 100.0 != 0U, chartInstance->c2_sfEvent) != 0);
        if (c2_e_temp) {
          c2_e_temp = (_SFD_CCP_CALL(5U, 1, *c2_Accel_Cmd == 0.0F != 0U,
            chartInstance->c2_sfEvent) != 0);
        }

        c2_h_out = (CV_TRANSITION_EVAL(5U, (int32_T)c2_e_temp) != 0);
        if (c2_h_out) {
          if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
            unsigned int transitionList[2];
            unsigned int numTransitions = 1;
            transitionList[0] = 5;
            _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
            c2_i_out = ((*c2_Accel_Cmd > 0.0F) && (*c2_Decel_Cmd == 0.0F) &&
                        (*c2_veh_spd > 1.0F));
            if (c2_i_out) {
              transitionList[numTransitions] = 10;
              numTransitions++;
            }

            _SFD_TRANSITION_CONFLICT_CHECK_END();
            if (numTransitions > 1) {
              _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
            }
          }

          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c2_sfEvent);
          chartInstance->c2_tp_Decel = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
          chartInstance->c2_is_c2_EV_Pwr_Manager = c2_IN_Coast;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
          chartInstance->c2_temporalCounter_i1 = 0U;
          chartInstance->c2_tp_Coast = 1U;
          *c2_Mode = 2U;
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                       chartInstance->c2_sfEvent);
          c2_f_temp = (_SFD_CCP_CALL(10U, 0, *c2_Accel_Cmd > 0.0F != 0U,
            chartInstance->c2_sfEvent) != 0);
          if (c2_f_temp) {
            c2_f_temp = (_SFD_CCP_CALL(10U, 1, *c2_Decel_Cmd == 0.0F != 0U,
              chartInstance->c2_sfEvent) != 0);
          }

          c2_g_temp = c2_f_temp;
          if (c2_g_temp) {
            c2_g_temp = (_SFD_CCP_CALL(10U, 2, *c2_veh_spd > 1.0F != 0U,
              chartInstance->c2_sfEvent) != 0);
          }

          c2_j_out = (CV_TRANSITION_EVAL(10U, (int32_T)c2_g_temp) != 0);
          if (c2_j_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c2_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c2_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_Decel = 0U;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
            chartInstance->c2_is_c2_EV_Pwr_Manager = c2_IN_Accel;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
            chartInstance->c2_tp_Accel = 1U;
            *c2_Mode = 1U;
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                         chartInstance->c2_sfEvent);
          }
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c2_sfEvent);
      break;

     case c2_IN_Stop:
      CV_CHART_EVAL(0, 0, 4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c2_sfEvent);
      c2_k_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0, (real_T)
        *c2_Accel_Cmd > 0.05 != 0U, chartInstance->c2_sfEvent)) != 0);
      if (c2_k_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
        *c2_BrakeSet = FALSE;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Stop = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_EV_Pwr_Manager = c2_IN_Accel;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Accel = 1U;
        *c2_Mode = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     chartInstance->c2_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c2_sfEvent);
      break;

     default:
      CV_CHART_EVAL(0, 0, 0);
      chartInstance->c2_is_c2_EV_Pwr_Manager = c2_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_EV_Pwr_Manager(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance)
{
}

static void c2_Accel(SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance)
{
  boolean_T c2_temp;
  boolean_T c2_out;
  boolean_T c2_b_out;
  boolean_T c2_c_out;
  boolean_T c2_b_temp;
  boolean_T c2_d_out;
  boolean_T c2_e_out;
  boolean_T c2_c_temp;
  boolean_T c2_f_out;
  real32_T *c2_Accel_Cmd;
  real32_T *c2_veh_spd;
  real32_T *c2_Decel_Cmd;
  uint8_T *c2_Mode;
  boolean_T *c2_BrakeSet;
  c2_BrakeSet = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_veh_spd = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_Decel_Cmd = (real32_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_Accel_Cmd = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_Mode = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c2_sfEvent);
  c2_temp = (_SFD_CCP_CALL(2U, 0, (real_T)*c2_Accel_Cmd < 0.125 * (real_T)
              *c2_veh_spd / 100.0 != 0U, chartInstance->c2_sfEvent) != 0);
  if (c2_temp) {
    c2_temp = (_SFD_CCP_CALL(2U, 1, *c2_Decel_Cmd == 0.0F != 0U,
                chartInstance->c2_sfEvent) != 0);
  }

  c2_out = (CV_TRANSITION_EVAL(2U, (int32_T)c2_temp) != 0);
  if (c2_out) {
    if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
      unsigned int transitionList[3];
      unsigned int numTransitions = 1;
      transitionList[0] = 2;
      _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
      c2_b_out = (((real_T)*c2_veh_spd < 0.05 * (real_T)*c2_veh_spd / 100.0) &&
                  ((real_T)*c2_Accel_Cmd < 0.005));
      if (c2_b_out) {
        transitionList[numTransitions] = 8;
        numTransitions++;
      }

      c2_c_out = ((*c2_Accel_Cmd == 0.0F) && (*c2_Decel_Cmd > 0.0F));
      if (c2_c_out) {
        transitionList[numTransitions] = 9;
        numTransitions++;
      }

      _SFD_TRANSITION_CONFLICT_CHECK_END();
      if (numTransitions > 1) {
        _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
      }
    }

    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
    chartInstance->c2_tp_Accel = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
    chartInstance->c2_is_c2_EV_Pwr_Manager = c2_IN_Coast;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c2_sfEvent);
    chartInstance->c2_temporalCounter_i1 = 0U;
    chartInstance->c2_tp_Coast = 1U;
    *c2_Mode = 2U;
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c2_sfEvent);
    c2_b_temp = (_SFD_CCP_CALL(8U, 0, (real_T)*c2_veh_spd < 0.05 * (real_T)
      *c2_veh_spd / 100.0 != 0U, chartInstance->c2_sfEvent) != 0);
    if (c2_b_temp) {
      c2_b_temp = (_SFD_CCP_CALL(8U, 1, (real_T)*c2_Accel_Cmd < 0.005 != 0U,
        chartInstance->c2_sfEvent) != 0);
    }

    c2_d_out = (CV_TRANSITION_EVAL(8U, (int32_T)c2_b_temp) != 0);
    if (c2_d_out) {
      if (_SFD_TRANSITION_CONFLICT_CHECK_ENABLED()) {
        unsigned int transitionList[2];
        unsigned int numTransitions = 1;
        transitionList[0] = 8;
        _SFD_TRANSITION_CONFLICT_CHECK_BEGIN();
        c2_e_out = ((*c2_Accel_Cmd == 0.0F) && (*c2_Decel_Cmd > 0.0F));
        if (c2_e_out) {
          transitionList[numTransitions] = 9;
          numTransitions++;
        }

        _SFD_TRANSITION_CONFLICT_CHECK_END();
        if (numTransitions > 1) {
          _SFD_TRANSITION_CONFLICT(&(transitionList[0]),numTransitions);
        }
      }

      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c2_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_Accel = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
      chartInstance->c2_is_c2_EV_Pwr_Manager = c2_IN_Stop;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c2_sfEvent);
      chartInstance->c2_tp_Stop = 1U;
      *c2_Mode = 0U;
      *c2_BrakeSet = TRUE;
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                   chartInstance->c2_sfEvent);
      c2_c_temp = (_SFD_CCP_CALL(9U, 0, *c2_Accel_Cmd == 0.0F != 0U,
        chartInstance->c2_sfEvent) != 0);
      if (c2_c_temp) {
        c2_c_temp = (_SFD_CCP_CALL(9U, 1, *c2_Decel_Cmd > 0.0F != 0U,
          chartInstance->c2_sfEvent) != 0);
      }

      c2_f_out = (CV_TRANSITION_EVAL(9U, (int32_T)c2_c_temp) != 0);
      if (c2_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c2_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c2_sfEvent);
        chartInstance->c2_tp_Accel = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c2_sfEvent);
        chartInstance->c2_is_c2_EV_Pwr_Manager = c2_IN_Decel;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c2_sfEvent);
        chartInstance->c2_temporalCounter_i1 = 0U;
        chartInstance->c2_tp_Decel = 1U;
        *c2_Mode = 3U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     chartInstance->c2_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

const mxArray *sf_c2_EV_Pwr_Manager_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance;
  chartInstance = (SFc2_EV_Pwr_ManagerInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_emlrt_marshallIn(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i0, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance;
  chartInstance = (SFc2_EV_Pwr_ManagerInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance;
  chartInstance = (SFc2_EV_Pwr_ManagerInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static uint8_T c2_b_emlrt_marshallIn(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance, const mxArray *c2_b_tp_Stop, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_Stop),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_Stop);
  return c2_y;
}

static uint8_T c2_c_emlrt_marshallIn(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_tp_Stop;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  uint8_T c2_y;
  SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance;
  chartInstance = (SFc2_EV_Pwr_ManagerInstanceStruct *)chartInstanceVoid;
  c2_b_tp_Stop = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_tp_Stop),
    &c2_thisId);
  sf_mex_destroy(&c2_b_tp_Stop);
  *(uint8_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance;
  chartInstance = (SFc2_EV_Pwr_ManagerInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 1, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  boolean_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance;
  chartInstance = (SFc2_EV_Pwr_ManagerInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(boolean_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static boolean_T c2_d_emlrt_marshallIn(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance, const mxArray *c2_BrakeSet, const char_T *c2_identifier)
{
  boolean_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_BrakeSet),
    &c2_thisId);
  sf_mex_destroy(&c2_BrakeSet);
  return c2_y;
}

static boolean_T c2_e_emlrt_marshallIn(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  boolean_T c2_y;
  boolean_T c2_b0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_b0, 1, 11, 0U, 0, 0U, 0);
  c2_y = c2_b0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_BrakeSet;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  boolean_T c2_y;
  SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance;
  chartInstance = (SFc2_EV_Pwr_ManagerInstanceStruct *)chartInstanceVoid;
  c2_BrakeSet = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_BrakeSet),
    &c2_thisId);
  sf_mex_destroy(&c2_BrakeSet);
  *(boolean_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_emlrt_marshallIn(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance, const mxArray *c2_b_setSimStateSideEffectsInfo, const char_T
  *c2_identifier)
{
  const mxArray *c2_y = NULL;
  emlrtMsgIdentifier c2_thisId;
  c2_y = NULL;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  sf_mex_assign(&c2_y, c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_setSimStateSideEffectsInfo), &c2_thisId), FALSE);
  sf_mex_destroy(&c2_b_setSimStateSideEffectsInfo);
  return c2_y;
}

static const mxArray *c2_g_emlrt_marshallIn(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_duplicatearraysafe(&c2_u), FALSE);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_EV_Pwr_ManagerInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c2_EV_Pwr_Manager_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(621425594U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2173735809U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(556133786U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(413443209U);
}

mxArray *sf_c2_EV_Pwr_Manager_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("X2q6FXGOMhOfeF1lv4ojSD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_EV_Pwr_Manager_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_EV_Pwr_Manager_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c2_EV_Pwr_Manager(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[25],T\"BrakeSet\",},{M[1],M[22],T\"Mode\",},{M[8],M[0],T\"is_active_c2_EV_Pwr_Manager\",},{M[9],M[0],T\"is_c2_EV_Pwr_Manager\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"wu\",M1x2[5 6],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_EV_Pwr_Manager_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance;
    chartInstance = (SFc2_EV_Pwr_ManagerInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _EV_Pwr_ManagerMachineNumber_,
           2,
           4,
           18,
           5,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_EV_Pwr_ManagerMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_EV_Pwr_ManagerMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _EV_Pwr_ManagerMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"Mode");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Accel_Cmd");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Decel_Cmd");
          _SFD_SET_DATA_PROPS(3,1,1,0,"veh_spd");
          _SFD_SET_DATA_PROPS(4,2,0,1,"BrakeSet");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_CH_SUBSTATE_COUNT(4);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
        }

        _SFD_CV_INIT_CHART(4,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 17 };

          static unsigned int sEndGuardMap[] = { 13, 32 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(4,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 20, 42, 66 };

          static unsigned int sEndGuardMap[] = { 13, 34, 58, 81 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_TRANS(7,4,&(sStartGuardMap[0]),&(sEndGuardMap[0]),7,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 16 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2, 35 };

          static unsigned int sEndGuardMap[] = { 26, 50 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(8,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 36 };

          static unsigned int sEndGuardMap[] = { 28, 49 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(2,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 36 };

          static unsigned int sEndGuardMap[] = { 28, 49 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(5,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 28 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 27 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 16, 33 };

          static unsigned int sEndGuardMap[] = { 12, 29, 42 };

          static int sPostFixPredicateTree[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_TRANS(10,3,&(sStartGuardMap[0]),&(sEndGuardMap[0]),5,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1, 19 };

          static unsigned int sEndGuardMap[] = { 15, 32 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(9,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);

        {
          uint8_T *c2_Mode;
          real32_T *c2_Accel_Cmd;
          real32_T *c2_Decel_Cmd;
          real32_T *c2_veh_spd;
          boolean_T *c2_BrakeSet;
          c2_BrakeSet = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_veh_spd = (real32_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_Decel_Cmd = (real32_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_Accel_Cmd = (real32_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c2_Mode = (uint8_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_Mode);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_Accel_Cmd);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_Decel_Cmd);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_veh_spd);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_BrakeSet);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _EV_Pwr_ManagerMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "7yiiOwUJActcNjU0t1Deu";
}

static void sf_opaque_initialize_c2_EV_Pwr_Manager(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_EV_Pwr_ManagerInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_EV_Pwr_Manager((SFc2_EV_Pwr_ManagerInstanceStruct*)
    chartInstanceVar);
  initialize_c2_EV_Pwr_Manager((SFc2_EV_Pwr_ManagerInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_EV_Pwr_Manager(void *chartInstanceVar)
{
  enable_c2_EV_Pwr_Manager((SFc2_EV_Pwr_ManagerInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_EV_Pwr_Manager(void *chartInstanceVar)
{
  disable_c2_EV_Pwr_Manager((SFc2_EV_Pwr_ManagerInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_EV_Pwr_Manager(void *chartInstanceVar)
{
  sf_c2_EV_Pwr_Manager((SFc2_EV_Pwr_ManagerInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_EV_Pwr_Manager(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_EV_Pwr_Manager
    ((SFc2_EV_Pwr_ManagerInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_EV_Pwr_Manager();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_EV_Pwr_Manager(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_EV_Pwr_Manager();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_EV_Pwr_Manager((SFc2_EV_Pwr_ManagerInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_EV_Pwr_Manager(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_EV_Pwr_Manager(S);
}

static void sf_opaque_set_sim_state_c2_EV_Pwr_Manager(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_EV_Pwr_Manager(S, st);
}

static void sf_opaque_terminate_c2_EV_Pwr_Manager(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_EV_Pwr_ManagerInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_EV_Pwr_Manager_optimization_info();
    }

    finalize_c2_EV_Pwr_Manager((SFc2_EV_Pwr_ManagerInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_EV_Pwr_Manager((SFc2_EV_Pwr_ManagerInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_EV_Pwr_Manager(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_EV_Pwr_Manager((SFc2_EV_Pwr_ManagerInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_EV_Pwr_Manager(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_EV_Pwr_Manager_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3934489240U));
  ssSetChecksum1(S,(3708472369U));
  ssSetChecksum2(S,(2654352728U));
  ssSetChecksum3(S,(3229660379U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_EV_Pwr_Manager(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c2_EV_Pwr_Manager(SimStruct *S)
{
  SFc2_EV_Pwr_ManagerInstanceStruct *chartInstance;
  chartInstance = (SFc2_EV_Pwr_ManagerInstanceStruct *)utMalloc(sizeof
    (SFc2_EV_Pwr_ManagerInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_EV_Pwr_ManagerInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_EV_Pwr_Manager;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_EV_Pwr_Manager;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_EV_Pwr_Manager;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_EV_Pwr_Manager;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_EV_Pwr_Manager;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_EV_Pwr_Manager;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_EV_Pwr_Manager;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_EV_Pwr_Manager;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_EV_Pwr_Manager;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_EV_Pwr_Manager;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_EV_Pwr_Manager;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_EV_Pwr_Manager_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_EV_Pwr_Manager(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_EV_Pwr_Manager(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_EV_Pwr_Manager(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_EV_Pwr_Manager_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
