#!/bin/bash

# Função para gerar um número aleatório entre 1 e 5
gerar_numero_aleatorio() {
  echo $((RANDOM % 5 + 1))
}

# Função para verificar se o número é menor, maior ou igual ao número a ser adivinhado
verificar_numero() {
  local numero=$1
  local numero_adivinhar=$2

  if [ $numero -lt $numero_adivinhar ]; then
    echo "O número é menor!"
  elif [ $numero -gt $numero_adivinhar ]; then
    echo "O número é maior!"
  else
    echo "Parabéns! Você acertou o número!"
  fi
}

# Função principal do jogo
adivinhar_numero() {
  local numero_adivinhar=$(gerar_numero_aleatorio)
  local tentativas=0
  local numero

  echo "Bem-vindo ao jogo de adivinhação de números!"
  echo "Tente adivinhar o número entre 1 e 5."

  while true; do
    read -p "Digite um número: " numero
    ((tentativas++))

    case $(verificar_numero $numero $numero_adivinhar) in
      "O número é menor!") ;;
      "O número é maior!") ;;
      "Parabéns! Você acertou o número!") break ;;
    esac
  done

  echo "Parabéns! Você acertou o número em $tentativas tentativas!"
}

# Chama a função principal do jogo
adivinhar_numero

