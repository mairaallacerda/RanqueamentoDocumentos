
# Ranqueamento de Documentos


<div align="center">
   <img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Ubuntu-orange?logo=ubuntu">
   <img align="center" height="20px" width="80px" src="https://img.shields.io/badge/VS%20Code-blue?logo=visual%20studio%20code"/>
   <img align="center" height="20px" width="80px" src="https://img.shields.io/badge/MakeFile-green?logo=make">
   <img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-darkblue?logo=c%2B%2B"/>
</div>

<details>
  <summary>📌 Tópicos</summary>
    <ol>
        <li><a href="#-introdução">Introdução</a></li>
        <li><a href="#-estrutura-de-dados-escolhida">Estruturas de Dados Escolhida</a></li>
        <li><a href="#-alternativas-possíveis">Alternativas Possíveis</a></li>
        <li><a href="#-justificativa-das-escolhas">Justificativa das Escolhas</a></li>
        <li><a href="#-descrição-detalhada-das-operações-implementadas-e-suas-complexidades">Descrição Detalhada das Operações Implementadas e Suas Complexidades</a></li>
        <li><a href="#-conclusão">Conclusão</a></li>
        <li><a href="#-ambiente-de-compilação">Ambiente de Compilação</a></li>
        <li><a href="#-makefile">MakeFile</a></li>
        <li><a href="#-contato">Contato</a></li>
        <li><a href="#-referências">Referências</a></li>
    </ol>
</details>

## 👋 Introdução 

A crescente disponibilidade de informações em formato digital tem tornado o processo de busca e recuperação de dados um desafio cada vez mais complexo. Com o aumento exponencial da quantidade de documentos disponíveis, torna-se essencial o desenvolvimento de sistemas que possam ranquear eficientemente os documentos com base em sua relevância para termos ou frases de pesquisa específicas. Nesse contexto, o algoritmo TF/IDF (Term Frequency - Inverse Document Frequency) surge como uma ferramenta amplamente utilizada para medir a relevância de documentos em relação a uma consulta, analisando tanto a frequência dos termos dentro de um documento quanto sua raridade no conjunto de documentos.

Este trabalho tem como objetivo implementar um sistema de ranqueamento de documentos utilizando o algoritmo TF/IDF, aplicando os conceitos estudados na disciplina de Algoritmos e Estrutura de Dados I, como listas, pilhas, filas, métodos de ordenação e tabelas hash. 

## Estruturas de Dados Escolhida 
 1. **Fila**:
  - Descrição: Utilizada para armazenar os termos presentes em cada documento durante a leitura e processamento.
  - Justificativa: A fila é uma estrutura de dados simples e eficiente para armazenar e processar termos em ordem de chegada. Ela permite a inserção e remoção de elementos em tempo constante O(1).
2. **Tabela Hash**:
  - Descrição: Utilizada para armazenar a frequência de cada termo em um documento e calcular o TF/IDF.
  - Justificativa: A tabela hash oferece acesso rápido aos elementos, com complexidade média de O(1) para inserção, busca e remoção. Isso é crucial para lidar com grandes volumes de dados textuais, onde a eficiência no acesso aos termos é essencial.
3. **QuickSort**:
  - Descrição: Utilizado para ordenar os documentos de acordo com a relevância calculada.
  - Justificativa: O QuickSort é um algoritmo de ordenação eficiente com complexidade média de O(n log n). Ele é adequado para ordenar os documentos com base na relevância, garantindo um desempenho eficiente.

### Alternativas Possíveis 
1. Lista Ligada:
  - Descrição: Poderia ser utilizada para armazenar os termos de cada documento.
  - Comparação: Embora a lista ligada permita inserções e remoções eficientes, a busca por termos específicos tem complexidade O(n), o que pode ser ineficiente para grandes conjuntos de dados. A tabela hash, por outro lado, oferece busca em tempo constante O(1).
2. Árvore Binária de Busca (BST):
  - Descrição: Poderia ser utilizada para armazenar os termos de cada documento de forma ordenada.
  - Comparação: A BST oferece busca, inserção e remoção com complexidade O(log n) em média. No entanto, em casos de desbalanceamento, a complexidade pode degradar para O(n). Árvores balanceadas, como AVL ou Red-Black, poderiam resolver esse problema, mas adicionam complexidade na implementação.
3. Árvore AVL:
  - Descrição: Uma árvore AVL é uma árvore binária de busca auto-balanceada.
  - Comparação: A árvore AVL garante complexidade O(log n) para busca, inserção e remoção, independentemente da ordem de inserção dos elementos. Isso poderia melhorar a eficiência em comparação com a lista ligada e a BST desbalanceada. No entanto, a implementação é mais complexa e pode ser excessiva para o problema atual, onde a tabela hash já oferece desempenho eficiente.

