#ifndef MOSTRAR_GRAFO_COLORIDO_H
#define MOSTRAR_GRAFO_COLORIDO_H

#include "../Grafo.h"

const char *cores[] = {"Azul", "Verde", "Vermelho", "Amarelo", "Laranja", "Roxo"};

void mostrarGrafoColorido(pDGrafo grafo) {
    if (!grafo || !grafo->listaVertices) {
        return;
    }

    printf("\n=== Grafo Colorido ===\n");

    pNoh atual = grafo->listaVertices->primeiro;
    while (atual) {
        pVertice v = (pVertice)atual->info;
        printf("Vértice %d -> Cor: %s\n", *((int *)v->info), cores[v->cor % 6]);
        atual = atual->prox;
    }
}

#endif
