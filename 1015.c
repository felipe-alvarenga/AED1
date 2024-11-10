#include <stdio.h>
 
int main() {
    double a, b, c, d, R;
    printf ("");
    scanf ("%lf", &a);
    printf ("");
    scanf ("%lf", &b);
    printf ("");
    scanf ("%lf", &c);
    printf ("");
    scanf ("%lf", &d);
    R = sqrt((a-c)*(a-c)+(b-d)*(b-d));
    printf ("%.4lf\n", R);
}
