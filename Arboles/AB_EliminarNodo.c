#include <stdio.h>
#include <stdlib.h>

typedef struct EstructuraDelNodo
{
    int clave;
    struct EstructuraDelNodo *right, *left;
} Nodo;

Nodo *CrearNodo(int clave){
    Nodo *newNodo = malloc(sizeof(Nodo));
    //Este if es para verificar si hay almacenamiento necesario en la RAM por si acaso
    if (newNodo == NULL){
        exit(1);
    }
    //Este else creamos el nodo en si
    else{
        newNodo -> clave = clave;
        newNodo -> right = NULL;
        newNodo -> left = NULL;
        }
    return newNodo;
}

//BucarNodo
Nodo *BuscarDato(Nodo *raiz, int valor){
    while (raiz != NULL){
        if (raiz -> clave == valor){
            return raiz;
        } else if(raiz ->clave < valor){
                raiz = raiz -> right;
        } else{
                raiz = raiz -> left;
            }
        }
        return raiz;
    }

//Insercion Recusiva
Nodo *InsetarDato(Nodo *arbol, int dato){
    if(arbol == NULL){
        return CrearNodo(dato);
    } else {
        if (arbol -> clave == dato){
            return arbol;
        }
        if(dato < arbol -> clave){
            arbol -> left = InsetarDato(arbol -> left, dato);
        } else {
            arbol -> right = InsetarDato(arbol -> right, dato);
        }
    }
    return arbol;
}  

//
void RecorrerArbolEnOrden(Nodo *arbol){
    if (arbol != NULL){
        RecorrerArbolEnOrden(arbol -> left);
        printf("%d \n", arbol -> clave);
        RecorrerArbolEnOrden(arbol -> right);
    }
}

//encontrar valores minimos y mnaximos
Nodo *MinimoValorNodo(Nodo *nodo){
    Nodo *actual = nodo;
    while (actual && actual -> left != NULL){
        actual = actual -> left;
    }
    return actual;
}

Nodo *MaximoValorNodo(Nodo *nodo){
    Nodo *actual = nodo;
    while (actual && actual -> right != NULL){
        actual = actual -> right;
    }
    return actual;
}

//Metodos de eliminar datos del arbol

Nodo *EliminarNodoHoja(Nodo *raiz, int dato){
    Nodo *resultado = BuscarDato(raiz, dato);
    Nodo *temp = resultado;
    if (resultado != NULL) {
        if (resultado -> left == NULL && resultado -> right == NULL){
            free(temp);
            resultado = NULL;
        }
    }
    return raiz;
}

Nodo *EliminarNodoConHijos(Nodo *raiz, int dato){
    Nodo *resultado = BuscarDato(raiz, dato);
    Nodo *temp = resultado;
    if (resultado != NULL) {
        if (resultado -> left != NULL){
            resultado -> left = NULL;
        }
        if (resultado -> right != NULL){
            resultado -> right = NULL;
        }
        free(temp);
    }
    return raiz;
}

Nodo *ElimninarNodoConUnHijo(Nodo *raiz, int dato){
    Nodo *resultado = BuscarDato(raiz, dato);
    Nodo *temp = resultado;
    if (resultado != NULL) {
        if (resultado -> left != NULL){
            resultado -> left = resultado -> left;
        }
        if (resultado -> right != NULL){
            resultado -> right = resultado -> right;
        }
        free(temp);
    }
    return raiz;
}

Nodo *EliminarNodoRaiz(Nodo *raiz, int dato){
    Nodo *resultado = BuscarDato(raiz, dato);
    Nodo *temp = resultado;
    if (resultado != NULL) {
        if (resultado -> left != NULL && resultado -> right != NULL){
            Nodo *minimo = MinimoValorNodo(resultado -> right);
            resultado -> clave = minimo -> clave;
            resultado -> right = EliminarNodoHija(resultado -> right, minimo -> clave);
        } else if (resultado -> left != NULL){
            resultado = resultado -> left;
        } else if (resultado -> right != NULL){
            resultado = resultado -> right;
        } else {
            resultado = NULL;
        }
        free(temp);
    }
    return raiz;
}

//Metodo para eliminar un nodo cualquiera
Nodo *EliminarNodo(Nodo *raiz, int dato){
    //Si el nodo a eliminar es la raiz
    if (raiz != NULL && dato == raiz->clave){
        return EliminarNodoRaiz(raiz, dato);
    }
    Nodo *resultado = BuscarDato(raiz, dato);
    if (resultado != NULL) {
        //Si el nodo a eliminar es una hoja
        if (resultado -> left == NULL && resultado -> right == NULL){
            return EliminarNodoHoja(raiz, dato);
        }
        //Si el nodo a eliminar tiene dos hijos
        else if (resultado -> left != NULL && resultado -> right != NULL){
            return EliminarNodoConHijos(raiz, dato);
        }
        //Si el nodo a eliminar tiene un hijo
        else if (resultado -> left != NULL || resultado -> right != NULL){
            return ElimninarNodoConUnHijo(raiz, dato);
        }
    }
    return raiz;
}

//Metodo MAIN
int main(void){
    int arbol[14]={100, 50, 1, 55, 70, 120, 110, 105, 115, 140, 135, 132, 136, 145};
    Nodo *Arbol = NULL;
    for (int i = 0; i < 14; i++){
        Arbol = InsetarDato(Arbol, arbol[i]);
    }

    RecorrerArbolEnOrden(Arbol);
    Nodo *resultado = BuscarDato(Arbol, 66);
    if (resultado != NULL){
        printf("El dato %d fue encontrado en el arbol \n", resultado -> clave);
    } else {
        printf("El dato no fue encontrado en el arbol \n");
    } 

    Arbol = EliminarNodo(Arbol, 145);
    printf("Despues de eliminar el nodo 145 \n");
    RecorrerArbolEnOrden(Arbol);
}