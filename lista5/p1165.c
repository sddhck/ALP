//SUBMISSÃO # 48690225
//Submissão: 21/04/2026 16:42:02

#include <stdio.h>
 
int main() {
 
    int Numero, N;
    int divisores;

    scanf("%d", &N);

    for (int j = 0; j < N; j++) {

    scanf("%d", &Numero);
    divisores = 0;

    for (int i = 1; i <= Numero; i++) {
        if (Numero % i == 0) {
            divisores++;
        }
    }

    if (divisores == 2) {
        printf("%d eh primo\n", Numero);
    } else {
        printf("%d nao eh primo\n", Numero);
    } }
 
    return 0;
}