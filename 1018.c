#include <stdio.h>

int main() {
    int D, a, b, c, d, e, f, k;
    printf ("");
    scanf ("%i", &D);
    a = D/100;
    b = (D%100)/50;
    c = ((D%100)%50)/20;
    k = (((D%100)%50)%20)/10;
    d = ((((D%100)%50)%20)%10)/5;
    e = (((((D%100)%50)%20)%10)%5)/2;
    f = ((((((D%100)%50)%20)%10)%5)%2)/1;
    printf ("%i\n%i nota(s) de R$ 100,00\n%i nota(s) de R$ 50,00\n%i nota(s) de R$ 20,00\n%i nota(s) de R$ 10,00\n%i nota(s) de R$ 5,00\n%i nota(s) de R$ 2,00\n%i nota(s) de R$ 1,00\n", D, a, b, c, k, d, e, f);
}
