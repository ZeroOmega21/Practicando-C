#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo* next;
} Nodo;

// Función para dividir lista en dos listas según split
void ubicarDividirAsc(int split, Nodo* lista, Nodo** listaA, Nodo** listaB) {
    Nodo *actual = lista, *prev = NULL;

    *listaA = lista;
    *listaB = NULL;

    // Buscar el nodo con el split o el primer nodo mayor
    while (actual != NULL && actual->valor < split) {
        prev = actual;
        actual = actual->next;
    }

    // Si la lista está vacía no hay nada realizar la division
    if (lista == NULL) {
        *listaA = NULL;
        *listaB = NULL;
        return;
    }

    // Cortar la lista en la posición encontrada
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        *listaA = NULL;
    }

    *listaB = actual; //segunda lista comienza en split o en el primer Nodo mayor

    // Contar elementos
    int countA = 0, countB = 0;
    Nodo* temp;
    for (temp = *listaA; temp != NULL; temp = temp->next) countA++;
    for (temp = *listaB; temp != NULL; temp = temp->next) countB++;

    //Buscar la lista con mayor valores que sera el split
   
    if (countA > countB && actual != NULL) {
        if (prev != NULL) {
            prev->next = actual;      
            *listaB = actual->next;  
            actual->next = NULL;      
        } else {
            *listaA = actual;        
            *listaB = actual->next;
            actual->next = NULL;
        }
    }

    // Solo si sale empate
    if (countA == countB && actual != NULL) {
        if (prev != NULL) {
            prev->next = actual;
            *listaB = actual->next;
            actual->next = NULL;
        } else {
            *listaA = actual;
            *listaB = actual->next;
            actual->next = NULL;
        }
    }
}

//Creacion del Nodo y auxiliares para modificarlo

Nodo* crearNodo(int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->valor = valor;
    nuevo->next = NULL;
    return nuevo;
}

    //Ordenarlo de manera asc
void insertarOrdenado(Nodo** lista, int valor) {
    Nodo* nuevo = crearNodo(valor);

    if (*lista == NULL || (*lista)->valor >= valor) {
        nuevo->next = *lista;
        *lista = nuevo;
        return;
    }

    Nodo* actual = *lista;
    while (actual->next != NULL && actual->next->valor < valor) {
        actual = actual->next;
    }

    // Insertar en la posición
    nuevo->next = actual->next;
    actual->next = nuevo;
}


void imprimirLista(Nodo* lista) {
    while (lista != NULL) {
        printf("%d -> ", lista->valor);
        lista = lista->next;
    }
    printf("NULL\n");
}

//Datos

int main() {
    Nodo* lista = NULL;
    Nodo* listaA = NULL;
    Nodo* listaB = NULL;

    int valores[] = {1, 6, 2, 8, 3, 12, 9};
    for (int i = 0; i < 7; i++) insertarOrdenado(&lista, valores[i]);

    printf("Lista original:\n");
    imprimirLista(lista);

    int split = 6;
    ubicarDividirAsc(split, lista, &listaA, &listaB);

    printf("\nLista A:\n");
    imprimirLista(listaA);
    printf("Lista B:\n");
    imprimirLista(listaB);

    return 0;
}