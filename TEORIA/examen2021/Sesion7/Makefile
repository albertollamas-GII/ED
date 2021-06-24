#############################################################################
#
# SISTEMAS OPERATIVOS
# DOBLE GRADO EN INGENIERIA INFORMATICA Y MATEMATICAS (DGIIM)
#
# AUTORES:  DANIEL PEREZ RUIZ
#
# MAKEFILE SESION 7
#
#############################################################################

TEST = test
NAME = ejercicio
PROG = programa
SRC = src
BIN = bin
OBJ = obj
CXX = gcc
CPPFLAGS = -Wall -g -c

#=============================================================================================
# 1. REGLA ALL
#=============================================================================================

all: clientes servidor proxy


#=============================================================================================
# 2. CREACION DE EJECUTABLES EN BIN A TRAVES DE OBJETOS
#=============================================================================================

servidor: $(OBJ)/servidor.o
	-mkdir -p $(BIN)
	$(CXX) -o $(BIN)/servidor $(OBJ)/servidor.o

clientes: $(OBJ)/clientes.o
	-mkdir -p $(BIN)
	$(CXX) -o $(BIN)/clientes $(OBJ)/clientes.o

proxy: $(OBJ)/proxy.o
	-mkdir -p $(BIN)
	$(CXX) -o $(BIN)/proxy $(OBJ)/proxy.o

#=============================================================================================
# 3. CREACION DE CODIGO OBJETO
#=============================================================================================

$(OBJ)/servidor.o: servidor.c
	-mkdir -p $(OBJ)
	$(CXX) $(CPPFLAGS) servidor.c -o $(OBJ)/servidor.o

$(OBJ)/clientes.o: clientes.c
	-mkdir -p $(OBJ)
	$(CXX) $(CPPFLAGS) clientes.c -o $(OBJ)/clientes.o

$(OBJ)/proxy.o: proxy.c
	-mkdir -p $(OBJ)
	$(CXX) $(CPPFLAGS) proxy.c -o $(OBJ)/proxy.o



#=============================================================================================
# 4. CREACION DE CODIGO OBJETO
#=============================================================================================

clean:
	-rm -r $(OBJ)/* $(BIN)/*
	-rmdir $(OBJ) $(BIN)
