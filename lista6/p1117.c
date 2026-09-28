//SUBMISSÃO # 48762201
//Submissão: 27/04/2026 13:38:47

#include <stdio.h>

int main() {
    double nota_lida, soma = 0;
    int contador = 0;

    
    while (contador < 2) {
        if (scanf("%lf", &nota_lida) == EOF) break;

        if (nota_lida >= 0 && nota_lida <= 10) {
            soma += nota_lida;
            contador++;        
        } else {
            printf("nota invalida\n");
        }
    }

    
    double media = soma / 2.0;
    printf("media = %.2lf\n", media);

    return 0;
}