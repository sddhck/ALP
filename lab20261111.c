#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO 20000
#define NUM_EXECUCOES 10
#define NUM_METODOS 7

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

void bubbleSortFlag(int *v, int n) {
    int i, j, temp;
    int trocou;

    for (i = 0; i < n - 1; i++) {
        trocou = 0;

        for (j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = 1;
            }
        }

        if (trocou == 0) {
            break;
        }
    }
}

void bubbleSortUltimaTroca(int *v, int n) {
    int j, temp;
    int limite = n - 1;
    int ultimaTroca;

    while (limite > 0) {
        ultimaTroca = 0;

        for (j = 0; j < limite; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                ultimaTroca = j;
            }
        }

        limite = ultimaTroca;
    }
}

void bubbleSortCocktail(int *v, int n) {
    int j, temp;
    int inicio = 0;
    int fim = n - 1;
    int trocou = 1;

    while (trocou == 1 && inicio < fim) {
        trocou = 0;

        for (j = inicio; j < fim; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = 1;
            }
        }
        fim--;

        for (j = fim; j > inicio; j--) {
            if (v[j - 1] > v[j]) {
                temp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = temp;
                trocou = 1;
            }
        }
        inicio++;
    }
}

/*
 * 2. Stone Sort (Método da Pedra / Sinking Sort):
 */
void stoneSort(int *v, int n) {
    int i, j, temp;
    int trocou;

    for (i = 0; i < n - 1; i++) {
        trocou = 0;

        for (j = n - 1; j > i; j--) {
            if (v[j] < v[j - 1]) {
                temp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = temp;
                trocou = 1;
            }
        }

        if (trocou == 0) {
            break;
        }
    }
}

/*
 * 3. Insertion Sort (Ordenação por Inserção):
 */
void insertionSort(int *v, int n) {
    int i, j, chave;

    for (i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = chave;
    }
}

/*
 * 4. Selection Sort (Ordenação por Seleção):
 */
void selectionSort(int *v, int n) {
    int i, j, posMenor, temp;

    for (i = 0; i < n - 1; i++) {
        posMenor = i;

        for (j = i + 1; j < n; j++) {
            if (v[j] < v[posMenor]) {
                posMenor = j;
            }
        }

        if (posMenor != i) {
            temp = v[posMenor];
            v[posMenor] = v[i];
            v[i] = temp;
        }
    }
}


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

int estaOrdenado(int *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            return 0;
        }
    }

    return 1;
}

void executaMetodo(int metodo, int *v, int n) {
    if (metodo == 0) {
        bubbleSort(v, n);
    } else if (metodo == 1) {
        bubbleSortFlag(v, n);
    } else if (metodo == 2) {
        bubbleSortUltimaTroca(v, n);
    } else if (metodo == 3) {
        bubbleSortCocktail(v, n);
    } else if (metodo == 4) {
        stoneSort(v, n);
    } else if (metodo == 5) {
        insertionSort(v, n);
    } else if (metodo == 6) {
        selectionSort(v, n);
    }
}

double medirTempo(int metodo, int *original, int *trabalho, int n) {
    double tempoTotal = 0.0;

    for (int r = 0; r < NUM_EXECUCOES; r++) {
        // Copia os dados do vetor original para o vetor de trabalho
        // Isso garante que todas as repetições comecem com exatamente o mesmo estado
        memcpy(trabalho, original, n * sizeof(int));

        // Medição de tempo em milissegundos
        clock_t inicio = clock();
        executaMetodo(metodo, trabalho, n);
        clock_t fim = clock();

        if (estaOrdenado(trabalho, n) == 0) {
            printf("ERRO: o metodo %d nao ordenou o vetor!\n", metodo);
        }

        double tempoExecMs = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
        tempoTotal += tempoExecMs;
    }

    return tempoTotal / NUM_EXECUCOES;
}

int main() {
    printf("===============================================================================\n");
    printf("       COMPARATIVO DE DESEMPENHO DOS ALGORITMOS DE ORDENACAO EM C              \n");
    printf("===============================================================================\n");
    printf("Tamanho dos vetores: %d inteiros\n", TAMANHO);
    printf("Repeticoes por cenario: %d vezes\n", NUM_EXECUCOES);
    printf("-------------------------------------------------------------------------------\n\n");

    char *nomes[NUM_METODOS] = {
        "Bubble Sort (original)",
        "Bubble Sort (flag)",
        "Bubble Sort (ult. troca)",
        "Bubble Sort (cocktail)",
        "Stone Sort",
        "Insertion Sort",
        "Selection Sort"
    };

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

    printf("============================================================================\n");
    printf(" Relatorio de testes!\n");
    printf("============================================================================\n");
    printf("Algoritmo                  | Aleatorio     | Crescente     | Decrescente   |\n");
    printf("============================================================================\n");

    for (int m = 0; m < NUM_METODOS; m++) {
        double mediaRand = medirTempo(m, vetorAleatorio, vetorTrabalho, TAMANHO);
        double mediaAsc = medirTempo(m, vetorAscendente, vetorTrabalho, TAMANHO);
        double mediaDesc = medirTempo(m, vetorDescendente, vetorTrabalho, TAMANHO);

        printf("%-26s | %10.2f ms | %10.2f ms | %10.2f ms |\n", nomes[m], mediaRand, mediaAsc, mediaDesc);
        fflush(stdout);
    }

    printf("============================================================================\n");


    // Liberação de memória
    free(vetorAleatorio);
    free(vetorAscendente);
    free(vetorDescendente);
    free(vetorTrabalho);

    return 0;
}


/*===============================================================================
       COMPARATIVO DE DESEMPENHO DOS ALGORITMOS DE ORDENACAO EM C              
===============================================================================
Tamanho dos vetores: 20000 inteiros
Repeticoes por cenario: 10 vezes
-------------------------------------------------------------------------------

============================================================================
 Relatorio de testes!
============================================================================
Algoritmo                  | Aleatorio     | Crescente     | Decrescente   |
============================================================================
Bubble Sort (original)     |     713.02 ms |     324.80 ms |     514.79 ms |
Bubble Sort (flag)         |     722.42 ms |       0.03 ms |     521.35 ms |
Bubble Sort (ult. troca)   |     692.93 ms |       0.03 ms |     504.03 ms |
Bubble Sort (cocktail)     |     571.02 ms |       0.06 ms |     497.03 ms |
Stone Sort                 |     819.78 ms |       0.03 ms |     505.04 ms |
Insertion Sort             |     121.41 ms |       0.04 ms |     249.32 ms |
Selection Sort             |     222.15 ms |     216.80 ms |     252.76 ms |
============================================================================*/