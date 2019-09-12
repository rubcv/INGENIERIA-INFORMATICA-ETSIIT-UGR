# fichero Makefile
#
# nombre del fichero ejecutable
#
# VARIABLES

BIN = bin
SRC = src
OBJ = obj
LIB = lib
INCLUDE = include


#
# GLUT_DIR=/casa/dmartin/codigo/funciontecas/freeglut
# GL_DIR=/usr/X11R6

# banderas para el compilador (C y C++). Se indican los directorios donde se puenden
# encontrar ficheros para incluir mediante la opcion -I
# la opcion -g sirve para permitir la depuraci�n
#
# CFLAGS=    -g -DXWINDOWS -DSHM -I/usr/include -I$(GLUT_DIR)/include -I.
# CXXFLAGS=  -g -DXWINDOWS -DSHM -I/usr/include -I$(GLUT_DIR)/include -I.
CFLAGS=    -g -DXWINDOWS -DSHM -I/usr/include -I$(INCLUDE)
CXXFLAGS=  -g -DXWINDOWS -DSHM -I/usr/include -I$(INCLUDE)

# banderas pra el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
#
#LDFLAGS=  -L$(GL_DIR)/lib64 -lGL -L$(GLUT_DIR)/lib64 -lglut 
LDFLAGS=  -lGLU -lGL -lglut

# definicion del compilador
#
CC = g++

TARGETS= practica2

all: presentacion clean $(TARGETS)
# sufijos
# .SUFFIXES: .cc .c .o

# Reglas
# $< -> todas las dependencias que han cambiado
# $@ -> el objetivo
# $^ -> todas las dependencias

# como pasar de .cc a .o

# .cc.o:
# 	$(CC) $(CXXFLAGS) -c $<

# como pasar de .o a ejecutable (sin sufijo)

# .o:
# 	$(CC) -o $@ $^ $(LDFLAGS) 


# regla de dependencias
#
#$(TARGETS) : basic_object3d.o object3d.o axis.o tetrahedron.o practica1.o
$(TARGETS):
	$(CC) -o $(BIN)/$@ $(CXXFLAGS)  $(SRC)/basic_object3d.cc $(SRC)/object3d.cc $(SRC)/cubo.cc $(SRC)/tetrahedron.cc $(SRC)/axis.cc $(SRC)/ORev.cc $(SRC)/cono.cc $(SRC)/cilindro.cc $(SRC)/esfera.cc $(SRC)/peon.cc $(SRC)/practica2.cc $(LDFLAGS)

# practica1.o: practica1.cc
# basic_object3d.o: basic_object3d.cc basic_object3d.h
# object3d.o: object3d.cc object3d.h
# axis.o: basic_object3d.o axis.cc axis.h
# tetrahedron.o: tetrahedron.cc tetrahedron.h


.PHONY: presentacion
presentacion:
	@echo "##################################################"
	@echo "#    Miguel Arredondo Calderon 3ºB (B3)          #"
	@echo "#    Informatica Grafica                         #"
	@echo "#    Curso 2018/2019                             #"
	@echo "#    Practica2                                   #"
	@echo "##################################################"

.PHONY: clean
clean:
	@echo "Limpiando.."
	@rm -f $(BIN)/*\
	$(OBJ)/*\
	./*.tgz
	@echo "Limpieza finalizada"

#
#
.PHONY: redo
redo:
	touch $(SRC)/*.cpp
	make

#
#
.PHONY: superclean
superclean:
	rm -f *.o
	rm *~
	rm -f $(TARGETS)

#
#

tgz:
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*
	tar -zcvf $(TARGETS).tgz *

#
#
# clean:
# 	rm -f *.o
# 	rm -f $(TARGETS)

# #
# #
# redo:
# 	touch *.cc
# 	make

# #
# #
# superclean:
# 	rm -f *.o
# 	rm *~
# 	rm -f $(TARGETS)

# #
# #
# tgz:
# 	rm -f *.o
# 	rm *~
# 	rm -f $(TARGETS)
# 	tar -zcvf $(TARGETS).tgz *

