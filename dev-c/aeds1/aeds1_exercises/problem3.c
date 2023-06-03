#include <stdio.h>

int main(void) {
    int h, f, g, x, y;
    
    x = 1;

    printf("---------------------------------------\n");
    printf("    x \t|   f(x)  |   g(x)  |    y    \n");
    printf("---------------------------------------\n");

    while (x <= 10) {
      h = x - 16;

      if (h >= 0){
        f = h;
      } else
          f = 1;

      if (f == 0){
        g = x*x + 16;
      } else
          g = 0;

      y = f + g;

      printf("    %d \t|    %d    |    %d    |    %d    \n", x, f, g, y);

      x++;
    }
    printf("---------------------------------------\n");

    return 0;
}
