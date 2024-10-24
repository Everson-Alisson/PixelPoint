<img width=100% src="https://capsule-render.vercel.app/api?type=waving&height=120&color=FFFFFF"/>

[![Typing SVG](https://readme-typing-svg.herokuapp.com/?color=FFFFFF&size=35&center=true&vCenter=true&width=1000&lines=PixelPoint;Éverson+Alisson,+Nattan+Ferreira,;Pedro+Lucas+e+Rubens+Alexandre+:%29)](https://git.io/typing-svg)

## Doscente da turma
- [Kennedy Reurison Lopes](https://github.com/kennedyufersa)

## Componentes da equipe
- [Éverson Alisson Queiroz Silva](https://github.com/Everson-Alisson)
- [Nattan Ferreira Lopes](https://github.com/NattanFerreira)
- [Pedro Lucas de Sousa Ferreira](https://github.com/Pelluca)
- [Rubens Alexandre de Sousa Ferreira](https://github.com/alexrbss)


## Linguagem utilizada

![C](https://img.shields.io/badge/C-007ACC?style=for-the-badge&logo=C&logoColor=white)&nbsp;

Neste arquivo você verá:
- [IA's utilizadas](#1.0-IA's-utilizadas)
- [Introdução](#2.0-Introdução)
- [Organização do código](#3.0-Organização)
- [Problemática](#4.0-problemática)
- [Descrição](#5.0-descrição)
- [Árvore de busca binária ](#6.0-Avl)
- [Tabela Hash](#7.0-Hash)
- [Heap](#8.0-Heap)
- [Funções](#9.0-Menu)
- [Pré-requisitos para compilar](#10.0-Pre-requisitos)
- [Execução do Projeto](#11.0-Execução-do-projeto)

## **1.0-IA's utlizada**

### As IA's foram usadas em nosso código com o intuito de tirar dúvidas sobre funções, comandos e etc.

- **Github Copilot**: O GitHub Copilot é uma ferramenta de programação baseada em inteligência artificial, desenvolvida pela GitHub e pela OpenAI. Ele fornece sugestões de código em tempo real enquanto você escreve, usando modelos de linguagem avançados para aumentar a produtividade dos desenvolvedores.

## **2.0-Introdução**

Um sistema usado para gerenciar uma loja de jogos, com os seguintes atributos, cadastrar/buscar/remover clientes, cadastrar/buscar/remover mercadoria, ter o controle de estoque e realizar vendas.

## **3.0-Organização**

``` 
📁 - PixelPoint
│
└─── include
        │
        ├──clientes.h
        ├──jogos.h
        ├──sistema.h
│
└─── src
        │
        ├──clientes.c
        ├──jogos.c
        ├──main.c
        ├──sistema.c
│
└───README.md
```

## **4.0-Problemática**

Projete um sistema em alguma linguagem que faça uso de ponteiros para gerenciar uma loja de jogos. Seu sistema deve ser capaz de manipular informações dos jogos e possiveis clientes

## **5.0-Descrição**

#### O programa deve conter os seguintes atributos:<br>
- Cadastrar, buscar e remover jogos<br>
- Cadastrar, buscar e remover clientes<br>
- Ter o controle de estoque<br>
- Realizar vendas<br>

#### O programa irá utilizar as seguintes estruturas de dados<br>
- Arvore de busca binária ou AVL
- Tabela Hash
- Heap

## **6.0-Arvore de busca Binária**

#### Como a Arvore de busca binaria funciona? <br>
Uma árvore de busca binária é uma estrutura de dados em forma de árvore que armazena elementos de forma hierárquica, facilitando operações como busca, inserção e remoção. Cada nó de uma árvore binária de busca tem no máximo dois filhos: um filho à esquerda e um filho à direita.
<br>

#### Qual a função dela no programa?
Ela ficará responsavel por burcar, inserir e remover mercadorias e clientes da loja.

## **7.0-Tabela Hash**

#### Como funciona a tabela Hash?<br>
Uma tabela hash é uma estrutura de dados que mapeia chaves a valores de maneira muito eficiente, usando uma técnica conhecida como hashing. É amplamente usada quando se precisa de buscas rápidas, inserções e remoções de elementos, geralmente com complexidade próxima de O(1).
#### Qual a função dela no programa?
Mapear as mercadorias por categoria, facilitando o controle de estoque da loja.

## **8.0-Heap**

#### Como funciona a Heap?<br>
A estrutura de dados heap, também conhecida como heap binária, é uma árvore binária que organiza um conjunto de elementos. É uma estrutura útil para implementar filas de prioridade, pois permite adicionar e extrair o elemento de maior prioridade em tempo O(logn).

#### Qual a função dela no programa?
Ela armazena os jogos e coloca como prioridade o que está com menos itens no estoque

## **9.0-Funções** 
```
---------------------------------
            MENU
1 - Adicionar Cliente
2 - Remover Cliente
3 - Buscar Clientes
4 - Cadastrar Jogo
5 - Remover Jogo
6 - Estoque
7 - Buscar Jogo
8 - Realizar Venda
9 - Reabastecer Estoque
0 - SAIR
---------------------------------
```
## **9.1-Adicionar/Remover/Burscar Clientes**
```
---------------------------------
1 - Adicionar Cliente
2 - Remover Cliente
3 - Buscar Clientes
---------------------------------
```
#### As funções como adicionar/buscar e remover clientes, foram implementadas usando Arvore de Busca Binária(AVL). O que nos levou a usar ela, foi o fato de que os elementos são inseridos de forma hierarquica, facilitando assim as operações como por exemplo a de busca 
### **Função adicionar cliente**
```
Node* Inserir(Node* node, Cliente cliente);
```
##### A função Inserir insere um novo nó em uma árvore AVL com base no ID do cliente, realiza a inserção normal de uma árvore binária de busca e aplica rotações para manter o balanceamento da árvore. Ela lida com a atualização da altura e do fator de balanceamento após a inserção.
### **Função de remover cliente**
```
Node* Deletar_node(Node* raiz, int id);
```
##### A função Deletar_node remove um nó de uma árvore AVL com base no ID fornecido, realiza a remoção normal de uma árvore binária de busca e aplica rotações para manter o balanceamento da árvore. Ela lida com nós com nenhum, um ou dois filhos e atualiza a altura e o fator de balanceamento após a remoção.
### **Função de buscar cliente**
```
Node* Buscar(Node* raiz, int id);
```
##### A função Buscar busca um nó em uma árvore AVL com base no ID do cliente. Ela percorre a árvore recursivamente, comparando o ID fornecido com o ID dos nós, até encontrar o nó correspondente ou chegar a um nó nulo. Se o cliente for encontrado, a função retorna o nó correspondente; caso contrário, retorna NULL.
## **9.2-Cadastrar Jogo/Estoque/Buscar Jogo/Realizar Venda/Reabastecer Estoque**
```
---------------------------------
4 - Cadastrar Jogo
5 - Remover Jogo
6 - Estoque
7 - Buscar Jogo
8 - Realizar Venda
9 - Reabastecer Estoque
---------------------------------
```
#### As 5 funções referentes aos jogos, utilizaram duas estruturas de dados, a tabela Hash e a Heap. A escolha da tabela hash vem pelo fato que ela mapeia os jogos dando valores a eles, assim facilitando na hora das buscas que seriam utilizadas para as demais funções como por exemplo a de realizar venda e a Heap fui utilizada para armazenar os jogos e colocar como prioridade os que tem menos estoque
### **Função cadastrar jogo**
```
Jogo* criarJogo(int id, const char* nome, float preco, int quantidade);
```
##### A função criarJogo aloca memória para um novo jogo, inicializa seus campos com os valores fornecidos (ID, nome, preço e quantidade) e retorna um ponteiro para o novo jogo. Se a alocação de memória falhar, a função imprime uma mensagem de erro e encerra o programa.
### **Função remover jogo**
```
void excluirJogo(Lista tabela[], const char* nome);
```
##### A função excluirJogo remove um jogo de uma tabela hash com base no nome fornecido. Ela calcula o índice usando uma função hash, percorre a lista encadeada no índice correspondente, encontra o jogo com o nome especificado, remove o nó da lista e libera a memória alocada para o jogo e o nó.
### **Função estoque**
```
void imprimirTabela(Lista tabela[]);
```
##### A função imprimirTabela percorre todas as listas em uma tabela hash e imprime o conteúdo de cada lista. Para cada índice da tabela, a função chama imprimirLista para imprimir os elementos da lista correspondente.

### **Função buscar jogo**
```
int buscarNaTabela(Lista tabela[], const char *nome);
```
##### A função buscarNaTabela busca um jogo em uma tabela hash com base no nome fornecido. Ela calcula o índice usando uma função hash e chama a função buscarNaLista para procurar o jogo na lista encadeada no índice correspondente. Retorna um valor indicando se o jogo foi encontrado.

### **Função realizar venda**
```
void realizarVenda(Lista tabela[], Heap *heap, const char *nome, int quantidade);
```
##### A função realizarVenda realiza a venda de um jogo, atualizando a quantidade em estoque e a heap. Ela busca o jogo na tabela hash pelo nome, verifica se há quantidade suficiente em estoque, decrementa a quantidade vendida e atualiza a heap removendo e reinserindo o jogo. Se o jogo não for encontrado ou a quantidade for insuficiente, a função imprime uma mensagem de erro.
### **Função reabastecer estoque**
```
void reabastecerEstoque(Lista tabela[], Heap *heap, const char *nome, int quantidade);
```
##### A função reabastecerEstoque reabastece o estoque de um jogo na tabela hash com base no nome fornecido. Ela busca o jogo na tabela, incrementa a quantidade em estoque e atualiza a heap removendo e reinserindo o jogo. Se o jogo não for encontrado, a função imprime uma mensagem de erro.

## 10.0 Pré-Requisitos

Para executar o código é necessário um compilador C instalado. Recomendamos o uso do [GCC](https://gcc.gnu.org/).

## 11.0 Execução do Projeto
### 11.1 Compilação do Código
Para compilar o código, abra o terminal e navegue até a pasta `linguagem_c` e execute o seguinte comando:
```
gcc main.c clientes.c jogos.c sistema.c -o main
```
### 11.2 Execução do Código
Para executar o código, digite o comando:
```
./main
```
<img width=100% src="https://capsule-render.vercel.app/api?type=waving&height=120&color=FFFFFF&section=footer"/>
