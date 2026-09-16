//SUBMISSÃO # 49247664
//Submissão: 07/06/2026 18:15:54

#include <stdio.h>

int main(void) {


    while(1){
        /*primeira linha*/
       int B, N;
       scanf("%d %d", &B, &N);
       /*fim de código*/
        if(B == 0 && N == 0)
            break;
        /*segunda linha*/
        int reservas[B + 1];
        for (int i = 1; i <= B; i++) {
        scanf("%d", &reservas[i]);
        }
        /*terceira linha*/
        int D, C, V;
        for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &D, &C, &V);
        reservas[D] = reservas[D] - V;

        reservas[C] = reservas[C] + V;
        }
        /*saida*/
        int possivel = 1;

        for (int i = 1; i <= B; i++) {
            if (reservas[i] < 0) {
                possivel = 0;
                break;
            }
        }
        if (possivel == 1) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
 
    




}