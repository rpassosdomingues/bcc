#!/bin/bash

if [ -r escreveNome ] && [ -x escreveNome ]; then
    echo "O usuário possui permissão de leitura e execução sobre o script 'escreveNome'."
else
    echo "O usuário NÃO possui permissão de leitura e execução sobre o script 'escreveNome'."
fi
