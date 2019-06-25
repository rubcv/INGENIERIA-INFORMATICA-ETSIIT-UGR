SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/testimagen_paleta

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/testimagen_paleta: $(OBJ)/testimagen_paleta.o $(OBJ)/imagen.o $(OBJ)/imagenES.o 
	$(CXX) -o $(BIN)/testimagen_paleta  $(OBJ)/testimagen_paleta.o $(OBJ)/imagen.o $(OBJ)/imagenES.o 

$(OBJ)/testimagen_paleta.o: $(SRC)/testimagen_paleta.cpp $(INC)/imagenES.h $(INC)/imagen.h $(INC)/paleta.h 
	$(CXX) $(CPPFLAGS) $(SRC)/testimagen_paleta.cpp -o $(OBJ)/testimagen_paleta.o
$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o
		
$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp $(INC)/imagenES.h 
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o	


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
