/*
Exercício 11: Faça uma rotina com um parâmetro inteiro n e que ao ser chamado, imprime
uma figura da seguinte forma:

....*....
...***...
..*****..
.*******.
*********
.*******.
..*****..
...***...
....*....

No caso, a rotina foi chamada com o parâmetro 5. A quantidade de linhas impressas será
sempre 2n-1.

*/

#include <stdio.h>

void imprimirFigura(int n) {
    int linhas = 2 * n - 1;
    int espacos = n - 1;
    int asteriscos = 1;

    for (int i = 1; i <= linhas; i++) {
        for (int j = 1; j <= espacos; j++) {
            printf(".");
        }

        for (int j = 1; j <= asteriscos; j++) {
            printf("*");
        }

        for (int j = 1; j <= espacos; j++) {
            printf(".");
        }

        printf("\n");

        if (i < n) {
            espacos--;
            asteriscos += 2;
        } else {
            espacos++;
            asteriscos -= 2;
        }
    }
}

int main() {
    int n;

    // Leitura do parâmetro inteiro
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    // Chamada da rotina para imprimir a figura
    imprimirFigura(n);

    return 0;
}
