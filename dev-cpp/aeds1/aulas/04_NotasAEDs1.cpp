// Aqui eu escrevi um código implementando os recursos que aprendi
// utilizando os operadores condicionais if e estruturas de repetição while.

// Este programa informa ao usuário, dadas as entradas de notas
// se este está ou não aprovado de acordo com sua média.

#include<stdio.h>

int main() {
    
    float nota1, nota2, notatrab, media;
    
    printf("\n\t Digite a nota1: ");
    scanf(" %f", &nota1);
    while (nota1 < 0.0 || nota1 > 10.0){
        printf("\n\t Valor inválido. Digite novamente a nota1:");
        scanf(" %f", &nota1);
    }
    
    printf("\n\t Digite a nota2: ");
    scanf(" %f", &nota2);
    while (nota2 < 0.0 || nota2 > 10.0){
        printf("\n\t Valor inválido. Digite novamente a nota2:");
        scanf(" %f", &nota2);
    }
    
    printf("\n\t Digite a notatrab: ");
    scanf(" %f", &notatrab);
    while (notatrab < 0.0 || notatrab > 10.0){
        printf("\n\t Valor inválido. Digite novamente a notatrab:");
        scanf(" %f", &notatrab);
    }
    
    media = (3*nota1 + 3*nota2 + 4*notatrab)/10;  // Atribuição
    
    printf("\n Sua média é: %.2f \n", media);

    if (media >= 6.0){
        printf("\n\t Você está aprovado. \n\n");
    } else {
        printf("\n\t Você está reprovado. \n\n");
    }
    
    return 0;
}

