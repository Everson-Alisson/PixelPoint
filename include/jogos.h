#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef JOGOS_H

#define TAM 10

/* Definição do tipo estruturado Jogo */
typedef struct Jogo {
    int id;
    char nome[50];
    float preco;
    int quantidade;
} Jogo;

/* Definição do tipo estruturado No */
typedef struct No {
    Jogo *jogo;
    struct No *prox;
} No;

/* Definição do tipo estruturado Lista */
typedef struct Lista {
    No *inicio;
} Lista;

/* Definição do tipo estruturado Heap */
typedef struct Heap {
    Jogo *jogos[TAM];
    int tamanho;
} Heap;

/**
 * Calcula o valor do hash para uma string.
 *
 * Esta função calcula o valor do hash para uma string fornecida, somando os valores
 * ASCII de seus caracteres e aplicando o operador módulo com o tamanho da tabela hash.
 *
 * @param nome A string para a qual o valor do hash será calculado.
 *
 * @return O valor do hash calculado para a string.
 */
int funcaoHash(const char *nome);

/**
 * Busca um jogo em uma lista encadeada pelo nome.
 *
 * Esta função percorre uma lista encadeada de jogos para encontrar um jogo
 * com o nome especificado.
 *
 * @param lista Ponteiro para a lista encadeada onde a busca será realizada.
 * @param nome O nome do jogo a ser buscado.
 *
 * @return 1 se o jogo for encontrado na lista, 0 caso contrário.
 */
int buscarNaLista(Lista *lista, const char *nome);

/**
 * Busca um jogo na tabela hash pelo nome.
 *
 * Esta função calcula o valor do hash para o nome fornecido e busca o jogo
 * correspondente na lista encadeada da tabela hash.
 *
 * @param tabela A tabela hash onde a busca será realizada.
 * @param nome O nome do jogo a ser buscado.
 *
 * @return 1 se o jogo for encontrado na tabela, 0 caso contrário.
 */
int buscarNaTabela(Lista tabela[], const char *nome);

/**
 * Verifica se um jogo existe na tabela hash pelo nome.
 *
 * Esta função verifica se um jogo com o nome especificado existe na tabela hash,
 * utilizando a função buscarNaTabela para realizar a busca.
 *
 * @param tabela A tabela hash onde a busca será realizada.
 * @param nome O nome do jogo a ser verificado.
 *
 * @return 1 se o jogo existir na tabela, 0 caso contrário.
 */
int jogoExiste(Lista tabela[], const char *nome);

/**
 * Cria um novo jogo com os dados fornecidos.
 *
 * Esta função aloca memória para um novo jogo e inicializa seus campos
 * com os valores fornecidos. Se a alocação de memória falhar, a função
 * imprime uma mensagem de erro e encerra o programa.
 *
 * @param id O ID do jogo.
 * @param nome O nome do jogo.
 * @param preco O preço do jogo.
 * @param quantidade A quantidade do jogo em estoque.
 *
 * @return Um ponteiro para a estrutura Jogo criada.
 */
Jogo* criarJogo(int id, const char* nome, float preco, int quantidade);

/**
 * Insere um novo jogo no início de uma lista encadeada.
 *
 * Esta função aloca memória para um novo nó, inicializa seus campos com o jogo fornecido,
 * e insere o nó no início da lista encadeada. Se a alocação de memória falhar, a função
 * imprime uma mensagem de erro e encerra o programa.
 *
 * @param lista Ponteiro para a lista encadeada onde o jogo será inserido.
 * @param jogo Ponteiro para a estrutura Jogo a ser inserida na lista.
 */
void inserirNaLista(Lista *lista, Jogo *jogo);

/**
 * Insere um novo jogo na tabela hash.
 *
 * Esta função insere um novo jogo na tabela hash, garantindo que não haja duplicatas.
 * Se um jogo com o mesmo nome já existir na tabela, a função imprime uma mensagem de erro
 * e não realiza a inserção. Caso contrário, a função calcula o valor do hash para o nome
 * fornecido, cria um novo jogo e o insere na lista encadeada correspondente na tabela hash.
 *
 * @param tabela A tabela hash onde o jogo será inserido.
 * @param chave A chave única do jogo.
 * @param nome O nome do jogo.
 * @param preco O preço do jogo.
 * @param quantidade A quantidade do jogo em estoque.
 */
void inserirNaTabela(Lista tabela[], int chave, const char* nome, float preco, int quantidade);

/**
 * Imprime os jogos em uma lista encadeada.
 *
 * Esta função percorre uma lista encadeada de jogos e imprime os detalhes
 * de cada jogo, incluindo ID, nome, preço e quantidade.
 *
 * @param lista Ponteiro para a lista encadeada de jogos a ser impressa.
 */
void imprimirLista(Lista *lista);

/**
 * Imprime todas as listas encadeadas na tabela hash.
 *
 * Esta função percorre todas as listas encadeadas na tabela hash e imprime
 * os detalhes de cada jogo em cada lista. Cada lista é precedida por um
 * cabeçalho indicando seu índice na tabela.
 *
 * @param tabela A tabela hash contendo as listas encadeadas de jogos.
 */
