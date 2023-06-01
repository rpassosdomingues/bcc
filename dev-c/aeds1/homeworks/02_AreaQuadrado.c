// Aqui eu fiz um projeto para calcular a área de um quadrado.

#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {

    float lado, area_quadrado;
    
    printf("\n Digite o valor do lado: ");
    scanf(" %f", &lado);
    
    area_quadrado = lado * lado;
    
    printf("\n\t A área do quadrado é: %.2f m² \n\n", area_quadrado);

    return 0;
}
