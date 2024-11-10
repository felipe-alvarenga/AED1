#include <stdio.h>
 
int main() {
    double a, b, c;
    double ret, cir, trap, quad, tri;
    printf ("");
    scanf ("%lf", &a);
    printf ("");
    scanf ("%lf", &b);
    printf ("");
    scanf ("%lf", &c);
    tri = (a*c)/2;
    cir = (c*c)*3.14159;
    trap = ((a+b)*c)/2;
    quad = b*b;
    ret = a*b;
    printf ("TRIANGULO: %.3lf\nCIRCULO: %.3lf\nTRAPEZIO: %.3lf\nQUADRADO: %.3lf\nRETANGULO: %.3lf\n", tri, cir, trap, quad, ret);
}
