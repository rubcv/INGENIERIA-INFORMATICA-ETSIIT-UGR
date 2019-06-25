#!/bin/bash

sudo apt-get install -y freeglut3 freeglut3-dev libjpeg-dev libopenmpi-dev openmpi-bin openmpi-doc libxmu-dev libxi-dev cmake libboost-all-dev
cmake .
make

