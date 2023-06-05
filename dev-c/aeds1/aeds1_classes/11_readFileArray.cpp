// This project read a text file "data.txt".

#include <cstdlib>
#include <iostream> // Uses cin and cout - Replacement for scanf
#include <fstream> // For handling file-specific commands. Stream refers to data flow character by character.
#define LENGHT 10

using namespace std;

int main(void) {
  
  int array1[LENGHT];
  int array2[LENGHT];
  int array3[LENGHT];

  // The variable "inputFile" acts as the user who inputs elements.
  // ifstream (input-file-stream) is the specific type of the variable.
  ifstream inputFile("dataArray.txt");
  if(!inputFile.is_open()){
    cout << "\n File not found. \n";
    return 1;
  }

  //Takes the data from the file and assigns it to the elements in the arrays.
  for(int i = 0; i < LENGHT; i++){
    inputFile >> array1[i];
    inputFile >> array2[i];
  }
  inputFile.close();
  cout << "\n";
  
  // array 1
  cout << "array1 = {";
  for(int i = 0; i < LENGHT; i++){
    cout << array1[i] << " ";
  }
  cout << "}";
  cout << "\n";
  
  // array 2
  cout << "array2 = {";
  for(int i = 0; i < LENGHT; i++){
    cout << array2[i] << " ";
  }
  cout << "}";
  cout << "\n";
  
  // operations with arrays
  for(int i = 0; i < LENGHT; i++){
    array3[i] = array1[i] + array2[i];
  }

  // array 3  
  cout << "array3 = {";
  for(int i = 0; i < LENGHT; i++){
    cout << array3[i] << " ";
  }
  cout << "}";
  cout << "\n\n";

return 0;
}
