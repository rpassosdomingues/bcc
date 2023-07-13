#!/bin/bash

# Exibe o menu principal usando Whiptail
main_menu() {
    local options=("Inicializar um novo repositório"
                   "Clonar um repositório"
                   "Adicionar arquivos ao índice"
                   "Criar um novo commit"
                   "Enviar commits para um repositório remoto"
                   "Atualizar o repositório local"
                   "Exibir o status do repositório"
                   "Sair")

    local choice=$(whiptail --title "Menu Principal" \
                            --menu "Selecione uma opção:" \
                            20 60 10 \
                            "${options[@]}" \
                            3>&1 1>&2 2>&3)

    case $choice in
        "Inicializar um novo repositório")
            git_init
            ;;
        "Clonar um repositório")
            git_clone
            ;;
        "Adicionar arquivos ao índice")
            git_add
            ;;
        "Criar um novo commit")
            git_commit
            ;;
        "Enviar commits para um repositório remoto")
            git_push
            ;;
        "Atualizar o repositório local")
            git_pull
            ;;
        "Exibir o status do repositório")
            git_status
            ;;
        "Sair")
            exit 0
            ;;
        *)
            whiptail --title "Opção inválida" \
                     --msgbox "Opção inválida. Por favor, tente novamente." 8 40
            main_menu
            ;;
    esac
}

# Executa o comando 'git init'
git_init() {
    git init
    whiptail --title "Git" --msgbox "Repositório inicializado com sucesso!" 8 40
    main_menu
}

# Executa o comando 'git clone'
git_clone() {
    local url=$(whiptail --title "Git Clone" \
                         --inputbox "Informe a URL do repositório:" 8 60 \
                         3>&1 1>&2 2>&3)

    if [[ -n "$url" ]]; then
        git clone "$url"
        whiptail --title "Git" --msgbox "Repositório clonado com sucesso!" 8 40
    else
        whiptail --title "URL inválida" \
                 --msgbox "A URL do repositório é inválida. Por favor, tente novamente." 8 60
    fi

    main_menu
}

# Executa o comando 'git add'
git_add() {
    git add .
    whiptail --title "Git" --msgbox "Arquivos adicionados ao índice com sucesso!" 8 40
    main_menu
}

# Executa o comando 'git commit'
git_commit() {
    local message=$(whiptail --title "Git Commit" \
                             --inputbox "Informe a mensagem do commit:" 8 60 \
                             3>&1 1>&2 2>&3)

    if [[ -n "$message" ]]; then
        git commit -m "$message"
        whiptail --title "Git" --msgbox "Commit criado com sucesso!" 8 40
    else
        whiptail --title "Mensagem inválida" \
                 --msgbox "A mensagem do commit é inválida. Por favor, tente novamente." 8 60
    fi

    main_menu
}

# Executa o comando 'git push'
git_push() {
    local email=$(whiptail --title "Git Push" \
                           --inputbox "Informe seu email:" 8 60 \
                           3>&1 1>&2 2>&3)

    local password=$(whiptail --title "Git Push" \
                              --passwordbox "Informe sua senha:" 8 60 \
                              3>&1 1>&2 2>&3)

    if [[ -n "$email" && -n "$password" ]]; then
        git config --global user.email "$email"
        git config --global user.password "$password"
        git push
        whiptail --title "Git" --msgbox "Commits enviados para o repositório remoto com sucesso!" 8 40
    else
        whiptail --title "Dados inválidos" \
                 --msgbox "O email ou a senha é inválido. Por favor, tente novamente." 8 60
    fi

    main_menu
}

# Executa o comando 'git pull'
git_pull() {
    git pull
    whiptail --title "Git" --msgbox "Repositório local atualizado com sucesso!" 8 40
    main_menu
}

# Executa o comando 'git status'
git_status() {
    git status | whiptail --title "Git Status" --textbox - 20 60
    main_menu
}

# Chama o menu principal para iniciar o script
main_menu

