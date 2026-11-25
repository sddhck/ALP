#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO 100000
#define NUM_EXECUCOES 10

/*
 * 1. Bubble Sort (Método da Bolha):
 */
void bubbleSort(int *v, int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

/*
 * 2. Stone Sort (Método da Pedra / Sinking Sort):
 */
//void stoneSort(int *v, int n) {

//}

/*
 * 3. Insertion Sort (Ordenação por Inserção):
 */
//void insertionSort(int *v, int n) {

//}

/*
 * 4. Selection Sort (Ordenação por Seleção):
 */
//void selectionSort(int *v, int n) {

//}


/*
 * ============================================================================
 * FUNCOES AUXILIARES DE COMPARACAO (Para uso com qsort na preparacao dos vetores)
 * ============================================================================
 */
int comparaAscendente(const void *a, const void *b) {
    int valA = *(const int *)a;
    int valB = *(const int *)b;
    return (valA - valB);
}

int comparaDescendente(const void *a, const void *b) {
    int valA = *(const int *)a;
    int valB = *(const int *)b;
    return (valB - valA);
}

void imprimeVetor(int *v, int n) {
    for (int i = 0; i < n; i++) 
        printf("%d ", v[i]);
    
    printf("\n");
}

int main() {
    printf("===============================================================================\n");
    printf("       COMPARATIVO DE DESEMPENHO DOS ALGORITMOS DE ORDENACAO EM C              \n");
    printf("===============================================================================\n");
    printf("Tamanho dos vetores: %d inteiros\n", TAMANHO);
    printf("Repeticoes por cenario: %d vezes\n", NUM_EXECUCOES);
    printf("-------------------------------------------------------------------------------\n\n");

    // Alocação dinâmica de memória para evitar estouro da pilha (stack overflow)
    int *vetorAleatorio   = (int *)malloc(TAMANHO * sizeof(int));
    int *vetorAscendente  = (int *)malloc(TAMANHO * sizeof(int));
    int *vetorDescendente = (int *)malloc(TAMANHO * sizeof(int));
    int *vetorTrabalho    = (int *)malloc(TAMANHO * sizeof(int));

    if (!vetorAleatorio || !vetorAscendente || !vetorDescendente || !vetorTrabalho) {
        fprintf(stderr, "Erro ao alocar memoria para os vetores!\n");
        return 1;
    }

    // 1. Geração do vetor com 100.000 valores aleatórios
    srand((unsigned int)time(NULL));
    for (int i = 0; i < TAMANHO; i++) {
        // Gera valores inteiros positivos aleatórios
        vetorAleatorio[i] = rand() % 20;
    }

    // 2. Geração do vetor ascendente com os MESMOS dados
    memcpy(vetorAscendente, vetorAleatorio, TAMANHO * sizeof(int));
    qsort(vetorAscendente, TAMANHO, sizeof(int), comparaAscendente);

    // 3. Geração do vetor descendente com os MESMOS dados
    memcpy(vetorDescendente, vetorAleatorio, TAMANHO * sizeof(int));
    qsort(vetorDescendente, TAMANHO, sizeof(int), comparaDescendente);

    double tempoTotal = 0.0;
    for (int r = 0; r < NUM_EXECUCOES; r++) {
        // Copia os dados do vetor original para o vetor de trabalho
        // Isso garante que todas as repetições comecem com exatamente o mesmo estado
        memcpy(vetorTrabalho, vetorAleatorio, TAMANHO * sizeof(int));

        // Medição de tempo em milissegundos
        clock_t inicio = clock();
        bubbleSort(vetorTrabalho, TAMANHO);
        clock_t fim = clock();

        double tempoExecMs = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
        tempoTotal += tempoExecMs;

        //printf("  [Execucao %2d] Tempo: %10.2f ms\n", r + 1, tempoExecMs);
    }

    double mediaBsRand = tempoTotal / NUM_EXECUCOES;


    tempoTotal = 0.0;
    for (int r = 0; r < NUM_EXECUCOES; r++) {
        memcpy(vetorTrabalho, vetorAscendente, TAMANHO * sizeof(int));

        clock_t inicio = clock();
        bubbleSort(vetorTrabalho, TAMANHO);
        clock_t fim = clock();

        double tempoExecMs = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
        tempoTotal += tempoExecMs;

    }

    double mediaBsAsc = tempoTotal / NUM_EXECUCOES;

    tempoTotal = 0.0;
    for (int r = 0; r < NUM_EXECUCOES; r++) {
        memcpy(vetorTrabalho, vetorDescendente, TAMANHO * sizeof(int));

        clock_t inicio = clock();
        bubbleSort(vetorTrabalho, TAMANHO);
        clock_t fim = clock();

        double tempoExecMs = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
        tempoTotal += tempoExecMs;
    }

    double mediaBsDesc = tempoTotal / NUM_EXECUCOES;

    printf("============================================================================\n");
    printf(" Relatorio de testes!\n");
    printf("============================================================================\n");
    printf("Algoritmo                  | Aleatorio     | Crescente     | Decrescente   |\n");
    printf("===========================================================================\n");
    printf("Bubble Sort                | %10.2f ms | %10.2f ms | %10.2f ms |\n", mediaBsRand, mediaBsAsc, mediaBsDesc);
    printf("============================================================================\n");


    // Liberação de memória
    free(vetorAleatorio);
    free(vetorAscendente);
    free(vetorDescendente);
    free(vetorTrabalho);

    return 0;
}