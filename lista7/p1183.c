//SUBMISSÃO # 49257851
//Submissão: 08/06/2026 17:01:10

#include <stdio.h>

int main(void) {
    /*variaveis*/
    char operacao;
    double matriz[12][12], soma = 0.0;
    int elementos = 0;
    /*leitura da operação*/
    scanf("%c", &operacao);
    /*ler elementos da matriz*/
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            scanf("%lf", &matriz[i][j]);

            if(j > i){
                soma += matriz[i][j];
                elementos++;
            }
        }
    }
        double media = soma / elementos;

        if(operacao == 'S') {
            printf("%.1lf\n", soma);
        }
        if(operacao == 'M') {
            printf("%.1lf\n", media);
        }
    return 0;
}