#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *next;
    struct nodo *prev;
}nodo;
// Recibe un puntero a un puntero a 'head' para poder modificar la cabeza de la lista
// si esta está vacía, y el valor que se guardará en el nuevo nodo.
void push(nodo **headref, int valor){
    // 1. Asignar memoria para el nuevo nodo.
    nodo *newnode = malloc(sizeof(nodo));
    // 2. Asignar los valores del nuevo nodo.
    newnode->dato = valor;
    newnode->next = NULL; // El nuevo nodo siempre se agrega al final, así que su siguiente es NULL.
    newnode->prev = NULL; // Inicialmente, su anterior es NULL.
    if (*headref == NULL){
        // Si la lista está vacía, el nuevo nodo se convierte en la cabeza de la lista.
        *headref = newnode;
    }else{
        // Si la lista ya tiene elementos, recorremos la lista para encontrar el último nodo.
        nodo *temp = *headref;
        while(temp->next != NULL){// El bucle continúa mientras el siguiente nodo no sea NULL.
            temp = temp->next;
        }
        // Cuando el bucle termina, 'temp' es el último nodo de la lista.
        temp->next = newnode;// 4. Enlazar el nuevo nodo al final de la lista.
        newnode->prev = temp; // 5. Enlazar el puntero 'prev' del nuevo nodo al último nodo anterior.
    }
}
// Función para imprimir los elementos de la lista enlazada.
// Recibe la cabeza de la lista como un puntero.
void imprime(nodo *head){
    // Recorremos la lista desde la cabeza hasta que el puntero sea NULL.
    while(head != NULL){
        // Imprimimos el valor del nodo actual.
        printf("%d->", head->dato);
        // Nos movemos al siguiente nodo.
        head = head->next;
    }
    // Una vez que el bucle termina, la lista se ha recorrido por completo.
    // Imprimimos "NULL" para indicar el final de la lista.
    printf("NULL \n");
}

// Función principal del programa.
int main (void){
    // Array de enteros que usaremos para llenar las listas.
    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8};

    // Declaración y inicialización de las dos cabezas de las listas enlazadas a NULL.
    // Esto indica que las listas están vacías al principio.
    nodo *lista1 = NULL;
    nodo *lista2 = NULL;
    
    int i;
    
    // Bucle para agregar los primeros 4 números (1, 2, 3, 4) a lista1.
    for (i = 0; i < 4; i++){
        push(&lista1, numeros[i]);
    }
    
    // Bucle para agregar los siguientes 4 números (5, 6, 7, 8) a lista2.
    for (i = 4; i < 8; i++){
        push(&lista2, numeros[i]);
    }
    
    // Imprimimos las dos listas para verificar que se crearon correctamente.
    printf("Lista 1: ");
    imprime(lista1);
    
    printf("Lista 2: ");
    imprime(lista2);
    
    return 0; // El programa termina con éxito.
}
