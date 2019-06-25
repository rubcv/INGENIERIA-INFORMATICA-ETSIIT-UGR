#!/bin/bash
	cd $PBS_O_WORKDIR
	n=1000;
	for i in `seq 1 12`
	do
		./ej9 $n $i >> escalabilidad.txt
	done
