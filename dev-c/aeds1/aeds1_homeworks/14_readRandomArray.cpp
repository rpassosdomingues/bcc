/*

problem 1: random without repetition
problem 2: set the first data of the file (output/input) to the length of the vector
problem 3: join the sorting algorithms (selection, insertion and bubble)
problem 4: show each one's output on the screen and observe the difference in execution time

*/

#include<fstream>
#include<iostream>
#include<cstdlib>

#define LENGHT 10

using namespace std;

int main(void){
  
  int array[LENGHT];
  
  ifstream inputFile("outputFile.txt");
  if(!inputFile.is_open()){
    cout << "\n File not found. \n";
    return 1;
  }
  
  for (int i = 0; i < LENGHT; i++) {
    inputFile >> array[i];
    cout << array[i] << " ";
  }
  inputFile.close();

  // Selection Sort
  for(int i = 0; i < LENGHT; i++){
    for(int j = i + 1; j < LENGHT; j++){
      handle = array[j];
      if(handle < array[i]){
        tmp = array[i];
        array[i] = handle;
        array[j] = tmp;
      }
    }
  }

  cout << "\n Selection Sort array: ";
  for(int start = 0; start < LENGHT; start++){
    cout << array[start] << " ";
  }
  cout << "\n\n";

  // Inserction Sort
  for(int start = 0; start < LENGHT; start++){
    for(int next = start + 1; next < LENGHT; next++){
      handle = array[next];
      if(array[start] > handle){
        array[next] = array[start];
        array[start] = handle;
      }
    }
  }

  cout << "\n Inserction Sort array: ";
  for(int start = 0; start < LENGHT; start++){
    cout << array[start] << " ";
  }
  cout << "\n\n";

  // Bubble Sort
  for(int start = 0; start < LENGHT - 1; start++){
    for(int next = start + 1; next < LENGHT; next++){
      if(array[start] > array[next]){
        temp = array[start];
        array[start] = array[next];
        array[next] = temp;
      }
    }
  }

  cout << "\n Bubble Sort array: ";
  for(int start = 0; start < LENGHT; start++){
    cout << array[start] << " ";
  }
  cout << "\n\n";

  return 0;
}
