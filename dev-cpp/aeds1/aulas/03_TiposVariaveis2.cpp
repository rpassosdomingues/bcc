// Este programa imprime a famigerada "Tabela ASCII".

// Tabela ASCII - (American Standard Code for Information Interchange (ASCII))
// more info: url<https://link.springer.com/chapter/10.1007/978-1-4842-7064-6_13>

#include<stdio.h>
#include<cstdlib>

using namespace std;  // Usado para evitar possíveis ambiguidades
		      // de variáveis, tipos e funções com o mesmo nome.
		      // Neste programa uso o tipo char com a variável valorchar.

/*
Os parâmetros argc e argv dão ao programador acesso à linha de comando
com a qual o programa foi chamado.

	O argc (argument count) é um inteiro e
	possui o número de argumentos com os
	quais a função main() foi chamada na linha
	de comando.

	O argv (argument values) é um vetor de
	strings. Cada string deste vetor é um dos
	parâmetros da linha de comando. É para
	saber quantos elementos temos em argv
	que temos argc.
*/

int main(int argc, char** argv) {
    
    printf("\n\t Tabela ASCII \n\n");
    
    unsigned char valorchar = 98;  // Variável do tipo sem-sinal.
    
    valorchar = 0;
    while (valorchar < 255){
        printf("\t\t Caracter: %c", valorchar);
        printf("\t\t Código: %d\n\n", valorchar);
        valorchar++;  // Incremento de (um): soma 1 a cada
        	      // valor começando em zero (chamada de função)
        	      // e parando em 254.
    }
    
    return 0;
}

