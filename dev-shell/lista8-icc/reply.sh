#!/bin/bash
#Teste de read e variável de ambiente REPLY
#Usando timer

read -p "Em que mês estamos? "

if read -t 8
then
   echo Estamos em $REPLY de 2023.
else
   echo Você demorou mais de 8 segundos para responder!
fi
