INC = include
OBJ = obj
SRC = src
BIN = bin

all:  bin/usodiccionario bin/usoguia doc/html

diccionario: bin/usodiccionario

$(BIN)/usodiccionario: $(OBJ)/usodiccionario.o
	g++ -o $(BIN)/usodiccionario $(OBJ)/usodiccionario.o

$(OBJ)/usodiccionario.o:
	g++ -c -I$(INC) $(SRC)/usodiccionario.cpp -o $(OBJ)/usodiccionario.o

guiatlf: bin/usoguia

$(BIN)/usoguia: $(OBJ)/usoguia.o
	g++ -o $(BIN)/usoguia $(OBJ)/usoguia.o

$(OBJ)/usoguia.o:
	g++ -c -I$(INC) $(SRC)/usoguia.cpp -o $(OBJ)/usoguia.o

#Documentacion
doc/html: Doxyfile
	doxygen Doxyfile

#Limpieza
clean:
		-rm obj/* lib/*

mrproper: clean
		-rm -r bin/* doc/html

autor:
		@echo "Alberto Llamas Gonzalez"


