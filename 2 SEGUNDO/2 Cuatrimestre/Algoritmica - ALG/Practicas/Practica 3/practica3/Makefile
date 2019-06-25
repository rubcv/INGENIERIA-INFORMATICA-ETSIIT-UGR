SRC = src
INC = include
OBJ = obj
DATOS = datos
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c -std=c++11



all:  $(BIN)/sumaHastaN $(BIN)/sumaHastaNPD  $(BIN)/cifrasV $(BIN)/cifrasEj3 
	@echo "\nEJECUCIÓN:"
	@echo ' ./script.sh <nombre-programa> <fichero-datos>'
	@echo ''
	@echo " <nombre-programa> puede ser:"
	@echo "\t\t sumaHastaN"
	@echo "\t\t sumaHastaNPD"
	@echo "\t\t cifrasV"
	@echo "\t\t cifrasEj3"
	@echo ''
	@echo " <fichero-datos> puede ser:"
	@echo "\t\t conjunto.txt"
	@echo "\t\t numeros1.txt"
	@echo "\t\t ..." 
	@echo ''
	@echo "El script añade el directorio, solo hay que escribir el nombre, también genera los N."
	@echo ''

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/cifrasV: $(OBJ)/cifrasV.o
	$(CXX) -o $(BIN)/cifrasV  $(OBJ)/cifrasV.o

$(BIN)/cifrasEj3: $(OBJ)/cifrasEj3.o
	$(CXX) -o $(BIN)/cifrasEj3  $(OBJ)/cifrasEj3.o

$(BIN)/sumaHastaN: $(OBJ)/sumaHastaN.o
	$(CXX) -o $(BIN)/sumaHastaN  $(OBJ)/sumaHastaN.o

$(BIN)/sumaHastaNPD: $(OBJ)/sumaHastaNPD.o
	$(CXX) -o $(BIN)/sumaHastaNPD  $(OBJ)/sumaHastaNPD.o

$(OBJ)/cifrasV.o: $(SRC)/cifrasV.cpp 
	$(CXX) $(CPPFLAGS) $(SRC)/cifrasV.cpp -o $(OBJ)/cifrasV.o

$(OBJ)/cifrasEj3.o: $(SRC)/cifrasEj3.cpp 
	$(CXX) $(CPPFLAGS) $(SRC)/cifrasEj3.cpp -o $(OBJ)/cifrasEj3.o

$(OBJ)/sumaHastaN.o: $(SRC)/sumaHastaN.cpp 
	$(CXX) $(CPPFLAGS) $(SRC)/sumaHastaN.cpp -o $(OBJ)/sumaHastaN.o

$(OBJ)/sumaHastaNPD.o: $(SRC)/sumaHastaNPD.cpp 
	$(CXX) $(CPPFLAGS) $(SRC)/sumaHastaNPD.cpp -o $(OBJ)/sumaHastaNPD.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(BIN)/* $(DATOS)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
