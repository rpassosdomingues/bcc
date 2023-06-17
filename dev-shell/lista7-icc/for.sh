#!/bin/bash

frutas=("maçã" "banana" "laranja" "uva" "abacaxi")

echo "Lista de compras: Mercadinho do Oswaldo"

for fruta in "${frutas[@]}"
do
    echo "$fruta"
done
