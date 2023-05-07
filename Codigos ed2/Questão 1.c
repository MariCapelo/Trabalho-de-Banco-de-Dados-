#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int **matriz = cria_matriz(m,n);

    //inicializando a matriz com zeros
    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            matriz[i][j] = 0;
        }
    }

    //mostrando a matriz
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    //liberando a matriz 
    libera_matriz(matriz, m);
    return 0;
}