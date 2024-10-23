#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef JOGOS_H

#define TAM 10

typedef struct Jogo {
    int id;
    char nome[50];
    float preco;
    int quantidade;
} Jogo;

typedef struct No {
    Jogo *jogo;
    struct No *prox;
} No;

typedef struct Lista {
    No *inicio;
} Lista;

// Função que calcula o hash de uma string
int funcaoHash(const char *nome);

// Função que busca um jogo na lista
int buscarNaLista(Lista *lista, const char *nome);

// Função que busca um jogo na tabela
int buscarNaTabela(Lista tabela[], const char *nome);

// Função que verifica se um jogo já existe na tabela
int jogoExiste(Lista tabela[], const char *nome);

// Função que cria um novo jogo
Jogo* criarJogo(int id, const char* nome, float preco, int quantidade);

// Função que insere um jogo na lista
void inserirNaLista(Lista *lista, Jogo *jogo);

// Função que insere um jogo na tabela
void inserirNaTabela(Lista tabela[], int chave, const char* nome, float preco, int quantidade);

// Função que imprime a lista
void imprimirLista(Lista *lista);

// Função que imprime a tabela
void imprimirTabela(Lista tabela[]);

// Função que inicializa a tabela
void inicializarTabela(Lista tabela[]);

// Função que gera um id único
int gerarIdUnico();

// Função que exclui um jogo da tabela
void excluirJogo(Lista tabela[], const char* nome);

#endif