/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: xgerc.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 04-Aug-2020 12:54:05
 */

/* Include Files */
#include "xgerc.h"
#include "polyfit.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : int m
 *                int n
 *                double alpha1
 *                int ix0
 *                const emxArray_real_T *y
 *                emxArray_real_T *A
 *                int ia0
 *                int lda
 * Return Type  : void
 */
void xgerc(int m, int n, double alpha1, int ix0, const emxArray_real_T *y,
           emxArray_real_T *A, int ia0, int lda)
{
  int jA;
  int jy;
  int j;
  double temp;
  int ix;
  int i;
  int ijA;
  if (!(alpha1 == 0.0)) {
    jA = ia0;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y->data[jy] != 0.0) {
        temp = y->data[jy] * alpha1;
        ix = ix0;
        i = m + jA;
        for (ijA = jA; ijA < i; ijA++) {
          A->data[ijA - 1] += A->data[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += lda;
    }
  }
}

/*
 * File trailer for xgerc.c
 *
 * [EOF]
 */