### Justificativa das Escolhas
  • Fila: Escolhida pela simplicidade e eficiência na inserção e remoção de termos durante o processamento dos documentos.
  • Tabela Hash: Escolhida pela eficiência no acesso e manipulação dos termos, permitindo cálculos rápidos de TF/IDF.
  • QuickSort: Escolhido pela eficiência na ordenação dos documentos com base na relevância, garantindo um desempenho adequado para o ranqueamento.


## Descrição Detalhada das Operações Implementadas e Suas Complexidades
1. **Leitura e Processamento dos Documentos** 
Função:(`processarDocumento`)
  • Descrição: Lê um documento, normaliza os termos (removendo pontuação, convertendo para minúsculas e removendo stop words) e armazena os termos em uma tabela hash.
  • Complexidade: O(n), onde n é o número de termos no documento. A leitura e normalização de cada termo é O(1), e a inserção na tabela hash é O(1) em média.
2. **Normalização de Termos** 
Função: (`processarTermo`)
  • escrição: Remove pontuação, converte para minúsculas e mantém apenas letras e caracteres acentuados.
  • Complexidade: O(m), onde m é o comprimento do termo.
3. **Verificação de Stop Words** 
Função: (`eStopword`)
  • Descrição: Verifica se um termo é uma stop word.
  • Complexidade: O(k), onde k é o número de stop words.
4. **Carregamento de Stop Words** 
Função: (`carregarStopwords`)
  • Descrição: Carrega as stop words de um arquivo.
  • Complexidade: O(k), onde k é o número de stop words.
5. **Inserção na Tabela Hash** 
Função: (`inserirTermoTabelaHash`)
  • Descrição: Insere um termo na tabela hash, redimensionando a tabela se necessário.
  • Complexidade: O(1) em média para inserção, O(n) para redimensionamento, onde n é o número de termos na tabela.
6. **Busca na Tabela Hash** (`buscarTermoTabelaHash`)
  • Descrição: Busca um termo na tabela hash.
  • Complexidade: O(1) em média.
7. **Cálculo do IDF** (`calcularIDF`)
  • Descrição: Calcula o Inverse Document Frequency (IDF) de um termo.
  • Complexidade: O(1).
8. **Cálculo do TF/IDF** (`calcularTFIDF`)
  • Descrição: Calcula o Term Frequency-Inverse Document Frequency (TF-IDF) para cada termo em cada documento.
  • Complexidade: O(n * m), onde n é o número de documentos e m é o número de termos em cada documento.
9. **Cálculo da Relevância do Documento** (`calcularRelevanciaDocumento`)
  • Descrição: Calcula a relevância de um documento para uma consulta, somando os valores de TF/IDF dos termos que aparecem na consulta.
  • Complexidade: O(m), onde m é o número de termos na consulta.
10. **Ordenação dos Documentos** (`ordenaDocumentosQuickSort`)
  • Descrição: Ordena os documentos de acordo com a relevância usando o algoritmo QuickSort.
  • Complexidade: O(n log n) em média, onde n é o número de documentos.
11. **Ranqueamento dos Documentos** (`ranquearDocumentos`)
  • Descrição: Calcula a relevância de cada documento para uma consulta e ordena os documentos de acordo com a relevância.
  • Complexidade: O(n * m + n log n), onde n é o número de documentos e m é o número de termos na consulta.

## Instruções de Compilação


## Exemplo de Entrada e Saída

### Exemplo 1
**Entrada**: Jesus e Maria e José  
**Saída**:  
```
1 - biblia.txt (relevancia: 0.00103054)
2 - quincas borba.txt (relevancia: 0.00075800)
3 -  DomCasmurro.txt (relevancia: 0.00063672)
4 -  Semana_Machado_Assis.txt (relevancia: 0.00018750)
5 -  terremoto.txt (relevancia: 0.00011235)
6 -  A mao e a luva.txt (relevancia: 0.00001287)
...
```
### Exemplo 2
**Entrada**: Dom casmurro e seu fiel escudeiro
**Saída**:  
```
1 -  DomCasmurro.txt (relevancia: 0.00026641)
2 -  biblia.txt (relevancia: 0.00014334)
3 -  quincas borba.txt (relevancia: 0.00006352)
4 -  A mao e a luva.txt (relevancia: 0.00005618)
5 -  Semana_Machado_Assis.txt (relevancia: 0.00002121)
6 -  terremoto.txt (relevancia: 0.00000000)
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
