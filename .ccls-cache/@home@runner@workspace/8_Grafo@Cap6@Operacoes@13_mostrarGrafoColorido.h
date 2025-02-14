#ifndef MOSTRAR_GRAFO_COLORIDO_B_MAIS_H
#define MOSTRAR_GRAFO_COLORIDO_B_MAIS_H

#include "../Grafo.h"

const char *cores[] = {"Azul", "Verde", "Vermelho", "Amarelo", "Laranja", "Roxo"};

void mostrarGrafoColorido(pDGrafo grafo) {
    if (!grafo || !grafo->listaVertices) {
        printf("Erro: Grafo não inicializado.\n");
        return;
    }

    printf("\n=== Grafo Colorido ===\n");

    pNoh noh = grafo->listaVertices->primeiro;
    while (noh) {
        pVertice v = (pVertice)noh->info;
        int corIndex = *((int *)v->info) % 6;
        printf("Vértice %d -> Cor: %s\n", *((int *)v->info), cores[corIndex]);
        noh = noh->prox;
    }
}

#endif
