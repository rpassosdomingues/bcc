// Aqui eu fiz um projeto para mostrar se a parábola tem raízes reais.

#include <stdio.h>
#include <math.h>

using namespace std;

int main() {

    float a, b, c, delta;

    printf("\n Digite os coeficientes a b c: ");
    scanf("%f %f %f", &a, &b, &c);

    delta = b*b - 4 * a * c;

    if (delta >= 0){
        printf("\n A equação tem raízes reais \n\n");
    } else
          printf("\n A equação não tem raízes reais \n\n");
    

    return 0;
}
