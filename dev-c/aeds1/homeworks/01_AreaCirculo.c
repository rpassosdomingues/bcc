// Aqui eu fiz um projeto para calcular a área de um círculo.

#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {

    float raio, area_circulo;
    const float pi = 3.1415;
    
    printf("\n Digite o valor do raio: ");
    scanf(" %f", &raio);
    
    area_circulo = pi * raio * raio;
    
    printf("\n\t A área do círculo é: %.2f m² \n\n", area_circulo);

    return 0;
}
