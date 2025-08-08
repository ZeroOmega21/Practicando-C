#include <stdio.h>

int main()
{
int a[5] = {5,15,20,25,30};
int *pa;
pa = &a[0]; // o también puede ser (pa = a)
int x = *pa;
pa = pa + 1;
pa[1];
printf("%d\n", *pa); // Imprime el segundo elemento del arreglo a
/*Pregunta para la casa
Porque tiene sentido pa[1];
*/
//funciona porque *pa se esta comportando como un puntero de a[] y al ser indirectamante este podemos hacer que se comporte como un arreglo
    return 0;
}
