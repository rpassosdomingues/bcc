#!/bin/bash

# Função para verificar e exibir o dobro dos números entre 20 e 30
function exibir_dobro {
   read -p "Digite um número entre 20 e 30: " numero

   if (( numero >= 20 && numero <= 30 )); then
      echo "O dobro do número é $(( numero * 2 ))"
   else
      echo "O número digitado está fora do intervalo aceito (20-30)."
   fi
}

# Chamar a função para exibir o dobro
exibir_dobro

