#!/bin/bash

# Função para exibir o checklist
exibir_checklist() {
    local selecionadas=()

    selecionadas=$(whiptail --clear --title "Checklist" --checklist "Selecione as tarefas concluídas:" 10 50 3 \
        "8 Listas de ICC" "" off \
        "Site HTML/CSS" "" off \
        "Controle de versões Git" "" off \
        3>&1 1>&2 2>&3)

    if [ -z "$selecionadas" ]; then
        echo "Operação cancelada."
        exit 1
    fi

    echo "Tarefas concluídas:"
    for selecionada in $selecionadas; do
        echo "- $selecionada"
    done
}

# Chamada da função para exibir o checklist
exibir_checklist

exit 0
