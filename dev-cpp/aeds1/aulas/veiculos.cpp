// Projeto: Estatística em Base de Dados de Veículos
// Rafael Passos Domingues

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int ano, quilometragem;
string placa, cor, direcao, trasmissao, tipo, marca;
float preco, motor;

int main() {
    // Definir o número total de veículos e contadores para as categorias
    int totalVeiculos = 0;
    int qtdHatch = 0, qtdSUV = 0, qtdSeda = 0, qtdPickup = 0, qtdVan = 0, qtdPasseio = 0;
    int veiculosAutoHidraulica = 0;
    int veiculosPotencia1 = 0;
    int veiculos5AnosMais = 0;
    int somaKilometragem5AnosMais = 0;
    float precoMinimo1 = 0, precoMaximo2 = 0;
    char placaMinima1[10], placaMaxima2[10];
    float seguroEstimado3 = 0;

    // Abrir o arquivo de dados
    ifstream teclado ("BD_veiculos.txt");
    if (!teclado.is_open()){
      cout << "\n Erro: Arquivo não encontrado. \n";
      return 1;
    }

    teclado >> veiculo;
    //cout << "veiculo: " << veiculo << endl;

    // Loop para ler e processar cada linha do arquivo
    while (teclado != fim)) {
        scanf(teclado, "%s %s %d %d %f %s %s %s %s %f",
               &marca, &tipo, &ano, &quilometragem,
               &motor, &transmissao, &direcao,
               &cor, &placa, &preco);

        // Contabilizar o tipo de veículo
        if (strcmp(tipo, "Hatch") == 0) {
            qtdHatch++;
        } else if (strcmp(tipo, "SUV") == 0) {
            qtdSUV++;
        } else if (strcmp(tipo, "Seda") == 0) {
            qtdSeda++;
        } else if (strcmp(tipo, "Pick-up") == 0) {
            qtdPickup++;
        } else if (strcmp(tipo, "Van") == 0) {
            qtdVan++;
        } else if (strcmp(tipo, "Passeio") == 0) {
            qtdPasseio++;
        }

        // Verificar se o veículo tem câmbio automático e direção hidráulica
        if (strcmp(transmissao, "Automático") == 0 && strcmp(direcao, "Hidráulica") == 0) {
            veiculosAutoHidraulica++;
        }

        // Verificar se o veículo tem potência do motor 1.0
        if (motor == 1.0) {
            // Verificar se é o primeiro veículo com potência 1.0 ou se o preço é menor que o mínimo atual
            if (veiculosPotencia1 == 0 || preco < precoMinimo1) {
                precoMinimo1 = preco;
                strcpy(placaMinima1, placa);
            }
            veiculosPotencia1++;
        }

        // Verificar se o veículo tem direção hidráulica e combustível flex
        if (strcmp(direcao, "Hidráulica") == 0 && motor == 1.0) {
            // Verificar se é o primeiro veículo com direção hidráulica e flex ou se o preço é maior que o máximo atual
            if (veiculos5AnosMais == 0 || preco > precoMaximo2) {
                precoMaximo2 = preco;
                strcpy(placaMaxima2, placa);
            }
            veiculos5AnosMais++;
        }

        // Verificar se o veículo tem 5 anos ou mais (2018)
        if (ano <= 2018) {
            somaKilometragem5AnosMais += quilometragem;
        }

        totalVeiculos++;
    }

    // Calcular as porcentagens
    float percentualHatch   = (float) (qtdHatch / totalVeiculos) * 100;
    float percentualSUV     = (float) (qtdSUV / totalVeiculos) * 100;
    float percentualSedan   = (float) (qtdSedan / totalVeiculos) * 100;
    float percentualPickup  = (float) (qtdPickup / totalVeiculos) * 100;
    float percentualVan     = (float) (qtdVan / totalVeiculos) * 100;
    float percentualPasseio = (float) (qtdPasseio / totalVeiculos) * 100;

    float percentualAutoHidraulica = (float) (veiculosAutoHidraulica / totalVeiculos) * 100;

    // Calcular o valor da prestação do financiamento
    float taxaJuros = 0.8; // Exemplo: 0.8% ao mês
    int numParcelas = 48;
    float prestacao = (valor * taxaJuros) / (1 - pow(1 + taxaJuros, -numParcelas)); 

    // Calcular o seguro estimado (10% do valor do veículo)
    seguroEstimado = precoMaximo * 0.1;

    // Calcular a média de quilometragem dos veículos com 5 anos ou mais
    float mediaKilometragem5AnosMais = (float)somaKilometragem5AnosMais / veiculos5AnosMais;

    // Imprimir os resultados
    printf("\n\n Porcentagens de veículos nas categorias de tipo:\n");
    printf("\t Hatch: %.2f%% \n", percentualHatch);
    printf("\t SUV: %.2f%% \n", percentualSUV);
    printf("\t Sedã: %.2f%% \n", percentualSedan);
    printf("\t Pick-up: %.2f%% \n", percentualPickup);
    printf("\t Van: %.2f%% \n", percentualVan);
    printf("\t Passeio: %.2f%% \n", percentualPasseio);

    printf("\n %.2f%% dos veículos possuem câmbio automático e direção hidráulica \n", percentualAutoHidraulica);

    printf("\n Placa e valor do veículo mais barato com potência do motor 1.0: \n");
    printf("\t Placa: %s \n", placaMinima1);
    printf("\t Valor: %.2f \n", precoMinimo1);
    printf("\t Valor da prestação do financiamento em 48 meses: %.2f \n", prestacaoFinanciamento);

    printf("\n Placa e valor do veículo mais caro com direção hidráulica e combustível flex: \n");
    printf("\t Placa: %s \n", placaMaxima2);
    printf("\t Valor: %.2f \n", precoMaximo2);
    printf("\t Valor do seguro estimado: %.2f \n", seguroEstimado3);

    printf("\n Quantidade e média de quilometragem dos veículos com 5 anos ou mais: \n");
    printf("\t Quantidade: %d \n", veiculos5AnosMais);
    printf("\t Média de quilometragem: %.2f \n\n", mediaKilometragem5AnosMais);

    // Fechar o arquivo
    teclado.close();

    return 0;
}
