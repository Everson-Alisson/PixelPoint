#include "../include/jogos.h"

void inicializarLista(Lista *lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void inicializarTabela(Lista tabela[]) {
    for (int i = 0; i < TAM; i++) {
        inicializarLista(&tabela[i]);
    }
}

int funcaoHash(int chave) {
    return chave % TAM;
}

void inserirNaLista(Lista *lista, Jogo *jogo) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação\n");
        exit(1);
    }

    novo->jogo = jogo;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
}

void inserirNaTabela(Lista tabela[], Jogo *jogo) {
    int id = funcaoHash(jogo->id);
    inserirNaLista(&tabela[id], jogo);
}

int buscarNaLista(Lista *lista, int chave) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->jogo->id == chave) {
            return 1; // Encontrado
        }
        atual = atual->prox;
    }
    return 0; // Não encontrado
}

int buscarNaTabela(Lista tabela[], int chave) {
    int id = funcaoHash(chave);
    return buscarNaLista(&tabela[id], chave);
}

Jogo* criarJogo(int id, const char* nome, float preco, int quantidade) {
    Jogo *novoJogo = malloc(sizeof(Jogo));
    if (novoJogo == NULL) {
        printf("Erro de alocação\n");
        exit(1);
    }

    novoJogo->id = id;
    strncpy(novoJogo->nome, nome, sizeof(novoJogo->nome) - 1);
    novoJogo->nome[sizeof(novoJogo->nome) - 1] = '\0';
    novoJogo->preco = preco;
    novoJogo->quantidade = quantidade;

    return novoJogo;
}

void imprimirLista(Lista *lista) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        printf("ID: %d, Nome: %s, Preco: %.2f, Quantidade: %d\n", atual->jogo->id, atual->jogo->nome, atual->jogo->preco, atual->jogo->quantidade);
        atual = atual->prox;
    }
}

void imprimirTabela(Lista tabela[]) {
    for (int i = 0; i < TAM; i++) {
        printf("Tabela[%d]:\n", i);
        imprimirLista(&tabela[i]);
    }
}

// int main() {
//     Lista tabela[TAM];
//     inicializarTabela(tabela);

//     Jogo *jogo1 = criarJogo(1, "Jogo A", 59.99, 10);
//     inserirNaTabela(tabela, jogo1);

//     Jogo *jogo2 = criarJogo(2, "Jogo B", 39.99, 5);
//     inserirNaTabela(tabela, jogo2);

//     imprimirTabela(tabela);

//     return 0;
// }