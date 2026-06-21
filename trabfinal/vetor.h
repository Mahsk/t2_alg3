#ifndef VETOR_H
#define VETOR_H

#include "ponto.h"
#include <stdlib.h>


typedef struct {
	Ponto *vetor;
  int tamanho;
} Vetor;


Vetor * cria_vetor(int tamanho);
void insere_vetor(Vetor *v, Ponto p, int i);
float remove_vetor(Vetor *vetor, int i);
void destroi_vetor(Vetor *vetor);


#endif // VETOR_H