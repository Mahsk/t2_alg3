#include "ponto.h"
#include "vetor.h"
// adicionei as structs ponto e vetor no ponto.h e vetor.h

Ponto *cria_ponto(int x, int y) {
	Ponto *p = malloc(sizeof(Ponto));
  if (p == NULL)
  	return NULL;
  p->x = x;
  p->y = y;
  p->i_prox = x+1;
  p->i_ant = x-1;
  p->custo = INFINITY;
  p->posheap = NAN;
  return p;
}

Vetor * cria_vetor(int tamanho) {
	Vetor *v = malloc(sizeof(Vetor));
  if (v == NULL)
  	return NULL;
  
  v->pontos = malloc(tamanho*sizeof(pontos));
}

..................