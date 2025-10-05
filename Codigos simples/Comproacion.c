#include <stdio.h>
#include <string.h> //para la funcion strlen que obrtiene la longitud de una cadena
int main(){
    const char *cadena[] = {"{()}", "[{)]","[(]",  NULL};  //cadena para comprobar
    for (int i = 0; cadena[i]; i++) { 
        const char *temp = cadena[i];
        char pila[(strlen(*cadena))];
        int top = -1, ok = 1;
        printf(" -------------------------\n");
        while (*temp != '\0') //un bucle mientras no sea nula(\0 seria como el NULL)
        {
            if(*temp == '(' || *temp == '{' || *temp == '['){ //evaluar si es un simbolo de apertura
                pila[++top] = *temp; //poner en la pila seria "push"
            } else if(*temp == ')' || *temp == '}' || *temp == ']'){//evaluar si es un simbolo de cierre
                if(top <0){
                    ok = 0;
                    break;  //romper el ciclo
                }
                char ultimo = pila[top--];//sacar de la pila "seria pop"
                if((ultimo == '(' && *temp != ')') || (ultimo == '{' && *temp != '}') || (ultimo == '[' && *temp != ']')){ //evaluar si es un simbolo de cierre
                    ok = 0;
                    printf("|Error: %c                 |\n", *temp);
                    break; //romper el ciclo
                }
            }
            temp++;//avanzar al siguiente caracter
        }
        if(top >= 0) ok = 0;                        
        printf("|Prueba %d: %s\n ", i+1, ok ? "Correcto       |" : "Incorrecto     |"); //imprimir si es correcto o incorrecto con operador ternario
        printf("-------------------------\n");                                          //si ok es verdadero imprime correcto, si no imprime incorrecto
    } 
}