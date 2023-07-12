/*
Exercício 13: Desenvolver um programa em C que leia o arquivo gerado pelo exercı́cio anterior
e apresente o nome e calcule a idade a partir da data de nascimento.
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

int calcularIdade(int diaAtual, int mesAtual, int anoAtual, int diaNascimento, int mesNascimento, int anoNascimento) {
    int idade = anoAtual - anoNascimento;
    
    if (mesAtual < mesNascimento || (mesAtual == mesNascimento && diaAtual < diaNascimento)) {
        idade--;
    }
    
    return idade;
}

int main() {
    struct Dado dados[MAX_DADOS];
    int contador = 0;

    // Abre o arquivo para leitura
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê os dados do arquivo
    while (fgets(dados[contador].nome, sizeof(dados[contador].nome), arquivo) != NULL) {
        dados[contador].nome[strcspn(dados[contador].nome, "\n")] = '\0'; // Remove o caractere de nova linha

        fscanf(arquivo, "%d %d %d", &dados[contador].dia, &dados[contador].mes, &dados[contador].ano);
        fgetc(arquivo); // Limpa o caractere de nova linha do buffer

        contador++;

        // Verifica se atingiu o limite máximo de dados
        if (contador == MAX_DADOS) {
            printf("Limite máximo de dados atingido.\n");
            break;
        }
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Obtém a data atual
    printf("Digite a data atual (dia mes ano): ");
    int diaAtual, mesAtual, anoAtual;
    scanf("%d %d %d", &diaAtual, &mesAtual, &anoAtual);

    // Calcula e imprime a idade
    printf("\nDados armazenados:\n");
    for (int i = 0; i < contador; i++) {
        printf("Nome: %s\n", dados[i].nome);
        int idade = calcularIdade(diaAtual, mesAtual, anoAtual, dados[i].dia, dados[i].mes, dados[i].ano);
        printf("Idade: %d\n", idade);
        printf("\n");
    }

    return 0;
}
