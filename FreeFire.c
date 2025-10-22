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
    return 0;
}