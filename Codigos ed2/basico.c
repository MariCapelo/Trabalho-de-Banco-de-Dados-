#include <stdlib.h>
#include "basico.h"

struct basico
{
    double a;
    double b;
};

basico* inicializar(double a, double b)
{
    basico *p = (basico*) malloc(sizeof(basico));
    if(p != NULL)
    {
        p -> a = a;
        p -> b = b;
    }
    return p;
}

double soma(basico* op)
{
    double s = op -> a + op -> b;
    return s;
}

double sub(basico* op)
{
    double s = op -> a - op -> b;
    return s;
}

double mult(basico* op)
{
    double m = op -> a * op-> b;
    return m;
}

double divis(basico* op)
{
    double d = op -> a / op -> b;
    return d;
}