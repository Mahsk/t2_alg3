#ifndef PONTO_H
#define PONTO_H

#include <math.h>
#include <stddef.h> 
#include <stdlib.h>

typedef struct {
    float x;// posicao na sequencia
    float y; // valor lido da entrada
    float custo; // custo de remover este ponto

    int i_ant; // indice do vizinho anterior
    int i_prox; // indice do vizinho seguinte

    int posheap; // posicao no heap (-1 se fora)
    int removido; // 1 se ja foi eliminado
} Ponto;



// area_triangulo
// retorna a area do triangulo formado por tres pontos
// usa metade do valor absoluto do determinante 3x3
float area_triangulo(float x1, float y1,
                     float x2, float y2,
                     float x3, float y3);

// altura2_triangulo
// retorna o quadrado da altura do triangulo com base em (x1,y1)-(x3,y3) e vertice em (x2,y2)
// formula: altura² = 4 * area² / base²
float altura2_triangulo(float x1, float y1,
                        float x2, float y2,
                        float x3, float y3);

// calcular_erro
// calcula o erro de remocao do ponto idx considerando vizinhos atuais (ant e prox)
// usar_area=1 -> area; usar_area=0 -> altura²
float calcular_erro(Ponto *pontos, int idx, int usar_area);

#endif