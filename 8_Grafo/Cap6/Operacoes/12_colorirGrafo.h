#ifndef COLORIR_GRAFO_B_MAIS_H
#define COLORIR_GRAFO_B_MAIS_H

#include "../Grafo.h"

void colorirGrafo(pDGrafo grafo, FuncaoComparacao fc) {
    if (!grafo || !grafo->listaVertices || grafo->listaVertices->quantidade == 0) return;
printf(" ");
    int V = grafo->listaVertices->quantidade;
    int cores[V];
    for (int i = 0; i < V; i++) cores[i] = -1;

    cores[0] = 0;
    int disponiveis[V];
    for (int i = 0; i < V; i++) disponiveis[i] = 1;
     printf("Vértice  -> Cor \n");
    pNoh noh = grafo->listaVertices->primeiro;
    for (int u = 1; noh != NULL; noh = noh->prox, u++) {
             printf(" ");
        pVertice v = (pVertice)noh->info;
        pNoh adj = v->listaAdjacencias->primeiro;
        while (adj) {
            printf(" ");
            pVertice adjV = (pVertice)adj->info;
            if (cores[*((int *)adjV->info)] != -1)
                disponiveis[cores[*((int *)adjV->info)]] = 0;
            adj = adj->prox;
        }
        printf(" ");
        int cr;
        for (cr = 0; cr < V; cr++) {
            if (disponiveis[cr]) break;
        }
        cores[*((int *)v->info)] = cr;
        printf(" ");
        adj = v->listaAdjacencias->primeiro;
        while (adj) {
                printf(" ");
            pVertice adjV = (pVertice)adj->info;
            if (cores[*((int *)adjV->info)] != -1)
                disponiveis[cores[*((int *)adjV->info)]] = 1;
            adj = adj->prox;
        }
    }
    noh = grafo->listaVertices->primeiro;
    while (noh) {
        pVertice v = (pVertice)noh->info;
        printf("Vértice %d -> Cor %d\n", *((int *)v->info), cores[*((int *)v->info)]);
        noh = noh->prox;
    }
}

#endif
