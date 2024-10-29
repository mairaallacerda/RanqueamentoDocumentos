#ifndef FILA_H
#define FILA_H

#include "config.h"

typedef struct Nodo {
    char termo[TAMANHO_MAX_TERMO];
    struct Nodo *proximo;
} Nodo;

typedef struct {
    Nodo *inicio;
    Nodo *fim;
    int tamanho;
} Fila;

void inicializarFila(Fila *fila);
void enfileirar(Fila *fila, const char *termo);
char *desenfileirar(Fila *fila);
int filaVazia(Fila *fila);

#endif // FILA_H