/* 
   Nombre: Marco Madrigal Pérez
   Carnet: 2019053902
   Estructuras de Datos Laboratorio III
 */
// Librerías utilizadas en el programa.
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define true 1
#define false 0

// Estructura de tipo estudiante, donde se encuentran los datos de los estudiantes.
typedef struct nodo{
    int carnet;
    char *nombre;
    struct nodo *siguiente;
}estudiante;

// Función para inicializar la lista como una lista vacía.
estudiante *iniciar_lista(estudiante *lista){
    lista = NULL;
    return lista;
}

// Función para agregar estudiantes a la lista
estudiante *agregar_estudiante(estudiante *lista, char *nombre, int carnet,int bandera){

    estudiante *nuevo_nodo, *auxiliar;
    nuevo_nodo = (estudiante *)malloc(sizeof(estudiante));
    if(nuevo_nodo != NULL){
            if(bandera == true){ // Cuando es true, va a almacenar un estudiante al final de la lista.
            nuevo_nodo->nombre = nombre;
            nuevo_nodo->carnet = carnet;
            nuevo_nodo->siguiente = NULL;

            if(lista == NULL){ // Si la lista está vacía, se iguala a la lista.
                lista = nuevo_nodo;
                
            }else{
                // Si la lista no está vacía, se busca la última posición y se agrega.
                auxiliar = lista;
                while(auxiliar->siguiente != NULL){

                    auxiliar = auxiliar->siguiente;
                }

                auxiliar->siguiente = nuevo_nodo;
                
            }
        }else{// Cuando es false, va a almacenar un estudiante al inicio de la lista.
            if(lista == NULL){ // Si la lista está vacía, se igual a la lista.
                nuevo_nodo->nombre = nombre;
                nuevo_nodo->carnet = carnet;
                nuevo_nodo->siguiente = NULL;
                lista = nuevo_nodo;

            }else{ // Si no, see añade al inicio inmediatamente.
            nuevo_nodo->nombre = nombre;
            nuevo_nodo->carnet = carnet;
            nuevo_nodo->siguiente = lista;
            lista = nuevo_nodo;
            }

        }


    }else{ // Cuando la memoria esté llena imprimirá este mensaje de error.
        printf("La memoria está llena");
    }
    return lista;
}

// Función para eliminar un estudiante de la lista según su posición.
estudiante *eliminar_estudiante(estudiante *lista,int posicion,int largo_lista){
    estudiante *temporal;
    int indice = 0;
    temporal = lista;

    if (lista != NULL){ // Cuando la lista no esté vacía entrará.

        if (posicion == 0){ //Si es igual a 0, va a borrar el primer elemento de la lista
            estudiante *temporal;
            temporal = lista;
            lista = lista->siguiente;
            free(temporal);

        // Si es igual a la última posición de la lista, va a borrar el último elemento de la lista.
        }else if(posicion == largo_lista-1){
            // Este ciclo se encarga de encontrar el último.
            if(temporal->siguiente != NULL){
                while((temporal->siguiente)->siguiente != NULL){
                    temporal = temporal->siguiente;
                }
                free(temporal->siguiente); // Libera la memoria.
                temporal->siguiente = NULL;

            }else{ // Si resultara que la lista solo tiene un elemento, será igual a vacía.
                lista = NULL;

            }

        }else{ // Este else borrará un elemento que no sea el último ni el primero.
            while((indice+1) != posicion){
                indice++;
                temporal = temporal->siguiente;
            }
            free(temporal->siguiente); // Libera la memoria
            temporal->siguiente = (temporal->siguiente)->siguiente;
        }


    }else{
        // Si la lista no tiene elementos, imprimirá este mensaje de error.
        printf("\nLa lista está vacía\n");
    }


    return lista;
}

// Función para verificar el carnet de un estudiante según su posición.
estudiante verificar_estudiante(estudiante *lista, int carnet_verificar,int posicion_validar){
    estudiante *temporal;
    temporal = lista;
    int contador = 0;

    // Con este ciclo se llega hasta la posición deseada.
    while(contador < posicion_validar){
        contador++;
        temporal = temporal->siguiente;

    }
    if (temporal->carnet == carnet_verificar){
        printf("\nEs el carnet correcto\n");
    }else{
        printf("Es el carnet incorrecto\n");
    }
    
}


// Función para imprimir el menú principal.
void imprimirMenu(int cantidad){
    printf("\n\t\tMenú principal\n");
    printf("\tCantidad de estudiantes ingresados: %d\n",cantidad);
    printf("\n1. Insertar un estudiante al final de la lista");
    printf("\n2. Insertar un estudiante al inicio de la lista");
    printf("\n3. Verificar el carnet de un estudiante según posición");
    printf("\n4. Eliminar de la lista a un estudiante según posición");
    printf("\n5. Salir del programa\n");

}

int main(){
    int opcion,posicion,carnet,carnet_verificar;
    int estado = 1;
    int largo_lista = 0;
    char nombre[30];

    // Se inicia la lista
    estudiante *lista = iniciar_lista(lista);

    // Ciclo encargado de la repetición del programa
    while(estado == true){
        
        imprimirMenu(largo_lista);

        printf("\nIngrese la opción que desea realizar: ");
        scanf("%d",&opcion);
        
        if(opcion == 1){ // Ingresar un estudiante al final de la lista.

            printf("\nIngrese el nombre del estudiante: ");
            scanf("%s",nombre);

            printf("\nIngrese el carnet del estudiante: ");
            scanf("%d",&carnet);

            lista = agregar_estudiante(lista,nombre,carnet,true);
            largo_lista++; 
        }
        else if(opcion == 2){ // Ingresar un estudiante al inicio de la lista.

            printf("\nIngrese el nombre del estudiante: ");
            scanf("%s",nombre);

            printf("\nIngrese el carnet del estudiante: ");
            scanf("%d",&carnet);

            lista = agregar_estudiante(lista,nombre,carnet,false);
            largo_lista++;
        }
        else if(opcion == 3){ // Verificar el carnet de un estudiante.

            printf("\n¿Cuál posición desea validar?\n");
            scanf("%d",&posicion);

            // Comprueba si la posición ingresada es válida.
            if (posicion < largo_lista && posicion >= 0){
                printf("\n¿Cuál es el carnet del estudiante?\n");
                scanf("%d",&carnet_verificar);

                verificar_estudiante(lista, carnet_verificar, posicion);

            }else{
                printf("\nLa posición solicitada no es válida\n");
            }

        }
        else if(opcion == 4){ // Eliminar un estudiante de la lista.

            printf("\n¿Cuál posición de la lista desea eliminar?\n");
            scanf("%d",&posicion);

            // Comprueba si la posición ingresada es válida.
            if(posicion < largo_lista && posicion >= 0){
                lista = eliminar_estudiante(lista,posicion,largo_lista);
                largo_lista--;

            }else{
                printf("\nLa posición solicitada no es válida\n");

            }
 
        }
        else if(opcion == 5){ // Salir del programa
            estado = false;
        }
        else{ // En caso de que se ingrese un número mayor o menor, se imprimirá este mensaje.
            printf("\nSolamente puede elegir un número entre 1 y 5\n");
        }
    }

    return 0;
}
