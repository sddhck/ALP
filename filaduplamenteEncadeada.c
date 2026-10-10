#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODO {
    int valor;
    struct NODO *proximo;
    struct NODO *anterior;
}NODO;

void inserirInicio(NODO **inicio, int valor){
    NODO *novo = (NODO*) mallor(sizeof(NODO));
    if (novo == NULL){
        printf("ERRO COM ALOCACAO");
        return;
    }
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = *inicio;

    if (*inicio != NULL){
        (*inicio)->anterior = novo;
    }
    *inicio = novo;
}

void inserirFim(NODO **inicio, int valor){
    NODO *novo = (NODO*) malloc(sizeof(NODO));
    if (novo == NULL){
        printf("ERRO DE ALOCACAO");
        return;
    }
    novo->valor = valor;
    novo->proximo = NULL;

    if(*inicio == NULL){
        inserirInicio(*inicio, valor);
        return;
    }
    NODO *atual = *inicio;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->proximo = novo;
    novo->anterior = atual;
}

void inserirPosicao(NODO **inicio, int valor, int pos){
    if (pos == 0){
        inserirInicio(inicio, valor);
        return;
    }

    NODO *atual = *inicio;
    int indicie = 0;

    while(atual != NULL && indicie < pos){
        atual = atual->proximo;
        indicie++;
    }

    if(atual = NULL){
        printf("POSICAO INVALIDA!");
        return;
    }

    NODO *novo = (NODO*) malloc(sizeof(NODO));
    novo->valor = valor;

    novo->proximo = atual;
    novo->anterior = atual->anterior;

    if(atual->anterior != NULL){
        atual->anterior->proximo = novo;
    }
    atual->anterior = novo;
}