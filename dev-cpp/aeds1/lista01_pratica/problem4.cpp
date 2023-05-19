#include <stdio.h>

int main() {
    
    int m, n, x, y, expressao, valorMax, xMax, yMax;

    x = 1;
    y = 1;
    valorMax = 0;

    printf("\n Digite o valor de m: ");
    scanf("%d", &m);
    printf("\n Digite o valor de n: ");
    scanf("%d", &n);

    while (x < m) {
      while (y < n) {
        expressao = x*y - x*x + y;
          if (expressao > valorMax) {
            valorMax = expressao;
            xMax = x;
            yMax = y;
          }
          y++;
      }
      x++;
    }

    printf("\n\t O par (x, y) que maximiza a expressão é: (%d, %d)\n", xMax, yMax);
    printf("\t O valor máximo encontrado é: %d \n\n", valorMax);

    return 0;
}
