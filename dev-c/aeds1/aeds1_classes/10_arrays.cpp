/*
 * Autor: Rafael Passos Domingues
 * RA: 2023.1.08.036
 * 
 * Exercício 1: Encontrar o maior e o menor valor do vetor e indicar suas posições.
 * Exercício 2: Buscar no vetor um valor informado pelo usuário. Caso seja encontrado, em que posição do vetor o valor se encontra?
 * Exercício 3: Contar o número de ocorrências de um valor fornecido pelo usuário.
 * Exercício 4: Em um vetor, multiplique os valores pares por 2 e atribua zero aos valores ímpares.
 * Exercício 5: Incremente os valores de um vetor por um fator informado pelo usuário, limitando os resultados no intervalo entre 0 e 255.
 * 
 * Criado em 30 de Maio de 2023
 */

#include <iostream>

using namespace std;

int main(void) {
  
  int i, tamanho = 10;
  int iMax, iMin, iProcurado;
  int maiorValor=-1, menorValor=1000;
  int valorProcurado, valorRepetido, qtdOcorrencias=0, incremento;

  int vetor1[tamanho] = {40, 11, 27, 30, 4, 25, 16, 27, 87, 9};
  int vetor2[tamanho] = {0, 0, 1, 1, 1, 2, 3, 3, 4, 5};
  int vetor3[tamanho] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int vetor4[tamanho] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  
  // Exercício 1
  cout << "Exercício 1 \n";
  for (i = 0; i < tamanho; i++) {
    if (vetor1[i] > vetor1[i+1] && maiorValor < vetor1[i]) {
      maiorValor = vetor1[i];
      iMax = i;
    } else
        if (vetor1[i] < vetor1[i+1] && menorValor > vetor1[i]) {
          menorValor = vetor1[i];
          iMin = i;
        }
  }
  cout << "O maior valor é: " << maiorValor << " e se encontra na " << iMax << "ª posição do vetor." << endl;
  cout << "O menor valor é: " << menorValor << " e se encontra na " << iMin << "ª posição do vetor." << endl;
  cout << "\n\n";

  // Exercício 2
  cout << "Exercício 2 \n";
  cout << "Digite um valor para procurar no vetor: ";
  cin >> valorProcurado;
  for (i = 0; i < tamanho; i++) {
    if (valorProcurado == vetor1[i]) {
      iProcurado = i;
    }
  }
  cout << "O valor foi encontrado na " << iProcurado << "ª posição do vetor." << endl;
  cout << "\n\n";

  // Exercício 3
  cout << "Exercício 3 \n";
  cout << "Digite um valor para procurar a qtd de suas ocorrências no vetor: ";
  cin >> valorRepetido;
  for (i = 0; i < tamanho; i++) {
    if (valorRepetido == vetor2[i]) {
      qtdOcorrencias++;
    }
  }
  cout << "O valor aparece " << qtdOcorrencias << " vezes no vetor." << endl;
  cout << "\n\n";

  // Exercício 4
  cout << "Exercício 4 \n";
  for (i = 0; i < tamanho; i++) {
    if (vetor3[i] % 2 == 0) {
      vetor3[i] = 2 * vetor3[i];
    } else
        if (vetor3[i] % 2 != 0) {
          vetor3[i] = 0;
        }
  }
  cout << "O vetor modificado é: ";
  for (i = 0; i < tamanho; i++) {
    cout << vetor3[i] << " ";
  }

  // Exercício 5
  cout << "Exercício 5 \n";
  cout << "Digite um incremento [0 < incremento < 255]: ";
  cin >> incremento;
  while (incremento < 0 || incremento > 255) {
    cout << "Desculpe, há algo errado... Tente de novo: ";
    cin >> incremento;
  }
  for (i = 0; i < tamanho; i++) {
    vetor4[i] += incremento;
  }
  cout << "O vetor incrementado é: ";
  for (i = 0; i < tamanho; i++) {
    cout << vetor4[i] << " ";
  }

  cout << "\n\n";
  return 0;
}
