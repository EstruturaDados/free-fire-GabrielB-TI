#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITENS 10

struct Item {
    char nome[50];
    char tipo[30];
    int quantidade;
};

int main() {
    struct Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf("\n=== INVENTÁRIO BÁSICO ===\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                if (total >= MAX_ITENS) {
                    printf("Mochila cheia! Não é possível adicionar mais itens.\n");
                } else {
                    printf("\n--- Adicionar Item ---\n");
                    printf("Nome: ");
                    fgets(mochila[total].nome, 50, stdin);
                    mochila[total].nome[strcspn(mochila[total].nome, "\n")] = 0;

                    printf("Tipo: ");
                    fgets(mochila[total].tipo, 30, stdin);
                    mochila[total].tipo[strcspn(mochila[total].tipo, "\n")] = 0;

                    printf("Quantidade: ");
                    scanf("%d", &mochila[total].quantidade);
                    getchar();

                    total++;
                    printf("Item adicionado com sucesso!\n");
                }
                break;

            case 2:
                if (total == 0) {
                    printf("Nenhum item para remover.\n");
                } else {
                    char nomeRemover[50];
                    int encontrado = 0;
                    printf("\nNome do item a remover: ");
                    fgets(nomeRemover, 50, stdin);
                    nomeRemover[strcspn(nomeRemover, "\n")] = 0;

                    for (int i = 0; i < total; i++) {
                        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                            for (int j = i; j < total - 1; j++) {
                                mochila[j] = mochila[j + 1];
                            }
                            total--;
                            encontrado = 1;
                            printf("Item removido com sucesso!\n");
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf("Item não encontrado.\n");
                    }
                }
                break;

            case 3:
                if (total == 0) {
                    printf("Nenhum item cadastrado.\n");
                } else {
                    printf("\n--- Itens Cadastrados ---\n");
                    printf("%-20s %-20s %-10s\n", "NOME", "TIPO", "QUANTIDADE");
                    printf("-----------------------------------------------\n");
                    for (int i = 0; i < total; i++) {
                        printf("%-20s %-20s %-10d\n",
                               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                    }
                }
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}