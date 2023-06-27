#include <iostream>

using namespace std;

void printArray(int array[], int length){
  cout << "\n{ ";
  for (int i = 0; i < length; i++) {
    cout << array[i] << " ";
  }
  cout << "}\n\n";
}

int main (void) {

  int length = 10;
  int array[length] = {0,1,2,3,4,5,6,7,8,9};
  
  printArray(array, length);

  return 0;
}
