/*
Exercício 8: Desenvolva uma função que transforma: Hora, Minuto e Segundo em Segundos.
*/

#include <stdio.h>

int converterParaSegundos(int hora, int minuto, int segundo) {
    int totalSegundos = hora * 3600 + minuto * 60 + segundo;
    return totalSegundos;
}

int main() {
    int hora, minuto, segundo;

    // Leitura da hora, minuto e segundo
    printf("Digite a hora: ");
    scanf("%d", &hora);
    printf("Digite o minuto: ");
    scanf("%d", &minuto);
    printf("Digite o segundo: ");
    scanf("%d", &segundo);

    // Conversão para segundos
    int segundos = converterParaSegundos(hora, minuto, segundo);

    // Impressão do resultado
    printf("O total de segundos é: %d\n", segundos);

    return 0;
}
