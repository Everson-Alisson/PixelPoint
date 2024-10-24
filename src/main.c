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
        pressioneENTER();
        limparTela();

        switch (opcao) {
        case '1':
            printf("Informe o nome do cliente: ");
            scanf(" %[^\n]", cliente.nome);
            
            verificacao = VerificaNome(cliente.nome);
            
            if(verificacao == 1){
                    while(VerificaNome(cliente.nome) == 1){
                    printf("Nome invalido, tente novamente\n");
                    printf("Deseja tentar novamente? (s/n)\n");
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite o nome do cliente: ");
                    scanf(" %[^\n]", cliente.nome);
                    }
                }
            
            printf("Informe o ID do cliente: ");
            scanf("%d", &cliente.id); 
            verificacao = VerificanumInt(&cliente.id);
                if(verificacao == 0){
                    printf("ID invalido, tente novamente\n");
                    break;
                }
            raiz = Inserir(raiz, cliente);
            if (raiz == NULL) {
                printf("Erro ao adicionar cliente\n");
                break;
            } else {
                printf("Cliente adicionado com sucesso\n");
            }

            Imprimir_AVL(raiz);
            
            break;
        case '2':
            Imprimir_AVL(raiz);

            printf("----------------------------------------\n\n");
            printf("Informe o ID do cliente a ser removido: ");
            scanf("%d", &cliente.id);
            
            verificacao = VerificanumInt(&cliente.id);
                if(verificacao == 0){
                    printf("ID invalido, tente novamente\n");
                    break;
                }
            
            raiz = Deletar_node(raiz, cliente.id);
            if (raiz == NULL) {
                printf("Erro ao remover cliente\n");
                break;
            } else {
                printf("Cliente removido com sucesso\n");
            }

            break;
        case '3':
            printf("Informe o nome do cliente a ser buscado: ");
            scanf(" %[^\n]", cliente.nome);
            
            verificacao = VerificaNome(cliente.nome);
            
            if(verificacao == 1){
                    while(VerificaNome(cliente.nome) == 1){
                    printf("Nome invalido, tente novamente\n");
                    printf("Deseja tentar novamente? (s/n)\n");
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite o nome do cliente: ");
                    scanf(" %[^\n]", cliente.nome);
                    }
                }

            Imprimir_AVL(raiz);
            Buscar(raiz, cliente.id);

            break;
        case '4':
            while (1) {
                    printf("Informe o nome do jogo: ");
                    scanf(" %[^\n]", jogos.nome);
                    if (jogoExiste(tabela, jogos.nome)) {
                        printf("Erro: Jogo com o nome '%s' ja existe. Tente novamente.\n", jogos.nome);
                        continue;
                    }
                    printf("Informe o preco do jogo: ");
                    scanf("%f", &jogos.preco);
                    
                    verificacao = VerificanumInt(&cliente.id);
                        if(verificacao == 0){
                        printf("ID invalido, tente novamente\n");
                        break;
                        }

                    printf("Informe a quantidade do jogo: ");
                    scanf("%d", &jogos.quantidade);
                    
                    verificacao = VerificanumInt(&cliente.id);
                        if(verificacao == 0){
                        printf("ID invalido, tente novamente\n");
                        break;
                        }

                    jogos.id = gerarIdUnico();

                    inserirNaTabela(tabela, jogos.id, jogos.nome, jogos.preco, jogos.quantidade);
                    inserirNoHeap(&heap, criarJogo(jogos.id, jogos.nome, jogos.preco, jogos.quantidade));

                    printf("Jogo cadastrado com sucesso!\n");
                    
                    break;
                }
                
                break;
        case '5':
                imprimirTabela(tabela);
                printf("Informe o nome do jogo a ser removido: ");
                scanf(" %[^\n]", jogos.nome);
                
                verificacao = VerificaNome(jogos.nome);
                if(verificacao == 1){
                    while(VerificaNome(jogos.nome) == 1){
                    printf("Nome invalido, tente novamente\n");
                    printf("Deseja tentar novamente? (s/n)\n");
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite o nome do jogos: ");
                    scanf(" %[^\n]", jogos.nome);
                    }
                }

                excluirJogo(tabela, jogos.nome);
                removerDoHeapPorNome(&heap, jogos.nome);
                printf("Jogo removido com sucesso!\n");
                
                break;
        case '6':
            printf("Estoque\n");
            imprimirTabela(tabela);
            
            break;
        case '7':
            printf("Informe o nome do jogo a ser buscado: ");
            scanf(" %[^\n]", jogos.nome);
            
            verificacao = VerificaNome(jogos.nome);
                if(verificacao == 1){
                    while(VerificaNome(jogos.nome) == 1){
                    printf("Nome invalido, tente novamente\n");
                    printf("Deseja tentar novamente? (s/n)\n");
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite o nome do jogos: ");
                    scanf(" %[^\n]", jogos.nome);
                    }
                }

            buscarNaTabela(tabela, jogos.nome);
            
            break;
        case '8':
            printf("Informe o nome do jogo a ser vendido: ");
            scanf(" %[^\n]", jogos.nome);
            
            verificacao = VerificaNome(jogos.nome);
                if(verificacao == 1){
                    while(VerificaNome(jogos.nome) == 1){
                    printf("Nome invalido, tente novamente\n");
                    printf("Deseja tentar novamente? (s/n)\n");
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite o nome do jogos: ");
                    scanf(" %[^\n]", jogos.nome);
                    }
                }

            printf("Informe a quantidade do jogo a ser vendida: ");
            scanf("%d", &jogos.quantidade);

            verificacao = VerificanumInt(&cliente.id);
                if(verificacao == 0){
                printf("ID invalido, tente novamente\n");
                break;
                }

            realizarVenda(tabela, &heap, jogos.nome, jogos.quantidade);
            break;

        case '9':
            printf("Reabastecer Estoque\n");
            imprimirHeap(&heap);
            printf("Informe o nome do jogo a ser reabastecido: ");
            scanf(" %[^\n]", jogos.nome);
            
            verificacao = VerificaNome(jogos.nome);
                if(verificacao == 1){
                    while(VerificaNome(jogos.nome) == 1){
                    printf("Nome invalido, tente novamente\n");
                    printf("Deseja tentar novamente? (s/n)\n");
                    char tentar;
                    scanf(" %c", &tentar);
                    if(tentar == 'n'){
                        break;
                    }
                    printf("Digite o nome do jogos: ");
                    scanf(" %[^\n]", jogos.nome);
                    }
                }

            printf("Informe a quantidade do jogo a ser reabastecida: ");
            scanf("%d", &jogos.quantidade);

            verificacao = VerificanumInt(&cliente.id);
                if(verificacao == 0){
                printf("ID invalido, tente novamente\n");
                break;
                }

            reabastecerEstoque(tabela, &heap, jogos.nome, jogos.quantidade);
            break;

        default:
            limparTela();
            printf("Saindo...\n");
            break;
        }
    } while (opcao != '0');

    return 0;
}