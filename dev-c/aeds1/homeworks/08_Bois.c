// Aqui eu fiz um projeto para informar qual o boi mais leve e o boi mais pesado.

#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <iostream> 

using namespace std;

int main() {

    int identificador, massa, id_BOI, massa_BOI, id_boi, massa_boi;

    ifstream teclado ("entrada.txt"); // Variável teclado faz o papel do usuário que digita valores.
                                      // ifstream (input-file-stream) é o tipo em questão da variável.
    if (!teclado.is_open()){
        cout << "\n Erro: Arquivo não encontrado. \n";
        return 1;
    }
    
    teclado >> identificador && massa; // >> Quando vem com o dado do arquivo e vai para a variável valor.
    //cout << "identificador && massa: " << identificador && massa << endl;
    
    if (massa_BOI < massa){
        identificador = id_BOI;
        massa_BOI = massa;
    } else
        if (massa_boi > massa){
            identificador = id_boi;
            massa_boi = massa;
        }

    printf("\n\t O boi mais pesado é o número %d e sua massa é %d \n", id_BOI, massa_BOI);
    printf("\n\t O boi mais leve é o número %d e sua massa é %d \n\n ", id_boi, massa_boi);
    
    return 0;
}
