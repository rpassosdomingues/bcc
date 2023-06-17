#!/bin/bash

echo "O número de argumentos passados é: $#"

if [ $# -eq 0 ]; then
    echo "Nenhum argumento foi fornecido."
elif [ $# -eq 1 ]; then
    echo "Foi fornecido 1 argumento."
else
    echo "Foram fornecidos $# argumentos."
fi
