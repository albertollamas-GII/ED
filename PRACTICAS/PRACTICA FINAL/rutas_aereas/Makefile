SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
LIB = lib
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/rutasaereas documentacion

$(BIN)/rutasaereas: $(OBJ)/rutasaereas.o $(LIB)/libimagen.a $(LIB)/libpaises.a $(LIB)/librutas.a
	$(CXX) -I$(INC) -o  $@ $< -L$(LIB) -limagen -lpaises -lrutas

$(OBJ)/rutasaereas.o: $(SRC)/rutasaereas.cpp $(INC)/Imagen.h $(INC)/Almacen_Rutas.h $(INC)/Paises.h $(INC)/Punto.h
	$(CXX) $(CPPFLAGS) $< -o $@ 

$(LIB)/libimagen.a: $(OBJ)/imagen.o $(OBJ)/imagenES.o
	ar -rvs $@ $^

$(OBJ)/imagen.o: $(SRC)/Imagen.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) -o $@ $<	
		
$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp
	$(CXX) $(CPPFLAGS) -o $@ $<

$(LIB)/libpaises.a: $(OBJ)/paises.o $(OBJ)/pais.o $(OBJ)/punto.o
	ar -rvs $@ $^

$(OBJ)/paises.o: $(SRC)/Paises.cpp $(INC)/Pais.h
	$(CXX) $(CPPFLAGS) -o $@ $<	
		
$(OBJ)/pais.o: $(SRC)/Pais.cpp $(SRC)/Punto.cpp
	$(CXX) $(CPPFLAGS) -o $@ $<

$(LIB)/librutas.a: $(OBJ)/almacen_rutas.o $(OBJ)/ruta.o $(OBJ)/punto.o
	ar -rvs $@ $^

$(OBJ)/almacen_rutas.o: $(SRC)/Almacen_Rutas.cpp $(INC)/Ruta.h
	$(CXX) $(CPPFLAGS) -o $@ $<	
		
$(OBJ)/ruta.o: $(SRC)/Ruta.cpp $(SRC)/Punto.cpp
	$(CXX) $(CPPFLAGS) -o $@ $<

$(OBJ)/punto.o: $(SRC)/Punto.cpp
	$(CXX) $(CPPFLAGS) -o $@ $<


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~ $(LIB)/*

mrproper : clean
	-rm $(BIN)/* doc/html/* *.ppm *.pgm
