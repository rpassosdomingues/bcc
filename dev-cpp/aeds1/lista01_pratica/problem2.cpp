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

#include <stdio.h> // bibliotecas necessárias

int main() {
    
    int contador, teto, qtdPessoasPressaoAlta, pcPessoasPressaoAlta, idade, pressaoArterialMax, pressaoArterialMin, qtdPessoas;
    char tipoSanguineo, fatorRH;

    // iniciar variaveis que acumulam valores (atualizadas)
    contador = 1;
    teto = 3;
    qtdPessoasPressaoAlta = 0;
    qtdPessoas = teto;

    // estruturas de repeticao
    while (contador <= teto){

      printf("\n Digite a idade [18 < idade < 130]: ");
      scanf(" %d", &idade);

      printf("\n Digite o tipo sanguíneo ['o', 'a', 'b' ou 'c'] _ ['p' ou 'n']: "); // ab = c
                                                                                    // porque ainda não sei lidar com strings
      scanf(" %c %c", &tipoSanguineo, &fatorRH);
      
      printf("\n Digite a pressão arterial [(7 < max < 25) (2 < min < 20)]: ");
      scanf(" %d %d", &pressaoArterialMax, &pressaoArterialMin);

      // estruturas condicionais
      
      if ((tipoSanguineo == 'a' || tipoSanguineo == 'a') && (pressaoArterialMax > 14 || pressaoArterialMin > 10)){
          qtdPessoasPressaoAlta++;
        }
    
    contador++;
    }
    
    // resultados

    pcPessoasPressaoAlta = (qtdPessoasPressaoAlta/qtdPessoas) * 100;

    printf("\n\t %d %% das pessoas possuem pressão alta. \n\n", pcPessoasPressaoAlta);

    return 0;
}
