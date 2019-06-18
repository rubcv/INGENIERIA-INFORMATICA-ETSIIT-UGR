#!/bin/bash

cp /fenix/depar/lsi/UML/*.gz /tmp
cd /tmp
gunzip *.gz
./kernel32-3.0.4 ubda=./Fedora14-x86-root_fs mem=2024m

mkdir Desktop

wget  -O /Desktop/ "https://download.sublimetext.com/sublime_text_3_build_3126_x64.tar.bz2"
