#!/bin/bash
# Saídas de variáveis

echo "Hoje é: $date"

# É possível "congelar" a variável date e isso pode ser útil
photoDate=`date`
echo $photoDate

filtraData=`date +%d`
ls -la $PWD > log.$arquivo
