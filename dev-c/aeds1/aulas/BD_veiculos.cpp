// Projeto: Estatística em Base de Dados de Veículos
// Autor: Rafael Passos Domingues
// RA: 2023.1.08.036

#include <math.h>   // para utilizar pow no cálculo do coeficiente de financiamento.
#include <cstdlib>
#include <iostream> // Usa o cin e cout - Substituto do scanf.
#include <fstream>  // Para entender comandos próprios do arquivo. Stream siginifica fluxo de dados por caracter.

using namespace std;

int main(void) {

    int ano, quilometragem;

    float motor, portas, taxaJuros, taxa, numParcelas, coefFinanceamento, prestacao, mediaKM5AnosMais, preco;
    float percentualHatch, percentualSUV, percentualSedan, percentualPickup, percentualVan, percentualPasseio, percentualAutoHidraulica;

    string modelo, marca, tipo, combustivel, transmissao, direcao, cor, placa, placaMinima1, placaMaxima;

    // Definir o número total de veículos e contadores para as categorias
    int totalVeiculos = 0;
    int qtdHatch = 0, qtdSUV = 0, qtdSedan = 0, qtdPickup = 0, qtdVan = 0, qtdPasseio = 0;
    int veiculosAutoHidraulica = 0;
    int veiculosPotencia1 = 0;
    int veiculos5AnosMais = 0;
    float somaKM5AnosMais = 0;
    float precoMinimo1 = 0, precoMaximo = 0;
    float seguroEstimado = 0;

    // Abrir o arquivo de dados
    ifstream teclado ("BD_veiculos.txt");
    if (!teclado.is_open()){
      cout << "\n Erro: Arquivo não encontrado. \n";
      return 1;
    }

    // Loop para ler e processar cada linha do arquivo
    while (modelo != "fim") {

        teclado >> modelo >> marca >> tipo >> ano >> quilometragem >> motor >> combustivel >> transmissao >> direcao >> cor >> portas >> placa >> preco;

        // Contabilizar o tipo de veículo
        if (tipo == "Hatch") {
            qtdHatch++;
        } else if (tipo == "SUV") {
            qtdSUV++;
        } else if (tipo == "Sedan") {
            qtdSedan++;
        } else if (tipo == "Pick-up") {
            qtdPickup++;
        } else if (tipo == "Van") {
            qtdVan++;
        } else if (tipo == "Passeio") {
            qtdPasseio++;
        }

        // Verificar se o veículo tem câmbio automático e direção hidráulica
        if (transmissao == "Automático" && direcao == "Hidráulica") {
            veiculosAutoHidraulica++;
        }

        // Verificar se o veículo tem potência do motor 1.0
        if (motor == 1.0) {
            // Verificar se é o primeiro veículo com potência 1.0 ou se o preço é menor que o mínimo atual
            if (veiculosPotencia1 == 0 || preco < precoMinimo1) {
                precoMinimo1 = preco;
                placaMinima1 = placa;
                // Calcular o valor da prestação do financiamento
                taxaJuros = 0.015;
                taxa = 1 + taxaJuros;
                numParcelas = 48;
                coefFinanceamento = taxaJuros / (1 - (pow(taxa, -numParcelas)));
                prestacao = preco * coefFinanceamento;
            }
            veiculosPotencia1++;
        }

        // Verificar se o veículo tem direção hidráulica e combustível flex
        if (direcao == "Hidráulica" && combustivel == "Flex") {
            // Verificar se é o primeiro veículo com direção hidráulica e flex ou se o preço é maior que o máximo atual
            if (veiculos5AnosMais == 0 || preco > precoMaximo) {
                precoMaximo = preco;
                placaMaxima = placa;
                // Calcular o seguro estimado (10% do valor do veículo)
                seguroEstimado = precoMaximo * 0.05;
            }
            veiculos5AnosMais++;
        }

        // Verificar se o veículo tem 5 anos ou mais (2018)
        if (ano <= 2018) {
            somaKM5AnosMais += quilometragem;
        }

        totalVeiculos++;
    }
    // Fechar o arquivo
    teclado.close();

    // Calcular as porcentagens
    percentualHatch   = (float)qtdHatch / totalVeiculos * 100;
    percentualSUV     = (float)qtdSUV / totalVeiculos * 100;
    percentualSedan   = (float)qtdSedan / totalVeiculos * 100;
    percentualPickup  = (float)qtdPickup / totalVeiculos * 100;
    percentualVan     = (float)qtdVan / totalVeiculos * 100;
    percentualPasseio = (float)qtdPasseio / totalVeiculos * 100;

    percentualAutoHidraulica = (float)veiculosAutoHidraulica / totalVeiculos * 100;

    // Calcular a média de quilometragem dos veículos com 5 anos ou mais
    mediaKM5AnosMais = somaKM5AnosMais / veiculos5AnosMais;
    
    cout << std::fixed << std::cout.precision(2);

    // Imprimir os resultados
    cout << "\n\n Porcentagens de veículos nas categorias de tipo:\n" << endl;
    cout << "   Hatch: " << percentualHatch << "%\n" << endl;
    cout << "     SUV: " << percentualSUV << "%\n" << endl;
    cout << "   Sedan: " << percentualSedan << "%\n" << endl;
    cout << " Pick-up: " << percentualPickup << "%\n" << endl;
    cout << "     Van: " << percentualVan << "%\n" << endl;
    cout << " Passeio: " << percentualPasseio << "%\n\n" << endl;

    cout << "\n Percentual de veículos que possuem câmbio automático e direção hidráulica: " << percentualAutoHidraulica << "% \n\n" << endl;

    cout << "\n Placa e valor do veículo mais barato com potência do motor 1.0: \n" << endl;
    cout << "\t Placa: " << placaMinima1 << "\n" << endl;
    cout << "\t Preço: R$ " << precoMinimo1 << "\n" << endl;
    cout << "\t Valor da prestação do financiamento em 48 meses: R$ " << prestacao << "\n\n" << endl;

    cout << "\n Placa e valor do veículo mais caro com direção hidráulica e combustível flex: \n" << endl;
    cout << "\t Placa: " << placaMaxima << "\n" << endl;
    cout << "\t Preço: R$ " << precoMaximo << "\n" << endl;
    cout << "\t Valor do seguro estimado: R$ " << seguroEstimado << "\n\n" << endl;

    cout << "\n Quantidade e média de quilometragem dos veículos com 5 anos ou mais: \n" << endl;
    cout << "\t Quantidade: " << veiculos5AnosMais << " veículos\n" << endl;
    cout << "\t Média de quilometragem: " << mediaKM5AnosMais << " km \n\n" << endl;

    return 0;
}
