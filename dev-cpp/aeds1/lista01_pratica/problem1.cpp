/*
Projeto 1: Faça um algoritmo que leia um conjunto de dados contendo a altura
(de 1,00 m a 2,30 m) e o sexo (‘F’ ou ‘M’) mantendo a consistência das
informações. Interrompa a entrada de dados quando a altura for igual à
zero. Calcule e apresente:
1. a porcentagem de pessoas com altura maior que 1,80 m;
2. a média de altura dos homens;
3. a porcentagem de mulheres menores que 1,70 m entre todas
as pessoas.
*/

#include <stdio.h>

using namespace std;

int main() {

    float altura, pc180, mediaAlturaHomens, pcMulheres170, somaAlturasHomens, qtdHomens, qtdMulheres, qtdPessoas180, qtdMulheres170, totalPessoas;
    char sexo;

    altura = -1;
    qtdHomens = 0;
    qtdMulheres = 0;
    somaAlturasHomens = 0;
    qtdPessoas180 = 0;
    qtdMulheres170 = 0;

    while (altura != 0){

      printf("\n Digite a altura: ");
      scanf(" %f", &altura);
      while(altura < 1.00 || altura > 2.30){
        printf("\n Há algo errado! Tente de novo. \n");
        printf("\n Digite a altura: ");
        scanf(" %f", &altura);
      }

      if (altura >= 1.80){
        qtdPessoas180 = qtdPessoas180 + 1;
      }

      sexo = getchar();
      printf("\n Digite o sexo (M/F): ");
      scanf(" %c", &sexo);
      while(sexo != 'M' || sexo != 'F'){
        printf("\n Há algo errado! Tente de novo. \n");
        
        sexo = getchar();
        printf("\n Digite o sexo (M/F): ");
        scanf(" %c", &sexo);
      }

      if (sexo == 'M'){
        qtdHomens = qtdHomens + 1;
        somaAlturasHomens = somaAlturasHomens + altura;
      } else if (sexo == 'F'){
                qtdMulheres = qtdMulheres + 1;
              } if (altura <= 1.70){
                  qtdMulheres170 = qtdMulheres170 + 1;
                }

      totalPessoas = qtdHomens + qtdMulheres;

      pc180 = qtdPessoas180/totalPessoas;

      if (qtdHomens > 0){
        mediaAlturaHomens = somaAlturasHomens/qtdHomens;
      }

      pcMulheres170 = qtdMulheres170/qtdMulheres;

    }

    printf("\n\t -- Resultados -- \n");

    printf("\n\t %.2f %% das pessoas possuem altura maior que 1.80 m. \n", pc180);
    printf("\t A média de altura dos homens é de %.2f m \n", mediaAlturaHomens);
    printf("\n\t %.2f %% das mulheres possuem altura menor que 1.70 m. \n", pcMulheres170);

    return 0;
}
