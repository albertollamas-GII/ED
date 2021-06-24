all: bin/usopilas_max doc/html

#Compilacion

pila_max_cola:	bin/usopilas_max_cola 

bin/usopilas_max_cola: lib/libcolas.a obj/usopilas_max_cola.o
		g++ -Llib/ -o bin/usopilas_max_cola obj/usopilas_max_cola.o -lcolas 

lib/libcolas.a: obj/pila_max_cola.o 
		ar -rvs lib/libcolas.a obj/pila_max_cola.o 

obj/pila_max_cola.o: src/pila_max_cola.cpp include/pila_max_cola.h include/cola.cpp include/cola.h
		g++ -g -c -o obj/pila_max_cola.o -I./include src/pila_max_cola.cpp

obj/usopilas_max_cola.o: src/usopilas_max.cpp include/pila_max.h include/pila_max_cola.h
		g++ -g -c -o obj/usopilas_max_cola.o -I./include src/usopilas_max.cpp

pila_max_vd:	bin/usopilas_max_vd

bin/usopilas_max_vd: lib/libvd.a obj/usopilas_max_vd.o
		g++ -Llib/ -o bin/usopilas_max_vd obj/usopilas_max_vd.o -lvd 
	
lib/libvd.a: obj/pila_max_vd.o
		ar -rvs lib/libvd.a obj/pila_max_vd.o

obj/pila_max_vd.o: src/pila_max_vd.cpp include/pila_max_vd.h
		g++ -g -c -o obj/pila_max_vd.o -I./include src/pila_max_vd.cpp

obj/usopilas_max_vd.o: src/usopilas_max.cpp include/pila_max.h include/pila_max_vd.h
		g++ -g -c -o obj/usopilas_max_vd.o -I./include src/usopilas_max.cpp

#Documentacion
doc/html: Doxyfile
	doxygen Doxyfile

#Limpieza
clean:
		-rm obj/* lib/*

mrproper: clean
		-rm -r bin/* doc/html

autor:
		@echo "Elena Ortega Contreras, Alberto Llamas Gonzalez"
