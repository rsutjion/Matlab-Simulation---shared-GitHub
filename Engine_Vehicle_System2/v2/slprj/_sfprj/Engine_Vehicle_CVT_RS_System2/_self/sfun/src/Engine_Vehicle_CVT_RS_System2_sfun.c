/* Include files */

#include "Engine_Vehicle_CVT_RS_System2_sfun.h"
#include "Engine_Vehicle_CVT_RS_System2_sfun_debug_macros.h"
#include "c1_Engine_Vehicle_CVT_RS_System2.h"
#include "c2_Engine_Vehicle_CVT_RS_System2.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Engine_Vehicle_CVT_RS_System2MachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Engine_Vehicle_CVT_RS_System2_initializer(void)
{
}

void Engine_Vehicle_CVT_RS_System2_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Engine_Vehicle_CVT_RS_System2_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_Engine_Vehicle_CVT_RS_System2_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Engine_Vehicle_CVT_RS_System2_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

extern void sf_Engine_Vehicle_CVT_RS_System2_uses_exported_functions(int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_Engine_Vehicle_CVT_RS_System2_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(479330163U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2374312273U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2641170935U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3962781052U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3851314739U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(870980897U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1217608503U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1442897990U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Engine_Vehicle_CVT_RS_System2_get_check_sum(mxArray *
            plhs[]);
          sf_c1_Engine_Vehicle_CVT_RS_System2_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Engine_Vehicle_CVT_RS_System2_get_check_sum(mxArray *
            plhs[]);
          sf_c2_Engine_Vehicle_CVT_RS_System2_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3061339410U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1991824845U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3599338742U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2357874978U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3689133557U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2665466691U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2192844344U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(652533724U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Engine_Vehicle_CVT_RS_System2_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "TCZPPqBKYZYQqqSv2Yl1LH") == 0) {
          extern mxArray
            *sf_c1_Engine_Vehicle_CVT_RS_System2_get_autoinheritance_info(void);
          plhs[0] = sf_c1_Engine_Vehicle_CVT_RS_System2_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "dkDMTqWlVgKj0ZbAMvxllG") == 0) {
          extern mxArray
            *sf_c2_Engine_Vehicle_CVT_RS_System2_get_autoinheritance_info(void);
          plhs[0] = sf_c2_Engine_Vehicle_CVT_RS_System2_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Engine_Vehicle_CVT_RS_System2_get_eml_resolved_functions_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_Engine_Vehicle_CVT_RS_System2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Engine_Vehicle_CVT_RS_System2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_Engine_Vehicle_CVT_RS_System2_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Engine_Vehicle_CVT_RS_System2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Engine_Vehicle_CVT_RS_System2_third_party_uses_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "AHKIRmrPu2umHOl1P0aBVC") == 0) {
          extern mxArray
            *sf_c1_Engine_Vehicle_CVT_RS_System2_third_party_uses_info(void);
          plhs[0] = sf_c1_Engine_Vehicle_CVT_RS_System2_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "ESbhtbRX0pqxqXdMlkQStE") == 0) {
          extern mxArray
            *sf_c2_Engine_Vehicle_CVT_RS_System2_third_party_uses_info(void);
          plhs[0] = sf_c2_Engine_Vehicle_CVT_RS_System2_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Engine_Vehicle_CVT_RS_System2_jit_fallback_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "AHKIRmrPu2umHOl1P0aBVC") == 0) {
          extern mxArray *sf_c1_Engine_Vehicle_CVT_RS_System2_jit_fallback_info
            (void);
          plhs[0] = sf_c1_Engine_Vehicle_CVT_RS_System2_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "ESbhtbRX0pqxqXdMlkQStE") == 0) {
          extern mxArray *sf_c2_Engine_Vehicle_CVT_RS_System2_jit_fallback_info
            (void);
          plhs[0] = sf_c2_Engine_Vehicle_CVT_RS_System2_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Engine_Vehicle_CVT_RS_System2_updateBuildInfo_args_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "AHKIRmrPu2umHOl1P0aBVC") == 0) {
          extern mxArray
            *sf_c1_Engine_Vehicle_CVT_RS_System2_updateBuildInfo_args_info(void);
          plhs[0] =
            sf_c1_Engine_Vehicle_CVT_RS_System2_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "ESbhtbRX0pqxqXdMlkQStE") == 0) {
          extern mxArray
            *sf_c2_Engine_Vehicle_CVT_RS_System2_updateBuildInfo_args_info(void);
          plhs[0] =
            sf_c2_Engine_Vehicle_CVT_RS_System2_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_Engine_Vehicle_CVT_RS_System2_get_post_codegen_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "AHKIRmrPu2umHOl1P0aBVC") == 0) {
        extern mxArray
          *sf_c1_Engine_Vehicle_CVT_RS_System2_get_post_codegen_info(void);
        plhs[0] = sf_c1_Engine_Vehicle_CVT_RS_System2_get_post_codegen_info();
        return;
      }
    }
    break;

   case 2:
    {
      if (strcmp(tpChksum, "ESbhtbRX0pqxqXdMlkQStE") == 0) {
        extern mxArray
          *sf_c2_Engine_Vehicle_CVT_RS_System2_get_post_codegen_info(void);
        plhs[0] = sf_c2_Engine_Vehicle_CVT_RS_System2_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void Engine_Vehicle_CVT_RS_System2_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _Engine_Vehicle_CVT_RS_System2MachineNumber_ = sf_debug_initialize_machine
    (debugInstance,"Engine_Vehicle_CVT_RS_System2","sfun",0,2,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Engine_Vehicle_CVT_RS_System2MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Engine_Vehicle_CVT_RS_System2MachineNumber_,0);
}

void Engine_Vehicle_CVT_RS_System2_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Engine_Vehicle_CVT_RS_System2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Engine_Vehicle_CVT_RS_System2", "Engine_Vehicle_CVT_RS_System2");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Engine_Vehicle_CVT_RS_System2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
