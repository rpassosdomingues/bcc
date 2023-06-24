#!/bin/bash

# Utilizando o comando dialog com o widget "menu"
CHOICE=$(dialog --clear --stdout --title "Pizzaria do Rafa" --menu "Escolha seu sabor:" 12 40 5 \
        1 "Marguerita" \
        2 "Verona" \
        3 "Portuguesa" \
        4 "Pepperoni" \
        5 "Rúcula c/ tomate seco")

# Verifica se o usuário pressionou Cancelar ou a caixa de diálogo foi fechada
if [ -z "$CHOICE" ]; then
    echo "Operação cancelada."
    exit 1
fi

# Exibe a opção escolhida pelo usuário
case $CHOICE in
    1)
        echo "Você escolheu Marguerita."
        ;;
    2)
        echo "Você escolheu Verona."
        ;;
    3)
        echo "Você escolheu Portuguesa."
        ;;
    4)
        echo "Você escolheu Pepperoni."
        ;;
    5)
        echo "Você escolheu Rúcula c/ tomate seco."
        ;;
    *)
        echo "Opção inválida."
        exit 1
        ;;
esac

exit 0

