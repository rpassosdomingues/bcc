// Projeto: Estatística em Base de Dados de Veículos
// Rafael Passos Domingues

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados de cada veículo
typedef struct {
    char marca[20];
    char tipo[20];
    int ano;
    int quilometragem;
    float motor;
    char transmissao[20];
    char direcao[20];
    char cor[20];
    char placa[10];
    float preco;
} Veiculo;

// Função para calcular a porcentagem
float calcularPorcentagem(int valor, int total) {
    return (float)valor / total * 100;
}

// Função para obter o valor da prestação do financiamento
float calcularPrestacao(float valor) {
    // Cálculo da prestação com taxa de juros atual
    // Substitua pela taxa de juros real obtida na consulta à internet
    float taxaJuros = 0.8; // Exemplo: 0.8% ao mês
    int numParcelas = 48;
    float prestacao = (valor * taxaJuros) / (1 - pow(1 + taxaJuros, -numParcelas));
    return prestacao;
}

int main() {
    // Definir o número total de veículos e contadores para as categorias
    int totalVeiculos = 0;
    int tipoHatch = 0, tipoSUV = 0, tipoSeda = 0, tipoPickup = 0, tipoVan = 0, tipoPasseio = 0;
    int veiculosAutoHidraulica = 0;
    int veiculosPotencia1 = 0;
    int veiculos5AnosMais = 0;
    int somaKilometragem5AnosMais = 0;
    float precoMinimo1 = 0, precoMaximo2 = 0;
    char placaMinima1[10], placaMaxima2[10];
    float seguroEstimado3 = 0;

    // Abrir o arquivo de dados
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de dados.\n");
        return 1;
    }

    // Loop para ler e processar cada linha do arquivo
    char linha[200];
    while (fgets(linha, sizeof(linha), arquivo)) {
        Veiculo veiculo;
        sscanf(linha, "%s %s %d %d %f %s %s %s %s %f",
               veiculo.marca, veiculo.tipo, &veiculo.ano, &veiculo.quilometragem,
               &veiculo.motor, veiculo.transmissao, veiculo.direcao,
               veiculo.cor, veiculo.placa, &veiculo.preco);

        // Contabilizar o tipo de veículo
        if (strcmp(veiculo.tipo, "Hatch") == 0) {
            tipoHatch++;
        } else if (strcmp(veiculo.tipo, "SUV") == 0) {
            tipoSUV++;
        } else if (strcmp(veiculo.tipo, "Sedã") == 0) {
            tipoSeda++;
        } else if (strcmp(veiculo.tipo, "Pick-up") == 0) {
            tipoPickup++;
        } else if (strcmp(veiculo.tipo, "Van") == 0) {
            tipoVan++;
        } else if (strcmp(veiculo.tipo, "Passeio") == 0) {
            tipoPasseio++;
        }

        // Verificar se o veículo tem câmbio automático e direção hidráulica
        if (strcmp(veiculo.transmissao, "Automático") == 0 && strcmp(veiculo.direcao, "Hidráulica") == 0) {
            veiculosAutoHidraulica++;
        }

        // Verificar se o veículo tem potência do motor 1.0
        if (veiculo.motor == 1.0) {
            // Verificar se é o primeiro veículo com potência 1.0 ou se o preço é menor que o mínimo atual
            if (veiculosPotencia1 == 0 || veiculo.preco < precoMinimo1) {
                precoMinimo1 = veiculo.preco;
                strcpy(placaMinima1, veiculo.placa);
            }
            veiculosPotencia1++;
        }

        // Verificar se o veículo tem direção hidráulica e combustível flex
        if (strcmp(veiculo.direcao, "Hidráulica") == 0 && veiculo.motor == 1.0) {
            // Verificar se é o primeiro veículo com direção hidráulica e flex ou se o preço é maior que o máximo atual
            if (veiculos5AnosMais == 0 || veiculo.preco > precoMaximo2) {
                precoMaximo2 = veiculo.preco;
                strcpy(placaMaxima2, veiculo.placa);
            }
            veiculos5AnosMais++;
        }

        // Verificar se o veículo tem 5 anos ou mais (2018)
        if (veiculo.ano <= 2018) {
            somaKilometragem5AnosMais += veiculo.quilometragem;
        }

        totalVeiculos++;
    }

    // Calcular as porcentagens
    float percentualHatch = calcularPorcentagem(tipoHatch, totalVeiculos);
    float percentualSUV = calcularPorcentagem(tipoSUV, totalVeiculos);
    float percentualSedan = calcularPorcentagem(tipoSeda, totalVeiculos);
    float percentualPickup = calcularPorcentagem(tipoPickup, totalVeiculos);
    float percentualVan = calcularPorcentagem(tipoVan, totalVeiculos);
    float percentualPasseio = calcularPorcentagem(tipoPasseio, totalVeiculos);

    float percentualAutoHidraulica = calcularPorcentagem(veiculosAutoHidraulica, totalVeiculos);

    // Calcular o valor da prestação do financiamento
    float prestacaoFinanciamento = calcularPrestacao(precoMinimo1);

    // Calcular o seguro estimado (10% do valor do veículo)
    seguroEstimado3 = precoMaximo2 * 0.1;

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
    fclose(arquivo);

    return 0;
}
