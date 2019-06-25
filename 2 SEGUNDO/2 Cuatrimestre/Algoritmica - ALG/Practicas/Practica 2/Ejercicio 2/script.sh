#!/bin/bash

i=0
ejecuciones=10
sec1=1
sec2=1

echo > ej3.dat

while [[ $i -ne $ejecuciones ]]; do
	echo "Ejecucion $i"
	echo "Sec1: $sec1 Sec2: $sec2"
	echo `./ej3 $sec1 $sec2` >> ej3.dat 
	sec1=$sec1$i
	sec2=$i$sec2 
	i=$(($i + 1))
done

