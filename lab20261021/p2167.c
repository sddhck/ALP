#include <stdio.h>

int encontrarqueda(int tamanho, int medidas[tamanho]){
    int queda = 0;
    for(int i = 1; i < tamanho; i++){
        int atual = medidas[i];
        int anterior = medidas[i-1];
        if(atual < anterior){
            queda = i + 1;
            break;
        }
    }
    return queda;
}

int main(void){
    int tamanho;
    scanf("%d", &tamanho);
    int vetor[tamanho];
    for(int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }
    int diminuicao = encontrarqueda(tamanho, vetor);
    printf("%d\n", diminuicao);

    return 0;
}