/*
Exercício 12: Desenvolver um programa em C que e armazene uma quantidade de dados
digitados pelo usuário. Os campos digitados são: nome e data de nascimento (dia, mês e ano).
O programa deve encerrar a entrada de dados quando o usuário digitar um nome vazio (string
nulo )
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DADOS 100

struct Dado {
    char nome[50];
    int dia;
    int mes;
    int ano;
};

int main() {
    struct Dado dados[MAX_DADOS];
    int contador = 0;

    while (1) {
        printf("Digite o nome: ");
        fgets(dados[contador].nome, sizeof(dados[contador].nome), stdin);
        dados[contador].nome[strcspn(dados[contador].nome, "\n")] = '\0'; // Remove o caractere de nova linha

        // Verifica se o nome é vazio (string nula)
        if (dados[contador].nome[0] == '\0') {
            break;
        }

        printf("Digite a data de nascimento (dia mes ano): ");
        scanf("%d %d %d", &dados[contador].dia, &dados[contador].mes, &dados[contador].ano);
        getchar(); // Limpa o caractere de nova linha do buffer

        contador++;

        // Verifica se atingiu o limite máximo de dados
        if (contador == MAX_DADOS) {
            printf("Limite máximo de dados atingido.\n");
            break;
        }
    }

    // Impressão dos dados armazenados
    printf("\nDados armazenados:\n");
    for (int i = 0; i < contador; i++) {
        printf("Nome: %s\n", dados[i].nome);
        printf("Data de nascimento: %d/%d/%d\n", dados[i].dia, dados[i].mes, dados[i].ano);
        printf("\n");
    }

    return 0;
}
