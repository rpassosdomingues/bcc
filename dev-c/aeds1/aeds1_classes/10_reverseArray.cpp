/*
  Author: Rafael Passos Domingues
  RA: 2023.1.08.026
  Written on May 29, 2023
*/

#include <iostream>

using namespace std;

int main(void) {
  
  int lenght = 10, temp;
  int array[lenght] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

  cout << "\n Original array: ";
  for(int start = 0; start < lenght; start++){
    cout << array[start] << " ";
  }

  for(int start = 0, end = lenght - 1; start < lenght / 2; start++, end--){
    temp = array[start];
    array[start] = array[end];
    array[end] = temp;
  }

  cout << "\n Reversed array: ";
  for(int start = 0; start < lenght; start++){
    cout << array[start] << " ";
  }
  cout << "\n\n";

  return 0;
}
