#include "ponto.h"



// ta finalizada, só validar se funciona c o resto da implementaçao das outras funções

Ponto *cria_ponto(int x, int y) {
	Ponto *p = malloc(sizeof(Ponto));
  if (p == NULL)
  	return NULL;
  p->x = x;
  p->y = y;
  p->i_prox = x+1;
  p->i_ant = x-1;
  p->custo = INFINITY;
  p->posheap = -1;
  return p;
}

float area_triangulo(float x1, float y1,
                     float x2, float y2,
                     float x3, float y3) {
    float area = (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0f;
    return (area < 0.0f) ? -area : area;
}

float altura2_triangulo(float x1, float y1,
                        float x2, float y2,
                        float x3, float y3) {
    float area  = area_triangulo(x1,y1,x2,y2,x3,y3);
    float dx    = x3 - x1;
    float dy    = y3 - y1;
    float base2 = dx*dx + dy*dy;
    if (base2 == 0.0f) return 0.0f;
    return 4.0f * (area*area) / base2;
}

float calcular_erro(Ponto *pontos, int idx, int usar_area) {
    int a = pontos[idx].i_ant;
    int p = pontos[idx].i_prox;
    if (usar_area)
        return area_triangulo(pontos[a].x, pontos[a].y,
                              pontos[idx].x, pontos[idx].y,
                              pontos[p].x, pontos[p].y);
    else
        return altura2_triangulo(pontos[a].x, pontos[a].y,
                                 pontos[idx].x, pontos[idx].y,
                                 pontos[p].x, pontos[p].y);
}