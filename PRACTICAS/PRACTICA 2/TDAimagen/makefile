all: bin/usoimagen doc/html
INCLUDE = include
LIB     = lib

bin/usoimagen : src/usoimagen.cpp lib/libimg.a lib/libimges.a
	g++ -L$(LIB) -o bin/usoimagen -I$(INCLUDE) src/usoimagen.cpp -limg -limges

lib/libimg.a : obj/imagen.o
	ar rvs $(LIB)/libimg.a obj/imagen.o

obj/imagen.o : src/imagen.cpp
	g++ -c -o obj/imagen.o -I$(INCLUDE) src/imagen.cpp

lib/libimges.a : obj/imagenES.o
	ar rvs $(LIB)/libimges.a obj/imagenES.o

obj/imagenES.o : src/imagenES.cpp
	g++ -c -o obj/imagenES.o -I$(INCLUDE) src/imagenES.cpp

doc/html: Doxyfile
	doxygen Doxyfile

