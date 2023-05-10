// Aqui eu fiz um projeto para mostrar a contagem regressiva de uma bomba.

#include <stdio.h>

using namespace std;

int main() {

    int contador_regressivo;
    
    printf("\n Digite o tempo de contagem regressiva: ");
    scanf(" %d", &contador_regressivo);

    while (contador_regressivo > 0){
        printf(" %d \n", contador_regressivo);
        contador_regressivo--;
    }
    
    printf("\n\t Buuuummmmmm!!! \n\n");

    return 0;
}
