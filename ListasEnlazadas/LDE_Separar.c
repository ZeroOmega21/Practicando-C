#include <stdio.h>
#include <stdlib.h>

//defino el nodo
typedef struct Nodo{
    char *nombre;
    struct Nodo *next;
    struct Nodo *prev;
}nodo;

//crear el nodo
nodo* CrearNodo(char *dato[]){
    nodo *newnodo = malloc(sizeof(nodo));
    if (newnodo == NULL){
        exit(1);
    }
    else{
        newnodo -> nombre = dato;
        newnodo -> next = NULL;
        newnodo -> prev = NULL;
    }
    return newnodo;
}

//funcion para separar la lista


int main (){
    nodo *string_nodo = CrearNodo("Mi nombre es *nombre*");
    printf("Lista original: %s\n", string_nodo -> nombre);

    return 0;
}
