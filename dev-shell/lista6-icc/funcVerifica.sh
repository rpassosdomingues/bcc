#!/bin/bash

cd pastaTeste
status=$?

if [ $status -eq 0 ];
then
  echo "O diretório foi encotrado com sucesso!"
elif [ $status -eq 127 ];
then
  echo "O diretório não foi encontrado."
fi

