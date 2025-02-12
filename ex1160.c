#include <stdio.h>

int main(void) {
    int t, anos;
    unsigned long int pa, pb;
    float g1, g2;
    
    scanf("%d", &t);
    
    while (t--) {
        scanf("%lu %lu %f %f", &pa, &pb, &g1, &g2);
        anos = 0;
        
        while (pa <= pb) {
            pa += (unsigned long int)(pa * (g1 / 100));
            pb += (unsigned long int)(pb * (g2 / 100));
            anos++;
            
            if (anos > 100) {
                printf("Mais de 1 seculo.\n");
                break;
            }
        }
        
        if (anos <= 100)
            printf("%d anos.\n", anos);
    }
    
    return 0;
}
