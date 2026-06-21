#ifndef HEAP_H
#define HEAP_H

#include "ponto.h"

typedef struct {
    int *dados;     // vetor de indices dos pontos
    int  tamanho;   // numero de elementos no heap
} Heap;

// constroi o heap inicial a partir dos pontos
void heap_build(Heap *h, Ponto *pontos);

// ajusta o heap subindo o elemento na posicao dada
void heapify_up(Heap *h, Ponto *pontos, int pos);

// ajusta o heap descendo o elemento na posicao dada
void heapify_down(Heap *h, Ponto *pontos, int pos);

// remove e retorna o ponto com menor erro
int heap_delete_min(Heap *h, Ponto *pontos);

// atualiza a posicao de um ponto no heap
void heap_update(Heap *h, Ponto *pontos, int idx);

Heap *cria_heap(int capacidade);

void destroi_heap(Heap *h);

#endif