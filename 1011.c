#include <stdio.h>
 
int main() {
    double R, r;
    printf ("");
    scanf ("%lf", &R);
    r = (4.0/3)*3.14159*R*R*R;
    printf ("VOLUME = %.3lf\n", r);
}
