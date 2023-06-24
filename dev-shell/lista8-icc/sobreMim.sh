#!/bin/bash
#Ler dados de um arquivo de texto:

contador=1
cat sobreMim.txt | while read linha
do
echo Linha $contador : $linha
contador=$[ $contador + 1]
done
