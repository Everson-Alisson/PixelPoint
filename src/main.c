#include "../include/clientes.h"

int main () {
    int opcao;

    do {
        int opcao;

        printf("-------------------------\n");
        printf("\tMENU\n");
        printf("-------------------------\n");
        printf("1|\tAdicionar Cliente\n");
        printf("2|\tRemover Cliente\n");
        printf("3|\tBuscar Clientes\n");
        printf("4|\tCadastrar Jogo\n");
        printf("5|\tRemover Jogo\n");
        printf("6|\tEstoque\n");
        printf("7|\tRealizar Venda\n");
        printf("8|\tSAIR\n");
        printf("-----------------------\n");
        
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Cadastrar Cliente\n");
                break;
            case 2:
                printf("Remover Cliente\n");
                break;
            case 3:
                printf("Buscar Clientes\n");
                break;
            case 4:
                printf("Cadastrar Jogo\n");
                break;
            case 5:
                printf("Remover Jogo\n");
                break;
            case 6:
                printf("Estoque\n");
                break;
            case 7:
                printf("Realizar Venda\n");
                break;
            case 8:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (opcao != 8);

    return 0;
}