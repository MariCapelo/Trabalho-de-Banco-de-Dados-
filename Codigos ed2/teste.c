#include<stdio.h>
#include<stdlib.h>
#include "basico.h"

int main()
{
    double num1, num2, op1, op2, op3, op4; 

    printf("Digite dois numeros\n");
    scanf("%lf %lf", &num1, &num2);

    basico* operacao = inicializar(num1, num2);

    op1 = soma(operacao);
    op2 = sub(operacao);
    op3 = mult(operacao);
    op4 = divis(operacao);

    printf("A soma dos dois numeros eh: %.2lf \n", op1);
    printf("A subtracao dos dois numeros eh: %.2lf \n", op2);
    printf("A multiplicacao dos dois numeros eh: %.2lf \n", op3);
    printf("A divisao dos dois numeros eh: %.2lf \n", op4);
    free(operacao);
}