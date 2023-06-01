// This project reads a text file "data.txt".

#include <cstdlib>
#include <iostream> // Uses cin and cout - Replacement for scanf
#include <fstream> // For handling file-specific commands. Stream refers to data flow character by character.

using namespace std;

int main(void){

  int count;
  float value, average;

  ifstream inputFile ("data.txt");
  if(!inputFile.is_open()){
    cout << "\n File not found. \n";
    return 1;
  }

  count = 0;
  average = 0;
  
  inputFile >> value;
  cout << "value: " << value << endl;
  while (value != 0){
    count = count + 1;
    average = average + value;
    inputFile >> value;
    cout << "value: " << value << endl;
  }
  inputFile.close();

  if(count != 0){
    average = average / count;
    cout << "\n\t The average is: " << average << "\n" << endl;
  }

  return 0;
}
