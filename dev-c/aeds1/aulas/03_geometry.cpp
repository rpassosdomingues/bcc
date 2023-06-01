/*
  Here I wrote a code to calculate the total area and amount of a cylinder
  by taking its radius and height as input.

  That is:
    input <-  radius and height.
    output -> total area and amount.
*/
#include<cstdlib>
#include<iostream> // scanf and printf to cin e cout
#include<math.h>  // Import the library that provides mathematical functions.

using namespace std;

int main(void){
    
    float radius, height, baseArea, totalArea, amount; // Reserve five memory spaces
                                                       // to store two inputs,
                                                       // perform assignment operations,
                                                       // and return two outputs.
    const float PI = 3.1415;  // Reserve one memory space
                              // to store the constant PI from the -math- library.
    
    cout <<"\n Enter the radius: ";
    cin >> radius;
    
    cout <<"\n Enter the height: ";
    cin >> height;
    
    baseArea = PI * pow(radius, 2);               // Assignment operation

    totalArea = 2*PI*radius*height + 2*baseArea;  // Assignment1 and output1
    amount = baseArea * height;                   // Assignment2 and output2
 
    cout <<"\n\t The total area of the Cylinder is: " << totalArea << "m²\n" << endl;
    cout <<"\t The amount of the Cylinder is: " << amount << "m³ \n\n" << endl;
    
    return 0;
}
