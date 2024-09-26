#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef CLIENTES_H

typedef struct {
    int id;
    char nome[100];
} Cliente;

typedef struct Node {
    Cliente cliente;
    struct Node *esquerda;
    struct Node *direita;
    int Altura;
} Node;

// Função para obter a Altura de um nó
int Altura(Node *N);

// Função para obter o valor máximo entre dois inteiros
int max(int a, int b);

// Função para criar um novo nó
Node* newNode(Cliente cliente);

// Função para rotacionar à direita a subárvore com raiz y
Node *Girar_direita(Node *y);

// Função para rotacionar à esquerda a subárvore com raiz x
Node *Girar_esquerda(Node *x);

// Função para obter o fator de balanceamento do nó N
int Fator_balanceamento(Node *N);

// Função para inserir um novo cliente na árvore AVL
Node* Inserir(Node* node, Cliente cliente);

// Função para imprimir os dados inseridos na árvore AVL
void Imprimir_AVL(Node *raiz);

// Função para buscar um cliente na árvore AVL pelo ID
Node* Buscar(Node* raiz, int id);

// Função para encontrar o nó com o menor valor (usado na remoção)
Node* minValueNode(Node* node);

// Função para remover um nó da árvore AVL
Node* Deletar_node(Node* raiz, int id);

#endif