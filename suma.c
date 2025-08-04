#include <stdio.h>

int main() {
    int a, b, sum;
    printf("Elija el primer numero: ");
    scanf("%d", &a);
    printf("Elija el segundo numero: ");
    scanf("%d", &b);
    sum = a + b;
    printf("La suma de %d y %d es: %d\n", a, b, sum);
    return 0;
}