/*
Problema 6: Supondo que a população de um país A seja da ordem de 90.000.000 de
habitantes com uma taxa anual de crescimento de 1.5% e que a população de um
país B seja, aproximadamente, de 200.000.000 de habitantes com uma taxa
anual de crescimento de 3%, fazer um programa que calcule e escreva o
número de anos necessários para que a população do país A ultrapasse a
população do país B, mantidas essas taxas de crescimento.
*/

#include <stdio.h>
#include <math.h>

int main() {

    float taxaCrescimentoA, taxaCrescimentoB;
    long int tempoAultrapassarB, populacaoA, populacaoB;

    tempoAultrapassarB = 0;

    populacaoA = 90000000;
    taxaCrescimentoA = 1.5;

    populacaoB = 200000000;
    taxaCrescimentoB = 0.03;

    // a cada ano que passa a populacaoA aumenta populacaoInicial*taxa
    // a cada ano que passa a populacaoB aumenta populacaoInicial*taxa

    while(populacaoA <= populacaoB){
        populacaoA = populacaoA + populacaoA * taxaCrescimentoA;
        populacaoB = populacaoB + populacaoB * taxaCrescimentoB;
        tempoAultrapassarB++;
    }

    printf("\n\t\t É necessário %ld ano \n\n", tempoAultrapassarB);

    return 0;
}
