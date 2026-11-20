#include <stdio.h>
#include <stdlib.h>

int buscaPrimeiraPosicao(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho;

    while (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio;
        }
    }

    if (inicio < tamanho && vetor[inicio] == valor) {
        return inicio + 1;
    }

    return -1;
}

int posicaoInsercao(int vetor[], int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho;

    while (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio;
        }
    }

    return inicio;
}

void inserirOrdenado(int vetor[], int *tamanho, int valor) {
    int posicao = posicaoInsercao(vetor, *tamanho, valor);

    for (int i = *tamanho; i > posicao; i--) {
        vetor[i] = vetor[i - 1];
    }

    vetor[posicao] = valor;
    (*tamanho)++;
}

int main(void) {
    int n;
    int q;
    int caso = 1;

    while (scanf("%d %d", &n, &q) == 2 && (n != 0 || q != 0)) {
        int *marbles = malloc(n * sizeof(int));
        int tamanhoOrdenado = 0;

        for (int i = 0; i < n; i++) {
            int valor;
            scanf("%d", &valor);
            inserirOrdenado(marbles, &tamanhoOrdenado, valor);
        }

        printf("CASE# %d:\n", caso++);

        for (int i = 0; i < q; i++) {
            int consulta;
            scanf("%d", &consulta);

            int posicao = buscaPrimeiraPosicao(marbles, n, consulta);

            if (posicao != -1) {
                printf("%d found at %d\n", consulta, posicao);
            } else {
                printf("%d not found\n", consulta);
            }
        }

        free(marbles);
    }

    return 0;
}