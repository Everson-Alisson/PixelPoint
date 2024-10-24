#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CLIENTES_H

/* Definição do tipo estruturado Cliente */
typedef struct {
    int id;
    char nome[100];
} Cliente;

/* Definição do tipo estruturado Node */
typedef struct Node {
    Cliente cliente;
    struct Node *esquerda;
    struct Node *direita;
    int Altura;
} Node;

/**
* Obtém a altura de um nó
*
* @param Ponteiro para o nó cuja altura deve ser retornada.
*
* @return A altura do nó. Se o nó for NULL, retorna 0. Caso contrário, retorna o valor do campo Altura do nó.
*/
int Altura(Node *N);

/**
 * Obtém o valor máximo entre dois inteiros.
 *
 * @param a O primeiro inteiro.
 * @param b O segundo inteiro.
 *
 * @return O maior valor entre a e b.
 */
int max(int a, int b);

/**
 * Cria um novo nó para a árvore AVL.
 *
 * @param cliente A estrutura Cliente que contém os dados do cliente a serem armazenados no nó.
 *
 * @return Um ponteiro para o novo nó criado. O nó é inicializado com o cliente fornecido, 
 *         ponteiros para os filhos esquerda e direita como NULL, e altura igual a 1.
 */
Node* newNode(Cliente cliente);

/**
 * Realiza uma rotação à direita na subárvore com raiz y.
 *
 * @param y Ponteiro para o nó raiz da subárvore que será rotacionada.
 *
 * @return Um ponteiro para a nova raiz da subárvore após a rotação.
 */
Node *Girar_direita(Node *y);

/**
 * Realiza uma rotação à esquerda na subárvore com raiz x.
 *
 * @param x Ponteiro para o nó raiz da subárvore que será rotacionada.
 *
 * @return Um ponteiro para a nova raiz da subárvore após a rotação.
 */
Node *Girar_esquerda(Node *x);

/**
 * Calcula o fator de balanceamento de um nó.
 *
 * O fator de balanceamento é a diferença entre a altura da subárvore esquerda
 * e a altura da subárvore direita. Um fator de balanceamento de -1, 0 ou 1
 * indica que o nó está balanceado.
 *
 * @param N Ponteiro para o nó cujo fator de balanceamento deve ser calculado.
 *
 * @return O fator de balanceamento do nó. Se o nó for NULL, retorna 0.
 */
int Fator_balanceamento(Node *N);

/**
 * Insere um novo cliente na árvore AVL.
 *
 * Esta função insere um novo nó na árvore AVL e garante que a árvore permaneça balanceada
 * após a inserção. Se um nó com o mesmo ID já existir, a inserção é rejeitada.
 *
 * @param node Ponteiro para o nó raiz da subárvore onde a inserção será realizada.
 * @param cliente A estrutura Cliente que contém os dados do cliente a serem inseridos.
 *
 * @return Um ponteiro para o nó raiz da subárvore após a inserção e balanceamento.
 */
Node* Inserir(Node* node, Cliente cliente);

/**
 * Imprime os nós de uma árvore AVL em pré-ordem.
 *
 * Esta função percorre a árvore AVL em pré-ordem (raiz, esquerda, direita)
 * e imprime o ID e o nome do cliente armazenado em cada nó.
 *
 * @param raiz Ponteiro para o nó raiz da árvore AVL.
 */
void Imprimir_AVL(Node *raiz);

/**
 * Busca um cliente na árvore AVL pelo ID.
 *
 * Esta função percorre a árvore AVL recursivamente para encontrar um nó
 * que contém o cliente com o ID especificado.
 *
 * @param raiz Ponteiro para o nó raiz da árvore AVL.
 * @param id O ID do cliente a ser buscado.
 *
 * @return Um ponteiro para o nó que contém o cliente com o ID especificado.
 *         Se o cliente não for encontrado, retorna NULL.
 */
Node* Buscar(Node* raiz, int id);

/**
 * Encontra o nó com o menor valor em uma árvore AVL.
 *
 * Esta função percorre a subárvore a partir do nó fornecido para encontrar
 * o nó com o menor valor (mais à esquerda).
 *
 * @param node Ponteiro para o nó raiz da subárvore onde a busca será realizada.
 *
 * @return Um ponteiro para o nó com o menor valor na subárvore.
 */
Node* minValueNode(Node* node);

/**
 * Remove um nó da árvore AVL pelo ID do cliente.
 *
 * Esta função remove um nó da árvore AVL que contém o cliente com o ID especificado.
 * Após a remoção, a árvore é balanceada para garantir que continue sendo uma árvore AVL.
 *
 * @param raiz Ponteiro para o nó raiz da árvore AVL.
 * @param id O ID do cliente a ser removido.
 *
 * @return Um ponteiro para o nó raiz da árvore AVL após a remoção e balanceamento.
 */
Node* Deletar_node(Node* raiz, int id);

#endif