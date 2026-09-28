#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 5

typedef struct {
    int fila[CAPACIDADE];
    int inicio;
    int total;
    int final;
}Fila;

void inicializar(Fila *f){
    f->inicio = 0;
    f->total = 0;
    f->final = 0;
}

int estaCheia(Fila *f){
    return f->total == CAPACIDADE;
}

 estaVazia(Fila *f){
    return f->total == 0;
}

void enfileirar(Fila *f, int valor){
    if (estaCheia(f)){
        printf("A FIA ESTA CHEIA");
        return;
    }

    f->fila[f->final] = valor;
    f->final = (f->final + 1) % CAPACIDADE;
    f->total++;
}

int desenfileirar(Fila *f){
    if(estaVazia(f)){
        printf("A FIA ESTA VAZIA");
        return;
    }
    int valor = f->fila[f->inicio];
    f->inicio = (f->inicio + 1) % CAPACIDADE;
    f->total--;
    return valor;
}

void imprimir(Fila *f){
    for (int i = 0; i < f->total; i++) {
        int idx = f->inicio + i;
        printf("[%d] ", f->fila[idx]);
    }
    printf("<- Fim\n");
}
