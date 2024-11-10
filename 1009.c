#include <stdio.h>
#include <string.h>

int main (){
  char nome[100];
  double s, v;
  printf ("");
  scanf ("%s", nome);
  printf ("");
  scanf ("%lf", &s);
  printf ("");
  scanf ("%lf", &v);
  printf ("TOTAL = R$ %.2lf\n", s + (v*0.15));
}
