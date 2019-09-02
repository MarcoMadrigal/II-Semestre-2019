/**********************************************************************
    Instituto Tecnológico de Costa Rica
    Estructuras de Datos IC-2001 - Laboratorio 4
    II Semestre 2019
    Profesora: Samanta Ramijan Carmiol
    Ejemplos Prácticos: Lista de Estudiantes
    Estudiante: Marco Antonio Madrigal Pérez
	Carnet: 2019053902


	Post de las evidencias de ejecución del programa:
	https://www.reddit.com/user/MadrigalMarco/comments/cxjcr2/estructuras_de_datos_laboratorio_4_evidencias_de/
**********************************************************************/
// Librerías utilizadas
#include <stdio.h>
#include "lista_estudiantes.h"
#include <stdlib.h>
#include <string.h>

// Se crea la lista que contiene a los nodos de estudiantes, se declara como global
lista_estudiantes *ref_lista = NULL;

// Función encargada de crear un nodo.
nodo_estudiante* crear_nodo(){
	char *ref_nombre;
	size_t max_size;
	int carnet;
	printf("\n---------------------------------------------------------------------");
	printf("\nPara agregar un estudiante por favor ingrese los siguientes datos");
	printf("\n---------------------------------------------------------------------");
	ref_nombre = (char *) malloc (LONGITUD_MAXIMA_NOMBRE); // Se asigna memoria al nombre
	printf("\n>> Nombre:");
	max_size = LONGITUD_MAXIMA_NOMBRE;
   ref_nombre = get_user_input(max_size); // Se solicita el nombre
   max_size = LONGITUD_MAXIMA_CARNET;
   printf(">> Carnet:");
   carnet = get_user_numerical_input(max_size); // Se solicita el carnet

	// Se crea el nuevo estudiante, asignando los datos ingresados por el usuario.
	nodo_estudiante* nuevo;
	nuevo = malloc (sizeof (nodo_estudiante));
	nuevo->carnet = carnet;
	nuevo->nombre = ref_nombre;
	nuevo->ref_siguiente = NULL;
	return nuevo; // Se retorna el nuevo nodo creado con los datos.
}

// Función para inicializar la lista de estudiantes
void inicializar_lista(){
	ref_lista = malloc(sizeof (lista_estudiantes)); // Se asigna memoria a la lista
	ref_lista->cantidad=0; // Se iguala la cantidad de estudiantes a 0
	ref_lista->ref_inicio = NULL; // Se indica el primer elemento como null
	ref_lista->ref_ultimo = NULL; // Se indica el último elemento como null
}

// Función para insertar un estudiante al inicio de la lista
void insertar_inicio(nodo_estudiante* nuevo){
	// Cuando la lista sea igual a null, se inicializará y luego se harán las asignaciones para el caso del primer elemento.
	if (ref_lista == NULL){
		inicializar_lista();
		ref_lista->ref_inicio = nuevo;
		ref_lista->ref_ultimo = nuevo;
		ref_lista->ref_ultimo->ref_siguiente = nuevo;
		ref_lista->cantidad = ref_lista->cantidad+1;

	}else{ // Estas asignaciones son cuando la lista tiene 1 o más elementos, ya que la lógica cambia
		nuevo->ref_siguiente = ref_lista->ref_inicio;
		ref_lista->ref_inicio = nuevo;
		ref_lista->ref_ultimo->ref_siguiente = ref_lista->ref_inicio;
		ref_lista->cantidad = ref_lista->cantidad+1;

	}
	
}

