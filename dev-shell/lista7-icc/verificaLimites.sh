#!/bin/bash

read -p "Digite o valor a ser comparado: " valor
read -p "Digite o limite inferior: " limite_inferior
read -p "Digite o limite superior: " limite_superior

if [ $valor -ge $limite_inferior ] && [ $valor -le $limite_superior ]; then
    echo "O valor $valor está entre $limite_inferior e $limite_superior."
else
    echo "O valor $valor não está entre $limite_inferior e $limite_superior."
fi
