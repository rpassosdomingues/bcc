/*
Exercício 9: Desenvolva uma função que recebe três parâmetros numéricos e retorna o maior
valor dos três parâmetros
*/

#include <stdio.h>

int encontrarMaior(int a, int b, int c) {
    int maior = a;

    if (b > maior) {
        maior = b;
    }

    if (c > maior) {
        maior = c;
    }

    return maior;
}

int main() {
    int num1, num2, num3;

    // Leitura dos números
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);
    printf("Digite o terceiro número: ");
    scanf("%d", &num3);

    // Chamada da função para encontrar o maior número
    int maior = encontrarMaior(num1, num2, num3);

    // Impressão do maior número
    printf("O maior número é: %d\n", maior);

    return 0;
}
