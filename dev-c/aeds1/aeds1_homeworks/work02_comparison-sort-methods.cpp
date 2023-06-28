/*
This code generates arrays of different sizes with different configurations 
(random, ascending and descending) and then runs the sorting algorithms 
(bubble sort, insertion sort and selection sort) on these arrays. 
It records the number of iterations performed by each 
sorting algorithm and saves the results in a CSV file. 
The goal is to make a comparative performance analysis between the 3 sorting methods.
*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>

using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int array[], int length, int& bubbleUsage) {
  int i, j;
  for (i = 0; i < length - 1; i++) {
    for (j = 0; j < length - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
      }
      bubbleUsage++;
    }
  }
}

// Function to perform Insertion Sort
void insertionSort(int array[], int length, int& insertionUsage) {
  int i, j;
  for (i = 1; i < length; i++) {
    int handle = array[i];
    for (j = i - 1; j >= 0 && array[j] > handle; j--) {
      array[j + 1] = array[j];
    }
    array[j + 1] = handle;
    insertionUsage++;
  }
}

// Function to perform Selection Sort
void selectionSort(int array[], int length, int& selectionUsage) {
  int i, j;
  for (i = 0; i < length - 1; i++) {
    int minIndex = i;
    for (j = i + 1; j < length; j++) {
      if (array[j] < array[minIndex]) {
        minIndex = j;
      }
      selectionUsage++;
    }
    int swap = array[i];
    array[i] = array[minIndex];
    array[minIndex] = swap;
  }
}

// Function to generate random array
void randomArrayGenerator(int array[], int start, int length) {
  srand(time(NULL));
  int range = length - start + 1;

  int i = 0;
  while (i < length) {
    array[i] = start + rand() % range;
    bool isRepeated = false;
    int j = 0;
    while (j < i) {
      if (array[i] == array[j]) {
        isRepeated = true;
        break;
      }
      j++;
    }
    if (!isRepeated) {
      i++;
    }
  }
}

// Function to save results to a CSV file
void saveResultsToFile(const string& filename, const int sizes[], const int randomBubbleUsages[], const int increasingBubbleUsages[], const int decreasingBubbleUsages[], const int randomInsertionUsages[], const int increasingInsertionUsages[], const int decreasingInsertionUsages[], const int randomSelectionUsages[], const int increasingSelectionUsages[], const int decreasingSelectionUsages[], int size) {
  ofstream file(filename);
  if (!file.is_open()) {
    cout << "Failed to create the file." << endl;
    return;
  }

  file << "Array Size , Random Bubble Sort Usage , Increasing Bubble Sort Usage , Decreasing Bubble Sort Usage , Random Insertion Sort Usage , Increasing Insertion Sort Usage , Decreasing Insertion Sort Usage , Random Selection Sort Usage , Increasing Selection Sort Usage , Decreasing Selection Sort Usage" << endl;
  for (int i = 0; i < size; i++) {
    file << sizes[i] << "," << randomBubbleUsages[i] << "," << increasingBubbleUsages[i] << "," << decreasingBubbleUsages[i] << "," << randomInsertionUsages[i] << "," << increasingInsertionUsages[i] << "," << decreasingInsertionUsages[i] << "," << randomSelectionUsages[i] << "," << increasingSelectionUsages[i] << "," << decreasingSelectionUsages[i] << endl;
  }

  file.close();
}

int main(void) {

  const int start = 10;
  const int end = 100;
  const int step = 10;
  const int numSizes = (end - start) / step + 1;

  int sizes[numSizes];
  int randomBubbleUsages[numSizes];
  int increasingBubbleUsages[numSizes];
  int decreasingBubbleUsages[numSizes];
  int randomInsertionUsages[numSizes];
  int increasingInsertionUsages[numSizes];
  int decreasingInsertionUsages[numSizes];
  int randomSelectionUsages[numSizes];
  int increasingSelectionUsages[numSizes];
  int decreasingSelectionUsages[numSizes];

  int currentSize = start;
  for (int i = 0; i < numSizes; i++) {
    sizes[i] = currentSize;
    currentSize += step;
  }

  for (int i = 0; i < numSizes; i++) {
    int length = sizes[i];

    // Random Array
    int randomArray[length];
    randomArrayGenerator(randomArray, start, length);

    int sortArray[length];

    int bubbleUsage = 0;
    copy(randomArray, randomArray + length, sortArray);
    bubbleSort(sortArray, length, bubbleUsage);
    randomBubbleUsages[i] = bubbleUsage;

    int insertionUsage = 0;
    copy(randomArray, randomArray + length, sortArray);
    insertionSort(sortArray, length, insertionUsage);
    randomInsertionUsages[i] = insertionUsage;

    int selectionUsage = 0;
    copy(randomArray, randomArray + length, sortArray);
    selectionSort(sortArray, length, selectionUsage);
    randomSelectionUsages[i] = selectionUsage;

    // Increasing Array
    int increasingArray[length];
    for (int j = 0; j < length; j++) {
      increasingArray[j] = j;
    }

    bubbleUsage = 0;
    copy(increasingArray, increasingArray + length, sortArray);
    bubbleSort(sortArray, length, bubbleUsage);
    increasingBubbleUsages[i] = bubbleUsage;

    insertionUsage = 0;
    copy(increasingArray, increasingArray + length, sortArray);
    insertionSort(sortArray, length, insertionUsage);
    increasingInsertionUsages[i] = insertionUsage;

    selectionUsage = 0;
    copy(increasingArray, increasingArray + length, sortArray);
    selectionSort(sortArray, length, selectionUsage);
    increasingSelectionUsages[i] = selectionUsage;

    // Decreasing Array
    int decreasingArray[length];
    for (int j = 0; j < length; j++) {
      decreasingArray[j] = length - j - 1;
    }

    bubbleUsage = 0;
    copy(decreasingArray, decreasingArray + length, sortArray);
    bubbleSort(sortArray, length, bubbleUsage);
    decreasingBubbleUsages[i] = bubbleUsage;

    insertionUsage = 0;
    copy(decreasingArray, decreasingArray + length, sortArray);
    insertionSort(sortArray, length, insertionUsage);
    decreasingInsertionUsages[i] = insertionUsage;

    selectionUsage = 0;
    copy(decreasingArray, decreasingArray + length, sortArray);
    selectionSort(sortArray, length, selectionUsage);
    decreasingSelectionUsages[i] = selectionUsage;
  }

  // Save results to a file
  saveResultsToFile("sort_usages.csv", sizes, randomBubbleUsages, increasingBubbleUsages, decreasingBubbleUsages, randomInsertionUsages, increasingInsertionUsages, decreasingInsertionUsages, randomSelectionUsages, increasingSelectionUsages, decreasingSelectionUsages, numSizes);
  
  cout << "File 'sort_usages.csv' created successfully." << endl;
  
  return 0;
}
