#include <stdio.h>
int main() {
    char texto[] = "()[](){}";
    int contador = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '(' || texto[i] == '{' || texto[i] == '[') {
            contador++;
        } else if (texto[i] == ')' || texto[i] == '}' || texto[i] == ']') {
            contador--;
        }
        if (contador < 0) {
            break; 
        }
    }
    if (contador == 0) {
        printf("La cadena es valida.\n");
    } else {
        printf("La cadena no es valida.\n");
    }
    return 0;
}