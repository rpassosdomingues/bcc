// Here I made a project to fill the entries of a file.txt.

#include<cstdlib>
#include<fstream>
#include<iostream>

using namespace std;

int main(void){

  int lenght=99, start=0, random;
  int range = lenght - start + 1;

  ofstream outputFile("outputFile.txt");

  if (!outputFile.is_open()) {
    cout << "\n Failed to create/open file." << endl;
    return 1;
  }
  
  for (int i = start; i < range; i++) {
    random = start + rand() % range;
    //outputFile << random << endl;
    outputFile << random << " ";
  }
  outputFile.close();
  cout << "\n File filled successfully." << endl;

  return 0;
}
