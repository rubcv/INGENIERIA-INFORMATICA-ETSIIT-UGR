cmake_minimum_required(VERSION 3.5)
project(codigo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES recorrido_mas_rapido.cpp Fecha.h Hora.h Instante.h Punto.h Recorrido.cpp Recorrido.h)
add_executable(codigo ${SOURCE_FILES})