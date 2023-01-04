/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generate.h
 *
 * Code generation for function 'generate'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real_T generate(const emlrtStack *sp, real_T dim, real_T num_min,
                real_T global_dist, real_T global_radius, real_T num_problems,
                real_T test_function);

/* End of code generation (generate.h) */
