#include <stdio.h>
#include <math.h>

#include "sleefquad.h"

int main(int argc, char **argv) {
  Sleef_quad a0[] = { Sleef_cast_from_doubleq1_purec(5), Sleef_cast_from_doubleq1_purec(239) };
  Sleef_quadx2 q0 = Sleef_loadq2_advsimd(a0);

  Sleef_quad a1[] = { Sleef_cast_from_doubleq1_purec(1), Sleef_cast_from_doubleq1_purec(1) };
  Sleef_quadx2 q1 = Sleef_loadq2_advsimd(a1);

  Sleef_quad a2[] = { Sleef_cast_from_doubleq1_purec(16), Sleef_cast_from_doubleq1_purec(4) };
  Sleef_quadx2 q2 = Sleef_loadq2_advsimd(a2);

  Sleef_quadx2 q3;

  q3 = Sleef_divq2_u05advsimd(q1, q0);
  q3 = Sleef_atanq2_u10advsimd(q3);
  q3 = Sleef_mulq2_u05advsimd(q3, q2);

  Sleef_quad pi = Sleef_subq1_u05purec(Sleef_getq2_advsimd(q3, 0), Sleef_getq2_advsimd(q3, 1));

  Sleef_printf("%.40Pg\n", &pi);
}
