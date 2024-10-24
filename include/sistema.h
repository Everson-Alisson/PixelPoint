#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef SISTEMA_H

/**
 * Verifica se a string contém apenas números
 * 
 * @param opcao
 * 
 * @return 1 se a string contém apenas números, 0 caso contrário
 */
int VerificanumInt(int *opcao);

/**
 * Verifica se a string não tem caracteres especiais
 * 
 * @param opcao
 * 
 * @return 1 se a string tem caracteres especiais, 0 caso contrário
 */
int VerificaCaracteres(char *opcao);

/**
 * Verifica se a string não contém números e caracteres especiais
 * 
 * @param opcao
 * 
 * @return 1 se a string contém números e caracteres especiais, 0 caso contrário
 */
int VerificaNome(char *opcao);

/**
 * Limpa o terminal, funciona tanto para Windows quanto para Linux
 */
void limparTela();

/**
 * Função pressiona ENTER para continuar
 */
void pressioneENTER();

/**
 * Verifica se a escolha do usuário é válida
 * 
 * @param opcao
 * 
 * @return opcao
 */
char verificaEscolha(char opcao);

#endif