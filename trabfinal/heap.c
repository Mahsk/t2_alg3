// ta finalizada, só validar se funciona c o resto da implementaçao das outras funções
#include "heap.h"

typedef struct {
    int *dados;
    int  tamanho;
} Heap;

static void heap_troca(Heap *h, Ponto *pontos, int i, int j) {
    int tmp     = h->dados[i];
    h->dados[i] = h->dados[j];
    h->dados[j] = tmp;
    pontos[h->dados[i]].posheap = i;
    pontos[h->dados[j]].posheap = j;
}

void heapify_up(Heap *h, Ponto *pontos, int pos) {
    while (pos > 0) {
        int pai = (pos - 1) / 2;
        if (pontos[h->dados[pai]].custo <= pontos[h->dados[pos]].custo)
            break;
        heap_troca(h, pontos, pai, pos);
        pos = pai;
    }
}

void heapify_down(Heap *h, Ponto *pontos, int pos) {
    for (;;) {
        int menor = pos;
        int esq = 2*pos + 1;
        int dir = 2*pos + 2;
        if (esq < h->tamanho &&
            pontos[h->dados[esq]].custo < pontos[h->dados[menor]].custo)
            menor = esq;
        if (dir < h->tamanho &&
            pontos[h->dados[dir]].custo < pontos[h->dados[menor]].custo)
            menor = dir;
        if (menor == pos) break;
        heap_troca(h, pontos, pos, menor);
        pos = menor;
    }
}

void heap_build(Heap *h, Ponto *pontos) {
    int i;
    for (i = 0; i < h->tamanho; i++)
        pontos[h->dados[i]].posheap = i;
    for (i = h->tamanho / 2 - 1; i >= 0; i--)
        heapify_down(h, pontos, i);
}

int heap_delete_min(Heap *h, Ponto *pontos) {
    int raiz = h->dados[0];
    h->tamanho--;
    if (h->tamanho > 0) {
        h->dados[0] = h->dados[h->tamanho];
        pontos[h->dados[0]].posheap = 0;
        heapify_down(h, pontos, 0);
    }
    pontos[raiz].posheap = -1;
    return raiz;
}

void heap_update(Heap *h, Ponto *pontos, int idx) {
    int pos = pontos[idx].posheap;
    heapify_up(h, pontos, pos);
    heapify_down(h, pontos, pontos[idx].posheap);
}