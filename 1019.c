#include <stdio.h>

void tempo (int);

int main(){
    int x;
    
    printf ("");
    scanf ("%i", &x);
    tempo(x);
}

void tempo (int x){
    printf ("%i:%i:%i\n", x/3600, (x%3600)/60, ((x%3600)%60));
}

