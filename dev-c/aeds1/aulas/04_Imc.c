// Aqui eu desenvolvi um projeto para calcular o Índice de Massa Corpórea (IMC) de um paciente
// e informar sua classificação.

// [pt-br] IMC = [en] BMI = Body Mass Index

// BMI, body mass index; WHO, World Health Organization.
// WHO 1998 classification of BMI categories for Europids

// Referência: url<https://onlinelibrary.wiley.com/doi/full/10.1046/j.1440-6047.11.s8.5.x>

#include<stdio.h>
#include<math.h>

int main() {
    
    float massa, altura, imc;
    
    printf("\n Digite a massa: ");
    scanf(" %f", &massa);
    while (massa < 0.0 || massa > 200.0){  // imc aqui calculado é limitado para massa < 200 kg.
        printf("\n\t Valor inválido. Digite novamente a massa:");
        scanf(" %f", &massa);
    }
    
    printf("\n Digite a altura: ");
    scanf(" %f", &altura);
    while (altura < 0.0 || altura > 2.5){  // imc aqui calculado é limitado para altura < 2.5 m.
        printf("\n\t Valor inválido. Digite novamente a altura:");
        scanf(" %f", &altura);
    }
    
    imc = massa/(pow(altura,2));  // índice de massa corpórea - imc
    				  // A função pow(altura, 2) eleva ao quadrado o valor
    				  // alocado em &altura.
    
    printf("\n Seu IMC é %.2f kg/m² \n\n", imc);

    if (imc <= 18.5){					// se imc for menor ou igual a 18.5
        printf("\n\t Você está abaixo do peso. \n\n");
    }else
        if (imc > 18.5 && imc <= 24.9){			// se 18.5 <= imc <= 24.9
            printf("\n\t Você está no peso normal. \n\n");
        }else
            if (imc > 25.0){
            printf("\n\t Você está acima do peso. \n\n"); // se imc > 25
            }
    
    return 0;
}

