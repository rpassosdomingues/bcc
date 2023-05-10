// Aqui eu escrevi um programa que dados os três valores de entrada
// representando lados de um triângulo me diz se há formação possível de triângulo
// e em caso de teste verdadeiro, classifica o tipo de triângulo de acordo com a distribuição.

#include <cstdlib>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {

    float ladoA, ladoB, ladoC;
    
    printf("\n\t Tipos de Triângulos. \n\n");
        
    printf("\n\t Digite o primeiro lado: ");
    scanf(" %f", &ladoA);
    while (ladoA <= 0.0){
        printf("\n\t Valor inválido, digite novamente o primeiro lado: ");
        scanf(" %f", &ladoA);
    }
    printf("\n\t Digite o segundo lado: ");
    scanf(" %f", &ladoB);
    while (ladoB <= 0.0){
        printf("\n\t Valor inválido, digite novamente o segundo lado: ");
        scanf(" %f", &ladoB);
    }
    printf("\n\t Digite o terceiro lado: ");
    scanf(" %f", &ladoC);
    while (ladoC <= 0.0){
        printf("\n\t Valor inválido, digite novamente o terceiro lado: ");
        scanf(" %f", &ladoC);
    }
    
    if ((ladoA + ladoB < ladoC) || (ladoB + ladoC < ladoA) || (ladoA + ladoC < ladoB)){ // Início do 1° if.
        printf("\n\t Estes lados não podem formar um triângulo.\n\n");
    } else {                                        		    			// Início do 1º else.
        if ((ladoA == ladoB) && (ladoA == ladoC)){                  			// Início do 2º if.
            printf("\n\t Estes lados formam um triângulo equilátero.\n\n");
        } else {                                    					// Início do 2º else.
            if ((ladoA == ladoB) || (ladoA == ladoC) || (ladoB == ladoC)){  		// Início do 3º if.
                printf("\n\t Estes lados formam um triângulo isósceles.\n\n");
            } else {                                					// Início do 3º else.
                printf("\n\t Estes lados formam um triângulo escaleno.\n\n");
            }                                       					// Fim do 3º if e else.
            if ((ladoA*ladoA == ladoB*ladoB+ladoC*ladoC) || (ladoB*ladoB == ladoA*ladoA+ladoC*ladoC) || (ladoC*ladoC == ladoB*ladoB+ladoA*ladoA)){ // Início do 4º if.
                printf("\t Estes lados formam um triângulo retângulo.\n\n");
            }                                       					// Fim do 4º if.
        }                                           					// Fim do 2º if e else.
    }                                               					// Fim do 1º if e else.
    
    return 0;
}
