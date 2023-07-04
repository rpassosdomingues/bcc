#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate an ordered array and shuffle it
void randomArrayGenerator(int start, int length, int randomArray[]) {
    srand(time(NULL));

    // generate a sort array
    for (int i = 0; i < length; i++) {
        randomArray[i] = start + i;
    }

    // shuffle array
    for (int i = length - 1; i > 0; i--) {
      int j = rand() % (i + 1);
      int temp = randomArray[i];
      randomArray[i] = randomArray[j];
      randomArray[j] = temp;
    }
}

int main(void) {
    int start = 0, length = 10;

    // Random Shuffle Array
    int randomArray[length];
    randomArrayGenerator(start, length, randomArray);

    cout << "\n shuffle Array: { ";
    for (int i = 0; i < length; i++) {
        cout << randomArray[i] << " ";
    }
    cout << "} \n\n";

    return 0;
}
