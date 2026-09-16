//SUBMISSÃO # 49270857
//Submissão: 09/06/2026 18:42:48

#include <stdio.h>

int menor (int A, int B, int C, int D) {
    int menorAtual = A;
    if (B < menorAtual) menorAtual = B;
    if (C < menorAtual) menorAtual = C;
    if (D < menorAtual) menorAtual = D;

    return menorAtual;
}
int calculoValor (int i, int j, int N) {
    int distanciaCima = i + 1;
    int distanciaEsquerda = j + 1;
    int distanciaBaixo = N - i;
    int distanciaDireita = N - j;

    return menor(distanciaCima, distanciaEsquerda, distanciaBaixo, distanciaDireita);
}

int main(void) {
    int N;

    while(scanf("%d", &N) && N != 0) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                int valor = calculoValor(i, j, N);
                if(j == 0){
                    printf("%3d", valor);
                } else {
                    printf(" %3d", valor);
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}