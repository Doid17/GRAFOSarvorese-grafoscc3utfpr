#ifndef GRAFO_CONEXO_H
#define GRAFO_CONEXO_H

#include "../Grafo.h"

int ehGrafoConexo(pDGrafo grafo, FuncaoComparacao fc) {
    if (!grafo || !grafo->listaVertices || grafo->listaVertices->quantidade == 0) {
        return 0;
    }

    pNoh nohOrigem = grafo->listaVertices->primeiro;
    pVertice vOrigem = (pVertice)nohOrigem->info;
    pNoh nohDestino = grafo->listaVertices->primeiro;

    while (nohDestino) {
        pVertice vDestino = (pVertice)nohDestino->info;
        if (existeCaminho(grafo, vOrigem->info, vDestino->info, fc) == 0) {
            return 0;
        }
        nohDestino = nohDestino->prox;
    }
    return 1;
}

#endif
