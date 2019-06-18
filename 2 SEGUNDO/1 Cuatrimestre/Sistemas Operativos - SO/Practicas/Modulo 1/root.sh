#!/bin/bash

cp /fenix/depar/lsi/UML/*.gz /tmp
cd /tmp
gunzip *.gz
./kernel32-3.0.4 ubda=./Fedora14-x86-root_fs mem=2024m

mkdir home/micuenta
mount none home/micuenta -t hostfs -o  /fenix/alum/d4/rubencav
