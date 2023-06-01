/*
Problema 7: Um determinado material radioativo perde metade de sua massa a cada 50
segundos. Dada a massa inicial, em gramas, fazer um programa que determine
o tempo necessário para que essa massa se torne menor do que 0,5 grama.
Escreva a massa inicial, a massa final e o tempo calculado em horas, minutos e
segundos.
*/

#include <stdio.h>
#include <math.h>

int main() {
    float massaInicial, massaFinal, tempoMeiaVida, tempo;

    printf("\n\t Informe a massa inicial do elemento radioativo: ");
    scanf("%f", &massaInicial);

    printf("\n\t Informe a massa final: ");
    scanf("%f", &massaFinal);

    printf("\n\t Informe a meia-vida do elemento radioativo: ");
    scanf("%f", &tempoMeiaVida);

    tempo = (tempoMeiaVida * log(massaInicial / massaFinal)) / log(2.0);

    printf("\n\t\t Tempo necessário para atingir a massa final: %.2f unidades de tempo \n\n", tempo);

    return 0;
}
