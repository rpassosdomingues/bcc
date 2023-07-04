#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate random array
int randomArrayGenerator(int start, int length, int randomArray[]) {
  
  srand(time(NULL));
  
  int i,j;
  int range = length - start + 1;

  i = 0;
  while (i < length) {
    randomArray[i] = start + rand() % range;
    j = 0;
    while (j < i || randomArray[j] != randomArray[i]) {
      if (randomArray[j] == randomArray[i]) {
        i--;
      }
      j++;
    }
    i++;
  }

  return randomArray[length];
}

int main(void) {
  
  int start = 0, length = 10;

  // Random Array
  int randomArray[length];
  randomArrayGenerator(start, length, randomArray);
  
  cout << "\n randomArray: { ";
  for (int i = 0; i < length; i++) {
    cout << randomArray[i] << " "; 
  }
  cout << "} \n\n";

  return 0;
}
