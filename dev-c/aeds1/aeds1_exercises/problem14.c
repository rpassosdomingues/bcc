/*
Exercício 3: Desenvolva um algoritmo que leia uma matriz de nxn (para n ≤ 100) valores
inteiros, calcule e apresente a transposta dessa matriz.
*/

#include <stdio.h>

#define TAMANHO_MAXIMO 100

void calcularTransposta(int matriz[][TAMANHO_MAXIMO], int tamanho) {
    int transposta[TAMANHO_MAXIMO][TAMANHO_MAXIMO];

    // Cálculo da matriz transposta
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            transposta[i][j] = matriz[j][i];
        }
    }

    // Apresentação da matriz transposta
    printf("Matriz transposta:\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int matriz[TAMANHO_MAXIMO][TAMANHO_MAXIMO];

    // Leitura do tamanho da matriz
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    if (n > TAMANHO_MAXIMO) {
        printf("O valor de n deve ser menor ou igual a %d\n", TAMANHO_MAXIMO);
        return 0;
    }

    // Leitura dos valores da matriz
    printf("Digite os valores da matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Valor [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    calcularTransposta(matriz, n);

    return 0;
}
