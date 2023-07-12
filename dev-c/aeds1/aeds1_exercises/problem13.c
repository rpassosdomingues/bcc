/*
Exercício 2: Modifique o algoritmo de ordenação por seleção para ordenar somente os k
primeiro valores de um vetor de 100 elementos do tipo inteiro. O valor k deve ser lido.
*/

#include <stdio.h>

#define TAMANHO_VETOR 100

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordenarSelecao(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int indice_minimo = i;

        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indice_minimo]) {
                indice_minimo = j;
            }
        }

        trocar(&vetor[i], &vetor[indice_minimo]);
    }
}

int main() {
    int vetor[TAMANHO_VETOR];

    // Lê os valores do vetor
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    int k;
    printf("Digite o valor de k: ");
    scanf("%d", &k);

    if (k > TAMANHO_VETOR) {
        printf("O valor de k deve ser menor ou igual a %d\n", TAMANHO_VETOR);
        return 0;
    }

    ordenarSelecao(vetor, k);

    printf("Os primeiros %d valores ordenados:\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
