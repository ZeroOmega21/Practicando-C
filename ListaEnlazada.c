#include <stdio.h>
#include <stdlib.h>

int elemento[] = {1,2,3,4,5,6,7,8,9,10};

//defino el nodo
typedef struct Nodo{
    int elemento;
    struct Nodo *next, *prev;
}Nodo;

//crear el Nodo
Nodo* CrearNodo(int elemento)
{
    struct Nodo *newNodo = malloc(sizeof(Nodo));
    if (newNodo == NULL){
        exit(1);
    }
    else{
        newNodo -> elemento;
        newNodo -> next = NULL;
        newNodo -> prev = NULL;
    }
    return newNodo;
}

void enlazarNodo(struct Nodo **head, struct Nodo *newNodo){
    Nodo *clonHead = *head;//clonamos la cabeza para no perderla
    if (*head == NULL){
        *head = newNodo;//si la lista esta vacia, el nuevo Nodo sera la cabeza
    }
    else{
        while(clonHead != NULL){
            if (newNodo -> next == NULL){
                newNodo -> next = clonHead;
                newNodo -> next -> prev = newNodo;
                newNodo = clonHead ;
            }
            clonHead = clonHead -> next;
    }
}
}

//metodo para imprimir la lista del nodo
void imprimirLista(Nodo *lista){
    Nodo *clonHead = lista;
    while(lista != NULL){
        printf("%d \n", lista -> elemento);
        lista = lista -> next;
    }
    printf("\n");
}


int main(){
    Nodo *head = NULL;
    for (int i = 0; i < 10; i++){
        Nodo *newNodo = CrearNodo(elemento[i]);
        enlazarNodo(&head, newNodo);
    }
    imprimirLista(head);
    return 0;
}