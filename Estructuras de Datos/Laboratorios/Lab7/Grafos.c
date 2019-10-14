#include <stdio.h>
#include <stdlib.h>

// Struct para personas
typedef struct persona{
    char *nombre;
    struct persona *amigo;

}persona;

// Struct para nodos
typedef struct Nodo{
    persona persona;
    struct Nodo *siguiente;

}Nodo;

// Struct para conteneder nodos 
typedef struct lista_personas{
    Nodo *cabeza;
    int cantidad;

}lista_personas;

// Se encarga de crear un nodo y asignar los valores de persona
Nodo *crear_nodo(char *name){
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    
    nuevo->persona.nombre = name;
    nuevo->persona.amigo = NULL;
    nuevo->siguiente = NULL;

    return nuevo;
}

// Inserta un nodo en la lista de personas
void insertar_lista(lista_personas* lista, Nodo* nuevo_nodo){
    
    // Si la lista está vacía, lo igual a la cabeza
    if(lista->cabeza == NULL){
        lista->cabeza = nuevo_nodo;
        lista->cantidad = lista->cantidad+1;

    // Si no, busca el último elemento y lo coloca en esa posición
    }else{
        Nodo *puntero = lista->cabeza;

        while(puntero->siguiente){
            puntero = puntero->siguiente;

        }

        puntero->siguiente = nuevo_nodo;
        lista->cantidad = lista->cantidad+1;
    }
    
}

// Se encarga de crear una persona, esta función se utiliza cuando a la persona
// se le van a añadir amigos
persona *crear_persona(char *name){
    persona *nuevo = (persona *)malloc(sizeof(persona));
    nuevo->nombre = name;
    nuevo->amigo = NULL;
    
    return nuevo;
}

// Se encarga de añadir amigos a una persona en específico
// El puntero head es la persona a la que se le añadirá el puntero amigo.
Nodo *insertar_amigo(Nodo *head, persona *amigo){
    Nodo *temp = head;

    while(temp->persona.amigo != NULL){
        temp = temp->persona.amigo;

    }

    temp->persona.amigo = amigo;

    return temp;
}

// Se encarga de inicializar la lista por primera vez, cuando no hay elementos.
lista_personas *inicializar_lista(lista_personas *lista){

    lista = (lista_personas *)malloc(sizeof(lista_personas));
    lista->cabeza = NULL;
    lista->cantidad = 0;

    return lista;
}

// Imprime la lista de persona, incluyendo los respectivos amigos de cada persona.
void imprimir_grafo(lista_personas *lista){
    int contador = lista->cantidad; // Cantidad de personas de la lista
    Nodo *temp = lista->cabeza; // Se crea una variable temporal para moverse entre las personas
    Nodo *auxiliar = lista->cabeza; // Se crea una variable temporal para moverse entre los amigos de las personas

    // Si la cabeza es igual a NULL, significa que la lista está vacía
    if(lista->cabeza == NULL){
        printf("La lista está vacía.\n");

    // Si no, procederá a moverse
    }else{
        while(contador != 0){

            printf("%s: ",temp->persona.nombre); // Imprime el nombre de la persona actual

            // Si la persona no tiene amigos, se imprime un mensaje referente.
            if(auxiliar->persona.amigo == NULL){
                printf("No tiene amigos.");

            // Si no es el caso, se procederá a recorrer la lista de amigos de esa persona
            }else{

                // Mientras el puntero a amigo sea diferente de NULL, significa que hay amigos, por lo tanto imprime al amigo y se mueve
                while(auxiliar->persona.amigo != NULL){
                    /* Esta validación es por simple estética.
                       Si el ciclo está en el último amigo de la persona actual, imprime un punto
                       al final del nombre y se sale del ciclo.
                    */
                    if(auxiliar->persona.amigo->amigo == NULL){
                        printf("%s.", auxiliar->persona.amigo->nombre);
                        break;

                    // Si no es así, imprime una coma y se sigue moviendo
                    }else{
                        printf("%s, ", auxiliar->persona.amigo->nombre);
                        auxiliar = auxiliar->persona.amigo;

                    }


                }

            }
            // Mueve el temporal a la siguiente persona y mueve el auxiliar también
            printf("\n");
            contador--;
            auxiliar = temp->siguiente;
            temp = temp->siguiente;
            
        }

    }

}

