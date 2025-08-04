#include <stdio.h>
int main()
{
    int a = 13;
    //realizemos la suma de flotantes
    float f = 8.5891;
    float suma = (float)a + f;
    printf("entero %i\n flotante %.2f\n double %.3f\n caracter %c\n", 
        a,
        (float)a, // lo transformamos en flotante
        (double)a,
        (char)a //lo que imprime son el caracte que representa el numero 23 = ↨
    );
    printf("Suma de %i y %.2f es igual a %.2f", a, f, suma);
    ;
    return 0;
}