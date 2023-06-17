#!/bin/bash

read -p "Digite um valor: " valor

if [ $valor -ge 1 ] && [ $valor -le 5 ]; then
    echo "O dobro do valor é: $((valor * 2))"
elif [ $valor -ge 6 ] && [ $valor -le 10 ]; then
    echo "O triplo do valor é: $((valor * 3))"
else
    echo "Erro: o valor não está entre 1 e 10."
fi

