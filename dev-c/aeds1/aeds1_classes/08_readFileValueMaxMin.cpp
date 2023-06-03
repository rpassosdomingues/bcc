// This project reads a text file and identifies the smallest and largest value and calculate the average of values.

#include <cstdlib>
#include <iostream> // Uses cin and cout - Replacement for scanf
#include <fstream> // For handling file-specific commands. Stream refers to data flow character by character.

using namespace std;

  int main(void){
    
    int count;
    float value, average, maxValue, minValue;
  
    ifstream inputFile("data.txt");
    if(!inputFile.is_open()){
      cout << "\n File not found. \n";
      return 1;
    }

  inputFile >> value;
  cout << "value: " << value << endl;
  
  count = 0;
  average = 0;
  while (value != 0){
  
    count = count + 1;
    average = average + value;

    inputFile >> value;
    cout << "value: " << value << endl;
    
    maxValue = value;
    minValue = value;
    
    if (value < minValue){
      minValue = value;
    } else if(value > maxValue){
        maxValue = value;
      }

  }
  inputFile.close();

  if(count != 0){
    average = average / count;
    cout << "\n The average is: " << average << endl;
  }
  
  cout << "\n\t  The largest value is: " << maxValue << endl;
  cout << "\t The smallest value is: " << minValue  << "\n" << endl;
  
  return 0;
}
