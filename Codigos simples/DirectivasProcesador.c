#include <stdio.h> //es una libreria estandar de C que permite la entrada y salida de datos
/*#include "nombre del archivo.h"*/ //busca el archivo en la carpeta en desarrollo
#define PI 3.14 //define una constante PI con el valor 3.14
#define CUBO(a) a*a*a //define una macro CUBO que calcula el cubo de un número
int main() {
    /*int suma;
    suma = PI + 3;*/
    int a = 5;
    printf("El cubo de %d es: %d\n", a, CUBO(a));
return 0;
}