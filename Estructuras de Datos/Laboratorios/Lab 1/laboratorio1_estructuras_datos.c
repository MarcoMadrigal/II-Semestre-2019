// Nombre: Marco Antonio Madrigal Pérez 
// Carnet: 2019053902
// Estructuras de datos - Laboratorio I

#include <stdio.h>
#include <string.h>

// Struct de tipo estudiante, donde se encuentra el arreglo de tamaño 10 llamado estudiantes,
//  para guardar el nombre y carnet de los 10 estudiantes a ingresar.
struct estudiante{
    char nombre[30];
    char carnet[11];

}estudiantes[10];

// Función principal
int main(){

    // La variable contador se utiliza como un contador para saber la cantidad de estudiantes que se
    // han ingresado y poder terminar el ciclo.
    int contador = 0;

    // Ciclo encargado de preguntar y guardar el nombre y carnet de los 10 estudiantes.
    while (contador < 10){
        printf("\nIngrese el nombre del estudiante #%d:\n",contador);
        scanf("%s", estudiantes[contador].nombre);

        printf("\nIngrese el carnet del estudiante #%d:\n",contador);
        scanf("%s", estudiantes[contador].carnet);

        contador++;
    };
    // Variables para la posición a confirmar y el posible carnet de esa posición respectivamente.
    int posicion;
    char confirmar_carnet[11];

    // Solicita la posición y la guarda en la variable posicion.
    printf("\nQué posición de carnet desea validar?\n");
    scanf("%d",&posicion);

    // Solicita el posible carnet y lo guarda en la variable confirmar_carnet.
    printf("\n¿Cuál es el carnet del estudiante en la posición %d?\n",posicion);
    scanf("%s", confirmar_carnet);

    // Esta variable se encarga de guardar el valor retornado por la función strcmp(), que sirve
    // para comparar 2 strings.
    int comparador = strcmp(confirmar_carnet,estudiantes[posicion].carnet);

    // Si la variable comparador es igual a 0, significa que son iguales, de lo contrario, los
    // carnets son diferentes.
    if(comparador == 0){
        printf("\n¡El carnet ingresado es el correcto!\n");

    }else{
        printf("\n¡El carnet ingresado no corresponde con la posición %d!\n",posicion);
    }
    
    return 0;
}
