#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "tabela_hash.h"

unsigned int hash(const char *termo, int tamanhoTabela) {
    unsigned int hash = 0;
    while (*termo) {
        hash = (hash << 5) + *termo++;
    }
    return hash % tamanhoTabela;
}

void inicializarTabelaHash(TabelaHash *tabela, int tamanho) {
    tabela->tamanho = tamanho;
    tabela->quantidade = 0;
    tabela->itens = (ItemTabelaHash **)malloc(tamanho * sizeof(ItemTabelaHash *));
    for (int i = 0; i < tamanho; i++) {
        tabela->itens[i] = NULL;
    }
}

void redimensionarTabelaHash(TabelaHash *tabela) {
    // Dobrar o tamanho da tabela
    int novoTamanho = tabela->tamanho * 2;
    ItemTabelaHash **novosItens = (ItemTabelaHash **)malloc(novoTamanho * sizeof(ItemTabelaHash *));
    for (int i = 0; i < novoTamanho; i++) {
        novosItens[i] = NULL;
    }

    // Transferir itens da tabela antiga para a nova
    for (int i = 0; i < tabela->tamanho; i++) {
        ItemTabelaHash *item = tabela->itens[i];
        while (item != NULL) {
            ItemTabelaHash *proximo = item->proximo;
            unsigned int indice = hash(item->termo, novoTamanho);
            item->proximo = novosItens[indice];
            novosItens[indice] = item;
            item = proximo;
        }
    }

    // Liberar memória da tabela antiga
    free(tabela->itens);

    // Atualizar a tabela
    tabela->itens = novosItens;
    tabela->tamanho = novoTamanho;
}


// Funções para inserir e buscar termos na tabela hash
void inserirTermoTabelaHash(TabelaHash *tabela, const char *termo) {
    // Verificar se é necessário redimensionar a tabela
    if ((double)tabela->quantidade / tabela->tamanho > FATOR_CARGA_MAXIMO) {
        redimensionarTabelaHash(tabela);
    }

    // Calcular o índice do termo
    unsigned int indice = hash(termo, tabela->tamanho);
    ItemTabelaHash *item = tabela->itens[indice];
    
    // Verificar se o termo já existe na tabela
    while (item != NULL && strcmp(item->termo, termo) != 0) {
        item = item->proximo;
    }
    
    // Inserir o termo na tabela caso não exista
    if (item == NULL) {
        item = (ItemTabelaHash *)malloc(sizeof(ItemTabelaHash));
        strcpy(item->termo, termo);
        item->frequencia = 1;
        item->tfidf = 0.0;
        item->proximo = tabela->itens[indice];
        tabela->itens[indice] = item;
        tabela->quantidade++;
    } else {
        // Incrementar a frequência do termo caso ele já exista
        item->frequencia++;
    }
}

// Função para buscar um termo na tabela hash
ItemTabelaHash *buscarTermoTabelaHash(TabelaHash *tabela, const char *termo) {
    unsigned int indice = hash(termo, tabela->tamanho);
    ItemTabelaHash *item = tabela->itens[indice];
    
    while (item != NULL && strcmp(item->termo, termo) != 0) {
        item = item->proximo;
    }
    
    return item;
}