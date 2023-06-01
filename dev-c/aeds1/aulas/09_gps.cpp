// This code calculate the distance between cities based on a text file "gps.txt".

#include <cstdlib>
#include <iostream> // Uses cin and cout - Replacement for scanf
#include <fstream>  // For handling file-specific commands. Stream refers to data flow character by character.
#include <cmath>

using namespace std;

int main(void){

  float x1, x2, y1, y2, z1, z2, distanceAB, distanceBC, distanceAC;
  
  ifstream inputFile("gps.txt");
  if(!inputFile.is_open()) {
    cout << "\n File not found. \n";
    return 1;
  }

  inputFile >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;

  cout << "x1: " << x1 << endl;
  cout << "x2: " << x2 << endl;

  cout << "y1: " << y1 << endl;
  cout << "y2: " << y2 << endl;

  cout << "z1: " << z1 << endl;
  cout << "z2: " << z2 << endl;

  while(x1 != 0 && x2 != 0){
    inputFile >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
  }
  inputFile.close();

  distanceAB = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
  distanceBC = sqrt((y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
  distanceAC = sqrt(distanceAB * distanceAB + distanceBC * distanceBC);

  cout << "The distance from A to B is: " << distanceAB << endl;
  cout << "The distance from B to C is: " << distanceBC << endl;
  cout << "The distance from A to C is: " << distanceAC << endl;

  return 0;
}
