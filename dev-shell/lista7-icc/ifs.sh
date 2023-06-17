#!/bin/bash

frase="Rafael Passos Domingues"

# Armazenando o valor atual do IFS
oldIFS=$IFS

# Definindo o novo separador como espaço em branco e vírgula
IFS=" ,"

echo "Dividindo a frase em palavras:"
for palavra in $frase; do
  echo "*$palavra*" | figlet -f slant
done

# Restaurando o valor original do IFS
IFS=$oldIFS
