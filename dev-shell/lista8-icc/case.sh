#!/bin/bash

echo "Olá, seja bem-vindo ao atendimento da RAFAnet"
echo "Por favor, selecione uma opção:"
echo "1. Consultar saldo"
echo "2. Recarregar créditos"
echo "3. Conhecer nossos planos"
echo "4. Falar com um de nossos atendentes"

read -p "Opção: " opcao

case $opcao in
  1)
    echo "Seu saldo é de R$50,00."
    ;;
  2)
    read -p "Digite o valor da recarga: R$" $valor
    echo "Recarga realizada com sucesso!"
    ;;
  3)
    echo "Nossos planos oferecem internet de alta velocidade, ligações ilimitadas e muito mais. Entre em nosso site para conhecer as opções disponíveis."
    ;;
  4)
    echo "Por favor, aguarde enquanto transferimos sua chamada para um de nossos atendentes."
    # (XX) X XXXX-XXXX
    ;;
  *)
    echo "Opção inválida. Por favor, selecione uma opção válida."
    ;;
esac
