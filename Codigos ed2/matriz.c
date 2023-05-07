#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

//função para criar matriz dinamicamente
int** cria_matriz(int m, int n)
{
    int **p = (int**)malloc(m * sizeof(int*));
    for(int i = 0; i < m; i++)
    {
        p[i]= (int*) malloc(n * sizeof(int));
    }
    printf("SUA MATRIZ FOI CRIADA\n");

    //retornando ponteiro de ponteiro que representa matriz 
    return p;

}

//função para liberar a matriz
void libera_matriz(int **matriz, int m)
{
    for(int i = 0; i < m; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    printf("A MATRIZ FOI LIBERADA\n");
}