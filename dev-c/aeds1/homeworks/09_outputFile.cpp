// Here I made a project to fill the entries of a file.txt.

#include<cstdlib>
#include<fstream>
#include<iostream>

using namespace std;

int main(void){

  int lenght=1000, increment=100, random_filler;

  ofstream outputFile("outputFile.txt");

  if(!outputFile.is_open()) {
    cout << "\n Failed to create/open file. \n";
    return 1;
  }

  cout << "\n Enter the starting value: ";
  cin >> random_filler;

  while (random_filler < lenght) {
    outputFile << random_filler << endl;
    random_filler += increment;
  }
  outputFile.close();
  cout << "\n File filled successfully. \n";

  return 0;
}
