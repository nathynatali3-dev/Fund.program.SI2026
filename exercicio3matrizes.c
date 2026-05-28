#include <stdio.h>

int main() {
    int matriz[3][3];
    int i, j;
    int pares = 0;

    // Leitura da matriz
    printf("Digite os valores da matriz 3x3:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            // Verifica se o número é par
            if(matriz[i][j] % 2 == 0) {
                pares++;
            }
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

    // Exibição da quantidade de pares
    printf("\nQuantidade de elementos pares = %d\n", pares);

    return 0;
}
