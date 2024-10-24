#include  "../include/sistema.h"

// Função que verifica se a string contém apenas números
int VerificanumInt(int *opcao) {
    while (*opcao) {
        if (!isdigit(*opcao)) {
            return 0; // Retorna falso se encontrar um caractere não numérico
        }
        opcao++;
    }
    return 1; // Retorna verdadeiro se todos os caracteres forem numéricos
}


//Função que verifica se a string nao tem caracteres especiais
int VerificaCaracteres(char *opcao) {
    for (int i = 0; opcao[i] != '\0'; i++) {
        if (!isalnum(opcao[i]) && opcao[i] != '.') {
            return 1; // Tem caracteres especiais
        }
    }
    return 0; // Não tem caracteres especiais
}

//Função que verifica se a string nao contem numeros e caracteres especiais de acordo com as funções acima
int VerificaNome(char *opcao) {
    int opcaoint = atoi(opcao);
    if (VerificanumInt(&opcaoint) == 1) {
        return 0; // Não contém números e caracteres especiais
    }
    return 1; // Contém números e caracteres especiais
}

//Função que limpa o terminal, funciona tanto para Windows quanto para Linux
void limparTela() {
    #ifdef _WIN32
        system("cls");  // Comando para Windows
    #else
        system("clear");  // Comando para Linux ou Unix-like
    #endif
}

//Função pressiona ENTER para continuar
void pressioneENTER() {
    printf("Pressione Enter para continuar...");
    while (getchar() != '\n');
    getchar();
}

char verificaEscolha(char opcao) {
    while (getchar() != '\n'){
        printf("Digite uma opcao valida: ");
        scanf("%c", &opcao);
    }
    return opcao;
}
