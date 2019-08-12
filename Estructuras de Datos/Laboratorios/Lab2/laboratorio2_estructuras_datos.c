// Nombre: Marco Antonio Madrigal Pérez 
// Carnet: 2019053902
// Estructuras de datos - Laboratorio II

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Se define la lista y la composición de los nodos de la lista.
typedef struct nodo{
    int carnet;
    char* nombre;
    struct nodo *siguiente;

    }estudiantes;

// Se inicializa la lista como una elemento nulo.
estudiantes *lista_estudiantes(estudiantes *lista){
    lista = NULL;
    return lista;
}

/* Esta función sirve para agregar estudiantes a la lista, recibe la lista actual, el nombre y el carnet del nuevo
estudiante. */
estudiantes *agregar_estudiante(estudiantes *lista, int carnet_inicial, char *nombre_estudiante){
    
    estudiantes *nuevo_estudiante, *auxiliar;

    nuevo_estudiante = (estudiantes*)malloc(sizeof(estudiantes));
    if(nuevo_estudiante != NULL){

        nuevo_estudiante->carnet = carnet_inicial;
        nuevo_estudiante->nombre = nombre_estudiante;
        nuevo_estudiante->siguiente = NULL;

        if (lista == NULL){
        lista = nuevo_estudiante;

        }else{
            auxiliar = lista;
        
            while (auxiliar->siguiente != NULL){
                auxiliar = auxiliar->siguiente;

            }
            auxiliar->siguiente = nuevo_estudiante;
        }
    }else{
        printf("No se pueden almacenar más estudiantes\n"); // Mensaje de error por si la cantidad supera la memoria.
        }
    return lista;
    }

// Función encargada de verificar el carnet del estudiante.
estudiantes verificar_estudiantes(estudiantes *lista, int carnet_verificar){
    estudiantes *aux;
    aux = lista;

    if(aux->carnet == carnet_verificar){
        printf("Es el carnet correcto");
    }else{

    while((aux->siguiente)->carnet != carnet_verificar){
        aux = aux->siguiente;
        if(aux->siguiente == NULL){
            printf("El carnet no es el correcto");
        }else{
            continue;
        }
    }
    printf("El carnet es el correcto");

    }

}

// Función principal del código.
int main(){
    int cantidad_estudiantes; // Cantidad de estudiantes a ingresar.
    int posicion_validar; // La posición a validar por parte del usuario.
    int carnet_verificar; // El carnet que el usuario va a querer verificar.

    // Se llama a la función y se inicializa la lista vacía.
    estudiantes *lista = lista_estudiantes(lista);

    printf("¿Cuántos estudiantes desea ingresar?");
    scanf("%d",&cantidad_estudiantes);

    // Ciclo para almacenar la cantidad de estudiantes deseados.
    while(cantidad_estudiantes != 0){
        int carnet_inicial;
        char nombre_estudiante[20];

        printf("\nIngrese el nombre del estudiante\n");
        scanf("%s", nombre_estudiante);

        printf("\nIngrese el carnet del estudiante\n");
        scanf("%d", &carnet_inicial);
        
        lista = agregar_estudiante(lista, carnet_inicial, nombre_estudiante);
        cantidad_estudiantes -= 1;
    }
    

    printf("¿Qué posición desea validar?\n");
    scanf("%d",&posicion_validar);

    printf("¿Cuál cree que sea el carnet del estudiante en la posición %d?\n",posicion_validar);
    scanf("%d",&carnet_verificar);

    /* Se llama a la función verificar_estudiantes para verificar el carnet del estudiante
     que el usuario desea.*/
    verificar_estudiantes(lista,carnet_verificar);

    return 0;

}
