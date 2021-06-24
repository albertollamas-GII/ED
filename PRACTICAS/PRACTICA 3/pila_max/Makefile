SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g -I$(INC) -c

# ************ Documentacion ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación ************

pila_max_cola: $(BIN)/usopilas_max_cola

$(BIN)/usopilas_max_cola: $(OBJ)/usopilas_max_cola.o $(LIB)/libpilamaxCola.a
	$(CXX) -o $@ $< -lpilamaxCola -L$(LIB)

$(OBJ)/usopilas_max_cola.o: $(SRC)/usopilas_max.cpp $(INC)/pila_max.h $(INC)/pila_max_cola.h $(INC)/cola.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(LIB)/libpilamaxCola.a: $(OBJ)/pila_max_cola.o $(OBJ)/cola.o
	ar -rvs $@ $^

$(OBJ)/pila_max_cola.o: $(SRC)/pila_max_cola.cpp $(INC)/pila_max_cola.h $(INC)/cola.h $(SRC)/cola.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/cola.o: $(INC)/cola.h $(SRC)/cola.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

pila_max_vd: $(BIN)/usopilas_max_VD

$(BIN)/usopilas_max_VD: $(OBJ)/usopilas_max_VD.o $(LIB)/libpilamaxVD.a
	$(CXX) -o $@ $< -lpilamaxVD -L$(LIB)

$(OBJ)/usopilas_max_VD.o: $(SRC)/usopilas_max.cpp $(INC)/pila_max.h $(INC)/pila_max_VD.h $(INC)/VDG.h
	$(CXX) $(CPPFLAGS) $< -o $@

$(LIB)/libpilamaxVD.a: $(OBJ)/pila_max_VD.o $(OBJ)/VDG.o
	ar -rvs $@ $^

$(OBJ)/pila_max_VD.o: $(SRC)/pila_max_VD.cpp $(INC)/pila_max_VD.h $(INC)/VDG.h $(SRC)/VDG.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/VDG.o: $(INC)/VDG.h $(SRC)/VDG.cpp
	$(CXX) $(CPPFLAGS) $< -o $@

# ************ Limpieza ************
clean:
	-rm $(OBJ)/* $(LIB)/*

mrproper: clean
	-rm -r $(BIN)/* doc/html doc/latex

autor:
	@echo "Francisco Rodriguez Jimenez"
