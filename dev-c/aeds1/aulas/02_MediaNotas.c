// Este programa recebe como entrada
// os valores numéricos que representam as -notas- de um aluno fictício
// e seu comando de atribuição -media- retorna a média ponderada do aluno.

#include<stdio.h>

int main() {
    
    float nota1, nota2, notatrab, media; // Reserva quatro espaços na memória
    				         // para guardar variáveis do tipo float -ponto flutuante-.
    
    printf("\n\t Digite a nota1: ");
    scanf(" %f", &nota1);  // Lê e guarda no endereço de memória -&nota1-
    			   // o que o usuário digita na entrada. 
    
    printf("\n\t Digite a nota2: ");
    scanf(" %f", &nota2);
    
    printf("\n\t Digite a notatrab: ");
    scanf(" %f", &notatrab);
    
    media = (3*nota1 + 3*nota2 + 4*notatrab)/10;  // Comando de atribuição.
    						  // Variável criada para receber os x valores
    						  // de entrada e devolver y valores de saída.
    
    printf("\n\t Média de AEDs I: %f\n\n", media);
    
    printf("\t Se a média for igual ou superior a 6.0, você está aprovado. \n");
    printf("\t Se a média for inferior a 6.0, você está reprovado. \n\n");
    
    return 0;
}

