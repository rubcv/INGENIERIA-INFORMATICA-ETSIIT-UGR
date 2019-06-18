# Makefile para compilar

SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++ -g
CPPFLAGS = -ansi -pedantic -Wall -Wextra -Wwrite-strings -Werror -g -c -std=c++0x -I$(INC)

# ************ Compilacion de los Programas ************

all: $(BIN)/arteASCII2 $(BIN)/testimagen $(BIN)/suma $(BIN)/testFinal

$(BIN)/suma: $(OBJ)/suma.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/suma.o -limagen -o $(BIN)/suma  -L$(LIB)

$(BIN)/arteASCII2: $(OBJ)/arteASCII2.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/arteASCII2.o -limagen -o $(BIN)/arteASCII2  -L$(LIB)

$(BIN)/testimagen: $(OBJ)/testimagen.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/testimagen.o -limagen -o $(BIN)/testimagen  -L$(LIB)

$(BIN)/testFinal: $(OBJ)/testFinal.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/testFinal.o -limagen -o $(BIN)/testFinal  -L$(LIB)

# ************ Creacion de Objetos ************

$(OBJ)/suma.o: $(SRC)/suma.cpp $(INC)/imagen.h 
	$(CXX) $(CPPFLAGS) $(SRC)/suma.cpp -o $(OBJ)/suma.o

$(OBJ)/arteASCII2.o: $(SRC)/arteASCII2.cpp $(INC)/imagen.h $(INC)/lista.h
	$(CXX) $(CPPFLAGS) $(SRC)/arteASCII2.cpp -o $(OBJ)/arteASCII2.o

$(OBJ)/testimagen.o: $(SRC)/testimagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/testimagen.cpp -o $(OBJ)/testimagen.o

$(OBJ)/testFinal.o: $(SRC)/testFinal.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/testFinal.cpp -o $(OBJ)/testFinal.o

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/pgm.h $(INC)/byte.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

$(OBJ)/pgm.o: $(SRC)/pgm.cpp $(INC)/pgm.h
	$(CXX) $(CPPFLAGS) $(SRC)/pgm.cpp -o $(OBJ)/pgm.o

$(OBJ)/byte.o: $(SRC)/byte.cpp $(INC)/byte.h
	$(CXX) $(CPPFLAGS) $(SRC)/byte.cpp -o $(OBJ)/byte.o
	
$(OBJ)/lista.o: $(SRC)/lista.cpp $(INC)/lista.h
	$(CXX) $(CPPFLAGS) $(SRC)/lista.cpp -o $(OBJ)/lista.o

# ************ Creacion de bibliotecas ************

$(LIB)/libimagen.a : $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o
	ar rvs $(LIB)/libimagen.a $(OBJ)/imagen.o $(OBJ)/pgm.o $(OBJ)/byte.o $(OBJ)/lista.o
	
# ************ documentación *******

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************

clean:
	echo "Limpiando..."
	rm $(OBJ)/* $(LIB)/*
	
mrproper: clean
	rm $(BIN)/* doc/html/* ascii* *.pgm
