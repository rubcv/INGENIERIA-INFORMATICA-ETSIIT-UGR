#!/bin/bash

for ((N=16384;N<67108865;N=N*2))
do
	./MiSumaVectoresC2 $N
done
