#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

int main()
{
    int i;
    scanf("%d", &i);
    int *v = cria_vetor(i);


    //printando o vetor
    for(int j = 0; j < i; j++)
    {
        printf("%d ", v[j]);
    }

    free(v);
    return 0;
}