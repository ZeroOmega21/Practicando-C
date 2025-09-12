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

void ImprimirListaInvertida(Nodo *lista) {
    if (lista == NULL) {
        printf("NULL\n");
        return;
    }
    // Moverse al final de la lista
    Nodo *temp = lista;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // Imprimir la lista en orden inverso
    while (temp != NULL) {
        printf("%d->", temp->elemento);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void insertarOrdenado(Nodo** lista) {
    if (lista == NULL){
        printf("La lista esta vacia\n");
        return;
    }
    Nodo *ultimo = *lista;
    while (ultimo->next != NULL){
        ultimo = ultimo->next;
    }
    while (ultimo != NULL)
    {
        printf("%d->", ultimo->elemento);
        ultimo = ultimo->prev;
    }
}

int main(){
    int elementos[] = {1,2,3,6,4,5,7,8,9,10};
    Nodo *head = NULL;
    for (int i = 0; i < 10; i++){
        Nodo *newNodo = CrearNodo(elementos[i]);
        enlazarNodo(&head, newNodo);
    }
    printf("Lista en original: ");
    imprimirLista(head);

    printf("Lista en reversa: ");
    ImprimirListaInvertida(head);
}