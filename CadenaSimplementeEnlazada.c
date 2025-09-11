#include <stdio.h>
#include <stdlib.h>

typedef struct mnodo{
    int valor;
    struct mnodo *next;
}Nodo;

void agregar_nodo(Nodo **headref, int dato){
    Nodo *newnodo = malloc(sizeof(Nodo));
    if (newnodo){
        newnodo -> valor = dato;
        newnodo -> next = *headref;
        *headref = newnodo;
    }
}
void imprimir(Nodo *lista){
    while(lista != NULL){
        printf("%d->", lista -> valor);
        lista = lista -> next;
    }
    printf("NULL \n");
}

int main(void){
    int lista[] = {10,9,8,7,6,5,4,3,2,1};
    Nodo *headref = NULL;
    for (int i = 0; i<10; i++){
        agregar_nodo(&headref, lista[i]);
    }
    imprimir(headref);
}
