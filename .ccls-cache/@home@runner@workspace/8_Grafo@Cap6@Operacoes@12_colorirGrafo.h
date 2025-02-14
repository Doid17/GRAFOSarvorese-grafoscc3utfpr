#ifndef COLORIR_GRAFO_H
#define COLORIR_GRAFO_H

#include "../Grafo.h"

void colorirGrafo(pDGrafo grafo, FuncaoComparacao fc) {
    if (!grafo || !grafo->listaVertices || grafo->listaVertices->quantidade == 0) {
        return;
    }

    int numVertices = grafo->listaVertices->quantidade;
    int cores[numVertices];

    for (int i = 0; i < numVertices; i++) {
        cores[i] = -1;
    }

    pNoh atual = grafo->listaVertices->primeiro;
    int index = 0;

    while (atual) {
        pVertice v = (pVertice)atual->info;
        int corUsada[numVertices];

        for (int i = 0; i < numVertices; i++) {
            corUsada[i] = 0;
        }

        pNoh adjacente = v->listaAdjacencias->primeiro;
        while (adjacente) {
            pVertice vAdj = (pVertice)adjacente->info;
            pNoh temp = grafo->listaVertices->primeiro;
            int adjIndex = 0;
            while (temp && fc(temp->info, vAdj) != 0) {
                adjIndex++;
                temp = temp->prox;
            }

            if (adjIndex < numVertices && cores[adjIndex] != -1) {
                corUsada[cores[adjIndex]] = 1;
            
            }
            adjacente = adjacente->prox;
        }

        for (int i = 0; i < numVertices; i++) {
            if (corUsada[i] == 0) {
                cores[index] = i;
                v->cor = i;
                break;
            }
        }

        atual = atual->prox;
        index++;
    }
}

#endif