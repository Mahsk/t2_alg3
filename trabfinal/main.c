#include <stdio.h>
#include <stdlib.h>

#include "heap.h"
#include "ponto.h"
#include "vetor.h"
#include "io.h"

int main(int argc, char *argv[]) {
    int qtd ;
    float x, y ;  
    Ponto *p;

    //le a qntdd de pontos
    scanf("%d", &qtd) ;

    Vetor *pontos = cria_vetor(qtd);

    for(int i = 0; i < qtd; i++) {
	
        x = (i + 1) ;
  
        scanf("%f", &y) ;
  
        p = cria_ponto(x, y) ;
  
        pontos->vetor[i] = *p;

    }

    imprime_saida(pontos) ;

    destroi_vetor(pontos) ;
    
    return 0 ;
}