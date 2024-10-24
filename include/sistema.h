#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Função que verifica se a string contém apenas números
int VerificanumInt(int *opcao);

//Função que verifica se a string nao tem caracteres especiais
int VerificaCaracteres(char *opcao);

//Função que verifica se a string nao contem numeros e caracteres especiais
int VerificaNome(char *opcao);

//Função que limpa o terminal, funciona tanto para Windows quanto para Linux
void limparTela();

//Função pressiona ENTER para continuar
void pressioneENTER();

//Função que verifica se a escolha do usuário é válida
char verificaEscolha(char opcao);

