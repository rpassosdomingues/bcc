/*
Exercício 6: Desenvolva uma função que tem como parâmetros uma data (dia, mês e ano) e
retorne o texto (string) da data por extenso. Assim: 1/12/2006 – Retorna 1 de dezembro de
2006.
*/

#include <stdio.h>

char* obterDataPorExtenso(int dia, int mes, int ano) {
    static char dataExtenso[50]; // Armazena a data por extenso
    
    // Array de strings para os nomes dos meses
    char* nomesMeses[12] = {
        "janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"
    };
    
    // Montagem da data por extenso
    sprintf(dataExtenso, "%d de %s de %d", dia, nomesMeses[mes - 1], ano);
    
    return dataExtenso;
}

int main() {
    int dia, mes, ano;
    
    // Leitura da data
    printf("Digite a data (dia mês ano): ");
    scanf("%d %d %d", &dia, &mes, &ano);
    
    // Obtendo a data por extenso
    char* dataPorExtenso = obterDataPorExtenso(dia, mes, ano);
    
    // Impressão da data por extenso
    printf("Data por extenso: %s\n", dataPorExtenso);
    
    return 0;
}
