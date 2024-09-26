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

// Função para realizar a rotação à direita
Node *Girar_direita(Node *y);

#endif