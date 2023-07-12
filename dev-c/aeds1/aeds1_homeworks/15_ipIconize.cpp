// Iconize the image, i.e. reduce the input image to a 64 x 64 pixel image.

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

typedef int tImage[1000][1000]; // Image data type

string error; // Global variable to store error messages

int uploadPGM(string name, tImage image, int* lines, int* columns, int* tones) {
  string type;
  ifstream file(name);
  
  if (!file.is_open()) {
    error = "Error: File not found.";
    return 1;
  }

  file >> type;
  if (type != "P2") {
    error = "Error: The file does not have the P2 format.";
    return 2;
  }

  file >> *columns >> *lines >> *tones;
  for (int i = 0; i < *lines; i++) {
    for (int j = 0; j < *columns; j++) {
      file >> image[i][j];
    }
  }
  file.close();
  return 0;
}

int savePGM(string name, tImage image, int lines, int columns, int tones) {
  ofstream file(name);
  
  if (!file.is_open()) {
    error = "Error: File not found.";
    return 1;
  }

  file << "P2" << endl << columns << " " << lines << endl << tones << endl;
  for (int i = 0; i < lines; i++) {
    for (int j = 0; j < columns; j++) {
      file << image[i][j] << " ";
    }
    file << endl;
  }
  file.close();
  return 0;
}

void iconize(tImage inputImage, tImage outputImage, int lines, int columns) {
  int iconSize = 64;

  for (int i = 0; i < iconSize; i++) {
    for (int j = 0; j < iconSize; j++) {
      int row = i * lines / iconSize;
      int col = j * columns / iconSize;
      outputImage[i][j] = inputImage[row][col];
    }
  }
}

int main(void) {
  tImage inputImage, outputImage;
  int columns = 10, lines = 10, tones;
  string inputFile, outputFile;

  // Read input image file
  cout << "Enter the input image name: ";
  cin >> inputFile;
  inputFile = inputFile + ".pgm";
  if (uploadPGM(inputFile, inputImage, &lines, &columns, &tones) != 0) {
    cout << "\n" + error + "\n";
    return 1;
  }
  
  // Iconize the image
  iconize(inputImage, outputImage, lines, columns);
  
  // Write the output image file
  cout << "Enter the output image name: ";
  cin >> outputFile;
  outputFile = outputFile + ".pgm";
  if (savePGM(outputFile, outputImage, columns, lines, tones) != 0) {
    cout << "\n" + error + "\n";
    return 1;
  }
  
  cout << "Image iconization complete.\n";
  
  return 0;
}
