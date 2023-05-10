// Este programa calcula a média de altura de um universo.

#include<stdio.h>

int main() {
    
    int contador;
    float altura, total, quantidade, media;
    
    contador = 0;
    total = 0;
    quantidade = 10;
    
    while (contador < quantidade){
    
      printf("\n\t Digite a altura: ");
      scanf(" %f", &altura);
      while (altura < 0.0 || altura > 2.5){
        printf("\n\t Valor inválido. Digite novamente a altura:");
        scanf(" %f", &altura);
      }
      
      total = total + altura;
      contador++;
    }

    media = total/quantidade;
    
    printf("\n\t\t A média de altura é: %.2f metro \n\n", media);
    
    return 0;
}

