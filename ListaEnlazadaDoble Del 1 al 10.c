#include <stdio.h>
#include <stdlib.h>

//defino el nodo
typedef struct Nodo{
    int elemento;
    struct Nodo *next, *prev;
}Nodo;

//crear el Nodo
Nodo* CrearNodo(int elemento){
    Nodo *newNodo = malloc(sizeof(Nodo));
    if (newNodo == NULL){
        exit(1);
    }
    else{
        newNodo -> elemento = elemento;//asigno el elemento
        newNodo -> next = NULL;//inicializo los punteros
        newNodo -> prev = NULL;//inicializo los punteros
    }
    return newNodo;
}

void enlazarNodo(struct Nodo **head, struct Nodo *newNodo){
    if (*head == NULL){
        *head = newNodo;//si la lista esta vacia, el nuevo Nodo sera la cabeza
    } else {
        // Creamos un puntero temporal para recorrer la lista
        Nodo *temp = *head; // Corregido: asignamos *head a temp
        // Recorremos la lista hasta encontrar el último nodo
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Enlazamos el nuevo nodo al final
        temp->next = newNodo;
        newNodo->prev = temp;
    }
}

//metodo para imprimir la lista del nodo
void imprimirLista(Nodo *lista){
    while(lista != NULL){
        printf("%d->", lista -> elemento);
        lista = lista -> next;
    }
    printf("NULL \n");
}


int main(){
    int elementos[] = {1,2,3,4,5,6,7,8,9,10};
    Nodo *head = NULL;
    for (int i = 0; i < 10; i++){
        Nodo *newNodo = CrearNodo(elementos[i]);
        enlazarNodo(&head, newNodo);
    }
    imprimirLista(head);
    return 0;
}