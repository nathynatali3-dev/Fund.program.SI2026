#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 10
#define TAM_NOME 50
#define TAM_TEL 20

// Protótipos
void cadastrar(char nomes[][TAM_NOME], char telefones[][TAM_TEL], int *qtd);
void listar(char nomes[][TAM_NOME], char telefones[][TAM_TEL], int qtd);
int buscar(char nomes[][TAM_NOME], int qtd, char nome[]);
void remover(char nomes[][TAM_NOME], char telefones[][TAM_TEL], int *qtd);
int menu();

int main() {
    char nomes[MAX_CONTATOS][TAM_NOME];
    char telefones[MAX_CONTATOS][TAM_TEL];
    int qtd = 0;
    int opcao;

    do {
        opcao = menu();

        switch(opcao) {
            case 1:
                cadastrar(nomes, telefones, &qtd);
                break;

            case 2:
                listar(nomes, telefones, qtd);
                break;

            case 3: {
                char nome[TAM_NOME];
                int pos;

                printf("Nome para buscar: ");
                fgets(nome, TAM_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                pos = buscar(nomes, qtd, nome);

                if (pos != -1)
                    printf("Telefone: %s\n", telefones[pos]);
                else
                    printf("Contato nao encontrado.\n");

                break;
            }

            case 4:
                remover(nomes, telefones, &qtd);
                break;

            case 0:
                printf("Encerrando agenda...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}

// Menu principal
int menu() {
    int op;

    printf("\n===== AGENDA =====\n");
    printf("1 - Cadastrar contato\n");
    printf("2 - Listar contatos\n");
    printf("3 - Buscar contato\n");
    printf("4 - Remover contato\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &op);
    getchar(); // limpa o ENTER

    return op;
}

// Cadastrar contato
void cadastrar(char nomes[][TAM_NOME], char telefones[][TAM_TEL], int *qtd) {
    if (*qtd >= MAX_CONTATOS) {
        printf("Agenda cheia!\n");
        return;
    }

    printf("Nome: ");
    fgets(nomes[*qtd], TAM_NOME, stdin);
    nomes[*qtd][strcspn(nomes[*qtd], "\n")] = '\0';

    printf("Telefone: ");
    fgets(telefones[*qtd], TAM_TEL, stdin);
    telefones[*qtd][strcspn(telefones[*qtd], "\n")] = '\0';

    (*qtd)++;

    printf("Contato cadastrado com sucesso!\n");
}

// Listar contatos
void listar(char nomes[][TAM_NOME], char telefones[][TAM_TEL], int qtd) {
    if (qtd == 0) {
        printf("Agenda vazia.\n");
        return;
    }

    printf("\n--- CONTATOS ---\n");

    for (int i = 0; i < qtd; i++) {
        printf("%d. %s - %s\n",
               i + 1,
               nomes[i],
               telefones[i]);
    }
}

// Buscar contato pelo nome
int buscar(char nomes[][TAM_NOME], int qtd, char nome[]) {
    for (int i = 0; i < qtd; i++) {
        if (strcmp(nomes[i], nome) == 0) {
            return i;
        }
    }

    return -1;
}

// Remover contato substituindo pelo último
void remover(char nomes[][TAM_NOME], char telefones[][TAM_TEL], int *qtd) {
    char nome[TAM_NOME];
    int pos;

    if (*qtd == 0) {
        printf("Agenda vazia.\n");
        return;
    }

    printf("Nome a remover: ");
    fgets(nome, TAM_NOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    pos = buscar(nomes, *qtd, nome);

    if (pos == -1) {
        printf("Contato nao encontrado.\n");
        return;
    }

    strcpy(nomes[pos], nomes[*qtd - 1]);
    strcpy(telefones[pos], telefones[*qtd - 1]);

    (*qtd)--;

    printf("Contato removido com sucesso!\n");
}
