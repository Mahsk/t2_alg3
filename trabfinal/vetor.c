#include "ponto.h"
#include "vetor.h"
// adicionei as structs ponto e vetor no ponto.h e vetor.h


Vetor * cria_vetor(int tamanho) {
	Vetor *v = malloc(sizeof(Vetor));
  if (v == NULL)
  	return NULL;

  v->vetor = malloc(tamanho * sizeof(Ponto));
  if (v->vetor == NULL) {
      free(v);
      return NULL;
    }
  
  v->tamanho = tamanho;
  return v;
}

void insere_vetor(Vetor *v, Ponto p, int i) {
  if (v != NULL && i >= 0 && i < v->tamanho) {
    v->vetor[i] = p;

    v->vetor[i].i_ant = i - 1;
    v->vetor[i].i_prox = i + 1;


    if (i == v->tamanho - 1) {
      v->vetor[i].i_prox = -1;
    }
  }
}


float remove_vetor(Vetor *v, int i) {
  if (v == NULL || i < 0 || i >= v->tamanho)
    return -1.0f;

  Ponto *p = &(v->vetor[i]);
  int ant = p->i_ant;
  int prox = p->i_prox;

  v->vetor[ant].i_prox = p->i_prox;
  v->vetor[prox].i_ant = p->i_ant;

  p->removido = 1;

  return p->custo;
}


void destroi_vetor(Vetor *vetor) {
    if (vetor != NULL) {
        free(vetor->vetor);
        free(vetor);
    }
}

