/*
  Author: Rafael Passos Domingues
  RA: 2023.1.08.026
  Written on May 29, 2023
*/

#include <iostream>

using namespace std;

int main(void) {
  
  int size = 10, temp;
  int array[size] = {9, 0, 8, 1, 7, 2, 6, 3, 5, 4};

  cout << "\n Original array: ";
  for(int start = 0; start < size; start++){
    cout << array[start] << " ";
  }

  for(int start = 0, end = size - 1; start < size / 2; start++, end--){
    temp = array[start];
    array[start] = array[end];
    array[end] = temp;
  }

  cout << "\n Reversed array: ";
  for(int start = 0; start < size; start++){
    cout << array[start] << " ";
  }
  cout << "\n\n";

  return 0;
}
