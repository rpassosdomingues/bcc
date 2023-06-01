// Aqui eu fiz um projeto para retornar o fatorial de um número n.

#include <stdio.h>

using namespace std;

int main() {

    long int n, fatorial_n;

    printf("\n Digite o número n: ");
    scanf(" %ld", &n);

    //fatorial_n = n * fatorial (n-1)
    
    fatorial_n = 1;
    while (n > 0){
        fatorial_n = n * fatorial_n;
        n = n - 1;
    }

    printf("\n O fatorial deste número é = %ld \n\n", fatorial_n);

    return 0;
}
