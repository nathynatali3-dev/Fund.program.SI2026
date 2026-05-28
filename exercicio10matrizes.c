#include <stdio.h>

int main() {
    int matriz1[3][3];
    int matriz2[3][3];
    int i, j;
    int iguais = 1;

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

    // Comparação das matrizes
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {

            if(matriz1[i][j] != matriz2[i][j]) {
                iguais = 0;
            }

        }
    }

    // Exibição das matrizes
    printf("\nPrimeira matriz:\n\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%4d", matriz1[i][j]);
        }
        printf("\n");
    }

    printf("\nSegunda matriz:\n\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%4d", matriz2[i][j]);
        }
        printf("\n");
    }

    // Resultado da comparação
    if(iguais == 1) {
        printf("\nAs matrizes sao iguais.\n");
    } else {
        printf("\nAs matrizes sao diferentes.\n");
    }

    return 0;
}
