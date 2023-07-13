#!/bin/bash

read -p "Digite seu e-mail do GitHub: " email
read -s -p "Digite sua senha do GitHub: " password
echo
read -p "Digite o nome do repositório a ser criado: " repository_name

# Autenticação no GitHub e criação do repositório
curl -u "$email:$password" -X POST https://api.github.com/user/repos -d '{"name":"'"$repository_name"'"}'

echo "Repositório $repository_name criado com sucesso!"

