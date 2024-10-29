#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "fila.h"

void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

void enfileirar(Fila *fila, const char *termo) {
    Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo));
    strcpy(novoNodo->termo, termo);
    novoNodo->proximo = NULL;
    if (fila->fim == NULL) {
        fila->inicio = novoNodo;
        fila->fim = novoNodo;
    } else {
        fila->fim->proximo = novoNodo;
        fila->fim = novoNodo;
    }
    fila->tamanho++;
}

char *desenfileirar(Fila *fila) {
    if (fila->inicio == NULL) {
        fprintf(stderr, "Erro: Fila vazia\n");
        exit(EXIT_FAILURE);
    }
    Nodo *nodoRemovido = fila->inicio;
    char *termo = (char *)malloc(TAMANHO_MAX_TERMO * sizeof(char));
    strcpy(termo, nodoRemovido->termo);
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    free(nodoRemovido);
    fila->tamanho--;
    return termo;
}

int filaVazia(Fila *fila) {
    return fila->tamanho == 0;
}