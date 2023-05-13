/*
Aqui estou trabalhando num projeto que mostre as possíveis tipagens sanguíneas==
*/

#include <stdio.h>

using namespace std;

int main() {
    
    char tipoSangue, fatorRH, tipoSangueMae, tipoSanguePai;

    printf("Digite a tipagem sanguínea do tipoSanguePai: ");
    scanf(" %c", &tipoSanguePai);

    printf("Digite a tipagem sanguínea da mãe: ");
    scanf(" %c", &tipoSangueMae);

    // estruturas condicionais

    // linha 01: mãe A
    if (tipoSangueMae == 'a' && tipoSanguePai == 'a'){
        tipoSangue == 'a' || tipoSangue == 'b';
    }
    if (tipoSangueMae == 'a' && tipoSanguePai == 'b'){
        tipoSangue == 'a' || tipoSangue == 'b' || tipoSangue == 'c' || tipoSangue == 'o';
    }
    if (tipoSangueMae == 'a' && tipoSanguePai == 'c'){
        tipoSangue == 'a' || tipoSangue == 'b' || tipoSangue == 'c';
    }
    if (tipoSangueMae == 'a' && tipoSanguePai == 'o'){
        tipoSangue == 'a' || tipoSangue == 'o';
    }


    // linha 02: mãe B
    if (tipoSangueMae == 'b' && tipoSanguePai == 'a'){
        tipoSangue == 'a' || tipoSangue == 'b' || tipoSangue == 'c' || tipoSangue == 'o';
    }
    if (tipoSangueMae == 'b' && tipoSanguePai == 'b'){
        tipoSangue == 'b' || tipoSangue == 'o';
    }
    if (tipoSangueMae == 'b' && tipoSanguePai == 'c'){
        tipoSangue == 'a' || tipoSangue == 'b' || tipoSangue == 'o';
    }
    if (tipoSangueMae == 'b' && tipoSanguePai == 'o'){
        tipoSangue == 'b' || tipoSangue == 'o';
    }

    // linha 03: mãe AB - obs: chamei de ab == c pois ainda não sei lidar com variáveis do tipo string
    if (tipoSangueMae == 'c' && tipoSanguePai == 'a'){
        tipoSangue == 'a' || tipoSangue == 'b' || tipoSangue == 'c' || tipoSangue == 'o';
    }
    if (tipoSangueMae == 'c' && tipoSanguePai == 'b'){
        tipoSangue == 'b' || tipoSangue == 'o';
    }
    if (tipoSangueMae == 'c' && tipoSanguePai == 'c'){
        tipoSangue == 'a' || tipoSangue == 'b' || tipoSangue == 'o';
    }
    if (tipoSangueMae == 'c' && tipoSanguePai == 'o'){
        tipoSangue == 'b' || tipoSangue == 'o';
    }

    // linha 04: mãe O
    if (tipoSangueMae == 'o' && tipoSanguePai == 'a'){
        tipoSangue == 'a' || tipoSangue == 'o';
    }
    if (tipoSangueMae == 'o' && tipoSanguePai == 'b'){
        tipoSangue == 'b' || tipoSangue == 'o';
    }
    if (tipoSangueMae == 'o' && tipoSanguePai == 'c'){
        tipoSangue == 'a' || tipoSangue == 'b';
    }
    if (tipoSangueMae == 'o' && tipoSanguePai == 'o'){
        tipoSangue == 'o';
    }

    // Positivo ou Negativo?
    if (tipoSangueMae == 'p' && tipoSanguePai == 'p'){
        tipoSangue == 'p';
    }
    if (tipoSangueMae == 'p' && tipoSanguePai == 'n'){
        tipoSangue == 'p' || tipoSangue == 'n';
    }
    if (tipoSangueMae == 'n' && tipoSanguePai == 'p'){
        tipoSangue == 'p' || tipoSangue == 'n';
    }
    if (tipoSangueMae == 'n' && tipoSanguePai == 'n'){
        tipoSangue == 'n';
    }
    
    printf("\n\t A(s) tipagem sanguínea possível é/são: %c \n", tipoSangue);
    printf("\n\t O(s) fator RH possível é/são: %c \n", fatorRH);

    return 0;
}
