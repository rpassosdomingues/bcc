/*
  This project identifies if the user input value is in the array and in which position.
*/

#include <iostream>

using namespace std;

int main(void){
  
  int lenght = 10, wanted;
  int array[lenght] = {9, 0, 8, 1, 7, 2, 6, 3, 5, 4};

  cout << "\n Enter the wanted value: ";
  cin >> wanted;

  for(int start = 0; start < lenght; start++){
    if(wanted == array[start]){
      cout << "\n The wanted value was found and is at " << start + 1 << "ª position of the array \n\n";
    }
  }

  return 0;
}
