#ifndef EXCLUIR_ARESTA_H
#define EXCLUIR_ARESTA_H

#include "../Grafo.h"

void excluirAresta(pDGrafo grafo, void *vOrig, void *vDest, FuncaoComparacao fc) {
    if (!grafo || !grafo->listaVertices) return;

    pVertice origem = buscarVertice(grafo, vOrig, fc);
    pVertice destino = buscarVertice(grafo, vDest, fc);

    if (!origem || !destino) return;

    excluirInfo(origem->listaAdjacencias, destino, fc);
    excluirInfo(destino->listaAdjacencias, origem, fc);
}

#endif