// Función para insertar un estudiante al final de la lista
void insertar_final(nodo_estudiante* nuevo){
	/*
	Si la lista es igual a NULL, se inicializará y se harán las asignaciones para cuando se ingrese el
	primer elemento, ya que no es el mismo caso para cuando hay 1 o más.
	*/
	if (ref_lista == NULL){
	  inicializar_lista();
		ref_lista->ref_inicio = nuevo;
		ref_lista->ref_ultimo = nuevo;
		ref_lista->ref_ultimo->ref_siguiente = nuevo;
		ref_lista->cantidad = ref_lista->cantidad+1;

	/*
	Si no es igual a NULL, se asignará memoria para ese nuevo estudiante y
	se harán las asignaciones correspondientes.
	 */
	}else{
		nodo_estudiante* temporal;
  		temporal = malloc (sizeof (nodo_estudiante));
  		temporal = ref_lista->ref_inicio;

		nuevo->ref_siguiente = ref_lista->ref_inicio;
		ref_lista->ref_ultimo->ref_siguiente = nuevo;
		ref_lista->ref_ultimo = nuevo;
		ref_lista->cantidad++;
 	}
}

// Función para borrar un estudiante de la lista según su índice
void borrar_por_indice(int indice) {
	nodo_estudiante* temporal;
  	temporal = malloc (sizeof (nodo_estudiante));
  	temporal = NULL;

	int cont = 0;

	// Cuando el inicio sea NULL, se imprimirá un mensaje de error, ya que la lista está vacía.
	if (ref_lista->ref_inicio == NULL){
		printf("\nLa lista está vacía");
		return;
	}else{
		// Validación para saber si el índice es mayor a la cantidad de elementos.
		if (indice >= ref_lista->cantidad){
			printf("\nEl índice ingresado no es valido");
			return;
		// Si no es así, empezará a buscar el estudiante a borrar
		} else{
			nodo_estudiante* temporal;
  			temporal = malloc (sizeof (nodo_estudiante));
  			temporal = ref_lista->ref_inicio;

			// Si es igual a 0, se borrará el primer estudiante.
  			if (indice == 0){
				ref_lista->ref_inicio = temporal->ref_siguiente;
				ref_lista->ref_ultimo->ref_siguiente = ref_lista->ref_inicio;
				ref_lista->cantidad--;
				free(temporal);
				return;

			/*
			Si no, se recorrerá la lista utilizando un while y una lista temporal hasta que el contador
			sea mayor a la cantidad de elementos de la lista.
			*/
  			}else{
  				while (cont < (ref_lista->cantidad)-1){
					cont++;
					if (cont == indice){
						
						free(temporal->ref_siguiente);
						temporal->ref_siguiente = temporal->ref_siguiente->ref_siguiente;
						ref_lista->cantidad--;
						return;
					}
					temporal = temporal->ref_siguiente;
				}
			}
		}
	}
}
 

// Función para imprimir la lista de estudiantes.
void imprimir(){
	printf("\n---------------------------------------------------------------------");
	printf("\n Lista de estudiantes");
	printf("\n---------------------------------------------------------------------");
	int cont = 0;
	// Validación para saber si la lista está vacía, si es así imprimirá un mensaje de error.
	if (ref_lista == NULL || ref_lista->cantidad==0){
		printf("\n No hay estudiantes registrados");
		return;

	// Si no, se recorrerá la lista con ayuda de un while y se irán imprimiendo los datos.
	}else{
  		nodo_estudiante* temporal;
		  
  		temporal = malloc (sizeof (nodo_estudiante));
  		temporal = ref_lista->ref_inicio;
		while (cont < (ref_lista->cantidad)-1){
			printf("\n   [%i] %i %s",cont,temporal->carnet,temporal->nombre);
			temporal = temporal->ref_siguiente;
			cont++;
		}
		printf("\n   [%i] %i %s",cont,temporal->carnet,temporal->nombre);
	}
	printf("\n---------------------------------------------------------------------");
	printf("\n    %i Estudiantes registrados", ref_lista->cantidad);
	printf("\n---------------------------------------------------------------------");
}

