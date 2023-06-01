// Aqui eu fiz um projeto para ler um arquivo de texto e calcula a distância entre 3 cidades.

#include <cstdlib>
#include <iostream> // Usa o cin e cout - Substituto do scanf
#include <fstream>  // Para entender comandos próprios do arquivo. Stream siginifica fluxo de dados por caracter.
#include <math.h>

using namespace std;

int main(int argc, char** argv) {

    float x1,x2,y1,y2,z1,z2, distanciaAB, distanciaBC, distanciaAC;
    ifstream teclado ("gps.txt"); // Variável teclado faz o papel do usuário que digita valores.
                                      // ifstream (input-file-stream) é o tipo em questão da variável.
    if (!teclado.is_open()){
        cout << "\n Erro: Arquivo não encontrado. \n";
        return 1;
    }
    
    teclado >> x1 >> x2;
    teclado >> y1 >> y2;
    teclado >> z1 >> z2;

    cout << "x1: " << x1 << endl;
    cout << "x2: " << x2 << endl;

    cout << "y1: " << y1 << endl;
    cout << "y2: " << y2 << endl;

    cout << "z1: " << z1 << endl;
    cout << "z2: " << z2 << endl;
    
    while ( x1 != 0 && x2 != 0 ){
        
        teclado >> x1 >> x2;
        teclado >> y1 >> y2;
        teclado >> z1 >> z2;
    }
    teclado.close();

    distanciaAB = sqrt( (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) );
    distanciaBC = sqrt( (y2 - y1)*(y2 - y1) + (z2 - z1)*(z2 - z1) );
    distanciaAC = sqrt( distanciaAB*distanciaAB + distanciaBC*distanciaBC );

    cout << "A distância de A até B é: " << distanciaAB << endl;
    cout << "A distância de B até C é: " << distanciaBC << endl;
    cout << "A distância de A até C é: " << distanciaAC << endl;

    return 0;
}
