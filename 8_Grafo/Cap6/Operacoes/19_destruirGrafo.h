#ifndef DESTRUIR_GRAFO_H
#define DESTRUIR_GRAFO_H
#include "../Grafo.h"
void destruirGrafo(pDGrafo grafo) {
    if (grafo) {
        // Destroy vertices and their adjacency lists
        pNoh atual = grafo->listaVertices->primeiro;
        while (atual) {
            pVertice v = (pVertice)atual->info;
            if (v) {
                destruirLista(v->listaAdjacencias);
                free(v->info);
                free(v);
            }
            atual = atual->prox;
        }
        // Destroy the vertices list itself
        destruirLista(grafo->listaVertices);
        free(grafo);
    }
}

#endif