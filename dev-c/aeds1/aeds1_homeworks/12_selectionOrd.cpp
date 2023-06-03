/*
  This project ordenate arrays with different methods.
*/

#include <iostream>

using namespace std;

int main(void) {
  
  int size = 10, swap;
  int array[size] = {9, 0, 8, 1, 7, 2, 6, 3, 5, 4};

  cout << "\n Original array: ";
  for(int start = 0; start < size; start++){
    cout << array[start] << " ";
  }

  for(int start = 0, end = size - 1; start < size / 2; start++, end--){
    swap = array[start];
    array[start] = array[end];
    array[end] = swap;
  }

  cout << "\n Reversed array: ";
  for(int start = 0; start < size; start++){
    cout << array[start] << " ";
  }
  cout << "\n\n";

  return 0;
}
