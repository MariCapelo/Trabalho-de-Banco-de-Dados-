#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

int *enche_vetor(int *v, int i)
{
    int j;
    for(j = 0; j < i; j++)
    {
        scanf("%d", &v[j]);
    }

    return v;
}

int *cria_vetor(int i)
{
    int *v = (int*) malloc(i * sizeof(int));
    enche_vetor(v, i);
    return v;
}




