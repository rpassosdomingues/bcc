// This project read a text file "data.txt".

#include <cstdlib>
#include <iostream> // Uses cin and cout - Replacement for scanf
#include <fstream> // For handling file-specific commands. Stream refers to data flow character by character.

using namespace std;

int main(void) {
  
  int value;
  // The variable "inputFile" acts as the user who inputs values.
  // ifstream (input-file-stream) is the specific type of the variable.
  ifstream inputFile("data.txt");
  if(!inputFile.is_open()){
    cout << "\n File not found. \n";
    return 1;
  }

  // Takes the data from the file and assigns it to the variable "value".
  inputFile >> value;
  cout << "value: " << value << endl;
  while (value != 0){
    inputFile >> value;
    cout << "value: " << value << endl;
  }
  inputFile.close();

return 0;
}
