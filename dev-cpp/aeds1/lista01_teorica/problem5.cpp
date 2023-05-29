/*
Projeto 5 - Série de Taylor
*/

// bibliotecas necessárias
#include <stdio.h>
#include <math.h>

int main() {
    
    // declaração de variáveis
    int n, fatorialN;
    float x, soma, qtdTermos, numerador, denominador, proximoTermo;

    // inicialização de variáveis acumuladoras
    soma = 0.;
    qtdTermos = 1.;

    numerador = 1.;
    denominador = 1.;

    proximoTermo = 1.;

    // leitura de variáveis
    printf("\n x = ");
    scanf("\n %f", x);
    
    printf("\n n = ");
    scanf("\n %d", n);

    fatorialN = 1;
    while (n > 0){
        fatorialN = n * fatorialN;
        n--;
    }

    while (proximoTermo < fatorialN){
        numerador += pow(x,n);
        denominador += n;
        proximoTermo = numerador/denominador;

        soma += proximoTermo;

        n++;
        qtdTermos++;
    }
    
    // escreve resultados
    printf("\n\t exp(x) = %f \t|\t A série possui %f termos. \n\n", soma, qtdTermos);

    return 0;
}
