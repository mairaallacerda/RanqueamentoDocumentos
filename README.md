
# 📄 Ranqueamento de Documentos

<div align="center">
   <img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Ubuntu-orange?logo=ubuntu">
   <img align="center" height="20px" width="80px" src="https://img.shields.io/badge/VS%20Code-blue?logo=visual%20studio%20code"/>
   <img align="center" height="20px" width="80px" src="https://img.shields.io/badge/MakeFile-green?logo=make">
   <img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-darkblue?logo=c%2B%2B"/>
</div>

---

<details>
  <summary>📌 Tópicos</summary>
  <ol>
    <li><a href="#-introdução">Introdução</a></li>
    <li><a href="#-estrutura-de-dados-escolhida">Estruturas de Dados Escolhida</a></li>
    <li><a href="#-alternativas-possíveis">Alternativas Possíveis</a></li>
    <li><a href="#-justificativa-das-escolhas">Justificativa das Escolhas</a></li>
    <li><a href="#-descrição-detalhada-das-operações-implementadas-e-suas-complexidades">Descrição Detalhada das Operações Implementadas e Suas Complexidades</a></li>
    <li><a href="#-exemplo-de-entrada-e-saída">Exemplo de Entrada e Saída</a></li>
    <li><a href="#-análise-dos-resultados">Análise dos Resultados</a></li>
    <li><a href="#-discussão-sobre-o-desempenho">Discussão sobre o Desempenho</a></li>
    <li><a href="#-conclusão">Conclusão</a></li>
    <li><a href="#-ambiente-de-compilação">Ambiente de Compilação</a></li>
    <li><a href="#-makefile">MakeFile</a></li>
    <li><a href="#-contato">Contato</a></li>

  </ol>
</details>

---

## 👋 Introdução 

A crescente disponibilidade de informações em formato digital tem tornado o processo de busca e recuperação de dados um desafio cada vez mais complexo. Com o aumento exponencial da quantidade de documentos disponíveis, torna-se essencial o desenvolvimento de sistemas que possam ranquear eficientemente os documentos com base em sua relevância para termos ou frases de pesquisa específicas. Nesse contexto, o algoritmo TF/IDF (Term Frequency - Inverse Document Frequency) surge como uma ferramenta amplamente utilizada para medir a relevância de documentos em relação a uma consulta, analisando tanto a frequência dos termos dentro de um documento quanto sua raridade no conjunto de documentos.

Este trabalho tem como objetivo implementar um sistema de ranqueamento de documentos utilizando o algoritmo TF/IDF, aplicando os conceitos estudados na disciplina de Algoritmos e Estrutura de Dados I, como listas, pilhas, filas, métodos de ordenação e tabelas hash. 

---

## 📂 Estrutura de Dados Escolhida

1. **Fila**:
   - **Descrição**: Armazena os termos presentes em cada documento durante a leitura e processamento.
   - **Justificativa**: Eficiência para armazenar e processar termos na ordem de chegada (complexidade `O(1)`).
   
2. **Tabela Hash**:
   - **Descrição**: Armazena a frequência de cada termo para cálculo de TF/IDF.
   - **Justificativa**: Acesso rápido com complexidade `O(1)`, essencial para grandes volumes de dados textuais.

3. **QuickSort**:
   - **Descrição**: Ordena os documentos por relevância.
   - **Justificativa**: Algoritmo eficiente (`O(n log n)`) para ordenação, adequado para ranqueamento dos documentos.

---

## 🔍 Alternativas Possíveis

1. **Lista Ligada** - Permite inserções e remoções eficientes, mas a busca tem complexidade `O(n)`.
2. **Árvore Binária de Busca (BST)** - Busca, inserção e remoção com complexidade média de `O(log n)`, porém pode degradar para `O(n)` em casos de desbalanceamento.
3. **Árvore AVL** - Garante `O(log n)` para operações principais, mas a implementação é mais complexa.

---

### 🔍 Justificativa das Escolhas

