#ifndef CRIAR_GRAFO_H
#define CRIAR_GRAFO_H
#include "../Grafo.h"
/* --------------------------- */
pDGrafo criarGrafo(){

  pDGrafo grafo = malloc(sizeof(DGrafo));
  grafo->listaVertices = criarLista();
 // grafo->fc = NULL;
 // grafo->fi = NULL;
 // grafo->fa = NULL;
  return grafo;

}

#endif
