#include <stdio.h>

#define TAM 10

// Protótipos das funções
void lerNotas(float notas[]);
float calcularMedia(float notas[]);
float maiorNota(float notas[]);
float menorNota(float notas[]);
void exibirResultados(float media, float maior, float menor);

int main() {
    float notas[TAM];
    float media, maior, menor;

    lerNotas(notas);

    media = calcularMedia(notas);
    maior = maiorNota(notas);
    menor = menorNota(notas);

    exibirResultados(media, maior, menor);

    return 0;
}

// Função para ler as notas
void lerNotas(float notas[]) {
    for (int i = 0; i < TAM; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }
}

// Função para calcular a média
float calcularMedia(float notas[]) {
    float soma = 0;

    for (int i = 0; i < TAM; i++) {
        soma += notas[i];
    }

    return soma / TAM;
}

// Função para encontrar a maior nota
float maiorNota(float notas[]) {
    float maior = notas[0];

    for (int i = 1; i < TAM; i++) {
        if (notas[i] > maior) {
            maior = notas[i];
        }
    }

    return maior;
}

// Função para encontrar a menor nota
float menorNota(float notas[]) {
    float menor = notas[0];

    for (int i = 1; i < TAM; i++) {
        if (notas[i] < menor) {
            menor = notas[i];
        }
    }

    return menor;
}

// Função para exibir os resultados
void exibirResultados(float media, float maior, float menor) {
    printf("\n=== RESULTADOS ===\n");
    printf("Media: %.2f\n", media);
    printf("Maior nota: %.2f\n", maior);
    printf("Menor nota: %.2f\n", menor);
}
