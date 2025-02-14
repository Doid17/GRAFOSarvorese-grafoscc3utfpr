#ifndef GRAFO_EULERIANO_H
#define GRAFO_EULERIANO_H

#include "0_structs.h"
#include "../Grafo.h"

/* Verifica se um grafo é Euleriano */
int ehEuleriano(pDGrafo grafo) {
    if (grafo == NULL || grafo->listaVertices == NULL || grafo->listaVertices->quantidade == 0) {
        return 0;
    }

    pNoh atual = grafo->listaVertices->primeiro;
    while (atual != NULL) {
        pVertice v = (pVertice) atual->info;
        if (v->listaAdjacencias->quantidade % 2 != 0) {
            return 0; // Se algum vértice tem grau ímpar, o grafo não é Euleriano
        }
        atual = atual->prox;
    }

    return 1; // Todos os vértices têm grau par
}

#endif // IS_EULERIAN_H
