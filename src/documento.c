#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "config.h"
#include "documento.h"
#include "fila.h"
#include "tabela_hash.h"

void processarTermo(char *termo) {
    int i = 0, j = 0;
    while (termo[i]) {
        if (isalpha((unsigned char)termo[i])) {  // Manter apenas letras e caracteres acentuados
            termo[j++] = tolower((unsigned char)termo[i]);  // Converter para minúsculas
        }
        i++;
    }
    termo[j] = '\0';  // Finalizar string
}

// Funções para stopwords
int eStopword(const char *termo, char stopwords[][TAMANHO_MAX_TERMO], int quantidadeStopwords) {
    for (int i = 0; i < quantidadeStopwords; i++) {
        if (strcmp(termo, stopwords[i]) == 0) {
            return 1;  // É stopword
        }
    }
    return 0;  // Não é stopword
}

int carregarStopwords(char stopwords[][TAMANHO_MAX_TERMO], const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir arquivo de stopwords");
        return 0;
    }

    int quantidade = 0;
    while (fscanf(arquivo, "%s", stopwords[quantidade]) != EOF && quantidade < QUANT_MAX_STOPWORDS) {
        quantidade++;
    }

    fclose(arquivo);
    return quantidade;  // Retorna o número de stopwords
}

// Função para processar um documento e gerar tabela hash
void processarDocumento(const char *nomeArquivo, TabelaHash *tabela, char stopwords[][TAMANHO_MAX_TERMO], int quantidadeStopwords, int *totalTermos) {
    printf("Processando documento: %s\n", nomeArquivo);

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir documento");
        return;
    }

    Fila fila;
    inicializarFila(&fila);

    char palavra[TAMANHO_MAX_TERMO];
    while (fscanf(arquivo, "%s", palavra) != EOF) {
        processarTermo(palavra);  // Limpa e normaliza o termo
        if (strlen(palavra) > 0 && !eStopword(palavra, stopwords, quantidadeStopwords)) {
            enfileirar(&fila, palavra);  // Adiciona o termo na fila
            (*totalTermos)++;  // Incrementa o contador de termos
        }
    }

    fclose(arquivo);

    // Transferir termos da fila para a tabela hash
    while (!filaVazia(&fila)) {
        char *termo = desenfileirar(&fila);
        inserirTermoTabelaHash(tabela, termo);
        free(termo);
    }
}

// Funçoes para calcular o IDF e o TFIDF
double calcularIDF(int totalDocumentos, int documentosComTermo) {
    if (documentosComTermo == 0) {
        return log((double)totalDocumentos + 1);
    }
    return log((double)(totalDocumentos + 1) / (documentosComTermo + 1));
}

void calcularTFIDF(Documento *documentos, int numDocumentos) {
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < numDocumentos; i++) {
        printf("Calculando TFIDF: %s com %d termos\n", documentos[i].nomeArquivo, documentos[i].totalTermos);
        TabelaHash *termosDoc = &documentos[i].termos;

        for (int j = 0; j < termosDoc->tamanho; j++) {
            ItemTabelaHash *item = termosDoc->itens[j];
            while (item != NULL) {
                int documentosComTermo = 0;
                for (int k = 0; k < numDocumentos; k++) {
                    TabelaHash *termosOutroDoc = &documentos[k].termos;
                    ItemTabelaHash *outroItem = buscarTermoTabelaHash(termosOutroDoc, item->termo);
                    if (outroItem != NULL) {
                        documentosComTermo++;
                    }
                }

                double idf = calcularIDF(numDocumentos, documentosComTermo);
                double tf = (double)item->frequencia / documentos[i].totalTermos;
                item->tfidf = tf * idf;

                item = item->proximo;
            }
        }
    }
    printf("--------------------------------------------------------------------------------\n");
}

// Função para calcular a relevância de um documento para uma consulta
double calcularRelevanciaDocumento(Documento *doc, const char consulta[]) {
    char palavra[TAMANHO_MAX_TERMO];
    double relevancia = 0.0;

    const char *delimitador = " ";
    char *token = strtok(strdup(consulta), delimitador);

    while (token != NULL) {
        strcpy(palavra, token);
        processarTermo(palavra);  // Normalizar o termo

        ItemTabelaHash *item = buscarTermoTabelaHash(&doc->termos, palavra);
        if (item != NULL) {
            relevancia += item->tfidf;
        }

        token = strtok(NULL, delimitador);
    }

    return relevancia;
}

// Função para trocar dois documentos
void trocaDocumentos(Documento *a, Documento *b) {
    Documento temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição para o QuickSort
int particionaDocumentos(Documento documentos[], int baixo, int alto) {
    double pivo = documentos[alto].relevancia;
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (documentos[j].relevancia > pivo) {
            i++;
            trocaDocumentos(&documentos[i], &documentos[j]);
        }
    }
    trocaDocumentos(&documentos[i + 1], &documentos[alto]);
    return (i + 1);
}

// Função QuickSort
void ordenaDocumentosQuickSort(Documento documentos[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionaDocumentos(documentos, baixo, alto);

        ordenaDocumentosQuickSort(documentos, baixo, pi - 1);
        ordenaDocumentosQuickSort(documentos, pi + 1, alto);
    }
}

// Função para ranquear documentos
void ranquearDocumentos(Documento *documentos, int numDocumentos, const char *consulta) {
    for (int i = 0; i < numDocumentos; i++) {
        documentos[i].relevancia = calcularRelevanciaDocumento(&documentos[i], consulta);
    }

    // Ordenar os documentos usando QuickSort
    ordenaDocumentosQuickSort(documentos, 0, numDocumentos - 1);

    printf("\nDocumentos ranqueados para a pesquisa '%s':\n\n", consulta);
    for (int i = 0; i < numDocumentos; i++) {
        printf("%d -  %s (relevancia: %.8f)\n", (i+1), documentos[i].nomeArquivo, documentos[i].relevancia);
    }
}