/*
Projeto 8 - Foi feita uma pesquisa para determinar o ı́ndice de mortalidade infantil num
certo perı́odo. Fazer um algoritmo que:

Leia o número de crianças nascidas no perı́odo investigado.

Leia um número indeterminado com o sexo da criança morta(masculino ou feminino) e o
número de meses de vida da criança. O último valor lido contém a palavra ”FIM” para o
sexo.

O algoritmo deve então determinar e imprimir:
– A percentagem de crianças mortas no perı́odo.
– A percentagem de crianças do sexo masculino mortas no perı́odo.
– A percentagem de crianças que viveram 24 meses ou menos no perı́odo.
*/

#include <stdio.h>

using namespace std;

int main(){

  int qtdNascidos=0, qtdMortos=0, qtdVidas24=0, qtdMortesMasc=0, qtdMortesFem=0;
  float mesesVida, pcMortes, pcMortesMasc, pcVidas24;
  char sexo;

  printf("\n Digite o número de crianças nascidas: ");
  scanf(" %d", &qtdNascidos);

  while (qtdMortos <= 5){
    
    printf("\n Digite o sexo (M/F): ");
    scanf(" %c", &sexo);
      while (sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f') {
        printf("\n Há algo errado! Tente de novo. ");
        scanf(" %c", &sexo);
      }

    printf("\n Quantos meses a criança viveu? ");
    scanf(" %f", &mesesVida);
    
    if (sexo == 'm'){
      qtdMortesMasc++;
    }

    if(mesesVida <= 24){
      qtdVidas24++;
    }

    qtdMortos++;
  }

  pcMortes = (float)qtdMortos / qtdNascidos * 100;
  pcMortesMasc = (float)qtdMortesMasc / qtdNascidos * 100;
  pcVidas24 = (float)qtdVidas24 / qtdMortos * 100;

  printf("\n\t === Resultados === \n");

  printf("\n\t %.2f%% das crianças mortas no periodo. \n", pcMortes);
  printf("\n\t %.2f%% dos meninos mortos no periodo. \n", pcMortesMasc);
  printf("\n\t %.2f%% das crianças viveram até 2 anos no periodo. \n\n", pcVidas24);

  return 0;
}

