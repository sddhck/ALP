#include <stdio.h>
#include <stdlib.h>

#define MAX_TAG 64
#define TAM_CONTEUDO 256

typedef struct Nodo {
    char tag[MAX_TAG];
    int linha;
    struct Nodo *proximo;
}Nodo;

typedef struct {
    Nodo *topo;
    int total;
}Pilha;

Pilha *criar(void){
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));

    if (p == NULL){
        return NULL;
    }

    p->topo = NULL;
    p->total = 0;
    return p;
}

int tamanho(Pilha *p){
    return p->total;
}

int vazia(Pilha *p){
    return p->total == 0;
}

int empilhar(Pilha *p, char *tag, int linha){
    Nodo *novo = (Nodo *) malloc(sizeof(Nodo));

    if (novo == NULL){
        return 0;
    }

    int i;
    for (i = 0; tag[i] != '\0' && i < MAX_TAG - 1; i++){
        novo->tag[i] = tag[i];
    }
    novo->tag[i] = '\0';
    novo->linha = linha;

    novo->proximo = p->topo;
    p->topo = novo;
    p->total++;
    return 1;
}

int desempilhar(Pilha *p, char *tag, int *linha){
    if (vazia(p)){
        return 0;
    }

    Nodo *removido = p->topo;

    int i;
    for (i = 0; removido->tag[i] != '\0'; i++){
        tag[i] = removido->tag[i];
    }
    tag[i] = '\0';
    *linha = removido->linha;

    p->topo = removido->proximo;
    p->total--;
    free(removido);
    return 1;
}

void destruir(Pilha *p){
    while (p->topo != NULL){
        Nodo *removido = p->topo;
        p->topo = removido->proximo;
        free(removido);
    }

    free(p);
}

int iguais(char *a, char *b) {
    int i = 0;

    while (a[i] != '\0' && a[i] == b[i]) {
        i++;
    }

    return a[i] == b[i];
}

int ehLetra(int c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int ehEspaco(int c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int ehOrfa(char *nome) {
    if (iguais(nome, "br") == 1) {
        return 1;
    }

    if (iguais(nome, "hr") == 1) {
        return 1;
    }

    if (iguais(nome, "img") == 1) {
        return 1;
    }

    if (iguais(nome, "input") == 1) {
        return 1;
    }

    if (iguais(nome, "meta") == 1) {
        return 1;
    }

    if (iguais(nome, "link") == 1) {
        return 1;
    }

    return 0;
}

void lerTag(FILE *arquivo, char *conteudo, int *linha) {
    int c, n = 0;
    int penultimo = 0, ultimo = 0;

    conteudo[0] = '\0';

    while ((c = fgetc(arquivo)) != EOF) {
        if (c == '\n') {
            (*linha)++;
        }

        if (c == '>') {
            int comentario = (conteudo[0] == '!' && conteudo[1] == '-' && conteudo[2] == '-');

            if (comentario == 0 || (penultimo == '-' && ultimo == '-')) {
                break;
            }
        }

        if (n < TAM_CONTEUDO - 1) {
            conteudo[n] = c;
            n++;
            conteudo[n] = '\0';
        }

        penultimo = ultimo;
        ultimo = c;
    }
}

void extrairNome(char *conteudo, char *nome) {
    int i = 0;

    while (conteudo[i] != '\0' && ehEspaco(conteudo[i]) == 0 && conteudo[i] != '/' && i < MAX_TAG - 1) {
        nome[i] = conteudo[i];
        i++;
    }

    nome[i] = '\0';
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: %s arquivo.html\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", argv[1]);
        return 1;
    }

    Pilha *pilha = criar();

    if (pilha == NULL) {
        printf("Erro de memoria\n");
        fclose(arquivo);
        return 1;
    }

    char conteudo[TAM_CONTEUDO];
    char nome[MAX_TAG], topoNome[MAX_TAG];
    int topoLinha;
    int linha = 1, erro = 0;
    int c;

    while (erro == 0 && (c = fgetc(arquivo)) != EOF) {

        if (c == '\n') {
            linha++;
        }

        if (c == '<') {
            int proximo = fgetc(arquivo);
            ungetc(proximo, arquivo);

            if (ehLetra(proximo) == 1 || proximo == '/' || proximo == '!' || proximo == '?') {
                int linhaTag = linha;

                lerTag(arquivo, conteudo, &linha);

                if (conteudo[0] == '/') {
                    extrairNome(conteudo + 1, nome);

                    if (vazia(pilha)) {
                        printf("Mal formatado: Tag de fechamento </%s> inesperada na linha %d\n", nome, linhaTag);
                        erro = 1;
                    } else {
                        desempilhar(pilha, topoNome, &topoLinha);

                        if (iguais(topoNome, nome) == 0) {
                            printf("Mal formatado: Tag de fechamento </%s> inesperada na linha %d\n", nome, linhaTag);
                            erro = 1;
                        }
                    }
                } else if (conteudo[0] != '!' && conteudo[0] != '?') {
                    extrairNome(conteudo, nome);

                    int fim;
                    for (fim = 0; conteudo[fim] != '\0'; fim++) {
                    }

                    if (ehOrfa(nome) == 0 && conteudo[fim - 1] != '/') {
                        if (empilhar(pilha, nome, linhaTag) == 0) {
                            erro = 2;
                        }
                    }
                }
            }
        }
    }

    if (erro == 0) {
        if (vazia(pilha)) {
            printf("Bem formatado\n");
        } else {
            desempilhar(pilha, topoNome, &topoLinha);
            printf("Mal formatado: Tag <%s> aberta na linha %d não foi fechada\n", topoNome, topoLinha);
        }
    }

    if (erro == 2) {
        printf("Erro de memoria\n");
    }

    destruir(pilha);
    fclose(arquivo);

    return 0;
}