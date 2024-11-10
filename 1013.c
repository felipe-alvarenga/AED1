#include <stdio.h>
#include <stdlib.h>

int maior(int a, int b){
    return (a + b + abs(a - b))/2;
}

int main(){
    int a, b, c, d;
    printf ("");
    scanf ("%i", &a);
    printf ("");
    scanf ("%i", &b);
    printf ("");
    scanf ("%i", &c);
    d = maior(a, maior(b, c));
    printf("%d eh o maior\n", d);
}