- **Fila**: Escolhida pela simplicidade e eficiência na inserção e remoção de termos durante o processamento dos documentos.
- **Tabela Hash**: Escolhida pela eficiência no acesso e manipulação dos termos, permitindo cálculos rápidos de TF/IDF.
- **QuickSort**: Escolhido pela eficiência na ordenação dos documentos com base na relevância, garantindo um desempenho adequado para o ranqueamento.



## 📝 Descrição Detalhada das Operações Implementadas e Suas Complexidades

1. **Leitura e Processamento dos Documentos**  
   **Função:** `processarDocumento`  
   - **Descrição:** Lê um documento, normaliza os termos (removendo pontuação, convertendo para minúsculas e removendo stop words) e armazena os termos em uma tabela hash.  
   - **Complexidade:** O(n), onde n é o número de termos no documento. A leitura e normalização de cada termo é O(1), e a inserção na tabela hash é O(1) em média.

2. **Normalização de Termos**  
   **Função:** `processarTermo`  
   - **Descrição:** Remove pontuação, converte para minúsculas e mantém apenas letras e caracteres acentuados.  
   - **Complexidade:** O(m), onde m é o comprimento do termo.

3. **Verificação de Stop Words**  
   **Função:** `eStopword`  
   - **Descrição:** Verifica se um termo é uma stop word.  
   - **Complexidade:** O(k), onde k é o número de stop words.

4. **Carregamento de Stop Words**  
   **Função:** `carregarStopwords`  
   - **Descrição:** Carrega as stop words de um arquivo.  
   - **Complexidade:** O(k), onde k é o número de stop words.

5. **Inserção na Tabela Hash**  
   **Função:** `inserirTermoTabelaHash`  
   - **Descrição:** Insere um termo na tabela hash, redimensionando a tabela se necessário.  
   - **Complexidade:** O(1) em média para inserção, O(n) para redimensionamento, onde n é o número de termos na tabela.

6. **Busca na Tabela Hash**  
   **Função:** `buscarTermoTabelaHash`  
   - **Descrição:** Busca um termo na tabela hash.  
   - **Complexidade:** O(1) em média.

7. **Cálculo do IDF**  
   **Função:** `calcularIDF`  
   - **Descrição:** Calcula o Inverse Document Frequency (IDF) de um termo.  
   - **Complexidade:** O(1).

8. **Cálculo do TF/IDF**  
   **Função:** `calcularTFIDF`  
   - **Descrição:** Calcula o Term Frequency-Inverse Document Frequency (TF-IDF) para cada termo em cada documento.  
   - **Complexidade:** O(n * m), onde n é o número de documentos e m é o número de termos em cada documento.

9. **Cálculo da Relevância do Documento**  
   **Função:** `calcularRelevanciaDocumento`  
   - **Descrição:** Calcula a relevância de um documento para uma consulta, somando os valores de TF/IDF dos termos que aparecem na consulta.  
   - **Complexidade:** O(m), onde m é o número de termos na consulta.

10. **Ordenação dos Documentos**  
    **Função:** `ordenaDocumentosQuickSort`  
    - **Descrição:** Ordena os documentos de acordo com a relevância usando o algoritmo QuickSort.  
    - **Complexidade:** O(n log n) em média, onde n é o número de documentos.

11. **Ranqueamento dos Documentos**  
    **Função:** `ranquearDocumentos`  
    - **Descrição:** Calcula a relevância de cada documento para uma consulta e ordena os documentos de acordo com a relevância.  
    - **Complexidade:** O(n * m + n log n), onde n é o número de documentos e m é o número de termos na consulta.


## 💡 Exemplo de Entrada e Saída

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



## 📊 Análise dos Resultados

Após o desenvolvimento, foram adicionados métricas para avaliar o consumo de memória e o tempo de processamento da aplicação. A imagem abaixo retrata as saídas de uma pesquisa e em seguida, uma discussão sobre os resultados.

![Saída de Uma Pesquisa](Imagens/exemplo.png)

