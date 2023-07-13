/*
Exercício 10: Desenvolva uma função com os parâmetros N (número de elementos do vetor)
e V (vetor de valores numéricos) e que retorna a soma dos valores do vetor.
*/

#include <stdio.h>

int calcularSoma(int N, int V[]) {
    int soma = 0;
    
    for (int i = 0; i < N; i++) {
        soma += V[i];
    }
    
    return soma;
}

int main() {
    int N;
    
    // Leitura do número de elementos do vetor
    printf("Digite o número de elementos do vetor: ");
    scanf("%d", &N);
    
    int V[N];
    
    // Leitura dos valores do vetor
    printf("Digite os valores do vetor:\n");
    for (int i = 0; i < N; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &V[i]);
    }
    
    // Chamada da função para calcular a soma
    int soma = calcularSoma(N, V);
    
    // Impressão da soma dos valores
    printf("A soma dos valores do vetor é: %d\n", soma);
    
    return 0;
}
