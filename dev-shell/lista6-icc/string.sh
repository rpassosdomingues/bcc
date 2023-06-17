#!/bin/bash

string1="RAFAEL"
string2="rafael"

if [ "$string1" == "$string2" ]; then
  echo "As strings são iguais."
else
  echo "As strings são diferentes."
fi
