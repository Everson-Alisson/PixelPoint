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
    node->Altura = 1;
    return(node);
}

Node *Girar_direita(Node *y) {
    Node *x = y->esquerda;
    Node *T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->Altura = max(Altura(y->esquerda), Altura(y->direita)) + 1;
    x->Altura = max(Altura(x->esquerda), Altura(x->direita)) + 1;

    return x;
}

Node *Girar_esquerda(Node *x) {
    Node *y = x->direita;
    Node *T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->Altura = max(Altura(x->esquerda), Altura(x->direita)) + 1;
    y->Altura = max(Altura(y->esquerda), Altura(y->direita)) + 1;

    return y;
}

int Fator_balanceamento(Node *N) {
    if (N == NULL)
        return 0;
    return Altura(N->esquerda) - Altura(N->direita);
}

Node* Inserir(Node* node, Cliente cliente) {
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
    else{ 
        printf("IDs iguais não são permitidos na árvore AVL\n");
        return node;
    }
    node->Altura = 1 + max(Altura(node->esquerda), Altura(node->direita));

    int balance = Fator_balanceamento(node);

    if (balance > 1 && cliente.id < node->esquerda->cliente.id)
        return Girar_direita(node);

    if (balance < -1 && cliente.id > node->direita->cliente.id)
        return Girar_esquerda(node);

    if (balance > 1 && cliente.id > node->esquerda->cliente.id) {
        node->esquerda = Girar_esquerda(node->esquerda);
        return Girar_direita(node);
    }

    if (balance < -1 && cliente.id < node->direita->cliente.id) {
        node->direita = Girar_direita(node->direita);
        return Girar_esquerda(node);
    }

    return node;
}

void Imprimir_AVL(Node *raiz) {
    if (raiz != NULL) {
        printf("%d %s\n", raiz->cliente.id, raiz->cliente.nome);
        Imprimir_AVL(raiz->esquerda);
        Imprimir_AVL(raiz->direita);
    }
}

Node* Buscar(Node* raiz, int id) {
    if (raiz == NULL || raiz->cliente.id == id){
        printf("Cliente encontrado\n");
        return raiz;
    }
    if (raiz->cliente.id < id){
        return Buscar(raiz->direita, id);
    }   
    return Buscar(raiz->esquerda, id);
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->esquerda != NULL)
        current = current->esquerda;
    return current;
}

Node* Deletar_node(Node* raiz, int id) {
    if (raiz == NULL){
        printf("Cliente não encontrado\n");
        return raiz;
    }
    if (id < raiz->cliente.id){
        raiz->esquerda = Deletar_node(raiz->esquerda, id);
        printf("Removido a esquerda\n");
    }
    else if (id > raiz->cliente.id){
        raiz->direita = Deletar_node(raiz->direita, id);
        printf("Removido a direita\n");
    }
    else {
        if ((raiz->esquerda == NULL) || (raiz->direita == NULL)) {
            Node *temp = raiz->esquerda ? raiz->esquerda : raiz->direita;

            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else 
                *raiz = *temp; 

            free(temp);
        } else {
            Node* temp = minValueNode(raiz->direita);

            raiz->cliente = temp->cliente;

            raiz->direita = Deletar_node(raiz->direita, temp->cliente.id);
        }
    }

    if (raiz == NULL){
        return raiz;
        printf("Árvore vazia\n");
    }

    raiz->Altura = 1 + max(Altura(raiz->esquerda), Altura(raiz->direita));

    int balance = Fator_balanceamento(raiz);

    if (balance > 1 && Fator_balanceamento(raiz->esquerda) >= 0)
        return Girar_direita(raiz);

    if (balance > 1 && Fator_balanceamento(raiz->esquerda) < 0) {
        raiz->esquerda = Girar_esquerda(raiz->esquerda);
        return Girar_direita(raiz);
    }

    if (balance < -1 && Fator_balanceamento(raiz->direita) <= 0)
        return Girar_esquerda(raiz);

    if (balance < -1 && Fator_balanceamento(raiz->direita) > 0) {
        raiz->direita = Girar_direita(raiz->direita);
        return Girar_esquerda(raiz);
    }

    return raiz;
}