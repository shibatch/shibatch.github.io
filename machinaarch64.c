#include <sleefquad.h>

int main(int argc, char **argv) {
  Sleef_quad a0[] = { Sleef_cast_from_doubleq1_purec(5), Sleef_cast_from_doubleq1_purec(239) };
  Sleef_quadx2 q0 = Sleef_loadq2_advsimd(a0);

  Sleef_quadx2 q1 = Sleef_splatq2_advsimd(Sleef_strtoq("1.0", NULL));

  Sleef_quadx2 q2 = Sleef_loadq2_advsimd((Sleef_quad[]) {
      SLEEF_Q(+0x1000000000000LL, 0x0000000000000000ULL, 4), // 16.0
      SLEEF_Q(+0x1000000000000LL, 0x0000000000000000ULL, 2), // 4.0
  });

  Sleef_quadx2 q3;

  q3 = Sleef_divq2_u05advsimd(q1, q0);
  q3 = Sleef_atanq2_u10advsimd(q3);
  q3 = Sleef_mulq2_u05advsimd(q3, q2);

  Sleef_quad pi = Sleef_subq1_u05purec(Sleef_getq2_advsimd(q3, 0), Sleef_getq2_advsimd(q3, 1));

  Sleef_printf("%.40Pg\n", &pi);
}
