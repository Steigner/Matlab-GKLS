/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_generate_api.c
 *
 * Code generation for function '_coder_generate_api'
 *
 */

/* Include files */
#include "_coder_generate_api.h"
#include "generate.h"
#include "generate_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *dim,
                               const char_T *identifier);

static const mxArray *emlrt_marshallOut(const real_T u);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *dim,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(dim), &thisId);
  emlrtDestroyArray(&dim);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

void generate_api(const mxArray *const prhs[7], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T dim;
  real_T global_dist;
  real_T global_radius;
  real_T num;
  real_T num_min;
  real_T num_problems;
  real_T test_function;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  dim = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "dim");
  num_min = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "num_min");
  global_dist = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "global_dist");
  global_radius = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "global_radius");
  num_problems = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "num_problems");
  test_function = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "test_function");
  num = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "num");
  /* Invoke the target function */
  dim = generate(&st, dim, num_min, global_dist, global_radius, num_problems,
                 test_function, num);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(dim);
}

/* End of code generation (_coder_generate_api.c) */
