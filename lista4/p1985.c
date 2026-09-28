//SUBMISSÃO # 48600661
//Submissão: 14/04/2026 21:44:19

#include <stdio.h>

int main() {
    int produtos;
    scanf("%d", &produtos);

    double total = 0;  // começa zerado, vai somando

    int i;
    for (i = 0; i < produtos; i++) {
        int codigo, quantidade;
        double valor;

        scanf("%d %d", &codigo, &quantidade);

        switch (codigo) {
            case 1001: valor = 1.50; break;
            case 1002: valor = 2.50; break;
            case 1003: valor = 3.50; break;
            case 1004: valor = 4.50; break;
            case 1005: valor = 5.50; break;
        }

        total = total + (valor * quantidade);
    }

    printf("%.2f\n", total);

    return 0;
}