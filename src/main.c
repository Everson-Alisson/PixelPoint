#include "../include/clientes.h"
#include "../include/jogos.h"

int main()
{
    int opcao;

    do
    {
        Node *raiz = NULL;
        Cliente cliente;

        Lista tabela[TAM];
        inicializarTabela(tabela);

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

        switch (opcao)
        {
        case 1:
            printf("Informe o nome do cliente: ");
            scanf(" %[^\n]", cliente.nome);
            printf("Informe o ID do cliente: ");
            scanf("%d", &cliente.id);

            raiz = Inserir(raiz, cliente);
            if (raiz == NULL)
            {
                printf("Erro ao adicionar cliente\n");
                break;
            }
            else
            {
                printf("Cliente adicionado com sucesso\n");
            }

            Imprimir_AVL(raiz);
            break;
        case 2:
            Imprimir_AVL(raiz);

            printf("----------------------------------------\n\n");
            printf("Informe o ID do cliente a ser removido: ");
            scanf("%d", &cliente.id);

            raiz = Deletar_node(raiz, cliente.id);
            if (raiz == NULL)
            {
                printf("Erro ao remover cliente\n");
                break;
            }
            else
            {
                printf("Cliente removido com sucesso\n");
            }

            break;
        case 3:
            printf("Informe o nome do cliente a ser buscado: ");
            scanf(" %[^\n]", cliente.nome);

            Imprimir_AVL(raiz);
            Buscar(raiz, cliente.id);

            break;
        case 4:
            printf("Cadastrar Jogo\n");
            break;
        case 5:
            printf("Remover Jogo\n");
            break;
        case 6:
            printf("Estoque\n");
            imprimirTabela(tabela);
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