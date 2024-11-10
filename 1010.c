#include <stdio.h>
 
int main() {
    int a, b, c, d;
    double g, h, k, q;
    printf ("");
    scanf ("%i", &a);
    printf ("");
    scanf ("%i", &b);
    printf ("");
    scanf ("%lf", &g);
    printf ("");
    scanf ("%i", &c);
    printf ("");
    scanf ("%i", &d);
    printf ("");
    scanf ("%lf", &k);
    
    h = b*g;
    q = d*k;
    
    printf("VALOR A PAGAR: R$ %.2lf\n", q+h);
}
