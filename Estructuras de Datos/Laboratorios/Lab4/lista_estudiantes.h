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
//Definición de Macros
#define LONGITUD_MAXIMA_NOMBRE 50 
#define LONGITUD_MAXIMA_CARNET 12

//Definición de Estructuras
typedef struct nodo_estudiante
{
	int carnet;
	char *nombre;

	struct nodo_estudiante *ref_siguiente;
}nodo_estudiante;

typedef struct lista_estudiantes
{
	nodo_estudiante *ref_inicio;
	nodo_estudiante *ref_ultimo;
	int cantidad;
}lista_estudiantes;

//Definición de Funciones
/*-----------------------------------------------------------------------
	crear_nodo
	Entradas: No recibe parámetros
	Salidas: Retorna un puntero de tipo nodo_estudiante al nodo creado
	Funcionamiento: 
		- Solicita al usuario ingresar Nombre y Carnet.
		- Le asigna memoria al nombre para solicitarlo por medio de un getline.
		- Llama a las funciones para solicitar nombre y carnet.
		- Crea un puntero de tipo nodo_estudiante y le asigna la memoria necesaria.
		- Le asigna al nodo el nombre y carnet ingresados.
		- El nodo siguiente apunta a NULL.
		- Retorna el puntero al nuevo nodo.
		- 
-----------------------------------------------------------------------*/
nodo_estudiante* crear_nodo();
/*-----------------------------------------------------------------------
	inicializar_lista
	Entradas: No recibe parámetros
	Salidas: No retorna nada
	Funcionamiento: 
		- Reserva el espacio para la lista
		- Iguala la variable Cantidad a 0, porque no hay elementos en la lista
		- Establece el inicio de la lista como NULL
-----------------------------------------------------------------------*/
void inicializar_lista();
/*-----------------------------------------------------------------------
	insertar_inicio
	Entradas: La función recibe un puntero llamado nuevo de tipo nodo_estudiante
	Salidas: No retorna nada
	Funcionamiento: 
		- Si la lista está vacía, llama a la función inicializar_lista para crearla
		- Si no, el siguiente de nuevo va a ser igual al inicio de la lista.
		- Y la cantidad va a aumentar en 1 porque se añadió un nuevo elemento
-----------------------------------------------------------------------*/
void insertar_inicio(nodo_estudiante* nuevo);
/*-----------------------------------------------------------------------
	insertar_final
	Entradas: Un puntero de la lista.
	Salidas: No retorna nada.
	Funcionamiento: 
		- Si la lista está vacía, va a llamar a inicializar_lista() para asignarle la memoria.
		- Si la cantidad de elementos es igual a 0, llama a la función insertar_inicio(nuevo) para añadirlo al inicio.
		- Si no, creará una lista temporal del tipo del struct y empezará a recorrer la lista hasta
		  encontrar el elemento siguiente que sea igual a NULL.
		- Cuando se cumpla esa condición, va a hacer la asignación correspondiente para ingresar el nuevo estudiante.
-----------------------------------------------------------------------*/
void insertar_final(nodo_estudiante* nuevo);
/*-----------------------------------------------------------------------
	borrar_por_indice
	Entradas: Un indice de tipo entero.
	Salidas: No retorna nada, pero actualiza la lista borrando el elemento.
	Funcionamiento: 
		- Crea una variable temporal de tipo del struct y le asigna memoria utilizando malloc, luego la iguala a NULL.
		- Crea un contador de tipo entero igualado a 0.
		- Si la lista está vacía, imprimirá un mensaje de error ya que no se puede borrar ningún elemento.
		- Si no, compara el indice con la variable cantidad de la lista, si es mayor, retornará un mensaje
		  de error, ya que el índice no es válido.
		- Si el índice es válido, se creará otra variable temporal y se igualará al inicio de la lista.
		- Si el indice es igual a 0, se hará un free de temporal para borrar ese elemento y se le modificarán los datos de la lista
		- Si no, recorrerá la lista sumándole al índice hasta encontrar la posición correcta y hará el mismo procedimiento.
		-----------------------------------------------------------------------*/
