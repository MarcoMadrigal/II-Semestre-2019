"""
    Instituto Tecnológico de Costa Rica
    Estructuras de Datos IC-2001
    II Semestre 2019
    Profesora: Samanta Ramijan Carmiol

    Laboratorio 8 | Repaso de Python
    Estudiante: Marco Madrigal Pérez
    Carnet: 2019053902
"""


# Clase encargada de la creación de un nodo
class nodo:
    
    """
    Método: __init__()
    Entradas: Ninguna
    Salidas: Ninguna
    Funcionamiento:
        -Constructor de la clase con valor igual a NULL y siguiente igual a NULL
    """

    def __init__(self, valor = None, siguiente = None):

        self.valor = valor
        self.siguiente = siguiente

    """
    Método: actualizar_valor()
    Entradas: Recibe como parámetro un valor
    Salidas: Ninguna
    Funcionamiento:
        -Iguala el valor entrante al valor del nodo actual
    """

    def actualizar_valor(self, valor):
        self.valor = valor

    """
    Método: actualizar_siguiente()
    Entradas: Recibe como parámetros un nodo
    Salidas: Ninguna
    Funcionamiento:
        -Iguala el nodo entrante como siguiente del nodo actual
    """

    def actualizar_siguiente(self, nodo_siguiente):
        self.siguiente = nodo_siguiente


# Clase encargada de la unión de los nodos en una lista enlazada simple
class lista_enlazada:

    """
    Método: __init__()
    Entradas: Ninguna
    Salidas: Ninguna
    Funcionamiento:
        -Constructor de la clase lista_enlazada
    """
    def __init__(self):

        self.head = None

    """
    Método: agregar_inicio
    Entradas: Recibe como parámetro un valor
    Salidas: Ninguna
    Funcionamiento:
        -Crea un nodo con valor como parámetros y lo iguala a una variable temporal
        -Asigna como su siguiente la cabeza actual de la lista
        -Actualiza la cabeza, siendo ahora el nodo temporal creado
        -Por último, libera el nodo temporal
    """
    def agregar_inicio(self, valor):

        temp = nodo(valor)

        temp.siguiente = self.head

        self.head = temp

        del temp

    """
    Método: agregar_final()
    Entradas: Recibe como parámetro un valor
    Salidas: Ninguna
    Funcionamiento:
        -Crea una variable temporal y se iguala a la cabeza actual de la lista
        -Crea una variable para guardar el nodo creado enviando valor como parámetro
        -Recorre la lista con ayuda de un ciclo, mientras el siguiente nodo sea diferente de NULL
        -Cuando encuentra el NULL, para e iguala el siguiente al nodo creado anteriormente
    """
    def agregar_final(self, valor):
        temp = self.head
        nuevo_nodo = nodo(valor)

        while(temp.siguiente != None):
            temp = temp.siguiente
        
        temp.siguiente = nuevo_nodo

    """
    Método: imprimir_lista()
    Entradas: Ninguna
    Salidas: Ninguna
    Funcionamiento:
        -Crea una variable temporal y se iguala a la cabeza actual
        -Si la lista no está vacía, es decir, es diferente de NULL, comenzará a recorrerla con ayuda
         de un ciclo e imprimirá en pantalla los datos de los nodos
        -Si la lista estuviera vacía, imprimirá un mensaje en pantalla indicándole al usuario que se encuentra vacía
    """
    def imprimir_lista(self):
        temp = self.head

        if(temp != None):
            while(temp != None):
                
                print(temp.valor)

                temp = temp.siguiente

        else:
            print("\nLista vacía")

    """
    Método: tamanno_lista()
    Entradas: Ninguna
    Salidas: Variable int contador con la cantidad de elementos de la lista
    Funcionamiento:
        -Crea una variable contador y la iguala a 0
        -Crea una variable temporal y la iguala a la cabeza actual de la lista
        -Recorre la lista con ayuda de un ciclo mientras sea diferente de NULL
        -Aumenta el contador en 1 cada iteración
    """
    def tamanno_lista(self):
        contador = 0
        temp = self.head

        while(temp != None):
            temp = temp.siguiente
            contador += 1

        return contador

    """
    Método: buscar_indice()
    Entradas: Recibe como parámetro un int índice
    Salidas: Retorna el nodo encontrado
    Funcionamiento:
        -Crea una variable temporal y la iguala la cabeza actual de la lista
        -Crea una variable int contador y la iguala a 0
        -Si el índice ingresado es menor al tamaño de la lista y mayor a 0, recorrerá la lista hasta retornar el nodo
        -Si no es así, imprimirá un mensaje en pantalla diciéndolo
    """
    def buscar_indice(self, indice):
        temp = self.head
        contador = 0
        
        if indice < lista_enlazada.tamanno_lista(self) and indice < 0:

            while(contador != indice):
                
                temp = temp.siguiente
                contador += 1

            return temp

        else:
            print("Indice inválido")

    """
    Método: reiniciar_lista()
    Entradas: Ninguna
    Salidas: Ninguna
    Funcionamiento:
        -Crea una variable temporal y la iguala a la cabeza actual de la lista
        -Actualiza la cabeza con el siguiente nodo de ella misma
        -Recorre la lista con ayuda de un ciclo mientras sea diferente de NULL
        -Borra la cabeza contenida en la variable temporal
        -Actualiza la variable temporal con la nueva cabeza
        -Actualiza la cabeza con el siguiente nodo de ella misma
        -Cuando termina de recorrer el ciclo, borra la cabeza actual, la iguala a 
         NULL e imprime un mensaje en pantalla
    """
    def reiniciar_lista(self):
        
        temp = self.head
        self.head = self.head.siguiente

        while(self.head != None):
            del temp
            temp = self.head
            self.head = self.head.siguiente

        del self.head
        self.head = None
        print("Lista reiniciada exitosamente")

    """
    Método: revertir()
    Entradas: Ninguna
    Salidas: Ninguna
    Funcionamiento:
        -Crea una variable anterior igual a NULL
        -Crea un pivote igualado a la cabeza actual de la lista
        -Recorre la lista con ayuda de un ciclo mientras sea diferente de NULL
        -Indica que el siguiente es igual al nodo siguiente de la cabeza actual
        -Le asigna el anterior al siguiente de la cabeza actual
        -Actualiza el anterior con la cabeza actual
        -Actualiza el indice con el siguiente
        -Por último, actualiza la cabeza igualándola a la variable anterior creada anteriormente
    """
    def revertir(self):
        anterior = None
        indice = self.head
        
        while(indice is not None):
            next = indice.siguiente
            indice.siguiente = anterior
            anterior = indice
            indice = next
        
        self.head = anterior


