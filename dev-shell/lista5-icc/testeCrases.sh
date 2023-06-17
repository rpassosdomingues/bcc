#!/bin/bash
# Saídas de variáveis

echo "Hoje é: "

# É possível "congelar" a variável date e isso pode ser útil
photoDate=`date`
echo $photoDate



filtraData=`date +%y%m%d%H%M%S`
echo "A hora é $filtraData"



ls -la $PWD > log.$filtraData
