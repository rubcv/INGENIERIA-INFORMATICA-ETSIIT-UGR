#!/bin/bash

if [[ $# -ne 2 ]]
then
    echo "Escribe $0 <nombre-programa> <fich-datos>" 
    exit
fi

programa="./bin/"$1
datos="datos/"$2
echo "Ejecutando $programa con $datos"

cont=0
maxM=637

echo > doc/$1/$1
while [[ cont -le maxM ]]
do
    echo `$programa $datos $cont` >> doc/$1/$1
    cont=$(($cont+1))
done