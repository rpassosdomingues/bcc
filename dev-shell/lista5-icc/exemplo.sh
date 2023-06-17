#!/bin/bash
# Este é um shell script escrito em vi.

echo "Nome de usuário: $USER"
echo "Diretório onde estou: $PWD"
echo "Diretório home: $HOME"
echo "UID do usuário: $UID"

echo "listagem do diretório home"
cd ~
ls -all

echo -n "usuário: "
whoami

echo "Diretório raiz onde ficam os executáveis do sistema: "
echo $PATH
