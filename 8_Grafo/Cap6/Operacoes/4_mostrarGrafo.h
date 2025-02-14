#ifndef MOSTRA_GRAFO_H
#define MOSTRA_GRAFO_H
#include "../Grafo.h"

#include <stdio.h>
#include <stdlib.h>
/* --------------------------- */
void mostrarGrafo(pDGrafo grafo, FuncaoImpressao fi){

     imprimirLista (grafo->listaVertices, fi);

}
#endif

