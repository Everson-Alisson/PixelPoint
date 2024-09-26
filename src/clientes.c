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

void Imprimir_AVL(Node *raiz) {
    if (raiz != NULL) {
        printf("%d %s\n", raiz->cliente.id, raiz->cliente.nome);
        Imprimir_AVL(raiz->esquerda);
        Imprimir_AVL(raiz->direita);
    }
}

Node* minValueNode(Node* node) {
    Node* current = node;
    // Loop para encontrar a folha mais à esquerda
    while (current->esquerda != NULL)
        current = current->esquerda;
    return current;
}

Node* Deletar_node(Node* raiz, int id) {
    // Passo 1: Realiza a remoção normal na árvore binária de busca
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
        // Nó com apenas um filho ou nenhum filho
        if ((raiz->esquerda == NULL) || (raiz->direita == NULL)) {
            Node *temp = raiz->esquerda ? raiz->esquerda : raiz->direita;

            // Caso sem filhos
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else // Caso com um filho
                *raiz = *temp; // Copia os conteúdos do filho não vazio

            free(temp);
        } else {
            // Nó com dois filhos: Obtém o sucessor em ordem (menor na subárvore direita)
            Node* temp = minValueNode(raiz->direita);

            // Copia os dados do sucessor em ordem para este nó
            raiz->cliente = temp->cliente;

            // Remove o sucessor em ordem
            raiz->direita = Deletar_node(raiz->direita, temp->cliente.id);
        }
    }

    // Se a árvore tinha apenas um nó, então retorna
    if (raiz == NULL){
        return raiz;
        printf("Árvore vazia\n");
    }
    // Passo 2: Atualiza a Altura do nó atual
    raiz->Altura = 1 + max(Altura(raiz->esquerda), Altura(raiz->direita));

    // Passo 3: Obtém o fator de balanceamento deste nó
    int balance = Fator_balanceamento(raiz);

    // Passo 4: Se o nó estiver desbalanceado, então existem 4 casos

    // Caso Esquerda-Esquerda
    if (balance > 1 && Fator_balanceamento(raiz->esquerda) >= 0)
        return Girar_direita(raiz);

    // Caso Esquerda-Direita
    if (balance > 1 && Fator_balanceamento(raiz->esquerda) < 0) {
        raiz->esquerda = Girar_esquerda(raiz->esquerda);
        return Girar_direita(raiz);
    }

    // Caso Direita-Direita
    if (balance < -1 && Fator_balanceamento(raiz->direita) <= 0)
        return Girar_esquerda(raiz);

    // Caso Direita-Esquerda
    if (balance < -1 && Fator_balanceamento(raiz->direita) > 0) {
        raiz->direita = Girar_direita(raiz->direita);
        return Girar_esquerda(raiz);
    }

    return raiz;
}