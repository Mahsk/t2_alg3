#include "stdio.h"
#include "ponto.h"
#include "vetor.h"
#include "io.h"

int main() {
    int qtd ;
    float x, y ;  
    Ponto *p;

    scanf("%f", &qtd) ;

    Vetor *pontos = cria_vetor(qtd);

    for(int i = 0; i < qtd; i++) {
	
        x = (i + 1) ;
  
        scanf("%f", &y) ;
  
        p = cria_ponto(x, y) ;
  
        pontos->vetor[i] = *p;

        free(p) ;
        return 0 ;

    }
}