// This project create a jail of characters.

#include <stdio.h>

#define LENGHT 30

int main(void) {
  
  int i,j;
  char name[LENGHT], lastName[LENGHT], fullName[2*LENGHT];
  
  name[0] = 'R';
  name[1] = 'a';
  name[2] = 'f';
  name[3] = 'a';
  name[4] = 'e';
  name[5] = 'l';
  name[6] = ' ';
  int sizeName = 7;

  printf("\n Name: %s.\n", name);

  lastName[0] = 'D';
  lastName[1] = 'o';
  lastName[2] = 'm';
  lastName[3] = 'i';
  lastName[4] = 'n';
  lastName[5] = 'g';
  lastName[6] = 'u';
  lastName[7] = 'e';
  lastName[8] = 's';
  lastName[9] = '\0';
  int sizeLastName = 10;

  printf("\n Last Name: %s.\n\n", lastName);

  for (i=0; i < sizeName; i++) {
    fullName[i] = name[i];
  }
  for (j=0; j < sizeLastName; j++) {
    fullName[j + sizeName] = lastName[j];
  }
  printf("\n Full Name: %s.\n\n", fullName);

return 0;
}
