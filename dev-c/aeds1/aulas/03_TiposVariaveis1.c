// Este programa tem como objetivo
// imprimir na tela diferentes tipos de variáveis
// e como cada tipo é alocado na memória do computador.

// Interessante notar o quanto de memória cada tipo de variável ocupa.

#include<stdio.h>
#include<cstdlib>

using namespace std;

int main(int argc, char** argv) {
    
    printf("\n\t Tipos de Variáveis e Alocação de Memória \n\n");
    
    int valorint = 50;
    
    printf("\t Variável Inteira: \n");
    printf("\t\t Valor Armazenado: %d\n", valorint);  // %d indica que o printf()
    						      // deve imprimir um valor inteiro.
    printf("\t\t Endereço na Memória: %p\n", &valorint);
    printf("\t\t Quantidade em bytes: %ld\n\n", sizeof(int));  // -sizeof- calcula o tamanho
    							       // do operando.
    
    float valorfloat = 50;
    
    printf("\t Variável Float: \n");
    printf("\t\t Valor Armazenado: %f\n", valorfloat);  // %f indica que o printf()
    						        // deve imprimir um valor ponto-flutuante.
    
    printf("\t\t Endereço na Memória: %p\n", &valorfloat);
    printf("\t\t Quantidade em bytes: %ld\n\n", sizeof(float));
    
    char valorchar = 64;
    
    printf("\t Variável Char: \n");
    printf("\t\t Valor Armazenado: %c\n", valorchar);  // %c indica que o printf()
    						       // deve imprimir um caracter.
    
    printf("\t\t Endereço na Memória: %p\n", &valorchar);
    printf("\t\t Quantidade em bytes: %ld\n\n", sizeof(char));
    
    return 0;
}

