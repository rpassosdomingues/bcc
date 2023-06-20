// Here I made a project to fill the entries of a file.txt.

#include<cstdlib>
#include<fstream>
#include<iostream>
#include<time.h>

#define LENGHT 100

using namespace std;

int main(void){
  
  srand(time(NULL));   // Initialization, should only be called once.

  int start = 0, lenght = 9, range;
  int random[LENGHT];

  ofstream outputFile("outputFile.txt");

  if (!outputFile.is_open()) {
    cout << "\n Failed to create/open file." << endl;
    return 1;
  }
  
  /*
  cout << "Enter a lenght[<100] of array: ";
  cin >> lenght;
  while (lenght > LENGHT) {
    cout << "Sorry, try again: ";
    cin >> lenght;
  }
  */
  
  range = lenght - start + 1;

  for (int i = start; i < range; i++) {
    random[i] = start + rand() % range;
    random[i+1] = start + rand() % range;
    if (random[i+1] == random[i]) {
      random[i+1] = start + rand() % range;
    }
    outputFile << random[i] << " ";
  }
  outputFile.close();
  cout << "\n File filled successfully." << endl;

  return 0;
}
