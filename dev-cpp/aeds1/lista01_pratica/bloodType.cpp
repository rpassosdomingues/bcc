/*
Aqui estou trabalhando num projeto que mostre as possíveis tipagens sanguíneas.
*/

#include <stdio.h>

using namespace std;

int main() {
    
    char filho, fatorRH tipoSangueMae, tipoSanguePai;

    printf("Digite a tipagem sanguínea do pai: ");
    scanf(" %c", &tipoSanguePai);

    printf("Digite a tipagem sanguínea da mãe: ");
    scanf(" %c", &tipoSangueMae);

    // estruturas condicionais

    // linha 01: mãe A
    if (mae == 'a' && pai == 'a'){
        tipoSangue = 'a' || tipoSangue = 'b';
    }
    if (mae == 'a' && pai == 'b'){
        tipoSangue = 'a' || tipoSangue = 'b' || tipoSangue = "c" || tipoSangue = 'o';
    }
    if (mae == 'a' && pai == "c"){
        tipoSangue = 'a' || tipoSangue = 'b' || tipoSangue = "c";
    }
    if (mae == 'a' && pai == 'o'){
        tipoSangue = 'a' || tipoSangue = 'o';
    }


    // linha 02: mãe B
    if (mae == 'b' && pai == 'a'){
        tipoSangue = 'a' || tipoSangue = 'b' || tipoSangue = "c" || tipoSangue = 'o';
    }
    if (mae == 'b' && pai == 'b'){
        tipoSangue = 'b' || tipoSangue = 'o';
    }
    if (mae == 'b' && pai == "c"){
        tipoSangue = 'a' || tipoSangue = 'b' || tipoSangue = "o";
    }
    if (mae == 'b' && pai == 'o'){
        tipoSangue = 'b' || tipoSangue = 'o';
    }

    // linha 03: mãe AB - obs: chamei de ab = c pois ainda não sei lidar com variáveis do tipo string
    if (mae == "c" && pai == 'a'){
        tipoSangue = 'a' || tipoSangue = 'b' || tipoSangue = "c" || tipoSangue = 'o';
    }
    if (mae == "c" && pai == 'b'){
        tipoSangue = 'b' || tipoSangue = 'o';
    }
    if (mae == "c" && pai == "c"){
        tipoSangue = 'a' || tipoSangue = 'b' || tipoSangue = "o";
    }
    if (mae == "c" && pai == 'o'){
        tipoSangue = 'b' || tipoSangue = 'o';
    }

    // linha 04: mãe O
    if (mae == 'o' && pai == 'a'){
        tipoSangue = 'a' || tipoSangue = 'o';
    }
    if (mae == 'o' && pai == 'b'){
        tipoSangue = 'b' || tipoSangue = 'o';
    }
    if (mae == 'o' && pai == "c"){
        tipoSangue = 'a' || tipoSangue = 'b';
    }
    if (mae == 'o' && pai == 'o'){
        tipoSangue = 'o';
    }

    // Positivo ou Negativo?
    if (mae == "p" && pai == "p"){
        tipoSangue = "p";
    }
    if (mae == "p" && pai == "n"){
        tipoSangue = "p" || tipoSangue = "n";
    }
    if (mae == "n" && pai == "p"){
        tipoSangue = "p" || tipoSangue = "n";
    }
    if (mae == "n" && pai == "n"){
        tipoSangue = "n";
    }
    
    printf("\n\t A(s) tipagem sanguínea possível é/são: %c \n", tipoSangue);
    printf("\n\t O(s) fator RH possível é/são: %c \n", fatorRH);

    return 0;
}
