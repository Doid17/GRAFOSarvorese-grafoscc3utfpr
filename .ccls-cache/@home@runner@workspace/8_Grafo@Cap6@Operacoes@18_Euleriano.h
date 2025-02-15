#ifndef GRAFO_EULERIANO_H
#define GRAFO_EULERIANO_H

#include "0_structs.h"
#include "../Grafo.h"

int ehEuleriano(pDGrafo grafo) {
    if (grafo == NULL || grafo->listaVertices == NULL || grafo->listaVertices->quantidade == 0) {
        printf("[DEBUG] Grafo inválido ou vazio.\n");
        return 0;
    }

    printf("[DEBUG] Verificando graus dos vértices...\n");

    pNoh atual = grafo->listaVertices->primeiro;
    while (atual != NULL) {
        pVertice v = (pVertice) atual->info;
        printf("[DEBUG] Vértice %d - Grau: %d\n", *((int *)v->info), v->listaAdjacencias->quantidade);

        if (v->listaAdjacencias->quantidade % 2 != 0) {
            printf("[DEBUG] Vértice %d tem grau ímpar. Grafo NÃO é Euleriano.\n", *((int *)v->info));
            return 0;
        }

        atual = atual->prox;
    }

    printf("[DEBUG] Todos os vértices têm grau par. Grafo é Euleriano.\n");
    return 1;
}

#endif //EULERIANO_H
