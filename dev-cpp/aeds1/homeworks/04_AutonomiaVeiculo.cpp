// Aqui eu fiz um projeto para calcular a autonomia de um veículo.

#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {

    float distancia_viagem, litros_combustivel, autonomia_veiculo;
    
    printf("\n Digite a distância da viagem (km): ");
    scanf(" %f", &distancia_viagem);

    printf("\n Digite a quantidade de litros gastos: ");
    scanf(" %f", &litros_combustivel);
    
    autonomia_veiculo = distancia_viagem / litros_combustivel;
    
    printf("\n\t O veículo faz: %.2f km/L \n\n", autonomia_veiculo);

    return 0;
}
