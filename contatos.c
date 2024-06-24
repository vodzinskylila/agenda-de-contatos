#include <stdio.h>

#include <stdlib.h>

#include <string.h>
 
#define MAX_CONTATOS 100

#define TAM_NOME 50

#define TAM_TELEFONE 15
 
typedef struct {

    char nome[TAM_NOME];

    char telefone[TAM_TELEFONE];

} Contato;
 
Contato contatos[MAX_CONTATOS];

int total_contatos = 0;
 
void limparEntrada() {

    int c;

    while ((c = getchar()) != '\n' && c != EOF);

}
 
void adicionarContato() {

    if (total_contatos >= MAX_CONTATOS) {

        printf("Catálogo cheio! Não é possível adicionar mais contatos.\n");

        return;

    }
 
    printf("Digite o nome: ");

    fgets(contatos[total_contatos].nome, TAM_NOME, stdin);

    contatos[total_contatos].nome[strcspn(contatos[total_contatos].nome, "\n")] = '\0'; // Remove newline
 
    printf("Digite o telefone: ");

    fgets(contatos[total_contatos].telefone, TAM_TELEFONE, stdin);

    contatos[total_contatos].telefone[strcspn(contatos[total_contatos].telefone, "\n")] = '\0'; // Remove newline
 
    total_contatos++;

    printf("Contato adicionado com sucesso!\n");

}
 
void listarContatos() {

    if (total_contatos == 0) {

        printf("Nenhum contato no catálogo.\n");

        return;

    }
 
    printf("Lista de contatos:\n");

    for (int i = 0; i < total_contatos; i++) {

        printf("Contato %d\n", i + 1);

        printf("Nome: %s\n", contatos[i].nome);

        printf("Telefone: %s\n", contatos[i].telefone);

    }

}
 
void buscarContato() {

    char nome[TAM_NOME];

    printf("Digite o nome do contato a ser buscado: ");

    fgets(nome, TAM_NOME, stdin);

    nome[strcspn(nome, "\n")] = '\0'; // Remove newline
 
    for (int i = 0; i < total_contatos; i++) {

        if (strcmp(contatos[i].nome, nome) == 0) {

            printf("Contato encontrado:\n");

            printf("Nome: %s\n", contatos[i].nome);

            printf("Telefone: %s\n", contatos[i].telefone);

            return;

        }

    }
 
    printf("Contato não encontrado.\n");

}
 
void excluirContato() {

    char nome[TAM_NOME];

    printf("Digite o nome do contato a ser excluído: ");

    fgets(nome, TAM_NOME, stdin);

    nome[strcspn(nome, "\n")] = '\0'; // Remove newline
 
    for (int i = 0; i < total_contatos; i++) {

        if (strcmp(contatos[i].nome, nome) == 0) {

            for (int j = i; j < total_contatos - 1; j++) {

                contatos[j] = contatos[j + 1];

            }

            total_contatos--;

            printf("Contato excluído com sucesso!\n");

            return;

        }

    }
 
    printf("Contato não encontrado.\n");

}
 
void exibirMenu() {

    printf("\nCatálogo de Contatos\n");

    printf("1. Adicionar Contato\n");

    printf("2. Listar Contatos\n");

    printf("3. Buscar Contato\n");

    printf("4. Excluir Contato\n");

    printf("5. Sair\n");

    printf("Escolha uma opção: ");

}
 
int main() {

    int opcao;
 
    while (1) {

        exibirMenu();

        scanf("%d", &opcao);

        limparEntrada(); // Limpa a entrada para evitar problemas com fgets
 
        switch (opcao) {

            case 1:

                adicionarContato();

                break;

            case 2:

                listarContatos();

                break;

            case 3:

                buscarContato();

                break;

            case 4:

                excluirContato();

                break;

            case 5:

                printf("Saindo...\n");

                exit(0);

            default:

                printf("Opção inválida! Tente novamente.\n");

        }

    }
 
    return 0;

}