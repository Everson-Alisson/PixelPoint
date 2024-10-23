#include "../include/jogos.h"

int funcaoHash(const char *nome) {
    int hash = 0;
    while (*nome) {
        hash += *nome++;
    }
    return hash % TAM;
}

int buscarNaLista(Lista *lista, const char *nome) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->jogo->nome, nome) == 0) {
            return 1; // Encontrado
        }
        atual = atual->prox;
    }
    return 0; // Não encontrado
}

int buscarNaTabela(Lista tabela[], const char *nome) {
    int id = funcaoHash(nome);
    return buscarNaLista(&tabela[id], nome);
}

int jogoExiste(Lista tabela[], const char *nome) {
    return buscarNaTabela(tabela, nome);
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

void inserirNaLista(Lista *lista, Jogo *jogo) {
    No *novoNo = malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocação\n");
        exit(1);
    }
    novoNo->jogo = jogo;
    novoNo->prox = lista->inicio;
    lista->inicio = novoNo;
}

void inserirNaTabela(Lista tabela[], int chave, const char* nome, float preco, int quantidade) {
    if (jogoExiste(tabela, nome)) {
        printf("Erro: Jogo com o nome '%s' já existe.\n", nome);
        return;
    }
    int id = funcaoHash(nome);
    Jogo *novoJogo = criarJogo(chave, nome, preco, quantidade);
    inserirNaLista(&tabela[id], novoJogo);
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
        printf("Lista %d:\n", i);
        imprimirLista(&tabela[i]);
    }
}

void inicializarTabela(Lista tabela[]) {
    for (int i = 0; i < TAM; i++) {
        tabela[i].inicio = NULL;
    }
}

int gerarIdUnico() {
    static int id = 0;
    return ++id;
}

void excluirJogo(Lista tabela[], const char* nome) {
    int id = funcaoHash(nome);
    No *atual = tabela[id].inicio;
    No *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->jogo->nome, nome) == 0) {
            if (anterior == NULL) {
                tabela[id].inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual->jogo);
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}