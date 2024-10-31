#ifndef DOCUMENTO_H
#define DOCUMENTO_H

#include "tabela_hash.h"
#include "config.h"

typedef struct {
    char nomeArquivo[512];
    TabelaHash termos;
    int totalTermos;  
    double relevancia;  
} Documento;

void processarDocumento(const char *nomeArquivo, TabelaHash *tabela, char stopwords[][TAMANHO_MAX_TERMO], int quantidadeStopwords, int *totalTermos);
double calcularIDF(int totalDocumentos, int documentosComTermo);
void calcularTFIDF(Documento *documentos, int numDocumentos);
double calcularRelevanciaDocumento(Documento *doc, const char consulta[]);
void ranquearDocumentos(Documento *documentos, int numDocumentos, const char *consulta);
void ordenaDocumentosQuickSort(Documento documentos[], int baixo, int alto);
int particionaDocumentos(Documento documentos[], int baixo, int alto);
int carregarStopwords(char stopwords[][TAMANHO_MAX_TERMO], const char *nomeArquivo);
void trocaDocumentos(Documento *a, Documento *b);

#endif // DOCUMENTO_H