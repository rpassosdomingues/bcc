// Aqui eu fiz um projeto para preencher entrada de um arquivo.txt.

#include <stdio.h>

using namespace std;

int main() {

    int preenchedor_aleatorio;
    
    printf("\n Digite o valor de partida: ");
    scanf(" %d", &preenchedor_aleatorio);

    while (preenchedor_aleatorio < 10000){
        printf(" %d \n", preenchedor_aleatorio);
        preenchedor_aleatorio = preenchedor_aleatorio + 100;
    }

    return 0;
}
