// Aqui fiz um projeto para encontrar o menor e o maior valor digitado.

#include <cstdlib>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {

    float valor, maiorValor, menorValor;

    printf("\n\t Digite o valor: ");
    scanf(" %f", &valor);

    if (valor != 0){

      maiorValor = valor;
      menorValor = valor;

      while (valor != 0){

        if (valor < menorValor){
          menorValor = valor;
        } else
              if(valor > maiorValor){
                maiorValor = valor;
              }

        printf("\n\t Digite o valor: ");
        scanf(" %f", &valor);
      
      }
    
      printf("\n\t\t O maior valor é: %.2f \n", maiorValor);
      printf("\n\t\t O menor valor é: %.2f \n\n", menorValor);
    
    }

    return 0;
}
