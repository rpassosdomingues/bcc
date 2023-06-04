/*
  This project sort vector with inserction sort method.
*/

#include <iostream>

using namespace std;

int main(void){
  
  int lenght = 10, key;
  int array[lenght] = {9, 0, 8, 1, 7, 2, 6, 3, 5, 4};

  cout << "\n Original array: ";
  for(int start = 0; start < lenght; start++){
    cout << array[start] << " ";
  }

  // Inserction Sort
  for(int start = 0; start < lenght; start++){
    for(int next = start + 1; next < lenght; next++){
      key = array[next];
      if(array[start] > key){
        array[next] = array[start];
        array[start] = key;
      }
    }
  }

  cout << "\n Sort array: ";
  for(int start = 0; start < lenght; start++){
    cout << array[start] << " ";
  }
  cout << "\n\n";

  return 0;
}
