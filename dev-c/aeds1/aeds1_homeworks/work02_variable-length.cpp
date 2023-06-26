#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {

  int length;
  for (length = 100; length < 1000; length += 100) {

    // Generate a random array without repetition
    srand(time(NULL));

    int start = 0;
    int range = length - start + 1;

    int array[length];
    int i,j;

    ofstream outputFile("randomArrayFile.txt");

    if (!outputFile.is_open()) {
      cout << "\n Failed to create file." << endl;
      return 1;
    }

    array[0] = start + rand() % range;
    outputFile << length << " " << array[0] << " ";

    i = 1;
    while (i < length) {
      array[i] = start + rand() % range;
      bool isRepeated = false;
      int j = 0;
      while (j < i) {
        if (array[i] == array[j]) {
          isRepeated = true;
          j = i;
        }
        j++;
      }
      if (!isRepeated) {
        outputFile << array[i] << " ";
        i++;
      }
    }
    outputFile.close();
    cout << "\n File filled successfully. \n\n" << endl;

    cout << " Original array: { ";
    for (i = 0; i < length; i++) {
      cout << array[i] << " ";
    }
    cout << "}\n";
  
    // Selection Sort
    int selectionUsage = 0;
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

    cout << "\n Selection Sort: { ";
    for (i = 0; i < length; i++) {
      cout << array[i] << " ";
    }
    cout << "}\n";
    
    // Insertion Sort
    int insertionUsage = 0;
    for (i = 1; i < length; i++) {
      int handle = array[i];
      for (j = i-1; j >= 0 && array[j] > handle; j++) {
        array[j+1] = array[j];
      }
      array[j+1] = handle;
      insertionUsage++;
    }

    cout << " Insertion Sort: { ";
    for (i = 0; i < length; i++) {
      cout << array[i] << " ";
    }
    cout << "}\n";

    // Bubble Sort
    int bubbleUsage = 0;
    for (i = 0; i < length - 1; i++) {
      for (j = 0; j < length - i - 1; j++) {
        if (array[j] > array[j+1]) {
          int tmp = array[j];
          array[j] = array[j+1];
          array[j+1] = tmp;
        }
        bubbleUsage++;
      }
    }

    cout << "    Bubble Sort: { ";
    for (i = 0; i < length; i++) {
      cout << array[i] << " ";
    }
    cout << "}\n\n";

    ofstream outputFile2("dataGraph.txt");
    if (!outputFile2.is_open()) {
      cout << "\n Failed to create file." << endl;
      return 1;
    }
    
    for (length = 100; length < 1000; length+=100) {
      outputFile2 << length << " " << selectionUsage << " " << insertionUsage << " " << bubbleUsage << endl;
    }

    outputFile2.close();
    cout << "\n Data Graph create with successfully. \n\n" << endl;
    
  }
  
  return 0;
}