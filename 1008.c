#include <stdio.h>

int main (){
  int a, b;
  double c, d;
  printf ("");
  scanf ("%i", &a);
  printf ("");
  scanf ("%i", &b);
  printf ("");
  scanf ("%lf", &c);
  d = b * c;
  printf ("NUMBER = %i\nSALARY = U$ %.2lf\n", a, d);
}