void imprimirTabela(Lista tabela[]);

/**
 * Inicializa a tabela hash.
 *
 * Esta função inicializa a tabela hash, configurando o ponteiro de início
 * de cada lista encadeada para NULL. Isso garante que todas as listas
 * estejam vazias antes de serem usadas.
 *
 * @param tabela A tabela hash a ser inicializada.
 */
void inicializarTabela(Lista tabela[]);

/**
 * Gera um ID único para um jogo.
 *
 * Esta função gera um ID único incrementando um valor estático a cada chamada.
 * O valor inicial do ID é 0 e é incrementado em 1 a cada vez que a função é chamada.
 *
 * @return Um ID único para um jogo.
 */
int gerarIdUnico();

/**
 * Exclui um jogo da tabela hash pelo nome.
 *
 * Esta função busca um jogo na tabela hash pelo nome e o remove da lista encadeada
 * correspondente. Se o jogo for encontrado, ele é removido da lista e a memória
 * alocada para o jogo e o nó é liberada.
 *
 * @param tabela A tabela hash contendo as listas encadeadas de jogos.
 * @param nome O nome do jogo a ser excluído.
 */
void excluirJogo(Lista tabela[], const char* nome);

/**
 * Inicializa uma estrutura de heap.
 *
 * Esta função inicializa uma estrutura de heap, configurando o tamanho do heap para 0.
 * Isso garante que o heap esteja vazio antes de ser usado.
 *
 * @param heap Ponteiro para a estrutura de heap a ser inicializada.
 */
void inicializarHeap(Heap *heap);

/**
 * Insere um novo jogo no heap.
 *
 * Esta função insere um novo jogo no heap, mantendo a propriedade do heap.
 * Se o heap estiver cheio, a função imprime uma mensagem de erro e não realiza a inserção.
 *
 * @param heap Ponteiro para a estrutura de heap onde o jogo será inserido.
 * @param jogo Ponteiro para a estrutura Jogo a ser inserida no heap.
 */
void inserirNoHeap(Heap *heap, Jogo *jogo);

/**
 * Remove e retorna o jogo com a menor quantidade do heap.
 *
 * Esta função remove o jogo com a menor quantidade do heap, mantendo a propriedade do heap.
 * Se o heap estiver vazio, a função imprime uma mensagem de erro e retorna NULL.
 *
 * @param heap Ponteiro para a estrutura de heap de onde o jogo será removido.
 *
 * @return Um ponteiro para a estrutura Jogo removida do heap. Se o heap estiver vazio, retorna NULL.
 */
Jogo *removerDoHeap(Heap *heap);

/**
 * Imprime os jogos no heap.
 *
 * Esta função imprime os jogos no heap em ordem de reabastecimento, ou seja,
 * na ordem em que estão armazenados no heap. Para cada jogo, são impressos
 * o nome, o preço e a quantidade.
 *
 * @param heap Ponteiro para a estrutura de heap contendo os jogos a serem impressos.
 */
void imprimirHeap(Heap *heap);

/**
 * Remove um jogo do heap pelo nome.
 *
 * Esta função remove um jogo do heap pelo nome, mantendo a propriedade do heap.
 * Se o jogo não for encontrado no heap, a função imprime uma mensagem de erro e não realiza a remoção.
 *
 * @param heap Ponteiro para a estrutura de heap de onde o jogo será removido.
 * @param nome O nome do jogo a ser removido do heap.
 */
void removerDoHeapPorNome(Heap *heap, const char *nome);

/**
 * Realiza uma venda de um jogo.
 *
 * Esta função realiza uma venda de um jogo, atualizando a quantidade em estoque
 * e reordenando o heap de acordo com a nova quantidade. Se a quantidade vendida
 * for maior que a quantidade em estoque, a função imprime uma mensagem de erro
 * e não realiza a venda.
 *
 * @param tabela A tabela hash contendo as listas encadeadas de jogos.
 * @param heap Ponteiro para a estrutura de heap contendo os jogos em ordem de reabastecimento.
 * @param nome O nome do jogo a ser vendido.
 * @param quantidade A quantidade do jogo a ser vendida.
 */
void realizarVenda(Lista tabela[], Heap *heap, const char *nome, int quantidade);

/**
 * Reabastece o estoque de um jogo.
 *
 * Esta função reabastece o estoque de um jogo, atualizando a quantidade em estoque
 * e reordenando o heap de acordo com a nova quantidade. Se o jogo não for encontrado
 * na tabela hash, a função imprime uma mensagem de erro e não realiza o reabastecimento.
 *
 * @param tabela A tabela hash contendo as listas encadeadas de jogos.
 * @param heap Ponteiro para a estrutura de heap contendo os jogos em ordem de reabastecimento.
 * @param nome O nome do jogo a ser reabastecido.
 * @param quantidade A quantidade a ser adicionada ao estoque.
 */
void reabastecerEstoque(Lista tabela[], Heap *heap, const char *nome, int quantidade);

#endif