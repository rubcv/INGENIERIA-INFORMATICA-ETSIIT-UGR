# Directorio include (ficheros .h)
INC = include

# Directorio bin (ejecutables)
BIN = bin

# Directorio obj (ficheros .o)
OBJ = obj

# Directorio src (ficheros .cpp)
SRC = src

all: $(BIN)/main

bin/main: reconstruir $(OBJ)/main.o $(OBJ)/bloqueLed.o
	g++ -o $(BIN)/main $(OBJ)/main.o $(OBJ)/bloqueLed.o
	
obj/bloqueLed.o: reconstruir $(SRC)/bloqueLed.cpp $(INC)/bloqueLed.h
	g++ -c $(SRC)/bloqueLed.cpp -o $(OBJ)/bloqueLed.o -I$(INC)/
	
obj/main.o: reconstruir $(SRC)/main.cpp $(INC)/bloqueLed.h
	g++ -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)/
	
reconstruir:
	test -d $(OBJ) || mkdir -p $(OBJ)
	test -d $(BIN) || mkdir -p $(BIN)

clean:
	echo "Limpiando..."
	rm $(OBJ)/*.o

mrproper: clean
	rm $(BIN)/main