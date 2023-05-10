// Este programa converte valores de temperatura
// de Celsius (de 0°C a 100°C) para Farenheit.

#include<stdio.h>

int main() {
    
    int contador;
    float tempcel, tempfah, incremento, limite;
    
    contador = 0;
    incremento = 1;
    
    tempcel = -incremento;

    limite = 100;
    
    printf("--------------------------------------------\n");
    printf("    Contador Temperatura (°C) Temperatura (°F) \n");
    printf("--------------------------------------------\n");

    while (tempcel < limite) {
    	
        contador = contador + incremento;
    	tempcel = tempcel + incremento;

        tempfah = (9 * tempcel/5) + 32;

    	printf("\n\t %d \t %.2f \t\t %.2f \n", contador, tempcel, tempfah);
    
    }
    
    return 0;
}

