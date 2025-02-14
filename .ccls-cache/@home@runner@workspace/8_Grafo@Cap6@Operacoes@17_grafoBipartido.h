#ifndef GRAFO_BIPARTIDO_H
#define GRAFO_BIPARTIDO_H

#include "../Grafo.h"

int verificarBipartidoDFS(pVertice vertice, int *cores, int cor, FuncaoComparacao fc) {
    int id = *((int *)vertice->info);
    if (cores[id] != -1) {
        return cores[id] == cor;
    }

    cores[id] = cor;

    pNoh adjacente = vertice->listaAdjacencias->primeiro;
    while (adjacente) {
        pVertice vAdj = (pVertice)adjacente->info;
        if (!verificarBipartidoDFS(vAdj, cores, 1 - cor, fc)) {
            return 0;
        }
        adjacente = adjacente->prox;
    }

    return 1;
}

int grafoBipartido(pDGrafo grafo, FuncaoComparacao fc) {
    if (!grafo || !grafo->listaVertices || grafo->listaVertices->quantidade == 0) {
        return 0;
    }

    int numVertices = grafo->listaVertices->quantidade;
    int *cores = (int *)malloc((numVertices + 1) * sizeof(int));
    for (int i = 0; i <= numVertices; i++) {
        cores[i] = -1;
    }

    pNoh atual = grafo->listaVertices->primeiro;
    while (atual) {
        pVertice v = (pVertice)atual->info;
        if (cores[*((int *)v->info)] == -1) {
            if (!verificarBipartidoDFS(v, cores, 0, fc)) {
                free(cores);
                return 0;
            }
        }
        atual = atual->prox;
    }

    free(cores);
    return 1;
}

#endif
