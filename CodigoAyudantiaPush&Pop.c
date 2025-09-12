#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo* next;
} Nodo;

// Usamos el push
void push(Nodo** lista, int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->valor = valor;
    nuevo->next = *lista;
    *lista = nuevo;
}

// Usamos el pop
int pop(Nodo** lista) {
    if (*lista == NULL) {
        printf("Lista vacía\n");
        return -1;
    }
    Nodo* temp = *lista;
    int valor = temp->valor;
    *lista = temp->next;
    free(temp);
    return valor;
}

// Insertar al final push de manera invertida
void insertarFinal(Nodo** lista, int valor) {
    Nodo* temp = NULL;
    while (*lista != NULL) {
        push(&temp, pop(lista));
    }
    push(lista, valor);
    while (temp != NULL) {
        push(lista, pop(&temp));
    }
}

// Mostrar la lista
void MostrarLista(Nodo* lista) {
    while (lista != NULL) {
        printf("%d -> ", lista->valor);
        lista = lista->next;
    }
    printf("NULL\n");
}

// Dividir lista ascendente usando pop/push
void ubicarDividirAsc(int split, Nodo** lista, Nodo** listaA, Nodo** listaB) {
    Nodo* temp = NULL;

    // Mover todos los nodos menores al split a listaA
    while (*lista != NULL) {
        int val = pop(lista);
        if (val < split) {
            push(listaA, val); // menor va a listaA
        } else {
            push(&temp, val); // mayor o igual temporal
        }
    }

    // Invertir listaA para mantener orden ascendente
    Nodo* listaAux = NULL;
    while (*listaA != NULL) push(&listaAux, pop(listaA));
    *listaA = listaAux;

    // Invertir temp a listaB para mantener orden ascendente
    Nodo* listaAuxB = NULL;
    while (temp != NULL) push(&listaAuxB, pop(&temp));
    *listaB = listaAuxB;
}

int main() {
    Nodo* lista = NULL;
    Nodo* listaA = NULL;
    Nodo* listaB = NULL;

    int valores[] = {1, 3, 5, 6, 8, 9, 12};
    for (int i = 0; i < 7; i++) insertarFinal(&lista, valores[i]);

    printf("Lista original:\n");
    MostrarLista(lista);

    int split = 6;
    ubicarDividirAsc(split, &lista, &listaA, &listaB);

    printf("\nLista A:\n");
    MostrarLista(listaA);
    printf("Lista B:\n");
    MostrarLista(listaB);

    return 0;
}