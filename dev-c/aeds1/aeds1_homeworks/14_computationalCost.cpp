#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main() {
    // Generate a random array without repetition
    const int ARRAY_SIZE = 10;
    vector<int> arr(ARRAY_SIZE);

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        arr[i] = i + 1;
    }

    random_shuffle(arr.begin(), arr.end());

    // Set the first data of the file to the length of the vector
    ofstream file("output.txt");
    file << ARRAY_SIZE << endl;
    file.close();

    // Join the sorting algorithms (selection, insertion, and bubble)
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Selection Sort
    cout << "Selection Sort: ";
    clock_t start = clock();

    for (int i = 0; i < ARRAY_SIZE - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < ARRAY_SIZE; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }

    clock_t end = clock();
    double selectionTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Selection Sort Execution Time: " << selectionTime << " seconds" << endl;

    // Insertion Sort
    cout << "Insertion Sort: ";
    start = clock();

    for (int i = 1; i < ARRAY_SIZE; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }

    end = clock();
    double insertionTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Insertion Sort Execution Time: " << insertionTime << " seconds" << endl;

    // Bubble Sort
    cout << "Bubble Sort: ";
    start = clock();

    for (int i = 0; i < ARRAY_SIZE - 1; ++i) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    end = clock();
    double bubbleTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Bubble Sort Execution Time: " << bubbleTime << " seconds" << endl;

    return 0;
}

