/*
 * Autor: Rafael Passos Domingues
 * RA: 2023.1.08.036
 * 
 * Criado em 29 de Maio de 2023
 * 
 * Exercício 01: Inverta o vetor
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char**argv) {
    
    float notas[10] = {40, 11, 27, 30, 4, 25, 16, 27, 87, 9};
    float swap;
    int i = 0, j = 9;
    
    while (i < 5){
      swap = notas[j];
      notas[j] = notas[i];
      notas[i] = swap;
      i++;
      j--;
      cout << notas[i] << endl;
    }
    
    return 0;
}