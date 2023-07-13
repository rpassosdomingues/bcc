/*
Exercício 1: Fazer um algoritmo que leia um vetor de 50 elementos de valores inteiros e com
os valores do vetor calcule e escreva:
  - O maior e menor valor do vetor
  - A média dos valores no vetor
  - A quantidade de valores acima e abaixo da média
*/

#include <stdio.h>

#define TAMANHO_VETOR 50

void calcularEstatisticas(int vetor[], int tamanho, int *maior, int *menor, float *media, int *acimaMedia, int *abaixoMedia) {
    int soma = 0;
    *maior = vetor[0];
    *menor = vetor[0];

    // Calcula a soma, o maior e o menor valor do vetor
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];

        if (vetor[i] > *maior) {
            *maior = vetor[i];
        }

        if (vetor[i] < *menor) {
            *menor = vetor[i];
        }
    }

    *media = (float)soma / tamanho;
    *acimaMedia = 0;
    *abaixoMedia = 0;

    // Calcula a quantidade de valores acima e abaixo da média
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] > *media) {
            (*acimaMedia)++;
        } else if (vetor[i] < *media) {
            (*abaixoMedia)++;
        }
    }
}

int main() {
    int vetor[TAMANHO_VETOR];

    // Lê os valores do vetor
    for (int i = 0; i < TAMANHO_VETOR; i++) {
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    int maior, menor, acimaMedia, abaixoMedia;
    float media;

    calcularEstatisticas(vetor, TAMANHO_VETOR, &maior, &menor, &media, &acimaMedia, &abaixoMedia);

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);
    printf("Média: %.2f\n", media);
    printf("Valores acima da média: %d\n", acimaMedia);
    printf("Valores abaixo da média: %d\n", abaixoMedia);

    return 0;
}
