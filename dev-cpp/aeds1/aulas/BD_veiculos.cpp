// Projeto: Estatística em Base de Dados de Veículos

/*
O aplicativo desenvolvido no projeto deve ler os dados de um arquivo-texto em variáveis simples e atualizar outras variáveis
de forma que no final responder as informações solicitadas nos requisitos.
Cada linha do arquivo de entrada tem informações de apenas um veículo, conforme o modelo apresentado no arquivo-texto
de exemplo “BD_veiculos.txt”.
A última linha, que não fará parte dos  cálculos, terá no nome do veículo a palavra “FIM”.
Após o final de leitura do arquivo, o projeto deve apresentar de forma clara as informações solicitadas nos requisitos abaixo.
*/

#include <cstdlib>
#include <iostream> // Usa o cin e cout - Substituto do scanf
#include <fstream>  // Para entender comandos próprios do arquivo. Stream siginifica fluxo de dados por caracter.

using namespace std;

int main() {

    string veiculo, modelo, marca, tipo, combustivel, cambio, direcao, cor, portas, placa, placaBarato, placaCaro, valorCaro, seguroCaro;
    int ano;
    float quilometragem, potenciaMotor, valor, pcModelo, pcAutomaticoHidraulica;
    ifstream teclado ("BD_veiculos.txt");

    // acumuladoras

    if (!teclado.is_open()){
      cout << "\n Erro: Arquivo não encontrado. \n";
      return 1;
    }
    
    teclado >> veiculo;
    //cout << "veiculo: " << veiculo << endl;
    
    while ( veiculo != "fim" ){

      if (veiculo == "HEB0A14"){
        teclado >> veiculo;
        printf("\n   A placa é: \n", placa);
      } else
          if (veiculo == "2002"){
            teclado >> anoFabricacao;
            printf("\n O ano é: \n", anoFabricacao);
          } else
              if (veiculo == "algumaCoisa"){
                teclado >> algumAver;
                // printf("\n     bla bla bla \n", blablabla);
              }
    
      teclado >> veiculo;
    }
    teclado.close();

    /*
    printf("\n > %.2f%% na categoria x \n", pcModelo);

    printf("\n\t >> %.2f%% possuem câmbio automático e direção hidráulica \n", pcAutomaticoHidraulica);
    
    printf("\n\t\t * O veículo mais barato possui placa: %s e o valor da prestação é: %d \n", placaBarato, prestacaoBarato);
    printf("\n\t\t * O veículo mais caro possui placa: %s e custa: R$ %.2f e o valor do seguro é: R$ %.2f \n", placaCaro, valorCaro, seguroCaro);
    
    printf(" ======================================== ");
    printf("\n \t|\t Quantidade \t|\t KM \n");
    printf(" ---------------------------------------- ");
    printf("\n \t|\t %d \t|\t %.2f \n\n", quantidade, mediaKM);
    printf(" ======================================== ");
    */

    return 0;
}
