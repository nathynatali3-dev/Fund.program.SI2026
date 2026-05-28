#include <stdio.h>

int main() {
    int matriz[3][3];
    int i, j;
    int soma = 0;

    // Leitura da matriz
    printf("Digite os valores da matriz 3x3:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            // Soma dos elementos
            soma += matriz[i][j];
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

    // Exibição da soma
    printf("\nSoma de todos os elementos = %d\n", soma);

    return 0;
}
