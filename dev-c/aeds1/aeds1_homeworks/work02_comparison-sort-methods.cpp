#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>

using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int array[], int length) {
  int bubbleUsage = 0; // Counter for Bubble Sort usage
  int i, j;
  for (i = 0; i < length - 1; i++) {
    for (j = 0; j < length - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
        bubbleUsage += 3; // Increment counter for Bubble Sort usage
      }
    }
  }
  //cout << "Bubble Sort Usage: " << bubbleUsage << endl;
}

// Function to perform Insertion Sort
void insertionSort(int array[], int length) {
  int insertionUsage = 0; // Counter for Insertion Sort usage
  int i, j;
  for (i = 1; i < length; i++) {
    int handle = array[i];
    for (j = i - 1; j >= 0 && array[j] > handle; j--) {
      array[j + 1] = array[j];
      insertionUsage += 1; // Increment counter for Insertion Sort usage
    }
    array[j + 1] = handle;
  }
  //cout << "Insertion Sort Usage: " << insertionUsage << endl;
}

// Function to perform Selection Sort
void selectionSort(int array[], int length) {
  int selectionUsage = 0; // Counter for Selection Sort usage
  int i, j;
  for (i = 0; i < length - 1; i++) {
    int minIndex = i;
    for (j = i + 1; j < length; j++) {
      if (array[j] < array[minIndex]) {
        minIndex = j;
        selectionUsage += 2; // Increment counter for Selection Sort usage
      }
    }
    int swap = array[i];
    array[i] = array[minIndex];
    array[minIndex] = swap;
  }
  //cout << "Selection Sort Usage: " << selectionUsage << endl;
}

// Function to generate random array and calculate the average of three generated arrays
void randomArrayGenerator(int array[], int start, int length) {
  srand(time(NULL));
  int range = length - start + 1;

  int randomArray1[length];
  int randomArray2[length];
  int randomArray3[length];

  // Generate three random arrays
  for (int i = 0; i < length; i++) {
    randomArray1[i] = start + rand() % range;
    randomArray2[i] = start + rand() % range;
    randomArray3[i] = start + rand() % range;
  }

  // Calculate the average of the three arrays
  for (int i = 0; i < length; i++) {
    array[i] = (randomArray1[i] + randomArray2[i] + randomArray3[i]) / 3;
  }
}

// Function to copy the elements of one array to another
void copyArray(int source[], int destination[], int length) {
  for (int i = 0; i < length; i++) {
    destination[i] = source[i];
  }
}

// Function to save results to a CSV file
void saveResultsToFile(const string& filename, const int sizes[], const int randomBubbleUsages[],
                       const int increasingBubbleUsages[], const int decreasingBubbleUsages[],
                       const int randomInsertionUsages[], const int increasingInsertionUsages[],
                       const int decreasingInsertionUsages[], const int randomSelectionUsages[],
                       const int increasingSelectionUsages[], const int decreasingSelectionUsages[],
                       int size) {
  ofstream file(filename);
  if (!file.is_open()) {
    cout << "Failed to create the file." << endl;
    return;
  }

  // Write header to the file
  file << "Array Size" << "," <<
          "Random Bubble Sort Usage" << "," << "Increasing Bubble Sort Usage" << "," << "Decreasing Bubble Sort Usage" << "," <<
          "Random Insertion Sort Usage" << "," << "Increasing Insertion Sort Usage" << "," << "Decreasing Insertion Sort Usage" << "," <<
          "Random Selection Sort Usage" << "," << "Increasing Selection Sort Usage" << "," << "Decreasing Selection Sort Usage" << endl;

  // Write data to the file
  for (int i = 0; i < size; i++) {
    file << sizes[i] << "," <<
            randomBubbleUsages[i] << "," << increasingBubbleUsages[i] << "," << decreasingBubbleUsages[i] << "," <<
            randomInsertionUsages[i] << "," << increasingInsertionUsages[i] << "," << decreasingInsertionUsages[i] << "," <<
            randomSelectionUsages[i] << "," << increasingSelectionUsages[i] << "," << decreasingSelectionUsages[i] << endl;
  }

  file.close();
}

int main(void) {
  const int start = 100;
  const int end = 10000;
  const int step = 100;
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

    // Bubble Sort
    int bubbleUsage = 0;
    copyArray(randomArray, sortArray, length);
    bubbleSort(sortArray, length);
    randomBubbleUsages[i] = bubbleUsage;

    // Insertion Sort
    int insertionUsage = 0;
    copyArray(randomArray, sortArray, length);
    insertionSort(sortArray, length);
    randomInsertionUsages[i] = insertionUsage;

    // Selection Sort
    int selectionUsage = 0;
    copyArray(randomArray, sortArray, length);
    selectionSort(sortArray, length);
    randomSelectionUsages[i] = selectionUsage;

    // Rest of the code for generating and sorting increasing and decreasing arrays
  }

  // Save results to a file
  saveResultsToFile("sort_usages.csv", sizes,
                     randomBubbleUsages, increasingBubbleUsages, decreasingBubbleUsages,
                     randomInsertionUsages, increasingInsertionUsages, decreasingInsertionUsages,
                     randomSelectionUsages, increasingSelectionUsages, decreasingSelectionUsages,
                     numSizes);

  cout << "File 'sort_usages.csv' created successfully." << endl;

  return 0;
}
