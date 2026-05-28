#include <stdio.h>

int main() {
    int matriz[3][3];
    int i, j;
    int somaColuna;

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

    // Soma dos elementos de cada coluna
    printf("\nSoma de cada coluna:\n");

    for(j = 0; j < 3; j++) {
        somaColuna = 0;

        for(i = 0; i < 3; i++) {
            somaColuna += matriz[i][j];
        }

        printf("Coluna %d = %d\n", j + 1, somaColuna);
    }

    return 0;
}