// Función principal encargada de ejecutar las otras funciones.
int main(){
    
    // Se crea la lista y se inicializa
    lista_personas *lista = inicializar_lista(lista);

    Nodo *nuevo_nodo; // Este puntero sirve para crear personas como tal
    persona *nuevo_amigo; // Este puntero se utiliza cuando se quiera añadir amigos a una persona ya creada

    // Si la persona no tiene amigos, se realiza este proceso
    nuevo_nodo = crear_nodo("Luis");
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Steven");
    insertar_lista(lista, nuevo_nodo);


    /* Si la persona sí tiene amigos, se crea su nodo, se crea su amigo, se inserta y se añade a la lista.
       En caso de tener más de un amigo, la inserción a la lista_personas se realiza hasta que
       el último de los amigos haya sido insertado.
    */
    nuevo_nodo = crear_nodo("Raychell"); // Crea el nodo
    nuevo_amigo = crear_persona("Andrés"); // Crea un amigo
    insertar_amigo(nuevo_nodo, nuevo_amigo); // Inserta el amigo en el nodo creado

    nuevo_amigo = crear_persona("Saúl"); // Se repite el proceso sin crear un nuevo nodo
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Johan");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Te");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("María");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Pablo");
    insertar_amigo(nuevo_nodo,nuevo_amigo);
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("José Ale.");
    insertar_lista(lista, nuevo_nodo); // Y por último, se inserta en la lista de personas.

    nuevo_nodo = crear_nodo("María");
    nuevo_amigo = crear_persona("Steven");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Raychell");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Kevin C");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Te");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Randy");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Bryan");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Johan");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Andrés");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Marco");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Pablo");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Fernando");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Randall");
    insertar_amigo(nuevo_nodo, nuevo_amigo);
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Will");
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Armando");
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Kevin C");
    nuevo_amigo = crear_persona("Pablo");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Steven");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Te");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("María");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Fernando");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Marco");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Kevin Z");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Luis Diego");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Bryan");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Joseph");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Andrés");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Johan");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Randy");
    insertar_amigo(nuevo_nodo,nuevo_amigo);
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Te");
    nuevo_amigo = crear_persona("Raychell");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("María");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Randall");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Kevin Z");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Kevin C");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Randy");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Marco");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Steven");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Johan");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Pablo");
    insertar_amigo(nuevo_nodo,nuevo_amigo);
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Randy");
    nuevo_amigo = crear_persona("Kevin Z");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Randall");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Kevin C");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("María");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Te");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Saúl");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Marco");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Steven");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Johan");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Pablo");
    insertar_amigo(nuevo_nodo,nuevo_amigo);
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Bryan");
    nuevo_amigo = crear_persona("Kevin");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Randall");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Te");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Saúl");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Steven");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Johan");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Andrés");
    insertar_amigo(nuevo_nodo,nuevo_amigo);
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Alejandro");
    nuevo_amigo = crear_persona("Joseph");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Will");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Fernando");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Randall");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Raychell");
    insertar_amigo(nuevo_nodo,nuevo_amigo);
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Johan");
    nuevo_amigo = crear_persona("Kevin Z");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Randall");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Te");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("María");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Raychell");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Pablo");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Fernando");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Randy");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Kevin C");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Luis Diego");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Steven");
    insertar_amigo(nuevo_nodo,nuevo_amigo);
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Jose Ant.");
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Saúl");
    nuevo_amigo = crear_persona("Marco");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Te");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("María");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Raychell");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Pablo");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Randy");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Kevin Z");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("José");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Randall");
    insertar_amigo(nuevo_nodo,nuevo_amigo);
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Andrés");
    nuevo_amigo = crear_persona("Bryan");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Steven");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Raychell");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Kevin");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Te");
    insertar_amigo(nuevo_nodo,nuevo_amigo);
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Marco");
    nuevo_amigo = crear_persona("Kevin C");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("María");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Te");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Randall");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Kevin Z");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Saúl");
    insertar_amigo(nuevo_nodo,nuevo_amigo);
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Jeremy");
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("José Andrés");
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Pablo");
    nuevo_amigo = crear_persona("Kevin C");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Te");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Raychell");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("María");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Alejandro");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Johan");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Saúl");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Marco");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Fernando");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Joseph");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Randall");
    insertar_amigo(nuevo_nodo,nuevo_amigo);
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Luis Diego");
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Fernando");
    nuevo_amigo = crear_persona("Will");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("María");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Te");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Alejandro");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Johan");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Saúl");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Pablo");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Luis Diego");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Joseph");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Randall");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Kevin");
    insertar_amigo(nuevo_nodo,nuevo_amigo);
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Joseph");
    nuevo_amigo = crear_persona("Alejandro");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Johan");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Will");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Kevin C");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Randall");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Luis Diego");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Steven");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Raychell");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Fernando");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Saúl");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Te");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("María José");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Pablo");
    insertar_amigo(nuevo_nodo,nuevo_amigo);
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Kevin Z");
    nuevo_amigo = crear_persona("Randy");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Saúl");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Marco");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Randall");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Johan");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Raychell");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Steven");
    insertar_amigo(nuevo_nodo,nuevo_amigo);
    insertar_lista(lista, nuevo_nodo);

    nuevo_nodo = crear_nodo("Randall");
    nuevo_amigo = crear_persona("Marco");
    insertar_amigo(nuevo_nodo, nuevo_amigo);

    nuevo_amigo = crear_persona("Te");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Joseph");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Pablo");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Johan");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Alejandro");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Saúl");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Randy");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("Kevin Z");
    insertar_amigo(nuevo_nodo,nuevo_amigo);

    nuevo_amigo = crear_persona("María");
    insertar_amigo(nuevo_nodo,nuevo_amigo);
    insertar_lista(lista, nuevo_nodo);


    // Imprime la lista de personas con sus respectivos amigos
    imprimir_grafo(lista);

    return 0;
}