#include "../include/clientes.h"

int Altura(Node *N) {
    if (N == NULL)
        return 0;
    return N->Altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode(Cliente cliente) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->cliente = cliente;
    node->esquerda = NULL;
    node->direita = NULL;
    node->Altura = 1; // Novo nó é inicialmente adicionado na folha
    return(node);
}