#ifndef NUMERO_CROMATICO_H
#define NUMERO_CROMATICO_H

#include "../Grafo.h"

int numeroCromatico(pDGrafo grafo) {
    if (!grafo || !grafo->listaVertices) {
        return 0;
    }

    int maxCor = 0;
    pNoh atual = grafo->listaVertices->primeiro;
    while (atual) {
        pVertice v = (pVertice)atual->info;
        if (v->cor > maxCor) {
            maxCor = v->cor;
        }
        atual = atual->prox;
    }
    return maxCor + 1;
}

#endif
