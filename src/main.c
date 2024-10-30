#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "documento.h"
#include "fila.h"
#include "tabela_hash.h"
#include "config.h"

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");  // Definir localidade para português

    // Carregar stopwords
    //printf("Carregando stopwords...\n");
    char stopwords[QUANT_MAX_STOPWORDS][TAMANHO_MAX_TERMO];
    char caminhoStopwords[256];
    strcpy(caminhoStopwords, DIRETORIO_DOCUMENTOS);
    strcat(caminhoStopwords, "stopwords.txt");
    int quantidadeStopwords = carregarStopwords(stopwords, caminhoStopwords);


    // Lista de arquivos de documentos
    const char *arquivos[] = {"A mao e a luva.txt", "biblia.txt", "DomCasmurro.txt", "quincas borba.txt", "Semana_Machado_Assis.txt", "terremoto.txt"};
    const int numDocumentos = sizeof(arquivos) / sizeof(arquivos[0]);

    // Carregar e processar documentos
    printf("Inicializando Documentos...\n");
    Documento documentos[numDocumentos];
    for (int i = 0; i < numDocumentos; i++) {
        char caminhoCompleto[256];
        strcpy(caminhoCompleto, DIRETORIO_DOCUMENTOS);
        strcat(caminhoCompleto, arquivos[i]);
        strcpy(documentos[i].nomeArquivo, arquivos[i]);
        inicializarTabelaHash(&documentos[i].termos, TAMANHO_INICIAL_TABELA_HASH);
        documentos[i].totalTermos = 0;
        processarDocumento(caminhoCompleto, &documentos[i].termos, stopwords, quantidadeStopwords, &documentos[i].totalTermos);
    }

    calcularTFIDF(documentos, numDocumentos);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Pesquisar termo\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");

        int opcao;
        scanf("%d", &opcao);
        getchar();  // Limpa o buffer de entrada

        if (opcao == 1) {
            char consulta[512];
            printf("Digite a frase de pesquisa: ");
            fgets(consulta, sizeof(consulta), stdin);
            consulta[strcspn(consulta, "\n")] = 0;  // Remove o caractere de nova linha

            ranquearDocumentos(documentos, numDocumentos, consulta);
        } else if (opcao == 2) {
            printf("Saindo do programa.\n");
            break;
        } else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}
