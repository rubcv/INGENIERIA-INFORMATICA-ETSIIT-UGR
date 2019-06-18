# Nombre archivo: makefile
# Uso: make 
# Descripción: Mantiene todas las dependencias entre los módulos y la biblioteca
#              que utiliza el programa2.

LIB_DIR=./

programa2: main2.o factorial.o hello.o libmates.a
	g++ -L$(LIB_DIR) -o $@ $^

main2.o: main2.cpp
	g++ -I./includes -c main2.cpp

factorial.o: factorial.cpp
	g++ -I./includes -c factorial.cpp

hello.o: hello.cpp
	g++ -I./includes -c hello.cpp

libmates.a: sin.o cos.o tan.o
	ar -rvs libmates.a sin.o cos.o tan.o

sin.o: sin.cpp
	g++ -I./includes -c sin.cpp

cos.o: cos.cpp
	g++ -I./includes -c cos.cpp

tan.o: tan.cpp
	g++ -I./includes -c tan.cpp

cleanAll: cleanObj cleanLib
	rm programa2

cleanObj:
	rm main2.o factorial.o hello.o

cleanLib:
	rm sin.o cos.o tan.o
