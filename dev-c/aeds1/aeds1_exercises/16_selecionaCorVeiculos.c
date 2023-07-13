/*
Exercício 5: Complete o programa do exercı́cio anterior para apresentar as placas dos veı́culos
de cor branca.
*/

#include <stdio.h>

struct Veiculo {
    char proprietario[30];
    int combustivel; // 0=álcool, 1=gasolina, 2=flex
    char modelo[20];
    char cor[20];
    struct {
        int dia, mes, ano;
    } data;
    char placa[7];
};

int main() {
    struct Veiculo tabela[100];
    int n;

    // Leitura do número de veículos
    printf("Digite o número de veículos: ");
    scanf("%d", &n);

    if (n > 100) {
        printf("O número de veículos deve ser menor ou igual a 100\n");
        return 0;
    }

    // Leitura das informações dos veículos
    for (int i = 0; i < n; i++) {
        printf("Veículo %d:\n", i + 1);
        printf("Proprietário: ");
        scanf("%s", tabela[i].proprietario);
        printf("Combustível (0-álcool, 1-gasolina, 2-flex): ");
        scanf("%d", &tabela[i].combustivel);
        printf("Modelo: ");
        scanf("%s", tabela[i].modelo);
        printf("Cor: ");
        scanf("%s", tabela[i].cor);
        printf("Data de fabricação (dia mês ano): ");
        scanf("%d %d %d", &tabela[i].data.dia, &tabela[i].data.mes, &tabela[i].data.ano);
        printf("Placa: ");
        scanf("%s", tabela[i].placa);
        printf("\n");
    }

    // Impressão das informações dos veículos de cor branca
    printf("Veículos de cor branca:\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(tabela[i].cor, "branca") == 0) {
            printf("Placa: %s\n", tabela[i].placa);
        }
    }

    return 0;
}
