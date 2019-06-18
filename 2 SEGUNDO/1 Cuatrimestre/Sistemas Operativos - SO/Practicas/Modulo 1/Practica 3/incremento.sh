#!bin/bash

#Actividad 3.2
if [[ $# -ne 1 ]]
then
  echo "Escribe $0 [entero]"
  exit
fi

var=0
for (( i = 0; i < $1; i++ )); do
  var=$(($var + 1))
  sleep 1
done

echo "Valor de la variable: $var"
