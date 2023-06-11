#!/bin/bash

ls -l  # Executando o comando "ls -l"
status=$?  # Armazenando o status de saída na variável "status"

if [ $status -eq 0 ]
then
  echo "O comando foi executado com sucesso!"
else
  echo "O comando retornou um erro. O status de saída foi $status."
elif [ $status -eq 1 ]
then
  echo "Falha na execução do comando."
elif [ $status -eq 2 ]
then
  echo "Erro de sintaxe ou parâmetro inválido."
elif [ $status -eq 126 ]
then
  echo "Permissão negada."
elif [ $status -eq 127 ]
then
  echo "Comando não encontrado."
elif [ $status -eq 128 ]
then
  echo "Processo interrompido."
elif [ $status -eq 130 ]
then
  echo "Processo interrompido pelo usuário."
elif [ $status -eq 139 ]
then
  echo "Violação de segmento."
elif [ $status -eq 141 ]
then
  echo "Acesso inválido à memória."
elif [ $status -eq 255 ]
then
  echo "Erro desconhecido."
fi

