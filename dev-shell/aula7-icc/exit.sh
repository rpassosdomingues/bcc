#!/bin/bash

ano=2023
meuAno=1996

minhaIdade=$[$ano-$meuAno]

echo "Tenho $minhaIdade anos de idade."

exit 2

status=$?  # Armazenando o status de saída na variável "status"

echo "$status"
