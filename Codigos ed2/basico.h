#ifndef BASICO_H
#define BASICO_H

typedef struct basico basico;

basico* inicializar(double, double);

double soma(basico*);

double sub(basico*);

double mult(basico*);

double divis(basico*);
#endif