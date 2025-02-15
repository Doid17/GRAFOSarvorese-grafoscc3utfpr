#ifndef EXCLUIR_VERTICE_B_MAIS_H
#define EXCLUIR_VERTICE_B_MAIS_H

#include "../Grafo.h"

void excluirVertice(pDGrafo grafo, void *info, FuncaoComparacao fc) {
    if (!grafo || !grafo->listaVertices) return;

    pNoh noh = grafo->listaVertices->primeiro;
    pNoh anterior = NULL;

    while (noh) {
        pVertice v = (pVertice)noh->info;
        if (fc(v->info, info) == 0) {
            pNoh adj = v->listaAdjacencias->primeiro;
            while (adj) {
                pVertice vAdj = (pVertice)adj->info;
                excluirInfo(vAdj->listaAdjacencias, v, fc);
                adj = adj->prox;
            }
            destruirLista(v->listaAdjacencias);
            if (anterior) {
                anterior->prox = noh->prox;
            } else {
                grafo->listaVertices->primeiro = noh->prox;
            }
            if (noh == grafo->listaVertices->ultimo) {
                grafo->listaVertices->ultimo = anterior;
            }
            free(v);
            free(noh);
            grafo->listaVertices->quantidade--;
            return;
        }
        anterior = noh;
        noh = noh->prox;
    }
}

#endif
