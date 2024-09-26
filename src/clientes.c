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

Node* Inserir(Node* node, Cliente cliente) {
    // 1. Realiza a inserção normal na árvore binária de busca
    if (node == NULL)
        return(newNode(cliente));

    if (cliente.id < node->cliente.id){
        node->esquerda = Inserir(node->esquerda, cliente);
        printf("Inserido a esquerda\n");
    }
    else if (cliente.id > node->cliente.id){
        printf("Inserido a direita\n");
        node->direita = Inserir(node->direita, cliente);
    }    
    else{ // IDs iguais não são permitidos na árvore AVL
        printf("IDs iguais não são permitidos na árvore AVL\n");
        return node;
    }
    // 2. Atualiza a Altura deste nó ancestral
    node->Altura = 1 + max(Altura(node->esquerda), Altura(node->direita));

    // 3. Obtém o fator de balanceamento deste nó ancestral
    int balance = Fator_balanceamento(node);

    // 4. Se o nó estiver desbalanceado, então existem 4 casos

    // Caso Esquerda-Esquerda
    if (balance > 1 && cliente.id < node->esquerda->cliente.id)
        return Girar_direita(node);

    // Caso Direita-Direita
    if (balance < -1 && cliente.id > node->direita->cliente.id)
        return Girar_esquerda(node);

    // Caso Esquerda-Direita
    if (balance > 1 && cliente.id > node->esquerda->cliente.id) {
        node->esquerda = Girar_esquerda(node->esquerda);
        return Girar_direita(node);
    }

    // Caso Direita-Esquerda
    if (balance < -1 && cliente.id < node->direita->cliente.id) {
        node->direita = Girar_direita(node->direita);
        return Girar_esquerda(node);
    }

    // Retorna o ponteiro do nó (inalterado)
    return node;
}