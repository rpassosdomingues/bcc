#!/bin/bash

count=5

echo "Bomba ativada com sucesso. Afaste-se!"

while [ $count -ge 0 ]
do
    echo "$count"
    sleep 1
    ((count--))
done

echo "!!! Boooommmm !!!"
