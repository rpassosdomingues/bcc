#include <stdio.h>

int main() {
    int x = 1;

    printf("x\t|\tf(x)\t|\tg(x)\t|\ty\n");
    printf("--------------------------------------\n");

    while (x <= 10) {
        int hx = x - 16;
        int fx, gx;

        if (hx >= 0)
            fx = hx;
        else
            fx = 1;

        if (fx == 0)
            gx = x + 16;
        else
            gx = 0;

        int result = fx + gx;

        printf("%d\t|\t%d\t|\t%d\t|\t%d\n", x, fx, gx, result);

        x++;
    }

    return 0;
}