void borrar_por_indice(int indice);
 /*-----------------------------------------------------------------------
	buscar_por_indice
	Entradas: Un índice de tipo entero.
	Salidas: Retorna una variable temporal, que se refiere al elemento que se estaba buscando.
	Funcionamiento: 
		- Crea una variable temporal y le asigna memoria, la iguala a NULL.
		- Si el inicio de la lista es igual a NULL o la cantidad de elementos es igual a 0, se imprimirá un mensaje
		  de error, diciendo que la lista está vacía y retornará temporal como NULL.
		- Si no, validará si el índice es mayor a la cantidad de elementos de la lista, si es así, imprimirá un mensaje de error.
		- Si no es así, iguala la variable temporal al inicio de la lista y empezará a buscar la posición correspondiente según
		  el índice hasta que el siguiente sea diferente de NULL.
		- Si lo encuentra, retornará temporal que contiene esa posición, si no, retornará temporal que contiene NULL.
-----------------------------------------------------------------------*/
nodo_estudiante* buscar_por_indice(int indice);

 /*-----------------------------------------------------------------------
	validar_carnets
	Entradas: Recibe el carnet en una posición solicitada y el carnet a comparar ingresado por el usuario, respectivamente.
	Salidas: No retorna nada.
	Funcionamiento: 
		- Si el carnet de la posición es igual al carnet ingresado por el usuario, se imprime un mensaje de correcto.
		- Si no es así, se imprimirá un mensaje de incorrecto.
-----------------------------------------------------------------------*/
void validar_carnets(int carnet_almacenado, int carnet_ingresado);
 /*-----------------------------------------------------------------------
	menu
	Entradas: Ninguna.
	Salidas: Ninguna.
	Funcionamiento: 
		- Se crea una variable max_size de tipo size_t, una opcion, indice y carnet de tipo entero y una variable temporal de tipo del struct.
		- Se imprimen las opciones posibles por medio de un do{} y se llama la función para obtener una entrada numérica del usuario, enviando
		  la variable max_size como 1, para que solo se pueda ingresar un número.
		- Se crea un switch() y las diferentes opciones.
		Caso 0:
			- Salir del programa
			- Se hará un break y se saldrá del programa
		Caso 1:
			- Agregar un estudiante al final
			- Se igual la variable temporal a la función crear_nodo() para crear un nuevo nodo.
			- Se llama la función insertar_final(temporal) con temporal como parámetro.
			- Se hace un break.

		Caso 2:
			- Agregar un estudiante al inicio
			- Se iguala la variable temporal a la función crear_nodo() para crear un nuevo nodo.
			- Se llama la función insertar_inicio(temporal) con temporal como parámetro.
			- Se hace un break.

		Caso 3:
			- Validar un carnet en una posición dada.
			- Se solicita la posición a validar y se almacena en índice.
			- Se llama la función buscar_por_indice(indice) con indice como parámetro, para verificar si esa posición existe.
			- Si es así, en esa función se guardará la información del estudiante en esa posición.
			- Se pregunta por el carnet del estudiante y se asigna a la variable carnet.
			- Se llama a la función validar_carnets(temporal->carnet,carnet) para validar el carnet ingresado por el usuario.
			- Se hace un break.

		Caso 4:
			- Borrar un estudiante en una posición dada.
			- Solicita la posición a borrar y la asigna a la variable indice.
			- Llama a la función borrar_por_indice(indice) con indice como parámetro.
			- Se hace un break.
-----------------------------------------------------------------------*/
void menu();
 /*-----------------------------------------------------------------------
	main
	Entradas: Ninguna.
	Salidas: Retorna 0.
	Funcionamiento: 
		- Sirve para ejecutar la función menu() del programa.
-----------------------------------------------------------------------*/
int main();
 /*-----------------------------------------------------------------------
	get_user_input
	Entradas: Un máximo, que se refiere a la cantidad maxima de caracteres que puede ingresar un usuario.
	Salidas: Retorna un buffer, que es el string que ingresó el usuario.
	Funcionamiento: 
		- Se crea una variable puntero de tipo char llamada buffer y una variable llamada characters de tipo size_t.
		- Se le asigna memoria mediante malloc al buffer. Dependiendo del tamaño máximo de caracteres que el usuario pueda ingresar
		  se crea el espacio para el buffer. Es decir, si el máximo es 30, se multiplica 30 por 1(ya que un tipo char, es de tamaño 1).
		- Si la memoria del buffer no se logra crear, es decir, es igual a NULL, se imprimirá un mensaje de error.
		- Si no es así, se hará un getline(&buffer,&max_size,stdin). La primera variable es donde se va a guardar lo que introduzca el usuario.
		  max_size se refiere al tamaño máximo de caracteres que va a poder ingresar ese usuario y stdin, se refiere a que es una entrada por consola.
		- Se le asigna a la última posición del buffer menos 1(strlen(buffer)-1) un cero, para hacer más eficiente el pedir entradas por consola. Ya que
		  esto le dice al compilador que esa es la última posición de todo el string y no tiene que recorrer espacios vacíos, en caso de que le tamaño
		  máximo sea 50 y solo se ingresen 2 caracteres.
		- Por último, retorna el buffer, que es la entrada que hizo el usuario.
-----------------------------------------------------------------------*/
char* get_user_input(size_t max_size);
 /*-----------------------------------------------------------------------
	get_user_numerical_input
	Entradas: Un máximo, que se refiere a la cantidad máxima de caracteres que puede ingresar un usuario.
	Salidas: Retorna le entrada del usuario.
	Funcionamiento: 
		- Crea una variable llamada numerical_input, que iguala a la función atoi(get_user_input(max_size)).
		  Esta función se encarga de transformar un tipo string en un tipo int.
		  Dentro de atoi() se le asigna como parámetro la función get_user_input, que va a solicitar una entrada del usuario.
		- Por último, retorna la entrada del usuario.
-----------------------------------------------------------------------*/
int get_user_numerical_input(size_t max_size);