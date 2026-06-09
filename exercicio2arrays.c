#include <stdio.h>

#define TAM 15

// Protótipos das funções
void lerVetor(int vetor[]);
int buscar(int vetor[], int numero);
int contar(int vetor[], int numero);
void exibirInverso(int vetor[]);

int main() {
    int vetor[TAM];
    int numero;

    lerVetor(vetor);

    printf("\nDigite o numero que deseja procurar: ");
    scanf("%d", &numero);

    if (buscar(vetor, numero)) {
        printf("O numero %d existe no vetor.\n", numero);
        printf("Ele aparece %d vez(es).\n", contar(vetor, numero));
    } else {
        printf("O numero %d nao existe no vetor.\n", numero);
    }

    exibirInverso(vetor);

    return 0;
}

// Função para ler os elementos do vetor
void lerVetor(int vetor[]) {
    for (int i = 0; i < TAM; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

// Função para verificar se o número existe
int buscar(int vetor[], int numero) {
    for (int i = 0; i < TAM; i++) {
        if (vetor[i] == numero) {
            return 1; // Encontrou
        }
    }
    return 0; // Não encontrou
}

// Função para contar quantas vezes o número aparece
int contar(int vetor[], int numero) {
    int contador = 0;

    for (int i = 0; i < TAM; i++) {
        if (vetor[i] == numero) {
            contador++;
        }
    }

    return contador;
}

// Função para exibir o vetor em ordem inversa
void exibirInverso(int vetor[]) {
    printf("\nVetor em ordem inversa:\n");

    for (int i = TAM - 1; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }

    printf("\n");
}
