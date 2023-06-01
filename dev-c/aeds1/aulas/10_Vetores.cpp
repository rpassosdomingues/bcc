/*
* Autor: Rafael Passos Domingues
* RA: 2023.1.08.026
* Escrito em 29 de Maio de 2023
*/

#include <iostream>

using namespace std;

int main(void) {
    int vetor[10] = {40, 11, 27, 30, 4, 25, 16, 27, 87, 9};
    int tamanho = 10;
    int inicio = 0;
    int fim = tamanho - 1;
    int swap;

    cout << "\n vetor original: ";
    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }

    while (inicio < fim) {
        swap = vetor[inicio];
        vetor[inicio] = vetor[fim];
        vetor[fim] = swap;

        inicio++;
        fim--;
    }

    cout << "\n vetor invertido: ";
    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }
    cout << "\n\n";

    return 0;
}
