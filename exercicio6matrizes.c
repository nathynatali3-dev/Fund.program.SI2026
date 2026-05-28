#include <stdio.h>

int main() {
    int matriz[3][3];
    int i, j;
    int maior;

    // Leitura da matriz
    printf("Digite os valores da matriz 3x3:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Inicializa o maior com o primeiro elemento
    maior = matriz[0][0];

    // Procura o maior valor
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {

            if(matriz[i][j] > maior) {
                maior = matriz[i][j];
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

    // Exibição do maior valor
    printf("\nMaior valor da matriz = %d\n", maior);

    return 0;
}
