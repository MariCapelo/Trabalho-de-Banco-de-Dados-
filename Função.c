#include<stdio.h>
#include<math.h>

int main()
{
    int m, n, M, N;
    float x, epslon;
    double X;
    scanf("%f, %d, %d", &x, &n, &m);
    scanf("%lf, %d, %d", &X, &N, &M);
    epslon = pow(x, n/m) - pow(X, N/M);
    printf("O valor da operacao 1 e: %f\n ", pow(x, n/m));
    printf("O valor da operacao 2 e: %lf\n ", pow(X, N/M));
    printf("O valor de epsolon e: %.4f", epslon);
    return 0;
}