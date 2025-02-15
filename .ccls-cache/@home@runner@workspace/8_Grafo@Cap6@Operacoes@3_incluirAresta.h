#ifndef INCLUIR_ARESTA_H
#define INCLUIR_ARESTA_H
#include "../Grafo.h"
/* --------------------------- */
void incluirAresta (pDGrafo grafo, void *vOrig, void *vDest, FuncaoComparacao fc){

     pVertice vOrigem  = buscarVertice(grafo, vOrig, fc);
     pVertice vDestino = buscarVertice(grafo, vDest, fc);

     if (vOrigem == NULL || vDestino == NULL){
        printf("Um dos vertices nao existe! \n");
        return;
     }

     if (!contemInfo(vOrigem->listaAdjacencias, vDestino, fc)) {
         incluirInfo(vOrigem->listaAdjacencias, vDestino);
     }
     if (!contemInfo(vDestino->listaAdjacencias, vOrigem, fc)) {
         incluirInfo(vDestino->listaAdjacencias, vOrigem);
     }

     printf("Aresta adicionada entre %d e %d\n", *((int*)vOrig), *((int*)vDest));
}

#endif
