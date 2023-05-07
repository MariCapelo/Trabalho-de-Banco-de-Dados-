#include <stdio.h>
#include <stdlib.h>
#include "Cilindro.h"

struct cilindro
{
    float h;
    float r;
};

Cilindro* cria_cilindro(float h, float r)
{
    Cilindro *c = (Cilindro*) malloc(sizeof(Cilindro));

    if(c != NULL)
    {
        c -> h = h;
        c -> r = r;
    }

    return c;
}

float area(Cilindro *c)
{
    return 2 * 3.14 * c->r * (c->r + c->h);
}

float volume(Cilindro *c)
{
    return 3.14 * c->r * c->r * c->h;
}

void libera_cilindro(Cilindro *c)
{
    free(c);
}

void mostrar(Cilindro *c)
{
    printf("%d cm e %d cm", c->h, c->r);
}