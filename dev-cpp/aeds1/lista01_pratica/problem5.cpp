/*
Problema 5: Um comerciante deseja fazer o levantamento do lucro das mercadorias que
ele comercializa. Para isso, mandou digitar uma linha para cada mercadoria com
o nome, preço de compra e preço de venda das mesmas, a última linha terá o
nome “fim” para a mercadoria. Faça um programa que:

determine e escreva quantas mercadorias proporcionam:
 - lucro menor do que 10%;
 - lucro entre 10 e 20%;
 - lucro maior que 20%.

determine e escreva o valor total de compra e de venda de todas as
mercadorias, assim como o lucro total.
*/

#include <cstdlib>
#include <fstream>  // Para entender comandos próprios do arquivo.
                    // Stream siginifica fluxo de dados por caracter.
using namespace std;

int main() {

    string mercadoria;
    float lucro, lucroTotal, lucroMaior, lucroMedio, lucroMenor, valorCompra, valorVenda, totalCompras, totalVendas;

    totalCompras = 0;
    totalVendas = 0;
    lucroTotal = 0;

    while (mercadoria != "fim"){

        printf("\n Digite a mercadoria: ");
        scanf(" %s", &mercadoria);

        printf("\n Digite o valor da compra: ");
        scanf(" %f", &valorCompra);

        printf("\n Digite o valor da venda: ");
        scanf(" %f", &valorVenda);

        totalCompras += valorCompra;
        totalVendas += valorVenda;

        lucro = (valorVenda/valorCompra) * 100;

        lucroTotal += lucro;

        if (lucro > 20){
            lucroMaior++;
        } else
            if (lucro > 10 || lucro < 20){
                lucroMedio++;
            } else
                lucroMenor++;

        printf("\n\t\t Resultados \n");

        printf("\n\t %.2f mercadorias: lucro > 20%%  \n\n", lucroMaior);
        printf("\n\t %.2f mercadorias: 10%% < lucro < 20%%  \n\n", lucroMedio);
        printf("\n\t %.2f mercadorias: lucro < 10%%  \n\n", lucroMenor);

        printf("\n\t O total de compras foi: %.2f \n\n", totalCompras);
        printf("\n\t O total de vendas foi: %.2f \n\n", totalVendas);
        printf("\n\t\t O lucro total foi: %.2f \n\n", lucroTotal);
    }

    return 0;
}
