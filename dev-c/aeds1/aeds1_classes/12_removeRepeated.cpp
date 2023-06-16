// This project remove repeated elements of the a array.

#include <cstdlib>
#include <iostream>
#define LENGHT 10

using namespace std;

int main(void) {
  
  int i, j;
  int array[LENGHT] = {0, 0, 1, 1, 1, 2, 3, 3, 4, 5};
  
  // Array with repeated elements
  cout << "\n arrayRepeated = {";
  for (i = 0; i < LENGHT; i++) {
    cout << array[i] << " ";
  }
  cout << "}";
  cout << "\n";

  // Identify repeated elements and shifts the positions by overwriting the vector

  for (i = 0, j = i+1; i < LENGHT; i++, j++) {
    if (array[i] == array[j] && array[j] != array[j+1]) {
      array[j] = array[j+1];
      array[i] = array[j];
    }
  }

  // Array with repeated elements remove
  cout << "\n \t array = {";
  for (i = 0; i < LENGHT; i++) {
    cout << array[i] << " ";
  }
  cout << "}";

  cout << "\n\n";

return 0;
}
