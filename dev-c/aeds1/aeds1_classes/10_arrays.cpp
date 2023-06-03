/*
  Author: Rafael Passos Domingues
  RA: 2023.1.08.026
  Written on May 29, 2023
*/

#include <iostream>

using namespace std;

int main(void) {
  
  int array[10] = {40, 11, 27, 30, 4, 25, 16, 27, 87, 9};
  int size = 10, start = 0, end = size - 1, swap;

  cout << "\n Original array: ";
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }

  while (start < end) {
    swap = array[start];
    array[start] = array[end];
    array[end] = swap;
    
    start++;
    end--;
  }

  cout << "\n Reversed array: ";
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << "\n\n";

  return 0;
}
