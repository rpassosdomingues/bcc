/*
  This project sort vector with insert sort method.
*/

#include <iostream>

using namespace std;

int main(void){
  
  int lenght = 10, temp;
  int array[lenght] = {9, 0, 8, 1, 7, 2, 6, 3, 5, 4};
  int sortArray[lenght] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  cout << "\n Original array: ";
  for(int start = 0; start < lenght; start++){
    cout << array[start] << " ";
  }

  // Insert Sort
  for(int start = 0; start < lenght - 1; start++){
    for(int next = start + 1; next < lenght; next++){
      if(array[start] < array[next]){
        temp = array[start];
        array[start] = array[next];
        sortArray[start] = temp;
      }
    }
  }

  cout << "\n Sort array: ";
  for(int start = 0; start < lenght; start++){
    cout << sortArray[start] << " ";
  }
  cout << "\n\n";

  return 0;
}
