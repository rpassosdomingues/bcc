/*
 * Autor: Rafael Passos Domingues
 * RA: 2023.1.08.036
 * 
 * Criado em 29 de Maio de 2023
 * 
 * Exercício 00: Apresentar na tela somente as posições e os valores acima da média.
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char**argv) {
    
    float notas[10] = {40, 11, 27, 30, 4, 25, 16, 27, 87, 9};
    float media;
    int i;

    media = 0.0;
    for (i = 0; i < 10; i++){
        //cout << "O " << i+1 << "° Valor é " << notas[i] << endl;
        media += notas[i];
    }
    media = media/i;
    
    cout << "\n" << endl;
    
    cout << "A média é " << media << endl;
    
    cout << "\n" << endl;
    
    cout << "Os valores acima da média são: " << endl;
    i = 0;
    while (i < 10){
      if (notas[i] > media){
        cout << "O " << i+1 << "° Valor, que é " << notas[i] << endl;
      }
      i++;
    }
    
    return 0;
}
