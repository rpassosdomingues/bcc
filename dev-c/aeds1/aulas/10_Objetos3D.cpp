// Aqui eu fiz um projeto para ler um arquivo de texto 'cena.txt' e distinguir strings.

#include <cstdlib>
#include <iostream> // Usa o cin e cout - Substituto do scanf
#include <fstream>  // Para entender comandos próprios do arquivo. Stream siginifica fluxo de dados por caracter.

using namespace std;

int main() {

    string figura;
    ifstream teclado ("cena.txt");
    const float PI = 3.14;
    float raio, radius, altura, areaBase, lado, area, volume, areaTotal, volumeTotal;

    areaTotal = 0;
    volumeTotal = 0;

    if (!teclado.is_open()){
      cout << "\n Erro: Arquivo não encontrado. \n";
      return 1;
    }
    
    teclado >> figura;
    //cout << "figura: " << figura << endl;
    
    while ( figura != "fim" ){

      if (figura == "esfera"){
        teclado >> raio;

        area = 4 * PI * raio * raio;
        volume = float(4/3) * PI * raio * raio * raio;
      
        areaTotal = areaTotal + area;
        volumeTotal = volumeTotal + volume;
      
        printf("\n   Esfera: área = %.2f m² & volume = %.2f m³ \n", area, volume);
      } else
          if (figura == "cilindro"){
            teclado >> radius, altura;

            areaBase = PI * radius * radius;
            area = (2 * PI * radius * altura) + (2 * areaBase);
            volume = areaBase * altura;
            
            areaTotal = areaTotal + area;
            volumeTotal = volumeTotal + volume;
            
            printf("\n Cilindro: área = %.2f m² & volume = %.2f m³ \n", area, volume);
          } else
              if (figura == "cubo"){
                teclado >> lado;

                area = lado * lado;
                volume = lado * lado * lado;
              
                areaTotal = areaTotal + area;
                volumeTotal = volumeTotal + volume;
              
                printf("\n     Cubo: área = %.2f m² & volume = %.2f m³ \n", area, volume);
              }
    
      teclado >> figura;
    }
    teclado.close();
    
    printf("\n\t -> A área total da cena é: %.2f m² \n", areaTotal);
    printf("\n\t -> O volume total da cena é: %.2f m³ \n\n", volumeTotal);

    return 0;
}
