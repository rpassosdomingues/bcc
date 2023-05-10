// Aqui eu fiz um projeto para calcular a média de valores digitados
// pelo usuário, sendo que o útltimo, que não entrará nos cálculos, será igual a 0 (zero).

// Aqui o zero será condição de parada.

#include <cstdlib>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {

    int contador;
    float total, quantidade, valor, media;
    
    contador = 0;
    total = 0;
    
    printf("\n\t Digite o valor: ");
    scanf(" %f", &valor);
    while (valor < 0.0){
      printf("\n\t Valor inválido. Digite novamente o valor:");
      scanf(" %f", &valor);
    }
    
    if (valor != 0){

      while (valor != 0){
      
        printf("\n\t Digite o valor: ");
        scanf(" %f", &valor);

        total = total + valor;
        contador = contador + 1;
        quantidade = contador - 1;

      }

      if (quantidade != 0){
        media = total/quantidade;
      }
      
      printf("\n\t\t A média de valores é: %.2f \n\n", media);
    }
    
    return 0;
}
