// Aqui eu fiz um projeto para calcular o salário líquido de um professor.

#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {

    float valor_aula, quantidade_aulas, salario_bruto, taxa_inss, salario_liquido;
    
    printf("\n Digite o valor da hora-aula: ");
    scanf(" %f", &valor_aula);

    printf("\n Digite a quantidade de aulas por mês: ");
    scanf(" %f", &quantidade_aulas);
    
    taxa_inss = 0.10;
    
    salario_bruto = quantidade_aulas * valor_aula;
    salario_liquido = salario_bruto - taxa_inss * salario_bruto;
    
    printf("\n\t O salário líquido do professor é: R$ %.2f \n\n", salario_liquido);

    return 0;
}
