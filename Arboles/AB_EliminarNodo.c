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

//encontrar valores minimos y maximos
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
    //buscar el nodo a eliminar
    if (dato < raiz->clave) {
        raiz->left = EliminarNodoHoja(raiz->left, dato);
    } else if (dato > raiz->clave) {
        raiz->right = EliminarNodoHoja(raiz->right, dato);
    } else {
        if (raiz->left == NULL && raiz->right == NULL) {
            free(raiz);
            return NULL;
        }
    }
    return raiz;
}

Nodo *EliminarNodoConHijos(Nodo *raiz, int dato){
    if (dato < raiz->clave) {
        raiz->left = EliminarNodoConHijos(raiz->left, dato);
    } else if (dato > raiz->clave) {
        raiz->right = EliminarNodoConHijos(raiz->right, dato);
    } else {
        // Nodo encontrado
        if (raiz->left == NULL) {
            Nodo *temp = raiz->right;
            free(raiz);
            return temp;
        } else if (raiz->right == NULL) {
            Nodo *temp = raiz->left;
            free(raiz);
            return temp;
        } else {
            Nodo *minimo = MinimoValorNodo(raiz->right);
            raiz->clave = minimo->clave;
            raiz->right = EliminarNodoConHijos(raiz->right, minimo->clave);
        }
    }
    return raiz;
}

Nodo *ElimninarNodoConUnHijo(Nodo *raiz, int dato){
    if (dato < raiz->clave) {
        raiz->left = ElimninarNodoConUnHijo(raiz->left, dato);
    } else if (dato > raiz->clave) {
        raiz->right = ElimninarNodoConUnHijo(raiz->right, dato);
    } else {
        // Nodo encontrado
        Nodo *child = (raiz->left != NULL) ? raiz->left : raiz->right;
        free(raiz);
        return child;
    }
    return raiz;
}

Nodo *EliminarNodoRaiz(Nodo *raiz){
    if (raiz == NULL) return NULL;
    // Si la raíz tiene dos hijos
    if (raiz->left != NULL && raiz->right != NULL) {
        // Buscar el mínimo del subárbol derecho (el sucesor)
        Nodo *minimo = MinimoValorNodo(raiz->right);
        // Si el mínimo es el hijo derecho directo
        if (raiz->right == minimo) {
            minimo->left = raiz->left;
            free(raiz);
            return minimo;
        } else {
            // Buscar el padre del mínimo
            Nodo *padre = raiz->right;
            while (padre->left != NULL && padre->left != minimo) {
                padre = padre->left;
            }
            // Eliminar el mínimo del subárbol derecho
            if (padre->left == minimo) {
                padre->left = minimo->right;
            }
            minimo->left = raiz->left;
            minimo->right = raiz->right;
            free(raiz);
            return minimo;
        }
    } else {
        // Si tiene un solo hijo o ninguno, el hijo pasa a ser la nueva raíz
        Nodo *nuevo_raiz = (raiz->left != NULL) ? raiz->left : raiz->right;
        free(raiz);
        return nuevo_raiz;
    }
}

//Metodo para eliminar un nodo cualquiera
Nodo *EliminarNodo(Nodo *raiz, int dato){
    // Verificar si el numero existe en el arbol
    Nodo *NumeroExiste = BuscarDato(raiz, dato);
    // Si el numero no existe en el arbol
    if (NumeroExiste == NULL){
        printf("El numero %d no existe en el arbol \n", dato);
        return raiz;
    }    
    // Si el numero si existe en el arbol
    else {
        printf("El numero %d si existe en el arbol \n", dato);
        // Si el nodo a eliminar es la raiz
        if (raiz != NULL && dato == raiz->clave){
            Nodo *nuevo_raiz = EliminarNodoRaiz(raiz);
            RecorrerArbolEnOrden(nuevo_raiz);
            return nuevo_raiz;
        }
        Nodo *resultado = BuscarDato(raiz, dato);
        if (resultado != NULL) {
            // Si el nodo a eliminar es una hoja
            if (resultado->left == NULL && resultado->right == NULL){
                Nodo *nuevo_raiz = EliminarNodoHoja(raiz, dato);
                RecorrerArbolEnOrden(nuevo_raiz);
                return nuevo_raiz;
            }
            // Si el nodo a eliminar tiene dos hijos
            else if (resultado->left != NULL && resultado->right != NULL){
                Nodo *nuevo_raiz = EliminarNodoConHijos(raiz, dato);
                RecorrerArbolEnOrden(nuevo_raiz);
                return nuevo_raiz;
            }
            // Si el nodo a eliminar tiene un hijo
            else if (resultado->left != NULL || resultado->right != NULL){
                Nodo *nuevo_raiz = ElimninarNodoConUnHijo(raiz, dato);
                RecorrerArbolEnOrden(nuevo_raiz);
                return nuevo_raiz;
            }
        }
        return raiz;
    }
}

//Metodo MAIN
int main(void){
    int arbol[14]={100, 50, 1, 55, 70, 120, 110, 105, 115, 140, 135, 132, 136, 145};
    Nodo *Arbol = NULL;
    //crear el arbol en el for
    for (int i = 0; i < 14; i++){
        Arbol = InsetarDato(Arbol, arbol[i]);
    }

    RecorrerArbolEnOrden(Arbol);
    Nodo *resultado = BuscarDato(Arbol, 145);
    //if si el dato fue encontrado o no
    if (resultado != NULL){
        printf("El numero %d fue encontrado en el arbol \n", resultado -> clave);
    } else {
        printf("El numero no fue encontrado en el arbol \n");
    }
    //Llamar a la funcion de eliminar nodo con los parametros del arbol y el dato a eliminar
    Arbol = EliminarNodo(Arbol, 5);
}