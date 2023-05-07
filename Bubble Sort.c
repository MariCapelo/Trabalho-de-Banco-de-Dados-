#include <stdio.h>

void BubbleSort(int n, int v[])
{
    int aux;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }

    //vetor depois de ser ordenado 
    for(int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int v[n];


    //lendo os numeros do vetor 
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    // vetor antes de ser ordenado 
    for(int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }

    printf("\n");

    //mandando o vetor para a função de Bubble Sort
    BubbleSort(n, v);

    return 0;
}