#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef JOGOS_H

#define TAM 31

typedef struct jogos {
    int id;
    char nome[50];
    float preco;
    int quantidade;
} Jogo;

typedef struct no {
    Jogo *jogo;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    int tamanho;
} Lista;

// Função para inicializar uma lista
void inicializarLista(Lista *lista);

// Função que incializa a tabela hash
void inicializarTabela(Lista tabela[]);

// Função que calcula o índice da tabela
int funcaoHash(int chave);

// Função que insere um novo elemento na lista
void inserirNaLista(Lista *lista, Jogo *jogo);

// Função que insere um novo elemento na tabela
void inserirNaTabela(Lista tabela[], Jogo *jogo);

// Função para realizar uma busca na lista
int buscarNaLista(Lista *lista, int chave);

// Função para realizar uma busca na tabela
int buscarNaTabela(Lista tabela[], int chave);

// Função para criar um novo jogo
Jogo* criarJogo(int id, const char* nome, float preco, int quantidade);

// Função que imprime a lista
void imprimirLista(Lista *lista);

// Função que imprime a tabela
void imprimirTabela(Lista tabela[]);

// Função que exclui um jogo
void excluirJogo(Lista tabela[], const char* nome);

#endif