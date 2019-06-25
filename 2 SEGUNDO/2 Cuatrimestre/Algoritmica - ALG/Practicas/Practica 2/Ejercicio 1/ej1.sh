#!/bin/bash


if [[ $# -ne 1 ]]
then
    echo "Escribe $0 [opcion (0/1 caso: peor/normal)]"
    exit 1
fi

END=100
case $1 in
    0)  echo > ej1_caso_peor.dat
        seq=0
        for ((i=1;i<=END;i++)) # Peor caso
        do
            seq=$seq$i
            echo `./ej1 $seq` >> ej1_caso_peor.dat
        done
        ;;

    1)  echo > ej1_caso_normal.dat
        seq=$((1 + RANDOM % 100))
        for ((i=1;i<=END;i++))
        do 
            echo `./ej1 $seq` >> ej1_caso_normal.dat
            seq=$seq$((1 + RANDOM % 100)) # Caso normal datos aleatorios
        done
        ;;

    *)  echo "Escribe $0 [opcion (0/1 caso: peor/normal)]" 
        exit 1 ;;
esac
