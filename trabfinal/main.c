#include "stdio.h"
#include "ponto.h"
#include "vetor.h"
#include "io.h"

int main() {
    int qtd ;
    int x, y ;  
    Ponto *p;

    scanf("%d", &qtd) ;

    Vetor *pontos = cria_vetor(int qtd);

    for(int i = 0; i < qtd; i++) {
	
        x = (i + 1) ;
  
        scanf("%f", &y) ;
  
        p = cria_ponto(x, y) ;
  
        pontos[i] = p;

    }
}