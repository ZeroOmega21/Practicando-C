#include <stdio.h>

int main(){
    char C = 'y'; //1 byte char es tipo caracter
    int a = 20; //2 bytes
    short e = -1L; //2 bytes desde -128 hasta 127
    unsigned int u = 25; //enteros sin signo
    long l = 5932; //4 bytes
    //Numeros reales
    float f = 72.56565; //4 bytes
    double d = 1231231.124124675443; //8 bytes
    /*Tipos de %#
    c = caracterers
    d o i = para numeros enteros con signos
    u = par aenteros sin signos
    li = long intenter
    f = numeros reales como el float
    Para limitar el numeros de decimales: %.2f. El .2 serian la cantidad de deciamles que queremos
    */
    printf("%f\n", d);
    return 0;
}