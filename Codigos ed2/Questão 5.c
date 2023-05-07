#include <stdio.h>
#include <stdlib.h>
#include "Cilindro.h"

int main()
{
    Cilindro *c;
    float a, b;
    scanf("%f %f", &a, &b);
    c = cria_cilindro(a, b);

    printf("A altura e volume do cilindro sao:\n");
    mostrar(c);

    printf("A area do cilindro é:\n");
    area(c);
    printf(" centimetros quadrados");


    printf("O volume do cilindro é:\n");
    volume(c);
    printf(" centimetros cubicos");

    libera_cilindro(c);
    return 0;
}