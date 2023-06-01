// This program prints the infamous "ASCII Table".

// ASCII Table - (American Standard Code for Information Interchange (ASCII))
// more info: url<https://link.springer.com/chapter/10.1007/978-1-4842-7064-6_13>

#include<stdio.h>

int main(void){
  
  printf("\n\t ASCII Table \n\n");

  unsigned char charValue = 98;  // Unsigned char variable.

  charValue = 0;
  while (charValue < 255){
    printf("\t\t Character: %c", charValue);
    printf("\t\t Code: %d\n\n", charValue);
    charValue++;  // Increment by (one): adds 1 to each
                  // value starting from zero (function call)
                  // and stops at 254.
  }

  return 0;
}
