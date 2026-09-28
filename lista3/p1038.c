//SUBMISSÃO # 48501255
//Submissão: 07/04/2026 20:56:33

#include <stdio.h>
 
int main() {
 
    int codigo, quantidade;
    double A = 4.00, B = 4.50, C = 5.00, D = 2.00, E = 1.50, total;

    scanf("%d %d", &codigo, &quantidade);

    if (codigo == 1) {
        total = A * quantidade;
    }

    if (codigo == 2) {
        total = B * quantidade;
    }

    if (codigo == 3) {
        total = C * quantidade;
    }

    if (codigo == 4) {
        total = D * quantidade;
    }

    if (codigo == 5) {
        total = E * quantidade;
    }

    printf("Total: R$ %.2f\n", total);

    return 0;
}