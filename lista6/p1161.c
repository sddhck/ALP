//SUBMISSÃO # 48771037
//Submissão: 27/04/2026 21:05:21

#include <stdio.h>

int main() {
    long long int fatM, fatN;
    int m, n;

    while (scanf("%d %d", &m, &n) != EOF) {
        fatM = 1;
        fatN = 1;

        for (int i = 1; i <= m; i++) {
            fatM *= i;
        }

        
        for (int i = 1; i <= n; i++) {
            fatN *= i;
        }

       
        printf("%lld\n", fatM + fatN);
    }

    return 0;
}