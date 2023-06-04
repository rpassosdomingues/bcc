/*
  This project sort vector with select sort method.
*/

#include <iostream>

using namespace std;

int main(void){
  
  int lenght = 10, temp;
  int array[lenght] = {9, 0, 8, 1, 7, 2, 6, 3, 5, 4};

  cout << "\n Original array: ";
  for(int start = 0; start < lenght; start++){
    cout << array[start] << " ";
  }

  // Select Sort
  for(int start = 0; start < lenght - 1; start++){
    int maxIndex = start;
    for(int next = start + 1; next < lenght; next++){
      if(array[next] > array[maxIndex]){
        maxIndex = next;
      }
      temp = array[maxIndex];
      array[maxIndex] = array[next];
      array[next] = temp;
    }
  }

  cout << "\n Sort array: ";
  for(int start = 0; start < lenght; start++){
    cout << array[start] << " ";
  }
  cout << "\n\n";

  return 0;
}
