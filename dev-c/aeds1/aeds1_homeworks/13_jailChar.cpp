/* 

  [Feito] Exercício 1: Faça um código para juntar o nome e sobrenome em um nome completo.
  [Feito] Exercício 2: Faça um código para verificar se duas cadeias de caracteres são iguais.
  [Feito] Exercício 3: Faça um código para verificar se um nome está contido num nome completo. [Aqui vale usar uma variável lógica FLAG]
  Exercício 4: Faça um código para coletar todas as letras de um nome completo em maiúsculas.
  Exercício 5: Faça um código para retirar os acentos de uma variável que armazena o número do CPF (com?) caracteres.

*/

#include <stdio.h>
#include <iostream>

using namespace std;

#define LENGHT 30

int main(void) {

  char name[LENGHT], lastName[LENGHT], fullName[2*LENGHT];
  
  name[0] = 'R';
  name[1] = 'a';
  name[2] = 'f';
  name[3] = 'a';
  name[4] = 'e';
  name[5] = 'l';
  name[6] = ' ';
  int sizeName = 7;

  printf("\n Name: %s.\n", name);

  lastName[0] = 'D';
  lastName[1] = 'o';
  lastName[2] = 'm';
  lastName[3] = 'i';
  lastName[4] = 'n';
  lastName[5] = 'g';
  lastName[6] = 'u';
  lastName[7] = 'e';
  lastName[8] = 's';
  lastName[9] = '\0';
  int sizeLastName = 10;

  printf("\n Last Name: %s.\n\n", lastName);

  for (int i = 0; i < sizeName; i++) {
    fullName[i] = name[i];
  }
  for (int j = 0; j < sizeLastName; j++) {
    fullName[j + sizeName] = lastName[j];
  }
  printf("\n Full Name: %s.\n\n", fullName);
  
  char equall[LENGHT];

  equall[0] = 'R';
  equall[1] = 'a';
  equall[2] = 'f';
  equall[3] = 'a';
  equall[4] = 'e';
  equall[5] = 'l';
  equall[6] = ' ';

  for (int i = 0; name[i] == equall[i]; i++) {
    
    bool flag = false;
    
    if (!flag) {
      printf("\n\t The jail chars are equalls.\n\n");
      break;
    }
  }

  char name1[LENGHT], name2[LENGHT];

  name1[0] = 'M';
  name1[1] = 'a';
  name1[2] = 'r';
  name1[3] = 'i';
  name1[4] = 'a';
  name1[5] = 'n';
  name1[6] = 'a';

  name2[0] = 'M';
  name2[1] = 'a';
  name2[2] = 'r';
  name2[3] = 'i';
  name2[4] = 'a';
  name2[5] = 'n';
  name2[6] = 'e';

  for (int i = 0; name1[i] == name2[i]; i++) {
    
    bool flag = false;
    
    if (!flag) {
      printf("\n\t The names are differents.\n\n");
      break;
    }
  }

  int char2int[LENGHT];
  char lowercase[LENGHT];

  lowercase[0] = 'r';
  lowercase[1] = 'a';
  lowercase[2] = 'f';
  lowercase[3] = 'a';
  lowercase[4] = 'e';
  lowercase[5] = 'l';

  // convert chars array to integers array

  for (int i = 0; i < LENGHT; i++) {
    char2int[i] = lowercase[i];
  }
  
  char lowercaseAB[LENGHT] = {97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122};
  char uppercaseAB[LENGHT] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};
  
  cout << "lowercase alphabet = {";
  for(int i = 0; i < LENGHT; i++){
    cout << lowercaseAB[i] << " ";
  }
  cout << "}";
  cout << "\n";

  cout << "uppercase alphabet = {";
  for(int i = 0; i < LENGHT; i++){
    cout << uppercaseAB[i] << " ";
  }
  cout << "}";
  cout << "\n";

  for (int i = 0; i < LENGHT; i++) {
    if (char2int[i] > 64 && char2int[i] < 91) {
      printf("\n\t Are uppercase letters.\n\n");
      break;
    } else
        if (char2int[i] > 96 && char2int[i] < 123) {
          printf("\n\t Are lowercase letters.\n\n");
          break;
        }
  }
  
  return 0;
}
