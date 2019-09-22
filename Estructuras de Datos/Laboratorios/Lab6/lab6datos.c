#include <stdio.h>
#include <stdlib.h>

// Se define el struct para el árbol binario.
typedef struct nodo{

    int dato;
    struct nodo *padre;
    struct nodo *izquierdo;
    struct nodo *derecho;

}arbolito;

// Funciones a implementar
arbolito *crear_nodo(arbolito *padre, int dato);
void agregar_nodo(arbolito *arbol, int valor);
void post_orden(arbolito *arbol);

// Función principal
int main(){
    arbolito *arbol;

    // Se agregan nodos alambradamente
    arbol = crear_nodo(NULL, 40);
    agregar_nodo(arbol, 10);
    agregar_nodo(arbol, 50);
    agregar_nodo(arbol, 1);
    agregar_nodo(arbol, 13);
    agregar_nodo(arbol, 15);

    // Se llama a la función para imprimir en post_orden el árbol completo
    post_orden(arbol);
    printf("\n");
    
    return 0;
}

// Función para crear un nodo, retorna el nodo creado
arbolito *crear_nodo(arbolito *padre, int dato){

    arbolito *nuevo_nodo = (arbolito *)malloc(sizeof(arbolito));

    nuevo_nodo->padre = padre;
    nuevo_nodo->dato = dato;
    return nuevo_nodo;

}

// Función para agregar un nodo al árbol, no retorna nada
void agregar_nodo(arbolito *arbol, int valor){
    arbolito *temporal, *pivote;
    int direccion = 0; 
    // Si dirección es 0, el lado elegido es el izquierdo
    // Si direccion es 1, el lado elegido es el derecho

    if(arbol != NULL){

        temporal = arbol;

        while(temporal != NULL){
            pivote = temporal;
            if(valor > temporal->dato){

                // Se mueve al lado derecho
                temporal = temporal->derecho;
                direccion = 1;

            }else{

                // Se mueve al lado izquierdo
                temporal = temporal->izquierdo;
                direccion = 0;
            }

        }

        // Se crea un nuevo nodo para el valor por ingresar
        temporal = crear_nodo(pivote, valor);

        if(direccion == 1){ // Inserta al lado derecho el nuevo nodo.
            pivote->derecho = temporal;
            

        }else{ // Inserta al lado izquierdo el nuevo nodo.
            pivote->izquierdo = temporal;

        }

    }else{
        printf("El árbol no está inicializado");

    }
}

// Función para imprimir el lado en post orden
void post_orden(arbolito *arbol){
    if(arbol == NULL){
        return;

    }else{
        post_orden(arbol->izquierdo); // Imprime todo el lado izquierdo
        post_orden(arbol->derecho); // Imprime todo el lado derecho
        printf(" %d  ", arbol->dato); // Imprime la raíz

    }
    
}