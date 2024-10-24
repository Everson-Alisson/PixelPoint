#include "../include/clientes.h"
#include "../include/jogos.h"
#include "../include/sistema.h"

int main() {
    Node *raiz = NULL;
    Lista tabela[TAM];
    Heap heap;
    inicializarTabela(tabela);
    inicializarHeap(&heap);
    
    Cliente cliente;
    Jogo jogos;

    char opcao;
    int verificacao;

    do {
        limparTela();
        printf("-------------------------\n");
        printf("\tMENU\n");
        printf("-------------------------\n");
        printf("1|\tAdicionar Cliente\n");
        printf("2|\tRemover Cliente\n");
        printf("3|\tBuscar Clientes\n");
        printf("4|\tCadastrar Jogo\n");
        printf("5|\tRemover Jogo\n");
        printf("6|\tEstoque\n");
        printf("7|\tBuscar Jogo\n");
        printf("8|\tRealizar Venda\n");
        printf("9|\tReabastecer Estoque\n");
        printf("0|\tSAIR\n");
        printf("-----------------------\n");

        printf("Digite a opcao desejada: ");
        scanf("%c", &opcao);
        verificacao = verificaEscolha(opcao);

        switch (opcao) {
        case '1':
            limparTela();
            printf("Informe o nome do cliente: ");
            scanf(" %[^\n]", cliente.nome);
            
            verificacao = VerificaNome(cliente.nome);
            
            if(verificacao == 1) {
                printf("Nome invalido, redirecionando para o menu\n");
                pressioneENTER();
                break;
            }
            
            printf("Informe o CPF do cliente: ");
            scanf("%d", &cliente.id); 
            verificacao = VerificanumInt(&cliente.id);
                
            if(verificacao == 1){
                printf("CPF invalido, redirecionando para o menu\n");
                pressioneENTER();
                break;
            }

            raiz = Inserir(raiz, cliente);
            if (raiz == NULL) {
                printf("Erro ao adicionar cliente\n");
                break;
            } else {
                printf("Cliente adicionado com sucesso\n");
            }

            pressioneENTER();
            
            break;
        case '2':
            limparTela();
            Imprimir_AVL(raiz);

            printf("----------------------------------------\n\n");
            printf("Informe o CPF do cliente a ser removido: ");
            scanf("%d", &cliente.id);
            verificacao = VerificanumInt(&cliente.id);
                
            if(verificacao == 1){
                printf("CPF invalido, redirecionando para o menu\n");
                pressioneENTER();
                break;
            }
            
            raiz = Deletar_node(raiz, cliente.id);
            if (raiz == NULL) {
                printf("Erro ao remover cliente\n");
                break;
            } else {
                printf("Cliente removido com sucesso\n");
            }

            pressioneENTER();

            break;
        case '3':
            limparTela();
            printf("Informe o nome do cliente a ser buscado: ");
            scanf(" %[^\n]", cliente.nome);
            
            verificacao = VerificaNome(cliente.nome);
            
            if(verificacao == 1){
                printf("Nome invalido, redirecionando para o menu\n");
                pressioneENTER();
                break;
            }

            Imprimir_AVL(raiz);
            Buscar(raiz, cliente.id);
            pressioneENTER();

            break;
        case '4':
            limparTela();
            while (1) {
                    printf("Informe o nome do jogo: ");
                    scanf(" %[^\n]", jogos.nome);

                    verificacao = VerificaNome(jogos.nome);
            
                    if(verificacao == 1){
                        printf("Nome invalido, redirecionando para o menu\n");
                        pressioneENTER();
                        break;
                    }

                    if (jogoExiste(tabela, jogos.nome)) {
                        printf("Erro: Jogo com o nome '%s' ja existe. redirecionando para o menu.\n", jogos.nome);
                        pressioneENTER();
                        break;
                    }

                    printf("Informe o preco do jogo: ");
                    scanf("%f", &jogos.preco);

                    printf("Informe a quantidade do jogo: ");
                    scanf("%d", &jogos.quantidade);
                    
                    verificacao = VerificanumInt(&jogos.quantidade);
                    if(verificacao == 1){
                        printf("Quantidade inválida, redirecionando para o menu\n");
                        pressioneENTER();
                        break;
                    }

                    jogos.id = gerarIdUnico();

                    inserirNaTabela(tabela, jogos.id, jogos.nome, jogos.preco, jogos.quantidade);
                    inserirNoHeap(&heap, criarJogo(jogos.id, jogos.nome, jogos.preco, jogos.quantidade));

                    printf("Jogo cadastrado com sucesso!\n");
                    pressioneENTER();
                    
                    break;
                }
                
                break;
        case '5':
                limparTela();
                imprimirTabela(tabela);
                printf("Informe o nome do jogo a ser removido: ");
                scanf(" %[^\n]", jogos.nome);
                
                verificacao = VerificaNome(jogos.nome);
                if(verificacao == 1){
                    printf("Nome invalido, redirecionando para o menu\n");
                    pressioneENTER();
                    break;
                }

                excluirJogo(tabela, jogos.nome);
                removerDoHeapPorNome(&heap, jogos.nome);
                printf("Jogo removido com sucesso!\n");
                pressioneENTER();
                
                break;
        case '6':
            limparTela();
            printf("Estoque\n");
            imprimirTabela(tabela);
            pressioneENTER();
            
            break;
        case '7':
            limparTela();
            printf("Informe o nome do jogo a ser buscado: ");
            scanf(" %[^\n]", jogos.nome);
            
            verificacao = VerificaNome(jogos.nome);
            if(verificacao == 1){
                printf("Nome invalido, redirecionando para o menu\n");
                pressioneENTER();
                break;
            }

            buscarNaTabela(tabela, jogos.nome);
            pressioneENTER();
            
            break;
        case '8':
            limparTela();
            printf("Informe o nome do jogo a ser vendido: ");
            scanf(" %[^\n]", jogos.nome);
            
            verificacao = VerificaNome(jogos.nome);
            if(verificacao == 1){
                printf("Nome invalido, redirecionando para o menu\n");
                pressioneENTER();
                break;
            }

            printf("Informe a quantidade do jogo a ser vendida: ");
            scanf("%d", &jogos.quantidade);

            verificacao = VerificanumInt(&jogos.quantidade);
            if(verificacao == 1){
                printf("Quantidade inválida, redirecionando para o menu\n");
                pressioneENTER();
                break;
            }

            realizarVenda(tabela, &heap, jogos.nome, jogos.quantidade);
            pressioneENTER();

            break;

        case '9':
            limparTela();
            printf("Reabastecer Estoque\n");
            imprimirHeap(&heap);
            printf("Informe o nome do jogo a ser reabastecido: ");
            scanf(" %[^\n]", jogos.nome);
            
            verificacao = VerificaNome(jogos.nome);
            if(verificacao == 1){
                printf("Nome invalido, redirecionando para o menu\n");
                pressioneENTER();
                break;
            }

            printf("Informe a quantidade do jogo a ser reabastecida: ");
            scanf("%d", &jogos.quantidade);

            verificacao = VerificanumInt(&jogos.quantidade);
            if(verificacao == 1){
                printf("Quantidade inválida, redirecionando para o menu\n");
                pressioneENTER();
                break;
            }

            reabastecerEstoque(tabela, &heap, jogos.nome, jogos.quantidade);
            pressioneENTER();

            break;

        default:
            limparTela();
            printf("Saindo...\n");
            break;
        }
    } while (opcao != '0');

    return 0;
}