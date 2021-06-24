# T.D.A PILA_MAX

Este T.D.A se corresponde con la Práctica 3 de la asignatura Estructura de Datos del Grado en Ingeniería Informática de la Universidad de Granada, curso 2020/21.

## Alumnos:

* Elena Ortega Contreras
* Alberto Llamas González


## Método de uso:

Para compilar el programa tenemos dos opciones a cambiar en pila_max.h:

	Si #define CUAL_COMPILA = 1 -> compilará pila_max_vd
	Si #define CUAL_COMPILA = 2 -> compilará pila_max_cola

Luego dependiendo de lo que tengamos en CUAL_COMPILA tendremos que ejecutar los siguientes comandos:
	
	make pila_max_vd
	make pila_max_cola

Para ver la documentación con doxygen (únicamente en formato html):

	make doc/html

Podemos hacer una limpieza de los archivos tras la ejecución con:

	make clean mrproper
	
	
