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
#include "rt_nonfinite.h"
#include "gkls.c"
#include "gkls.h"
#include "main.h"
#include "rnd_gen.c"
#include "rnd_gen.h"

/* Function Definitions */
real_T generate(const emlrtStack *sp, real_T dim, real_T num_min,
                real_T global_dist, real_T global_radius, real_T num_problems,
                real_T test_function)
{
  (void)sp;
  /*  generate an include in the C code */
  /*  evaluate the C function */
  return main(dim, num_min, global_dist, global_radius, num_problems,
              test_function);
}

/* End of code generation (generate.c) */
