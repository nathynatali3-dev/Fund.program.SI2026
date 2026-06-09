#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 5
#define MAX 50

// Protótipos das funções
void lerNomes(char nomes[TAM][MAX]);
void paraMaiusculas(char nomes[TAM][MAX]);
void ordenarNomes(char nomes[TAM][MAX]);
int buscarNome(char nomes[TAM][MAX], char nome[]);

int main() {
    char nomes[TAM][MAX];
    char nomeBusca[MAX];
    int posicao;

    lerNomes(nomes);

    paraMaiusculas(nomes);

    ordenarNomes(nomes);

    printf("\nNomes em ordem alfabetica:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%s\n", nomes[i]);
    }

    printf("\nDigite o nome que deseja buscar: ");
    fgets(nomeBusca, MAX, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    // Converte o nome digitado para maiúsculas
    for (int i = 0; nomeBusca[i] != '\0'; i++) {
        nomeBusca[i] = toupper(nomeBusca[i]);
    }

    posicao = buscarNome(nomes, nomeBusca);

    if (posicao != -1) {
        printf("Nome encontrado na posicao %d.\n", posicao + 1);
    } else {
        printf("Nome nao encontrado.\n");
    }

    return 0;
}

// Função para ler os nomes
void lerNomes(char nomes[TAM][MAX]) {
    for (int i = 0; i < TAM; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(nomes[i], MAX, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';
    }
}

// Função para converter os nomes para maiúsculas
void paraMaiusculas(char nomes[TAM][MAX]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; nomes[i][j] != '\0'; j++) {
            nomes[i][j] = toupper(nomes[i][j]);
        }
    }
}

// Função para ordenar os nomes (Bubble Sort)
void ordenarNomes(char nomes[TAM][MAX]) {
    char aux[MAX];

    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - 1 - i; j++) {
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                strcpy(aux, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], aux);
            }
        }
    }
}

// Função para buscar um nome
int buscarNome(char nomes[TAM][MAX], char nome[]) {
    for (int i = 0; i < TAM; i++) {
        if (strcmp(nomes[i], nome) == 0) {
            return i;
        }
    }
    return -1;
}
