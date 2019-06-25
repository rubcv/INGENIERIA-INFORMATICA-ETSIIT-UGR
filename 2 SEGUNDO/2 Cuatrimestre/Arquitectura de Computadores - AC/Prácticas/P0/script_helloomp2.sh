#!/bin/bash
#Se asigna al trabajo el nombre helloomp
#PBS -N helloomp2
#Se asigna al trabajo la cola ac
#PBS -q ac
#Se imprime información del trabajo usando variables de entorno de PBS
echo "Id. usuario del trabajo: $PBS_O_LOGNAME"
echo "Id. del trabajo: $PBS_JOBID"
echo "Nombre del trabajo especificado por usuario: $PBS_JOBNAME"
echo "Nodo que ejecuta qsub: $PBS_O_HOST"
echo "Cola: $PBS_QUEUE"
echo "Nodos asignados al trabajo: $PBS_NODEFILE"

# Se fija a 12 el nº de threads máximo(tantos como cores en un nodo)
export OMP_THREAD_LIMIT=12
echo "Nº de threads inicial: $OMP_THREAD_LIMIT"

#Se ejecuta HelloOMP, que está en el directorio en el que se ha ejecutado qsub
for (( P=OMP_THREAD_LIMIT; P>0; P=P/2 )); do
	export OMP_NUM_THREADS=$P
	echo -e "\ndirectorio: $PBS_O_WORKDIR \t hebras: $OMP_NUM_THREADS"
	$HOME/HelloOMP
done

