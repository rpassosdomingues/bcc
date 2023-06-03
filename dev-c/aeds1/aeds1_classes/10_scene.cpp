// This code distinguish strings.

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(void){
  
  string figure;
  const float PI = 3.14;
  float radius, height, baseArea, sideLength, area, amount, totalArea, totalAmount;

  totalArea = 0;
  totalAmount = 0;

  ifstream inputFile("scene.txt");
  if(!inputFile.is_open()) {
    cout << "\n File not found. \n";
    return 1;
  }

  inputFile >> figure;
  while(figure != "exit") {
  
    if(figure == "sphere") {
      inputFile >> radius;

      area = 4 * PI * radius * radius;
      amount = (4.0 / 3.0) * PI * radius * radius * radius;

      totalArea += area;
      totalAmount += amount;

      cout << "\n  Sphere: area = " << area << " m² & " << "amount = " << amount << " m³" << endl;

    } else if(figure == "cylinder"){
        inputFile >> radius >> height;

        baseArea = PI * radius * radius;
        area = (2 * PI * radius * height) + (2 * baseArea);
        amount = baseArea * height;
        
        totalArea += area;
        totalAmount += amount;
        
        cout << "Cylinder: area = " << area << " m² & " << "amount = " << amount << " m³" << endl;
    } else if(figure == "cube"){
        inputFile >> sideLength;

        area = 6 * sideLength * sideLength;
        amount = sideLength * sideLength * sideLength;

        totalArea += area;
        totalAmount += amount;

        cout << "    Cube: area =     " << area << " m² & " << "amount = " << amount << " m³" << endl;
      }
  inputFile >> figure;
  }
  inputFile.close();

  cout << "\n\t ->   The total area of the scene is: " << totalArea << " m²" << endl;
  cout << "\t -> The total amount of the scene is: " << totalAmount << " m³ \n" << endl;

  return 0;
}
