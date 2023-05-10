/*
Projeto 3. O sistema de avaliação da disciplina de Teoria de Linguagens segue os seguintes
critérios:
 - Serão aplicadas três provas no semestre.
 - A nota final será a média das provas aplicadas.
 - É considerado aprovado o aluno que obtiver nota igual ou superior a 60 pontos e que tiver
comparecido em pelo menos 40 aulas.
 - Fazer um algoritmo que leia os dados contendo a matrı́cula, a nota das 3 provas e o
número de aulas frequentadas por 100 alunos.
 . Calcule e imprima:
– A nota final de cada aluno.
– A maior e menor nota da turma.
– A nota média da turma.
– O total de alunos reprovados.
– O total de alunos reprovados por frequência.
*/

#include <stdio.h>

using namespace std;

int main() {

    int contador, matricula, notaP1, notaP2, notaP3, media, maiorMedia, menorMedia, numPresencas;

    contador = 0; // contar até 100.
    // iniciar variáveis

    while (contador < 2){

      printf("\n Digite o número de matrícula: ");
      scanf(" %d", &matricula);

      printf("\n Digite a nota na P1: ");
      scanf(" %d", &notaP1);

      printf("\n Digite a nota na P2: ");
      scanf(" %d", &notaP2);

      printf("\n Digite a nota na P3: ");
      scanf(" %d", &notaP3);

      printf("\n Digite o número de presenças: ");
      scanf(" %d", &numPresencas);
      
      
      if (media > maiorMedia){
            maiorMedia = media;
          } else
            if (media < menorMedia){
              menorMedia = media;
        }

      if (qtdAlunos > 0){
        media = somaNotas/qtdAlunos;
      }
      
      contador = contador + 1;

    }

    printf("\n\t -- Resultados -- \n");

    printf("\n\t %d pessoas responderam -SIM- \n", qtdSim);
    printf("\t %d pessoas responderam -NÃO- \n", qtdNao);
    
    printf("\n\t A média de idade das pessoas que responderam -SIM- é de %d anos \n", mediaIdadeSim);
    
    printf("\n\t O mais velho tem %d anos \n", maisVelho);
    printf("\t O mais novo tem %d anos \n\n", maisNovo);

    return 0;
}
