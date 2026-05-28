#include <stdio.h>

int main() {
    int matriz[3][3];
    int i, j;
    int somaLinha;

    // Leitura da matriz
    printf("Digite os valores da matriz 3x3:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Exibição da matriz
    printf("\nMatriz 3x3:\n\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    // Soma dos elementos de cada linha
    printf("\nSoma de cada linha:\n");

    for(i = 0; i < 3; i++) {
        somaLinha = 0;

        for(j = 0; j < 3; j++) {
            somaLinha += matriz[i][j];
        }

        printf("Linha %d = %d\n", i + 1, somaLinha);
    }

    return 0;
}
