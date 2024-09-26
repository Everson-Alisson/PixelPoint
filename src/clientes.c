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

Node *Girar_direita(Node *y) {
    Node *x = y->esquerda;
    Node *T2 = x->direita;

    // Realiza a rotação
    x->direita = y;
    y->esquerda = T2;

    // Atualiza alturas
    y->Altura = max(Altura(y->esquerda), Altura(y->direita)) + 1;
    x->Altura = max(Altura(x->esquerda), Altura(x->direita)) + 1;

    // Retorna a nova raiz
    return x;
}

Node *Girar_esquerda(Node *x) {
    Node *y = x->direita;
    Node *T2 = y->esquerda;

    // Realiza a rotação
    y->esquerda = x;
    x->direita = T2;

    // Atualiza alturas
    x->Altura = max(Altura(x->esquerda), Altura(x->direita)) + 1;
    y->Altura = max(Altura(y->esquerda), Altura(y->direita)) + 1;

    // Retorna a nova raiz
    return y;
}

int Fator_balanceamento(Node *N) {
    if (N == NULL)
        return 0;
    return Altura(N->esquerda) - Altura(N->direita);
}