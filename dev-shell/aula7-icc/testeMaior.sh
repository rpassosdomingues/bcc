#!/bin/bash

var1=10
var2=5

a=$[$var1 + $var2]
b=$[$var1 * $var2]

if [ $a -ge $b ]
then
  echo "O valor de [a = $a] é maior que o valor de [b = $b]."
elif [ $a -le $b ]
then
  echo "O valor de [a = $a] é menor que o valor de [b = $b]."
fi
