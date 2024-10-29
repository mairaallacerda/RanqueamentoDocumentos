#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#include "config.h"

typedef struct ItemTabelaHash {
    char termo[TAMANHO_MAX_TERMO];
    int frequencia;
    double tfidf;
    struct ItemTabelaHash *proximo;
} ItemTabelaHash;

typedef struct {
    ItemTabelaHash **itens;
    int tamanho;
    int quantidade;
} TabelaHash;

void inicializarTabelaHash(TabelaHash *tabela, int tamanho);
void redimensionarTabelaHash(TabelaHash *tabela);
void inserirTermoTabelaHash(TabelaHash *tabela, const char *termo);
ItemTabelaHash *buscarTermoTabelaHash(TabelaHash *tabela, const char *termo);
unsigned int hash(const char *termo, int tamanhoTabela);

#endif // TABELA_HASH_H