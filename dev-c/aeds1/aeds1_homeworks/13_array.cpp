#include <stdio.h>
#include <iostream>

using namespace std;

#define LENGHT 10

int main(void) {

  int i,j;
  
  // Exercise 1: overwrites repeated elements in the array
  int array0[LENGHT] = {0,0,1,1,2,2,3,3,4,4};

  // Exercise 2: arrays union
  int array1[LENGHT] = {0,1,2,3,4};
  int array2[LENGHT] = {5,6,7,8,9};
  int array3[LENGHT];

  for (i = 0; i < 5; i++) {
    array3[i] = array1[i];
    array3[i+5] = array2[i];
  }
  
  cout << "\n array union: { ";
  for(i = 0; i < LENGHT; i++){
    cout << array3[i] << " ";
  }
  cout << "}\n\n";

  // Exercise 3: arrays intersection
  int array4[LENGHT] = {-2,-1,0,1,2};
  int array5[LENGHT] = {9,8,7,6,5};
  int array6[LENGHT];
  
  i = 0;
  j = i+1;

  while (i < array3[i] && j < array4[j]) {
    if (array3[i] < array4[j]) {
      i++;
    } else if (array3[i] > array4[j]) {
      j++;
    } else {
        array5[i] = array3[i];
        array5[j] = array4[j];
        i++;
        j++;
      }
  }

  return 0;
}
