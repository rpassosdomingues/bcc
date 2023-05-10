// Aqui eu fiz um projeto para ler um arquivo de texto.

#include <cstdlib>
#include <iostream> // Usa o cin e cout - Substituto do scanf
#include <fstream>  // Para entender comandos próprios do arquivo. Stream siginifica fluxo de dados por caracter.

using namespace std;

int main(int argc, char** argv) {

    int valor;
    ifstream teclado ("entrada.txt"); // Variável teclado faz o papel do usuário que digita valores.
                                      // ifstream (input-file-stream) é o tipo em questão da variável.
    if (!teclado.is_open()){
        cout << "\n Erro: Arquivo não encontrado. \n";
        return 1;
    }
    
    teclado >> valor; // >> Quando vem com o dado do arquivo e vai para a variável valor.
    cout << "valor: " << valor << endl;
    while ( valor != 0 ){
        teclado >> valor;
        cout << "valor: " << valor << endl;
    }
    teclado.close();
    
    return 0;
}
