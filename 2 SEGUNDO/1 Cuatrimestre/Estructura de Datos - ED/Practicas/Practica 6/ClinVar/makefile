
# Rubén Calvo Villazán
# Makefile para compilar


# ************ FLAGS *******
CXX = g++
INC = include
BIN = bin
SRC = src
OBJ = obj
DOC = doc
FLAGS = -c

# ************ EJECUTAR PROGRAMA *******
run: all
	./$(BIN)/principal

# ************ PROGRAMA *******
all: $(BIN)/principal

# ************ FUENTE *******
$(BIN)/principal: $(OBJ)/principal.o
	$(CXX) -I$(INC) $(OBJ)/principal.o -o $(BIN)/principal

# ************ OBJETO *******
$(OBJ)/principal.o: $(SRC)/principal.cpp
	$(CXX) -I$(INC) $(FLAGS) $(SRC)/principal.cpp
	mv  principal.o $(OBJ)/

# ************ DOCUMENTACION *******
documentacion:
	doxygen $(DOC)/doxys/Doxyfile

# ************ LIMPIEZA ************
clean:
	echo "Limpiando..."
	rm $(OBJ)/*
	rm $(BIN)/*
	
	rm -rf $(DOC)/html/*
	rmdir $(DOC)/html

	rm -rf $(DOC)/latex/*
	rmdir $(DOC)/latex
