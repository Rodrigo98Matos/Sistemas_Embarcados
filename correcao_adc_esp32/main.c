#include <stdio.h>
#include <stdlib.h>
//FUNÇÃO DE GRAU SEM USAR O POW
double f13_semPow(double x) {
  return   2, 161282383460e+02
           +   3, 944594843419e-01 * x
           +   5, 395439724295e-04 * x * x
           +  -3, 968558178426e-06 * x * x * x
           +   1, 047910519933e-08 * x * x * x * x
           +  -1, 479271312313e-11 * x * x * x * x * x
           +   1, 220894795714e-14 * x * x * x * x * x * x
           +  -6, 136200785076e-18 * x * x * x * x * x * x * x
           +   1, 910015248179e-21 * x * x * x * x * x * x * x * x
           +  -3, 566607830903e-25 * x * x * x * x * x * x * x * x * x
           +   5, 000280815521e-30 * x * x * x * x * x * x * x * x * x * x
           +   3, 434515045670e-32 * x * x * x * x * x * x * x * x * x * x * x
           +  -1, 407635444704e-35 * x * x * x * x * x * x * x * x * x * x * x * x
           +   9, 871816383223e-40 * x * x * x * x * x * x * x * x * x * x * x * x * x;
}
double f1(double x) {
  return   2.202196968876e+02
           +   3.561383996027e-01 * x;
}
double f2(double x) {
  return   2.202196968876e+02
           +   3.561383996027e-01 * x
           +   1.276218788985e-04 * pow(x, 2);
}
//FUNÇÃO DE GRAU 3
double f3(double x) {
  return   2.202196968876e+02
           +   3.561383996027e-01 * x
           +   1.276218788985e-04 * pow(x, 2)
           +  -3.470360275448e-07 * pow(x, 3);
}
double f4(double x) {
  return   2.202196968876e+02
           +   3.561383996027e-01 * x
           +   1.276218788985e-04 * pow(x, 2)
           +  -3.470360275448e-07 * pow(x, 3)
           +   2.082790802069e-10 * pow(x, 4);
}
int main()
{
    for(int i = 0;i<4065;i++)
    printf("%g\n",f4(i));
    return 0;
}
