//SUBMISSÃO # 48500475
//Submissão: 07/04/2026 20:27:54

#include <stdio.h>

int main() {

    int a, b, c, d, e;
    int pares = 0, impares = 0, negativos = 0, positivos = 0;

    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    
    if (a > 0)  {
        positivos = positivos + 1;
    }

    if (b > 0)  {
        positivos = positivos + 1;
    }

    if (c > 0)  {
        positivos = positivos + 1;
    }

    if (d > 0)  {
        positivos = positivos + 1;
    }

    if (e > 0)  {
        positivos = positivos + 1;
    }

    if (a % 2 == 0) {
        pares = pares + 1;
    } else {
        impares = impares + 1;
    }

    if (b % 2 == 0) {
        pares = pares + 1;
    } else {
        impares = impares + 1;
    }

    if (c % 2 == 0) {
        pares = pares + 1;
    } else {
        impares = impares + 1;
    }

    if (d % 2 == 0) {
        pares = pares + 1;
    } else {
        impares = impares + 1;
    }

    if (e % 2 == 0) {
        pares = pares + 1;
    } else {
        impares = impares + 1;
    }

    if (a < 0)  {
        negativos = negativos + 1;
    }

    if (b < 0)  {
        negativos = negativos + 1;
    }

    if (c < 0)  {
        negativos = negativos + 1;
    }

    if (d < 0)  {
        negativos = negativos + 1;
    }

    if (e < 0)  {
        negativos = negativos + 1;
    }

    printf("%d valor(es) par(es)\n", pares);
    printf("%d valor(es) impar(es)\n", impares);
    printf("%d valor(es) positivo(s)\n", positivos);
    printf("%d valor(es) negativo(s)\n", negativos);

    return 0;
}

