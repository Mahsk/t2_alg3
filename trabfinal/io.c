#include "vetor.h"

void imprime_saida(Vetor *pontos) {
    int count = 0;
    int i = 0;

    while (i != -1) {
        count++;
        i = pontos->v[i].i_prox;
    }
    printf("%d\n", count);

    i = 0;
    while (i != -1) {
        printf("%.1f %g\n", pontos->v[i].x, pontos->v[i].y);
        i = pontos->v[i].i_prox;
    }
}