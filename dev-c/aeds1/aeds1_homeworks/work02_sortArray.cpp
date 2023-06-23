#include <cstdlib>
#include <fstream>
#include <iostream>
#include <time.h>

using namespace std;

int main(void) {

  srand(time(NULL));

  int length = 10, start = 0;
  int range = length - start + 1;

  int random[length];

  ofstream outputFile("randomArrayFile.txt");

  if (!outputFile.is_open()) {
    cout << "\n Failed to create file." << endl;
    return 1;
  }

  random[0] = start + rand() % range;
  outputFile << length << " " << random[0] << " ";

  int i = 1;
  while (i < length) {
    random[i] = start + rand() % range;
    bool isRepeated = false;
    int j = 0;
    while (j < i) {
      if (random[i] == random[j]) {
        isRepeated = true;
        j = i;
      }
      j++;
    }
    if (!isRepeated) {
      outputFile << random[i] << " ";
      i++;
    }
  }
  outputFile.close();
  cout << "\n File filled successfully. \n\n" << endl;

  return 0;
}
