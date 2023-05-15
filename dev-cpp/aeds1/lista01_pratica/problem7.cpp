/*
Problema 7: Um determinado material radioativo perde metade de sua massa a cada 50
segundos. Dada a massa inicial, em gramas, fazer um programa que determine
o tempo necessário para que essa massa se torne menor do que 0,5 grama.
Escreva a massa inicial, a massa final e o tempo calculado em horas, minutos e
segundos.
*/

#include <stdio.h>
#include <math.h>

using namespace std;

int main() {

    float massaInicial, massaFinal, tempoMeiaVida, tempo;

    tempoMeiaVida = 50;
    massaInicial = 1000;
    tempo = 0;

    while (massaFinal >= 0.5){
      massaFinal = massaInicial/2.0;
      tempo += tempoMeiaVida;
    }

    tempo = log(massaFinal/massaInicial);

    printf("\n\t -- Resultado -- \n");
    printf("\n\t O tempo de decaimento é: %.2f segundos \n", tempo);

    return 0;
}
