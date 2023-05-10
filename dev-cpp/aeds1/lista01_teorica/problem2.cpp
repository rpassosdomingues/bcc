/*
Projeto 2 - Foi feita uma pesquisa para determinar o ı́ndice de mortalidade infantil num
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

  int contador, teto, numNascidos, numMortos, mesesVida, pcMortes, mortesMasc, mortesFem, pcMortesMasc, numVidas24, pcVidas24;
  char sexo;

  contador = 1;
  teto = 4;
  
  numNascidos = 0;
  numMortos = 0;
  numVidas24 = 0;
  mortesMasc = 0;
  mortesFem = 0;

  printf("\n Digite o número de crianças nascidas: ");
  scanf(" %d", &numNascidos);

  while (contador < teto){
    
    printf("\n Menino ou Menina? (m/f): ");
    scanf(" %c", &sexo);

    printf("\n Quantos meses a criança viveu? ");
    scanf(" %d", &mesesVida);
      
    if (sexo == 'm' && mesesVida <= 24){
      numMortos++;
      numVidas24++;
      mortesMasc++;
    }
    
    if (sexo == 'f'){
      numMortos++;
      numVidas24++;
      mortesFem++;
    }
    
    pcMortes = numMortos/numNascidos;
    pcMortesMasc = mortesMasc/numNascidos;
    pcVidas24 = numVidas24/numMortos;

    contador = contador + 1;
  }

  printf("\n\t -- Resultados -- \n");

  printf("\n\t %d %% de crianças mortas no periodo. \n", pcMortes);
  printf("\n\t %d %% de meninos mortos no periodo. \n", pcMortesMasc);
  printf("\n\t %d %% de crianças que viveram até 2 anos no periodo. \n", pcVidas24);

  return 0;
}