1. Processamento dos Documentos
- **Tempo de Execução**:
  - O tempo de execução varia de 0.004 segundos a 0.658 segundos, dependendo do tamanho do documento.
  - Documentos maiores, como "biblia.txt", levam mais tempo para serem processados.
- **Uso de Memória**:
  - O uso de memória estimado para a tabela hash varia de 0.10 MB a 3.45 MB.
  - Documentos com mais termos requerem mais memória para armazenar a tabela hash.

2. Cálculo do TFIDF
- **Tempo de Execução**:
  - O tempo de execução total para o cálculo de TFIDF foi de 0.057 segundos.
  - O tempo de execução é eficiente, considerando o número de termos processados.

3. Pesquisa e Ranqueamento
- **Tempo de Execução**:
  - O tempo de execução para o cálculo de relevância e ordenação foi insignificante (0.000 segundos).
  - Isso indica que o sistema é muito eficiente para consultas rápidas.
- **Uso de Memória**:
  - O uso de memória estimado para os documentos foi de 0.00306702 MB.
  - Isso é esperado, pois estamos apenas armazenando informações básicas sobre cada documento.

---

### 📈 Discussão sobre o Desempenho

#### Tempo de Execução
- **Leitura e Processamento dos Documentos**:
  - O tempo de execução é proporcional ao tamanho do documento.
  - Documentos maiores levam mais tempo para serem processados, o que é esperado.
- **Cálculo do TFIDF**:
  - O tempo de execução é eficiente, considerando o número de termos processados.
  - A utilização de tabelas hash ajuda a manter o tempo de execução baixo.
- **Pesquisa e Ranqueamento**:
  - O tempo de execução para consultas é insignificante, indicando que o sistema é muito eficiente para consultas rápidas.
  - A utilização de QuickSort para ordenação garante um desempenho eficiente.

#### Uso de Memória
- **Tabelas Hash**:
  - O uso de memória é proporcional ao número de termos no documento.
  - Documentos maiores requerem mais memória para armazenar a tabela hash.
- **Documentos**:
  - O uso de memória para armazenar informações básicas sobre cada documento é baixo, o que já era esperado.


## Conclusão

Os resultados mostram que o sistema é eficiente tanto em termos de tempo de execução quanto de uso de memória. A utilização de tabelas hash e QuickSort garante um desempenho eficiente para o processamento de documentos e consultas rápidas. No entanto, há espaço para melhorias, especialmente para documentos muito grandes, onde o uso de memória pode ser otimizado. Além disso, seria importante realizar testes com um número maior de documentos, para que fosse possível constatar melhor o tempo de ordenação com uma lista maior de documentos. 

## 🔨 Ambiente de Compilação

A seguir estão os detalhes do ambiente de compilação onde o programa foi executado:

| Componente           | Detalhes                                  |
|----------------------|-------------------------------------------|
| Sistema Operacional  | Ubuntu 22.04.4 LTS - 64 bits              |
| Modelo do hardware   | Lenovo Ideapad 3                          |
| Processador          | AMD® Ryzen 7 5700u                        |
| Memória RAM          | 8 GB                                      |
| Armazenamento        | 512 GB SSD                                |
| IDE                  | Visual Studio Code                        |



## ⛏ Makefile

O Makefile é um utilitário que automatiza o processo de compilação e execução de programas. Aqui estão os principais comandos do Makefile para este projeto:

| Comando      | Descrição                               |
|--------------|-----------------------------------------|
| `make`       | Compila o programa.                     |
| `make run`   | Executa o programa com o arquivo de entrada fornecido. |
| `make clean` | Remove os arquivos compilados.          |


## 📧 Contato

Para mais informações ou sugestões, sinta-se à vontade para entrar em contato:

- ✉️ **E-mail**: [![Gmail Badge](https://img.shields.io/badge/-mairaallacerda@gmail.com-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:mairaallacerda@gmail.com)](mailto:mairaallacerda@gmail.com)
- 📸 **Instagram**: [![Instagram Badge](https://img.shields.io/badge/-Instagram-e4405f?style=flat-square&logo=Instagram&logoColor=white)](https://www.instagram.com/mairaallacerda/)
