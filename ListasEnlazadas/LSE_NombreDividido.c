#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mnodo{
    char valor;
    struct mnodo *next;
}Nodo;

void agregar_nodo(Nodo **headref, char dato){
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
        printf("%c", lista -> valor);
        lista = lista -> next;
    }
    printf("->NULL \n");
}

void ubicarDividir(int split, Nodo *lista, Nodo **lista1, Nodo **lista2){   
    *lista1 = NULL;
    *lista2 = NULL;
    Nodo *recorrido = lista;
    int contador = 0;

    while(recorrido != NULL){
        contador++;
    if (contador <= split){
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
    
    char lista[] = {"Mi nombre es Zero"};
    int len = strlen(lista);//logitud del arreglo
    for (int i = 0; i<len; i++){
        agregar_nodo(&headref, lista[i]);
    }
    printf("Lista Original: ");
    imprimir(headref);

    ubicarDividir(10, headref, &lista1, &lista2);
    printf("Lista 1:    "); imprimir(lista1);
    printf("Lista 2:    "); imprimir(lista2);
}