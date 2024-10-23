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

void inicializarHeap(Heap *heap) {
    heap->tamanho = 0;
}

void inserirNoHeap(Heap *heap, Jogo *jogo) {
    if (heap->tamanho >= TAM) {
        printf("Heap cheio\n");
        return;
    }

    int i = heap->tamanho;
    heap->jogos[i] = jogo;
    heap->tamanho++;

    while (i != 0 && heap->jogos[(i - 1) / 2]->quantidade > heap->jogos[i]->quantidade) {
        Jogo *temp = heap->jogos[i];
        heap->jogos[i] = heap->jogos[(i - 1) / 2];
        heap->jogos[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

Jogo *removerDoHeap(Heap *heap) {
    if (heap->tamanho <= 0) {
        printf("Heap vazio\n");
        return NULL;
    }

    Jogo *raiz = heap->jogos[0];
    heap->jogos[0] = heap->jogos[heap->tamanho - 1];
    heap->tamanho--;

    int i = 0;
    while (2 * i + 1 < heap->tamanho) {
        int menor = 2 * i + 1;
        if (2 * i + 2 < heap->tamanho && heap->jogos[2 * i + 2]->quantidade < heap->jogos[menor]->quantidade) {
            menor = 2 * i + 2;
        }

        if (heap->jogos[i]->quantidade <= heap->jogos[menor]->quantidade) {
            break;
        }

        Jogo *temp = heap->jogos[i];
        heap->jogos[i] = heap->jogos[menor];
        heap->jogos[menor] = temp;
        i = menor;
    }

    return raiz;
}

void removerDoHeapPorNome(Heap *heap, const char *nome) {
    int i;
    for (i = 0; i < heap->tamanho; i++) {
        if (strcmp(heap->jogos[i]->nome, nome) == 0) {
            break;
        }
    }

    if (i == heap->tamanho) {
        printf("Jogo não encontrado no heap\n");
        return;
    }

    heap->jogos[i] = heap->jogos[heap->tamanho - 1];
    heap->tamanho--;

    while (i != 0 && heap->jogos[(i - 1) / 2]->quantidade > heap->jogos[i]->quantidade) {
        Jogo *temp = heap->jogos[i];
        heap->jogos[i] = heap->jogos[(i - 1) / 2];
        heap->jogos[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }

    while (2 * i + 1 < heap->tamanho) {
        int menor = 2 * i + 1;
        if (2 * i + 2 < heap->tamanho && heap->jogos[2 * i + 2]->quantidade < heap->jogos[menor]->quantidade) {
            menor = 2 * i + 2;
        }

        if (heap->jogos[i]->quantidade <= heap->jogos[menor]->quantidade) {
            break;
        }

        Jogo *temp = heap->jogos[i];
        heap->jogos[i] = heap->jogos[menor];
        heap->jogos[menor] = temp;
        i = menor;
    }
}

void imprimirHeap(Heap *heap) {
    printf("Itens por ordem de reabastecimento\n");
    for (int i = 0; i < heap->tamanho; i++) {
        printf("Nome: %s, Preco: %.2f, Quantidade: %d\n", heap->jogos[i]->nome, heap->jogos[i]->preco, heap->jogos[i]->quantidade);
    }
}

void realizarVenda(Lista tabela[], Heap *heap, const char *nome, int quantidade) {
    int chave = funcaoHash(nome);
    No *atual = tabela[chave].inicio;

    while (atual != NULL && strcmp(atual->jogo->nome, nome) != 0) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Jogo não encontrado na tabela\n");
        return;
    }

    if (atual->jogo->quantidade < quantidade) {
        printf("Quantidade insuficiente em estoque\n");
        return;
    }

    atual->jogo->quantidade -= quantidade;

    // Atualizar a heap
    removerDoHeapPorNome(heap, nome);
    inserirNoHeap(heap, atual->jogo);

    printf("Venda realizada com sucesso\n");
}

void reabastecerEstoque(Lista tabela[], Heap *heap, const char *nome, int quantidade) {
    int chave = funcaoHash(nome);
    No *atual = tabela[chave].inicio;

    while (atual != NULL && strcmp(atual->jogo->nome, nome) != 0) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Jogo não encontrado na tabela\n");
        return;
    }

    atual->jogo->quantidade += quantidade;

    // Atualizar a heap
    removerDoHeapPorNome(heap, nome);
    inserirNoHeap(heap, atual->jogo);

    printf("Estoque reabastecido com sucesso\n");
}