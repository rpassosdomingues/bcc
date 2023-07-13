#!/bin/bash

echo "Bem-vindo ao script de comandos do Git!"

# Exibe as opções disponíveis
echo "Selecione uma opção:"
echo "1. Inicializar um novo repositório"
echo "2. Clonar um repositório"
echo "3. Adicionar arquivos ao índice"
echo "4. Criar um novo commit"
echo "5. Enviar commits para um repositório remoto"
echo "6. Atualizar o repositório local"
echo "7. Exibir o status do repositório"
echo "8. Sair"

# Lê a opção selecionada pelo usuário
read -p "Opção: " option

# Executa o comando correspondente à opção selecionada
case $option in
    1)
        git init
        ;;
    2)
        read -p "Informe a URL do repositório: " url
        git clone $url
        ;;
    3)
        git add .
        ;;
    4)
        read -p "Informe a mensagem do commit: " message
        git commit -m "$message"
        ;;
    5)
        git push
        ;;
    6)
        git pull
        ;;
    7)
        git status
        ;;
    8)
        echo "Saindo do script..."
        exit 0
        ;;
    *)
        echo "Opção inválida!"
        ;;
esac

