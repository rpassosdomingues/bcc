#!/bin/bash

# Utilizando o comando whiptail para exibir uma caixa de diálogo
NUMBER=$(whiptail --title "Dobro de um número" --inputbox "Digite um número:" 8 40 --nocancel 3>&1 1>&2 2>&3)

# Verifica se o usuário pressionou Cancelar ou a caixa de diálogo foi fechada
if [ $? -ne 0 ]; then
    echo "Operação cancelada."
    exit 1
fi

# Verifica se o valor digitado é um número válido
if ! [[ $NUMBER =~ ^[0-9]+$ ]]; then
    echo "Erro: '$NUMBER' não é um número válido."
    exit 1
fi

# Calcula o dobro do número
RESULT=$((NUMBER * 2))

# Exibe o resultado para o usuário
whiptail --title "Resultado" --msgbox "O dobro de $NUMBER é $RESULT." 8 40

exit 0
