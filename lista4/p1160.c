//SUBMISSÃO # 48600012
//Submissão: 14/04/2026 21:16:58

#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int i;
    for (i = 0; i < T; i++) {
        int PA, PB, anos;
        double G1, G2;
        scanf("%d %d %lf %lf", &PA, &PB, &G1, &G2);

        anos = 0;

       
        while (PA <= PB) {
            
            PA = PA + (int)(PA * G1 / 100.0);
            PB = PB + (int)(PB * G2 / 100.0);
            anos++;

            
            if (anos > 100) {
                break;
            }
        }

        if (anos > 100) {
            printf("Mais de 1 seculo.\n");
        } else {
            printf("%d anos.\n", anos);
        }
    }

    return 0;
}