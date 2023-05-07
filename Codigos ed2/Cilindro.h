#ifndef CILINDRO_H
#define CILINDRO_H

typedef struct cilindro Cilindro;

Cilindro* cria_cilindro(float h, float r);

float area(Cilindro *c);

float volume(Cilindro *c);

void libera_cilindro(Cilindro *c);

void mostrar(Cilindro *c);

#endif