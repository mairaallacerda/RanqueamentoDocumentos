
Ranqueamento de Documentos

Este projeto implementa um sistema de ranqueamento de documentos baseado no cálculo de relevância TF/IDF.

## Estruturas de Dados Escolhida 

- **Fila**: Armazena termos presentes em cada documento durante a leitura.
- **Tabela Hash**: Armazena a frequência de cada termo para calcular TF/IDF.
- **QuickSort**: Ordena os documentos conforme a relevância.

### Alternativas Consideradas

- **Lista Ligada**: Ineficiente para buscas rápidas em grandes conjuntos de dados.
- **Árvore Binária de Busca (BST)**: Complexidade degradada em árvores desbalanceadas.
- **Árvore AVL**: Complexidade adicional na implementação, não justificada pelo contexto.

## Operações e Complexidades

1. **Processamento de Documentos** (`processarDocumento`): O(n)
2. **Normalização de Termos** (`processarTermo`): O(m)
3. **Verificação de Stop Words** (`eStopword`): O(k)
4. **Carregamento de Stop Words** (`carregarStopwords`): O(k)
5. **Inserção na Tabela Hash** (`inserirTermoTabelaHash`): O(1) em média
6. **Busca na Tabela Hash** (`buscarTermoTabelaHash`): O(1) em média
7. **Cálculo do IDF** (`calcularIDF`): O(1)
8. **Cálculo do TF/IDF** (`calcularTFIDF`): O(n * m)
9. **Cálculo da Relevância do Documento** (`calcularRelevanciaDocumento`): O(m)
10. **Ordenação dos Documentos** (`ordenaDocumentosQuickSort`): O(n log n)
11. **Ranqueamento dos Documentos** (`ranquearDocumentos`): O(n * m + n log n)

## Instruções de Compilação

### Windows
```bash
cd src
gcc -o ../ranqueamento main.c fila.c documento.c tabela_hash.c
```

### Linux
```bash
make
./build/app
```

## Exemplo de Entrada e Saída

### Exemplo 1
**Entrada**: Jesus e Maria e José  
**Saída**:  
```
1 - biblia.txt (relevancia: 0.00103054)
2 - quincas borba.txt (relevancia: 0.00075800)
...
```

## Análise de Desempenho

- **Tempo de Execução**:
  - **Processamento de Documentos**: Proporcional ao tamanho do documento.
  - **Cálculo de TFIDF**: Eficiência em termos de tempo.
  - **Pesquisa e Ranqueamento**: Insignificante, permitindo consultas rápidas.
  
- **Uso de Memória**:
  - **Tabelas Hash**: Proporcional ao número de termos.
  - **Documentos**: Memória baixa para armazenar informações essenciais.

## Conclusão

O sistema é eficiente em termos de tempo e uso de memória, com desempenho otimizado para consultas rápidas.
