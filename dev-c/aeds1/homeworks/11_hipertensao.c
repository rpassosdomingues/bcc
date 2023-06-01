/*
Projeto - Aqui eu fiz um projeto para dizer se você está com pressão alta, normal ou baixa.
Referência: \url{https://www.ahajournals.org/doi/full/10.1161/01.CIR.93.6.1160}.
*/

#include <stdio.h>

int main() {
    
    int pressaoArterialSistolica, pressaoArterialDiastolica;
  
    printf("\n Digite a pressão arterial [(7 < sistólica < 25) (2 < diastólica < 20)]: ");
    scanf(" %d %d", &pressaoArterialSistolica, &pressaoArterialDiastolica);
      
    if ( pressaoArterialSistolica >= 13 || pressaoArterialDiastolica >= 10 ){
      printf("\n\t Sua pressão arterial está alta. \n\n");
    } else
        if ( pressaoArterialSistolica <= 9 || pressaoArterialDiastolica <= 6 ){
          printf("\n\t Sua pressão arterial está baixa. \n\n");
        } else
            printf("\n\t Sua pressão arterial está normal. \n\n");

    return 0;
}
