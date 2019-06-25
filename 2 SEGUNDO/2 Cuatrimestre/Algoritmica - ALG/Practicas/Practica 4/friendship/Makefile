SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -pg  -I$(INC) -c


all:  $(BIN)/prueba_APermutacion $(BIN)/friendshipV $(BIN)/friendshipVConRepeticion $(BIN)/friendshipBB

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************



	
$(BIN)/prueba_APermutacion: $(OBJ)/Apermutacion.o $(OBJ)/prueba_APermutacion.o
	$(CXX) -o $(BIN)/prueba_Apermutacion  $(OBJ)/prueba_APermutacion.o $(OBJ)/Apermutacion.o

$(BIN)/friendshipV: $(OBJ)/friendshipV.o
	$(CXX) -o $(BIN)/friendshipV  $(OBJ)/friendshipV.o

$(BIN)/friendshipVConRepeticion: $(OBJ)/friendshipVConRepeticion.o
	$(CXX) -o $(BIN)/friendshipVConRepeticion  $(OBJ)/friendshipVConRepeticion.o

$(BIN)/friendshipBB: $(OBJ)/friendshipBB.o
	$(CXX) -o $(BIN)/friendshipBB  $(OBJ)/friendshipBB.o

$(OBJ)/prueba_APermutacion.o: $(SRC)/prueba_APermutacion.cpp $(INC)/Apermutacion.h
	$(CXX) $(CPPFLAGS) $(SRC)/prueba_APermutacion.cpp -o $(OBJ)/prueba_APermutacion.o	

$(OBJ)/friendshipV.o: $(SRC)/friendshipV.cpp 
	$(CXX) $(CPPFLAGS) $(SRC)/friendshipV.cpp -o $(OBJ)/friendshipV.o

$(OBJ)/friendshipBB.o: $(SRC)/friendshipBB.cpp 
	$(CXX) $(CPPFLAGS) $(SRC)/friendshipBB.cpp -o $(OBJ)/friendshipBB.o	

$(OBJ)/friendshipVConRepeticion.o: $(SRC)/friendshipVConRepeticion.cpp 
	$(CXX) $(CPPFLAGS) $(SRC)/friendshipVConRepeticion.cpp -o $(OBJ)/friendshipVConRepeticion.o

$(OBJ)/Apermutacion.o: $(SRC)/Apermutacion.cpp $(INC)/Apermutacion.h
	$(CXX) $(CPPFLAGS) $(SRC)/Apermutacion.cpp -o $(OBJ)/Apermutacion.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/*  $(BIN)/* 

mrproper : clean
	-rm $(BIN)/* doc/html/*
