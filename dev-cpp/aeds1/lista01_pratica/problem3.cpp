#include <stdio.h>

int main() {
    int m, n;
    printf("Digite o valor de m: ");
    scanf("%d", &m);
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int max_value = 0;
    int max_x, max_y;

    int x = 1;
    while (x < m) {
        int y = 1;
        while (y < n) {
            int value = x * y - x * x + y;
            if (value > max_value) {
                max_value = value;
                max_x = x;
                max_y = y;
            }
            y++;
        }
        x++;
    }

    printf("O par (x, y) que maximiza a expressão é: (%d, %d)\n", max_x, max_y);
    printf("O valor máximo encontrado é: %d\n", max_value);

    return 0;
}