// Función para buscar un estudiante según el índice.
nodo_estudiante* buscar_por_indice(int indice) {
	nodo_estudiante* temporal;
  	temporal = malloc (sizeof (nodo_estudiante));
  	temporal = NULL;
	// Si la lista es igual a vacía, se imprimirá un mensaje de error.
	if (ref_lista->ref_inicio == NULL || ref_lista->cantidad ==0){
		printf("\nLa lista está vacía");
		return temporal;
	}else{
		// Validación para saber si el índice es mayor a la cantidad de estudiantes.
		if (indice >= ref_lista->cantidad){
			printf("\nEl índice ingresado no es valido");
			return temporal;
		} else{

			// Se recorrer la lista utilizando un while hasta encontrar al estudiante y lo retorna.
			int cont = 0;
			nodo_estudiante* temporal;
  			temporal = malloc (sizeof (nodo_estudiante));
  			temporal = ref_lista->ref_inicio;
			while (cont < (ref_lista->cantidad)-1){
				if (cont == indice){
					return temporal;
				}
				temporal = temporal->ref_siguiente;
				cont++;
			}
			return temporal;
		}
	}
}

// Función para validar los carnets de un estudiante
void validar_carnets(int carnet_almacenado, int carnet_ingresado){ // Pendiente de implementar lista circular
	// Compara el carnet almacenado con el carnet ingresado por el usuario.
	if(carnet_almacenado == carnet_ingresado){
		printf("\n El carnet ingresado es correcto");
	}else{
		printf("\n El carnet ingresado es incorrecto");
	}
}

// Función para imprimir el menú en pantalla.
void menu() { // Pendiente de implementar lista circular
	size_t max_size;
    int opcion,indice,carnet;
    nodo_estudiante* temporal;
	do{
		printf("\n\n\n\n\n");
		imprimir();
		printf("\n---------------------------------------------------------------------");
		printf("\n(0) Salir");
		printf("\n(1) Agregar estudiante al final");
		printf("\n(2) Agregar estudiante al inicio");
		printf("\n(3) Validar carnet de estudiante en posicion dada");
		printf("\n(4) Borrar un estudiante en posicion dada");
		printf("\n---------------------------------------------------------------------");
		printf("\n>> Opcion deseada: ");
		max_size = 1;
		opcion = get_user_numerical_input(max_size); // Obtiene la opción deseada por el usuario.
		switch(opcion){
			case 0: // Salir del programa
				break;
			case 1: // Agregar un estudiante al final
    			temporal = crear_nodo();
    			insertar_final(temporal);
				break;
			case 2: // Agregar un estudiante al inicio
				temporal = crear_nodo();
    			insertar_inicio(temporal);
				break;
			case 3: // Validar un carnet de un estudiante según posición
				printf("\n---------------------------------------------------------------------");
				printf("\n>> ¿Qué posición de carnet desea validar? ");
				indice = get_user_numerical_input(1); // Obtiene la posición a validar por el usuario
				temporal = buscar_por_indice(indice); // Busca ese estudiante
				if(temporal != NULL){ 
					// Si es diferente a NULL, preguntará por el carnet del estudiante y llamará a la función validar_carnets.
					printf("\n>> ¿Cuál es el carnet del estudiante en la posición indice? ");
					carnet = get_user_numerical_input(1);
					validar_carnets(temporal->carnet, carnet);

				}
				printf("\n---------------------------------------------------------------------");
				break;
			case 4: // Borrar un estudiante de la lista.
				printf("\n---------------------------------------------------------------------");
				printf("\n>> ¿Qué posición de carnet desea borrar? ");
				indice = get_user_numerical_input(1);
				borrar_por_indice(indice);
				break;
		}
	}while(opcion != 0);
}

// Función main del programa, sirve para llamar al menú y comenzar la ejecución.
int main() {
	menu();
	return 0;
}

// Función para capturar una entrada(string) por consola hecha por el usuario.
char* get_user_input(size_t max_size){
    
    char *buffer;
    size_t characters;

    buffer = (char *)malloc(max_size * sizeof(char));
    if(buffer == NULL){
        perror("ERROR No fue posible reservar memoria para el buffer");
        exit(1);
    }
    characters = getline(&buffer,&max_size,stdin);
    buffer[strlen(buffer)-1]= 0;
    return buffer;
}

/*
Función para convertir la entrada del usuario en un dato de tipo entero.
LLama a la función get_user_input() y convierte esa entrada(string) en un entero usando
la función atoi().
*/
int get_user_numerical_input(size_t max_size){
	int numerical_input = atoi(get_user_input(max_size));
	return numerical_input;
}