#!/bin/bash


if [[ $# -ne 1 ]]
then
    echo "Escribe $0 [opcion (0/1/2 caso: mejor/normal/peor)]"
    exit 1
fi

END=100
case $1 in
    0)  echo > ej4_caso_mejor.dat
        seq1=0
        seq2=0
        for ((i=1;i<=END;i++)) # Mejor caso seq = seq + i
        do
            seq1=$seq1$i
            seq2=$seq2$i
            echo `./ej4 $seq1 $seq2` >> ej4_caso_mejor.dat
        done
        ;;

    1)  echo > ej4_caso_normal.dat
        seq1=0
        seq2=0
        vez=0
        for ((i=1;i<=END;i++)) 
        do
            if [[ $((i % 2)) -eq 0 ]];
            then 
                seq1=$seq1$i
                seq2=$i$seq2
            else
                seq1=$i$seq1
                seq2=$seq1$i
            fi
            echo `./ej4 $seq1 $seq2` >> ej4_caso_normal.dat
        done
        ;;

    2)  echo > ej4_caso_peor.dat
        seq1=0
        seq2=$END 
        for ((i=1,j=END-1;i<=END,j>=0;i++,j--))
        do
            seq1=$seq1$i
            seq2=$seq2$i

            echo `./ej4 $seq1 $seq2` >> ej4_caso_peor.dat
        done

            # Caso peor, uno en orden creciente y el otro en orden decreciente
        ;;

    *)  echo "Escribe $0 [opcion (0/1/2 caso: mejor/normal/peor)]"
        exit 1 ;;
esac
