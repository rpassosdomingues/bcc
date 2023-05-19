/*
Projeto 2 - Foi realizada uma pesquisa de algumas características físicas de
habitantes de certa região. De cada habitante foram coletados os
seguintes dados: tipo sanguíneo (“O”, “A”, “B” ou “AB”), RH (positivo “+”
ou negativo “-“), pressão arterial máxima (entre 7 e 25), pressão arterial
mínima (entre 2 e 20) e idade (entre 18 e 130 anos). Não permita que o
usuário entre com informações erradas nos campos e estabeleça um
critério de parada. Faça um algoritmo que calcule a porcentagem de
pessoas com sangue A- ou B-, entre as pessoas com pressão alta, as quais
possuem pressão arterial acima de 14 para a máxima ou acima de 10
para a mínima.
*/

#include <stdio.h>

using namespace std;

int main() {

    float pcPessoasAnBn;
    float pcPessoasPressaoAlta;
    float pcPessoasAnBnPressaoAlta;
    
    int qtdPessoasAnBn = 0;
    int qtdPessoasPressaoAlta = 0;
    int qtdPessoasAnBnPressaoAlta = 0;
    int qtdPessoas = 0;

    int pressaoArterialSistolica;
    int pressaoArterialDiastolica;
    int idade;
    
    char tipoSanguineo, tipoRh;

    while (qtdPessoas < 5){

      printf("\n Digite a idade [18 < idade < 130]: ");
      scanf(" %d", &idade);
      while(idade < 18 || idade > 130){
        printf("\n Há algo errado! Tente de novo. \n");
        printf("\n Digite a idade [18 < idade < 130]: ");
        scanf(" %d", &idade);
      }

      printf("\n Digite o tipo sanguíneo ['a', 'b', 'ab', 'o'] --ESPAÇO-- ['p', 'n']: ");
      scanf(" %c %c", &tipoSanguineo, &tipoRh);
      while(tipoSanguineo != 'a' && tipoSanguineo != 'b' && tipoSanguineo != 'ab' && tipoSanguineo != 'o' || tipoRh != 'p' && tipoRh != 'n'){
        printf("\n Há algo errado! Tente de novo. \n");
        printf("\n Digite o tipo sanguíneo ['a', 'b', 'ab', 'o'] --ESPAÇO-- ['p', 'n']: ");
        scanf(" %c %c", &tipoSanguineo, &tipoRh);
      }

      printf("\n Digite a pressão arterial [Sistólica --ESPAÇO-- Diastólica]: ");
      scanf(" %d %d", &pressaoArterialSistolica, &pressaoArterialDiastolica);
      while((pressaoArterialSistolica < 7 || pressaoArterialSistolica > 25) && (pressaoArterialDiastolica < 2 || pressaoArterialDiastolica > 20)){
        printf("\n Há algo errado! Tente de novo. \n");
        printf("\n Digite a pressão arterial Sistólica_Diastólica: ");
        scanf(" %d %d", &pressaoArterialSistolica, &pressaoArterialDiastolica);
      }

      if(pressaoArterialSistolica > 14 || pressaoArterialDiastolica > 10){
        qtdPessoasPressaoAlta++;
      } if(tipoSanguineo == 'a' || tipoSanguineo == 'b'){
          if(tipoRh == 'n'){
            qtdPessoasAnBnPressaoAlta++;
          }
        }
        
      qtdPessoas++;

    }

    pcPessoasAnBn = (float)qtdPessoasAnBn / qtdPessoas * 100;
    pcPessoasPressaoAlta = (float)qtdPessoasPressaoAlta / qtdPessoas * 100;
    pcPessoasAnBnPressaoAlta = (float)qtdPessoasAnBnPressaoAlta / qtdPessoasPressaoAlta * 100;

    printf("\n\t === Resultados === \n");

    printf("\n\t %.2f%% das pessoas são hipertensas \n", pcPessoasPressaoAlta);
    printf("\n\t Dentre as hipertensas, %.2f%% possuem tipagem sanguínea A- ou B- \n\n", pcPessoasPressaoAlta);

    return 0;
}
