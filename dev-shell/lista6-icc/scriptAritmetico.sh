#!/bin/bash

numerador=1
denominador=2

divisao=`bc << EXP
scale=2
$numerador / $denominador

EXP
`
echo "Resultado: $divisao"
