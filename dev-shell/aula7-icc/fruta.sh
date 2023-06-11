#!/bin/bash

echo "Digite uma fruta:"
read fruta

if [ "$fruta" == "manga" ]; then
  echo "Frutas iguais!"
else
  echo "A fruta não é manga!"
fi
