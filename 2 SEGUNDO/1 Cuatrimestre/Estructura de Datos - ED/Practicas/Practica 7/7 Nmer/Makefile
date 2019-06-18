SRC = src
INC = include
OBJ = obj
LIB = lib
BIN = bin
CXX = g++ -std=c++11 -fpermissive
AR = ar rvs
AR_MACOSX = libtool -static -o  # Para MACs
CPPFLAGS = -g  -I$(INC) -c

runp: all
	./$(BIN)/prueba

rune:	all
	./$(BIN)/ejemploKtree

all: $(BIN)/ejemploKtree $(BIN)/prueba

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/doxPractica.txt


# ************ Compilación de módulos ************

$(BIN)/prueba: $(OBJ)/prueba.o $(OBJ)/Nmer.o
	$(CXX) $(OBJ)/prueba.o $(OBJ)/Nmer.o -o $(BIN)/prueba

$(BIN)/ejemploKtree: $(OBJ)/ejemploKtree.o $(LIB)/libNmer.a $(INC)/ktree.h
	$(CXX) -o $(BIN)/ejemploKtree $(OBJ)/ejemploKtree.o -I$(INC) -L$(LIB) -lNmer

$(OBJ)/ejemploKtree.o: $(SRC)/ejemploKtree.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/ejemploKtree.o $(SRC)/ejemploKtree.cpp

$(LIB)/libNmer.a: $(OBJ)/Nmer.o
	$(AR) $(LIB)/libNmer.a $(OBJ)/Nmer.o

$(OBJ)/Nmer.o: $(SRC)/Nmer.cpp $(INC)/Nmer.h $(INC)/ktree.h
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Nmer.o $(SRC)/Nmer.cpp

$(OBJ)/prueba.o: $(SRC)/prueba.cpp
	$(CXX) $(CPPFLAGS) -I$(INC)  $(SRC)/prueba.cpp -o $(OBJ)/prueba.o


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(BIN)/*

clean_doc : clean
	-rm doc/html/* doc/latex/*
