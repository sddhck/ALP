//SUBMISSÃO #48504264
//Submissão: 07/04/2026 23:24:59

#include <stdio.h>
 
int main() {
 
    int p, j1, j2, r, a, ganhador, soma;

    scanf("%d %d %d %d %d", &p, &j1, &j2, &r, &a);

//somar numeros
    soma = j1 + j2;
        if (soma % 2 == 0 && p == 1) {
        ganhador = 1;
    }

    if (soma % 2 == 0 && p == 0) {
        ganhador = 2;
    }

    if (soma % 2 > 0 && p == 1) {
        ganhador = 2;
    }

    if (soma % 2 > 0 && p == 0) {
        ganhador = 1;
    }


    if (r + a == 1) {
        printf("Jogador 1 ganha!\n");
    }

    if (r + a == 2) {
        printf("Jogador 2 ganha!\n");
    }

    if (r + a == 0) {
        printf("Jogador %d", ganhador);
        printf(" ganha!\n");
    }


    
    
 
    return 0;
}