"""
Función: main()
Entradas: Ninguna
Salidas: Ninguna
Funcionamiento:
    -Se encarga del flujo principal del programa
"""
def main():


    miLista = lista_enlazada()
    estado = True
    while(estado):
        print("\nMenú Principal")
        print("0. Salir del programa")
        print("1. Agregar un nodo al inicio")
        print("2. Agregar un nodo al final")
        print("3. Imprimir el contenido de la lista")
        print("4. Tamaño de la lista")
        print("5. Buscar un nodo por índice")
        print("6. Reiniciar la lista")
        print("7. Revertir la lista")

        opcion = int(input("\nElija una opción: "))
        if opcion == 1:
            valor = input("\nIngrese un valor: ")
            miLista.agregar_inicio(valor)

        elif opcion == 2:
            valor = input("\nIngrese un valor: ")
            miLista.agregar_final(valor)

        elif opcion == 3:
            miLista.imprimir_lista()
        
        elif opcion == 4:
            print("\nEl tamaño de la lista es: ", miLista.tamanno_lista())

        elif opcion == 5:
            valor = input("\nIngrese el valor a buscar: ")
            buscar_valor = miLista.buscar_indice(valor)
            
            if buscar_valor != None:
                print("\nEl valor es: ", buscar_valor.valor)
            else:
                print()
        
        elif opcion == 6:
            miLista.reiniciar_lista()
            print()

        elif opcion == 7:
            miLista.revertir()
            print("\nLista revertida exitosamente")
        
        else:
            estado = False
    return

# Ejecuta la función principal inmediatamente después de ejecutar el código
print(main())


