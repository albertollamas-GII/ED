MODO DE USO:
Para compilar, cambiar en include/pila_max.h, la manera de compilar:
	1) Si es CUAL_COMPILA = 1, compilara con el fichero de cabecera pila_max_VD.h
	2) Si es CUAL_COMPILA = 2, u otro numero, compilara con el fichero de cabecera pila_max_cola.h
Una vez realizado este cambio procederemos, hacer un make:
	1) make pila_max_vd para compilar la pila_max con vector dinámico
	2) make pila_max_cola para compilar la pila_max con cola
