// Apply the low-pass filter to smooth the image.

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

void applyLowPassFilter(tImage inputImage, tImage outputImage, int lines, int columns) {
  for (int i = 1; i < lines - 1; i++) {
    for (int j = 1; j < columns - 1; j++) {
      // Calculate the average of the surrounding pixels
      outputImage[i][j] = (inputImage[i - 1][j - 1] + inputImage[i - 1][j] + inputImage[i - 1][j + 1] +
                          inputImage[i][j - 1] + inputImage[i][j] + inputImage[i][j + 1] +
                          inputImage[i + 1][j - 1] + inputImage[i + 1][j] + inputImage[i + 1][j + 1]) / 9;
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
  
  // Apply low-pass filter to the image
  applyLowPassFilter(inputImage, outputImage, lines, columns);
  
  // Write the output image file
  cout << "Enter the output image name: ";
  cin >> outputFile;
  outputFile = outputFile + ".pgm";
  if (savePGM(outputFile, outputImage, columns, lines, tones) != 0) {
    cout << "\n" + error + "\n";
    return 1;
  }
  
  cout << "Low-pass filter applied.\n";
  
  return 0;
}
