#ifndef EMPARELHAMENTO_GRAFO_BIPARTIDO_H
#define EMPARELHAMENTO_GRAFO_BIPARTIDO_H

#include "../Grafo.h"

int emparelhamentoGrafoBipartido(pDGrafo grafo, FuncaoComparacao fc) {
    if (!grafo || !grafo->listaVertices || grafo->listaVertices->quantidade == 0) {
        return 0;
    }

    int numVertices = grafo->listaVertices->quantidade;
    int *pareamento = (int *)malloc((numVertices + 1) * sizeof(int));
    for (int i = 0; i <= numVertices; i++) {
        pareamento[i] = -1;
    }

    int emparelhados = 0;
    pNoh atual = grafo->listaVertices->primeiro;

    while (atual) {
        pVertice v = (pVertice)atual->info;
        if (pareamento[*((int *)v->info)] == -1) {
            pNoh adjacente = v->listaAdjacencias->primeiro;
            while (adjacente) {
                pVertice vAdj = (pVertice)adjacente->info;
                if (pareamento[*((int *)vAdj->info)] == -1) {
                    pareamento[*((int *)v->info)] = *((int *)vAdj->info);
                    pareamento[*((int *)vAdj->info)] = *((int *)v->info);
                    emparelhados++;
                    break;
                }
                adjacente = adjacente->prox;
            }
        }
        atual = atual->prox;
    }

    free(pareamento);
    return emparelhados;
}

#endif
