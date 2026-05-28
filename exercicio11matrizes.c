#include <stdio.h>

int main() {
    int matriz1[3][3];
    int matriz2[3][3];
    int resultado[3][3];
    int i, j, k;
    int soma;

    // Leitura da primeira matriz
    printf("Digite os valores da primeira matriz 3x3:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Matriz1 [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Leitura da segunda matriz
    printf("\nDigite os valores da segunda matriz 3x3:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Matriz2 [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Multiplicação das matrizes
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {

            soma = 0;

            for(k = 0; k < 3; k++) {
                soma += matriz1[i][k] * matriz2[k][j];
            }

            resultado[i][j] = soma;
        }
    }

    // Exibição da matriz resultado
    printf("\nMatriz resultante da multiplicacao:\n\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%5d", resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
