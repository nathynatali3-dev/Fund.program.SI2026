#include <stdio.h>

#define DIAS 7
#define PERIODOS 3

// Protótipos das funções
void lerMatriz(float temp[DIAS][PERIODOS]);
void mediaDiaria(float temp[DIAS][PERIODOS], float medias[]);
float maiorDaSemana(float temp[DIAS][PERIODOS]);
int diaQuente(float temp[DIAS][PERIODOS]);
void exibirTabela(float temp[DIAS][PERIODOS], float medias[]);

int main() {
    float temperaturas[DIAS][PERIODOS];
    float medias[DIAS];
    float maiorTemp;
    int diaMaisQuente;

    lerMatriz(temperaturas);

    mediaDiaria(temperaturas, medias);

    maiorTemp = maiorDaSemana(temperaturas);

    diaMaisQuente = diaQuente(temperaturas);

    exibirTabela(temperaturas, medias);

    printf("\nMaior temperatura da semana: %.1f°C\n", maiorTemp);
    printf("Dia mais quente: Dia %d\n", diaMaisQuente + 1);

    return 0;
}

// Função para ler a matriz de temperaturas
void lerMatriz(float temp[DIAS][PERIODOS]) {
    for (int i = 0; i < DIAS; i++) {
        printf("\nDia %d\n", i + 1);

        printf("Temperatura da manha: ");
        scanf("%f", &temp[i][0]);

        printf("Temperatura da tarde: ");
        scanf("%f", &temp[i][1]);

        printf("Temperatura da noite: ");
        scanf("%f", &temp[i][2]);
    }
}

// Função para calcular a média de cada dia
void mediaDiaria(float temp[DIAS][PERIODOS], float medias[]) {
    for (int i = 0; i < DIAS; i++) {
        medias[i] = (temp[i][0] + temp[i][1] + temp[i][2]) / 3.0;
    }
}

// Função para encontrar a maior temperatura da semana
float maiorDaSemana(float temp[DIAS][PERIODOS]) {
    float maior = temp[0][0];

    for (int i = 0; i < DIAS; i++) {
        for (int j = 0; j < PERIODOS; j++) {
            if (temp[i][j] > maior) {
                maior = temp[i][j];
            }
        }
    }

    return maior;
}

// Função para determinar o dia mais quente
int diaQuente(float temp[DIAS][PERIODOS]) {
    int dia = 0;
    float maiorMedia = (temp[0][0] + temp[0][1] + temp[0][2]) / 3.0;

    for (int i = 1; i < DIAS; i++) {
        float media = (temp[i][0] + temp[i][1] + temp[i][2]) / 3.0;

        if (media > maiorMedia) {
            maiorMedia = media;
            dia = i;
        }
    }

    return dia;
}

// Função para exibir a tabela de temperaturas
void exibirTabela(float temp[DIAS][PERIODOS], float medias[]) {
    printf("\n===== TABELA DE TEMPERATURAS =====\n");
    printf("Dia\tManha\tTarde\tNoite\tMedia\n");

    for (int i = 0; i < DIAS; i++) {
        printf("%d\t%.1f\t%.1f\t%.1f\t%.1f\n",
               i + 1,
               temp[i][0],
               temp[i][1],
               temp[i][2],
               medias[i]);
    }
}
