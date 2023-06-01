// Aqui eu escrevi um código para calcular a área total e o volume de um cilindro
// recebendo como entrada seu raio e sua altura.

// Ou seja:
  // input <-  raio e altura.
  // output -> area total e volume.

#include<stdio.h>
#include<math.h>  // Importa biblioteca que disponibiliza funções matemáticas.

int main() {
    
    float raio, altura, areadabase, areatotal, volume; // Reserva cinco lugares na memória
    						       // para receber duas entradas,
    						       // executar atribuição
    						       // e devolver duas saídas.
    float const PI = 3.1415;  // Reserva um lugar na memória
    			      // chamando a constante PI da biblioteca -math-.
    
    printf("\n Digite o raio: ");
    scanf(" %f", &raio);
    
    printf("\n Digite a altura: ");
    scanf(" %f", &altura);
    
    areadabase = PI*pow(raio, 2);  // Comando de atribuição

    areatotal = 2*PI*raio*altura + 2*areadabase;  // Atribuição1 e output1
    volume = areadabase*altura;		 	  // Atribuição2 e output2
 
    printf("\n\t A área total do Cilindro é: %.2f m²\n", areatotal);
    printf("\n\t O volume do Cilindro é: %.2f m³ \n\n", volume);
    
    return 0;
}
