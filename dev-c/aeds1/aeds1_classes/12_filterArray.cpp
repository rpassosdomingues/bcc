// This project read a text file "filterArray.txt" for filter array.

#include <cstdlib>
#include <iostream> // Uses cin and cout - Replacement for scanf
#include <fstream>  // For handling file-specific commands.
                    // Stream refers to data flow character by character.
#define LENGHT 10

using namespace std;

int main(void) {
  
  int array[LENGHT];
  int i, qtdElements=7, qtdRepeat=0;

  // The variable "inputFile" acts as the user who inputs elements.
  // ifstream (input-file-stream) is the specific type of the variable.
  ifstream inputFile("filterArray.txt");
  if(!inputFile.is_open()){
    cout << "\n File not found. \n";
    return 1;
  }

  //Takes the data from the file and assigns it to the elements in the array1.
  for(int i = 0; i < LENGHT; i++){
    inputFile >> array[i];
  }
  inputFile.close();
  cout << "\n";
  
  // array 1
  cout << "Array = {";
  for(int i = 0; i < LENGHT; i++){
    cout << array[i] << " ";
  }
  cout << "}";
  cout << "\n";

  // filter repeat elements on array
  for (i = 0; i < qtdElements; i++) {
    for (int j = i + 1; j < qtdElements; j++) {
      if (array[i] == array[j]) {
        for (j = 0; j < qtdElements; j++) {
          array[i] = array[j];
        }
        qtdRepeat++;
      }
    }
  }
  cout << "\n";

  int qtd = qtdElements - qtdRepeat;

  // filtered array
  cout << "Filtered Array = {";
  for(i = 0; i < qtd; i++){
    cout << array[i] << " ";
  }
  cout << "}";
  cout << "\n\n";

return 0;
}
