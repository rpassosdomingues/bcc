/*
Projeto 1: A empresa XYZ fez uma pesquisa de mercado para saber se seus clientes gostaram
ou não de um novo produto que foi lançado pela empresa recentemente. Para isto, perguntou
a idade e se o cliente gostou ou não do produto. Sabendo-se que foram feitas 200 entrevistas,
fazer um algoritmo que calcule e escreva:

1 - O número de pessoas que responderam sim.
2 - O número de pessoas que responderam não.
3 - A média de idade das pessoas que responderam sim.
4 - O mais velho e o mais novo que respondeu sim.
*/

#include <stdio.h>

using namespace std;

int main() {

    int contador, teto, idade, qtdSim, qtdNao, somaIdadeSim, mediaIdadeSim, maisVelhoSim, maisNovoSim;
    char resposta;

    contador = 1;
    teto = 4; // limite da repetição
    
    qtdSim = 0;
    qtdNao = 0;
    
    somaIdadeSim = 0;
    
    maisVelhoSim = 150;
    maisNovoSim = -1;

    while (contador < teto){

      printf("\n Quantos anos você tem? ");
      scanf(" %d", &idade);
      
      printf("\n Você gostou do novo produto? (s/n) ");
      scanf(" %c", &resposta);
      
      if (resposta == 's'){
        qtdSim = qtdSim + 1;
        somaIdadeSim = somaIdadeSim + idade;
        } else
          if (idade > maisVelhoSim){
            maisVelhoSim = idade;
          } else
            if (idade < maisNovoSim){
              maisNovoSim = idade;
            }
      if (resposta == 'n'){
        qtdNao = qtdNao + 1;
      }
               
      if (qtdSim > 0){
        mediaIdadeSim = somaIdadeSim/qtdSim;
      }
      
      contador = contador + 1;
    }

    printf("\n\t -- Resultados -- \n");

    printf("\n\t %d pessoas responderam -SIM- \n", qtdSim);
    printf("\t %d pessoas responderam -NÃO- \n", qtdNao);
    
    printf("\n\t A média de idade das pessoas que responderam -SIM- é de %d anos \n", mediaIdadeSim);
    
    printf("\n\t O mais velho tem %d anos \n", maisVelhoSim);
    printf("\t O mais novo tem %d anos \n\n", maisNovoSim);

    return 0;
}
