/*
  This project sort vector with selection sort method.
*/

#include<iostream>
#include<fstream>

using namespace std;

int main(void){
  
  ifstream inputFile("randomArrayFile.txt");
  if (!inputFile.is_open()) {
    cout << "\n File not found. \n";
    return 1;
  }
  
  int length;
  inputFile >> length;

  int array[length];
  inputFile >> array[0];
  
  int i,j;
  for (i = 1; i < length; i++) {
    inputFile >> array[i];
  }
  inputFile.close();

  cout << "\n Original array: { ";
  for (int i = 0; i < length; i++) {
    cout << array[i] << " ";
  }
  cout << "}\n";

  // Selection Sort
  for (i = 0; i < length - 1; i++) {
    int minIndex = i;

    for (j = i + 1; j < length; j++) {
      if (array[j] < array[minIndex]) {
        minIndex = j;
      }
    }

    int swap = array[i];
    array[i] = array[minIndex];
    array[minIndex] = swap;
  }

  cout << "\n Sort array: { ";
  for(i = 0; i < length; i++){
    cout << array[i] << " ";
  }
  cout << "}\n\n";

  return 0;
}
