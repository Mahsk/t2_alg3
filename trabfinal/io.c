#include <stdio.h>
#include "io.h"

void imprime_saida(Vetor *pontos) {
    int count = 0;
    int i = 0;

    while (i != -1) {
        count++;
        i = pontos->vetor[i].i_prox;
    }
    printf("%d\n", count);

    i = 0;
    while (i != -1) {
        printf("%.1f %g\n", pontos->vetor[i].x, pontos->vetor[i].y);
        i = pontos->vetor[i].i_prox;
    }
}