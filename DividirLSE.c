#include <stdio.h>
#include <stdlib.h>

typedef struct mnodo{
    int valor;
    struct mnodo *next;
}Nodo;

void agregar_nodo(Nodo **headref, int dato){
    Nodo *newnodo = malloc(sizeof(Nodo));
    newnodo->valor = dato;
    newnodo->next = NULL;
    if (*headref == NULL){
        *headref = newnodo;    
    }else{
        Nodo *temp = *headref;
        while (temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next = newnodo;
    }
}
void imprimir(Nodo *lista){
    while(lista != NULL){
        printf("%d->", lista -> valor);
        lista = lista -> next;
    }
    printf("NULL \n");
}

void ubicarDividir(int split, Nodo *lista, Nodo **lista1, Nodo **lista2){   
    *lista1 = NULL;
    *lista2 = NULL;
    Nodo *recorrido = lista;
    while(recorrido != NULL){
    if (recorrido->valor >= split){
        agregar_nodo(lista1, recorrido->valor);
    }else{
        agregar_nodo(lista2, recorrido->valor);
    }
    recorrido = recorrido ->next;
    }
}

int main(void){
    //NODOS
    Nodo *headref = NULL;
    Nodo *lista1 = NULL;
    Nodo *lista2 = NULL;

    int lista[] = {10,9,8,7,6,5,4,3,2,1};
    for (int i = 0; i<10; i++){
        agregar_nodo(&headref, lista[i]);
    }
    printf("Lista Original: ");
    imprimir(headref);

    ubicarDividir(6, headref, &lista1, &lista2);
    printf("Lista 1:    "); imprimir(lista1);
    printf("Lista 2:    "); imprimir(lista2);
}
