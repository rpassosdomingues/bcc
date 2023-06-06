/*
 * Author: Rafael Passos Domingues
 * Student ID: 2023.1.08.036
 * 
 * Exercise 1: Find the largest and smallest value in the array and indicate their positions.
 * Exercise 2: Search for a value provided by the user in the array. If found, indicate the position of the value in the array.
 * Exercise 3: Count the number of occurrences of a value provided by the user.
 * Exercise 4: Multiply the even values in an array by 2 and assign zero to the odd values.
 * Exercise 5: Increment the values in an array by a factor provided by the user, limiting the results to the range between 0 and 255.
 * 
 * Created on May 30, 2023
 */

#include <iostream>

using namespace std;

int main(void) {
  
  int i, size = 10;
  int iMax, iMin, iSearch;
  int largestValue = -1, smallestValue = 1000;
  int searchValue, repeatedValue, occurrencesCount = 0, increment;

  int array1[size] = {40, 11, 27, 30, 4, 25, 16, 27, 87, 9};
  int array2[size] = {0, 0, 1, 1, 1, 2, 3, 3, 4, 5};
  int array3[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int array4[size] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  
  // Exercise 1
  cout << "Exercise 1 \n";
  for (i = 0; i < size; i++) {
    if (array1[i] > array1[i+1] && largestValue < array1[i]) {
      largestValue = array1[i];
      iMax = i;
    } else
        if (array1[i] < array1[i+1] && smallestValue > array1[i]) {
          smallestValue = array1[i];
          iMin = i;
        }
  }
  cout << "The largest value is: " << largestValue << " and it is located at position " << iMax << " in the array." << endl;
  cout << "The smallest value is: " << smallestValue << " and it is located at position " << iMin << " in the array." << endl;
  cout << "\n\n";

  // Exercise 2
  cout << "Exercise 2 \n";
  cout << "Enter a value to search in the array: ";
  cin >> searchValue;
  for (i = 0; i < size; i++) {
    if (searchValue == array1[i]) {
      iSearch = i;
    }
  }
  cout << "The value was found at position " << iSearch << " in the array." << endl;
  cout << "\n\n";

  // Exercise 3
  cout << "Exercise 3 \n";
  cout << "Enter a value to count its occurrences in the array: ";
  cin >> repeatedValue;
  for (i = 0; i < size; i++) {
    if (repeatedValue == array2[i]) {
      occurrencesCount++;
    }
  }
  cout << "The value appears " << occurrencesCount << " times in the array." << endl;
  cout << "\n\n";



  // Exercise 4
  cout << "Exercise 4 \n";
  for (i = 0; i < size; i++) {
    if (array3[i] % 2 == 0) {
      array3[i] = 2 * array3[i];
    } else
        if (array3[i] % 2 != 0) {
          array3[i] = 0;
        }
  }
  cout << "The modified array is: ";
  for (i = 0; i < size; i++) {
    cout << array3[i] << " ";
  }

  // Exercise 5
  cout << "Exercise 5 \n";
  cout << "Enter an increment [0 < increment < 255]: ";
  cin >> increment;
  while (increment < 0 || increment > 255) {
    cout << "Sorry, something is wrong... Try again: ";
    cin >> increment;
  }
  for (i = 0; i < size; i++) {
    array4[i] += increment;
  }
  cout << "The incremented array is: ";
  for (i = 0; i < size; i++) {
    cout << array4[i] << " ";
  }

  cout << "\n\n";
  return 0;
}
