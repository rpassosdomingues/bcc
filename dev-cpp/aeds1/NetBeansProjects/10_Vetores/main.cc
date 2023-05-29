/*
 * Autor: Rafael Passos Domingues
 * RA: 2023.1.08.036
 * 
 * Criado em 29 de Maio de 2023
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char**argv) {
    
    float notas[10] = {40, 11, 27, 30, 4, 25, 16, 27, 87, 9};
    float media;
    int i;
    
    i = 0;
    while (i < 10){
      cout << "O " << i+1 << "° Valor é " << notas[i] << endl;
      i++;
    }
    
    media = 0.0;
    for (i = 0; i < 10; i++){
        cout << "O " << i+1 << "° Valor é " << notas[i] << endl;
        media += notas[i];
    }
    media = media/i;
    cout << "A média é " << media << endl;
    
    return 0;
}
