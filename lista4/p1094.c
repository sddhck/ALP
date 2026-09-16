//SUBMISSÃO # 48597483
//Submissão: 14/04/2026 18:39:41

#include <stdio.h>

int main() {
    int n, quantia;
    char tipo;
    double coelhos = 0.00, ratos = 0.00, sapos = 0.00;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %c", &quantia, &tipo);

        if (tipo == 'C')
            coelhos += quantia;
        else if (tipo == 'R')
            ratos += quantia;
        else if (tipo == 'S')
            sapos += quantia;
    }

    int total = coelhos + ratos + sapos;

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %.0f\n", coelhos);
    printf("Total de ratos: %.0f\n", ratos);
    printf("Total de sapos: %.0f\n", sapos);
    printf("Percentual de coelhos: %.2f %%\n", coelhos / total * 100);
    printf("Percentual de ratos: %.2f %%\n", ratos / total * 100);
    printf("Percentual de sapos: %.2f %%\n", sapos / total * 100);

    return 0;
}