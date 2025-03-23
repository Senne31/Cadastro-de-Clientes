#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

struct Cliente {
    char nome[100];
    char email[100];
};

int main() {
	setlocale(LC_ALL,"Portuguese");
    struct Cliente clientes[100];
    int opcao, numClientes = 0;

    do {
        printf("\nSelecione uma opção:\n");
        printf("1 - Adicionar cliente\n");
        printf("2 - Visualizar clientes\n");
        printf("3 - Editar cliente\n");
        printf("4 - Excluir cliente\n");
        printf("5 - Sair\n");

        scanf("%d", &opcao);
        getchar(); // Corrige o problema do ENTER no buffer

        switch (opcao) {
            case 1: {
            	system("cls");
                printf("Digite o nome do cliente: ");
                fgets(clientes[numClientes].nome, sizeof(clientes[numClientes].nome), stdin);
                clientes[numClientes].nome[strcspn(clientes[numClientes].nome, "\n")] = 0; // Remove \n

                printf("Digite o email do cliente: ");
                fgets(clientes[numClientes].email, sizeof(clientes[numClientes].email), stdin);
                clientes[numClientes].email[strcspn(clientes[numClientes].email, "\n")] = 0; // Remove \n

                numClientes++;
                printf("Cliente adicionado com sucesso.\n");
                Sleep(4000);
                system("cls");
                break;
            }
            case 2: {
                if (numClientes == 0) {
                    printf("Nenhum cliente cadastrado.\n");
                } else {
                	system("cls");
                    printf("Clientes cadastrados:\n");
                    for (int i = 0; i < numClientes; i++) {
                        printf("Nome: %s\n", clientes[i].nome);
                        printf("Email: %s\n", clientes[i].email);
                        printf("----------------------\n");
                    }
                }
                break;
            }
            case 3: {
                char nome[100];

                printf("Digite o nome do cliente que deseja editar: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0; // Remove \n

                int encontrado = 0;
                for (int i = 0; i < numClientes; i++) {
                    if (strcmp(clientes[i].nome, nome) == 0) {
                        printf("Digite o novo nome do cliente: ");
                        fgets(clientes[i].nome, sizeof(clientes[i].nome), stdin);
                        clientes[i].nome[strcspn(clientes[i].nome, "\n")] = 0; // Remove \n

                        printf("Digite o novo email do cliente: ");
                        fgets(clientes[i].email, sizeof(clientes[i].email), stdin);
                        clientes[i].email[strcspn(clientes[i].email, "\n")] = 0; // Remove \n

                        printf("Cliente editado com sucesso.\n");
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Cliente não encontrado.\n");
                }
                break;
            }
            case 4: {
                char nome[100];

                printf("Digite o nome do cliente que deseja excluir: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0; // Remove \n

                int encontrado = 0;
                for (int i = 0; i < numClientes; i++) {
                    if (strcmp(clientes[i].nome, nome) == 0) {
                        for (int j = i; j < numClientes - 1; j++) {
                            clientes[j] = clientes[j + 1]; // Desloca os elementos
                        }
                        numClientes--;
                        printf("Cliente excluído com sucesso.\n");
                        encontrado = 1;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Cliente não encontrado.\n");
                }
                break;
            }
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}

