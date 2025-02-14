#ifndef COLORIR_GRAFO_H
#define COLORIR_GRAFO_H

#include "../Grafo.h"

void colorirGrafo(pDGrafo grafo, FuncaoComparacao fc) { // Agora aceita os dois parâmetros
    if (!grafo || !grafo->listaVertices || grafo->listaVertices->quantidade == 0) return;

    printf("\n=== INICIANDO COLORAÇÃO ===\n");

    pNoh atual = grafo->listaVertices->primeiro;
    while (atual) {
        pVertice v = (pVertice)atual->info;
        printf("\nProcessando Vértice %d...\n", *((int *)v->info));

        int coresUsadas[grafo->listaVertices->quantidade];
        for (int i = 0; i < grafo->listaVertices->quantidade; i++) coresUsadas[i] = 0;

        pNoh adj = v->listaAdjacencias->primeiro;
        while (adj) {
            pVertice vAdj = (pVertice)adj->info;
            if (vAdj->cor != -1) {
                printf("    - Vértice %d é vizinho e tem cor %d\n", *((int *)vAdj->info), vAdj->cor);
                coresUsadas[vAdj->cor] = 1;
            }
            adj = adj->prox;
        }

        int cor = 0;
        while (coresUsadas[cor]) cor++;

        v->cor = cor;
        printf("  -> Cor escolhida para Vértice %d: %d\n", *((int *)v->info), v->cor);

        atual = atual->prox;
    }

    printf("\n=== RESULTADO FINAL DA COLORAÇÃO ===\n");
    atual = grafo->listaVertices->primeiro;
    while (atual) {
        pVertice v = (pVertice)atual->info;
        printf("Vértice %d -> Cor %d\n", *((int *)v->info), v->cor);
        atual = atual->prox;
    }
}

#endif
