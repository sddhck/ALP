//SUBMISSÃO # 48688835
//Submissão: 21/04/2026 14:57:34

#include <stdio.h>
 
int main() {
 int N;
 scanf("%d", &N);
for (int i = 0; i < N; i++) {
        int X;
        scanf("%d", &X);
        int soma = 0;
        for (int m = 1; m < X; m++) {
            if (X % m == 0) {
                soma = soma + m;
            }
        }

        if (soma == X) {
            printf("%d eh perfeito\n", X);
        } else {
            printf("%d nao eh perfeito\n", X);
        }

    }
 
    return 0;
}