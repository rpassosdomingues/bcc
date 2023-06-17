#!/bin/bash

number=0

echo "Aguardando número positivo:"

until [ $number -gt 0 ]
do
    read -p "Digite um número positivo: " number
done

echo "Número válido: $number"
