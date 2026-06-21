#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "heap.h"
#include "ponto.h"
#include "vetor.h"
#include "io.h"

int main(int argc, char *argv[]) {
    if (argc < 3)
        return 1;

    int usar_area = ( strcmp(argv[1], "-a") == 0) ? 1 : 0;
    float tol = atof(argv[2]); // tolerancia

    int qtd ;

    //le a qntdd de pontos
    scanf("%d", &qtd) ;

    if (qtd < 3) {
        return 0; // se tiver menos que 3 pontos não da pra remover nada
    }
    Vetor *pontos = cria_vetor(qtd);
    Heap * heap = cria_heap(qtd);

    for(int i = 0; i < qtd; i++ ) {
        Ponto p;
        p.x = (float)(i+1);
        scanf("%f", &p.y);
        p.custo = INFINITY;
        p.posheap = -1;
        p.removido = 0;
        insere_vetor(pontos, p, i);

    }

    for (int i = 1; i < qtd - 1; i++) {
        pontos->vetor[i].custo = calcular_erro(pontos->vetor, i, usar_area);
        heap->dados[heap->tamanho] = i;
        heap->tamanho++;
    }


    heap_build(heap, pontos->vetor);

    while (heap->tamanho > 0 && pontos->vetor[heap->dados[0]].custo < tol) {
        int min_idx = heap_delete_min(heap, pontos->vetor);
        remove_vetor(pontos, min_idx);
        int ant = pontos->vetor[min_idx].i_ant;
        int prox = pontos->vetor[min_idx].i_prox;

        if (ant > 0) {
            pontos->vetor[ant].custo = calcular_erro(pontos->vetor, ant, usar_area);
            heap_update(heap, pontos->vetor, ant);

        }

        if (prox < qtd -1) {
            pontos->vetor[prox].custo = calcular_erro(pontos->vetor, prox, usar_area);
            heap_update(heap, pontos->vetor, prox);
        }
    }

    destroi_heap(heap);

    imprime_saida(pontos);

    destroi_vetor(pontos);

    return 0;





    
    return 0 ;
}