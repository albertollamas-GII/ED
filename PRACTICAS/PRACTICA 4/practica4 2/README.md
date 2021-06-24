# T.D.A Diccionario y T.D.A Guía de Teléfono

Estos T.D.As se corresponden con la Práctica 4 de la asignatura Estructura de Datos del Grado en Ingeniería Informática de la Universidad de Granada, curso 2020/21.

## Alumno:

* Alberto Llamas González


## Método de uso:

Hay tres formas de compilar el proyecto:

		* make diccionario -> genera el ejecutable usodiccionario para ejecutar un ejemplo del T.D.A Diccionario
		* make guiatlf -> genera el ejecutable usoguia para ejecutar un ejemplo del T.D.A Guía_Tlf
		* make -> compila todo (doxygen incluido)

Ejecutaremos _usodiccionario_ y _usoguia_ de la siguiente manera:

		* bin/usodiccionario txt/data.txt
		* bin/usoguia txt/guia.txt

>Nota: No hace falta redireccionamiento de entrada porque pasamos los argumentos por el main

Para ver la documentación con doxygen (únicamente en formato html):

	make doc/html

Podemos hacer una limpieza de los archivos tras la ejecución con:

	make mrproper

### Clases Iterator y Const_iterator

Para cada T.D.A, se ha sobrecargado las clases iterator y const_iterator.

### Métodos Adicionales:

Se han añadido a las clases Diccionario y Guía de Teléfono métodos para darles más funcionalidad

#### T.D.A Diccionario

1. Sobrecarga de operator -
2. Sobrecarga de operator +
3. Borrar elemento del diccionario dada su clave
4. Método que invierte un diccionario
5. Método que dadas dos palabras, se muestran la clave con su respectiva informacion asociada en el rango definido por las dos claves
6. Imprime un diccionario al revés

### T.D.A Guía_Tlf

1. En las clases iterator y const_iterator:
	 - Sobrecarga del operador + que avanza un número de posiciones dado.
	 - Sobrecarga del operador - que retrocede un número de posiciones dado.
2. Intersección de dos guías
3. Método que dada una letra, devuelve una guía con todos los nombres que empiezan por esa letra
4. Método que dado un numero, devuelve una lista con todas las personas con números que empiezan por él.
5. Método que dados dos nombres, devuelve una guía con todos los números dentro de ese intervalo
