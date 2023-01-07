/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generate.c
 *
 * Code generation for function 'generate'
 *
 */

/* Include files */
#include "generate.h"
#include "generate_emxutil.h"
#include "generate_types.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "gkls.c"
#include "gkls.h"
#include "main.h"
#include "rnd_gen.c"
#include "rnd_gen.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    16,         /* lineNo */
    "generate", /* fcnName */
    "C:\\Users\\mjuri\\Documents\\generator_tasks\\GKLS-master\\GKLS_pdf_"
    "C\\Software\\generate.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    16,         /* lineNo */
    5,          /* colNo */
    "generate", /* fName */
    "C:\\Users\\mjuri\\Documents\\generator_tasks\\GKLS-master\\GKLS_pdf_"
    "C\\Software\\generate.m" /* pName */
};

/* Function Definitions */
real_T generate(const emlrtStack *sp, real_T dim, real_T num_min,
                real_T global_dist, real_T global_radius, real_T num_problems,
                real_T test_function, real_T num)
{
  emlrtStack st;
  emxArray_real_T *x;
  real_T error_msg;
  real_T *x_data;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &x, &emlrtRTEI);
  /*  ! Modificable ! */
  /*  generate random number or load from csv */
  /*  generate matrix dim x number of points */
  st.site = &emlrtRSI;
  b_rand(&st, dim, num, x);
  x_data = x->data;
  /*  include c code + header files */
  /*  generate an include in the C code */
  /*  evaluate the C function */
  error_msg = main(dim, num_min, global_dist, global_radius, num_problems,
                   test_function, &x_data[0], num);
  emxFree_real_T(sp, &x);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
  return error_msg;
}

/* End of code generation (generate.c) */
