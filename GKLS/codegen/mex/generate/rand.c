/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rand.c
 *
 * Code generation for function 'rand'
 *
 */

/* Include files */
#include "rand.h"
#include "generate_emxutil.h"
#include "generate_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtDCInfo emlrtDCI = {
    103,    /* lineNo */
    30,     /* colNo */
    "rand", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\randfun\\rand.m", /* pName
                                                                          */
    4 /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    103,    /* lineNo */
    24,     /* colNo */
    "rand", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\randfun\\rand.m" /* pName
                                                                         */
};

/* Function Definitions */
void b_rand(const emlrtStack *sp, real_T varargin_1, real_T varargin_2,
            emxArray_real_T *r)
{
  real_T *r_data;
  int32_T i;
  if (!(varargin_1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1, &emlrtDCI, (emlrtCTX)sp);
  }
  i = r->size[0] * r->size[1];
  r->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity_real_T(sp, r, i, &b_emlrtRTEI);
  if (!(varargin_2 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_2, &emlrtDCI, (emlrtCTX)sp);
  }
  i = r->size[0] * r->size[1];
  r->size[1] = (int32_T)varargin_2;
  emxEnsureCapacity_real_T(sp, r, i, &b_emlrtRTEI);
  r_data = r->data;
  if (((int32_T)varargin_1 != 0) && ((int32_T)varargin_2 != 0)) {
    emlrtRandu(&r_data[0], (int32_T)varargin_1 * (int32_T)varargin_2);
  }
}

/* End of code generation (rand.c) */
