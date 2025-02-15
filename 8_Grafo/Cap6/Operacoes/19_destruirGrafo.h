#ifndef DESTRUIR_GRAFO_H
#define DESTRUIR_GRAFO_H
#include "../Grafo.h"
void destruirGrafo(pDGrafo grafo) {
    if (grafo) {
          printf("Destruindo grafo anterior!\n");
        
        pNoh atual = grafo->listaVertices->primeiro;
        while (atual) {
            pVertice v = (pVertice)atual->info;
            if (v) {
                destruirLista(v->listaAdjacencias);
                //free(v->info);
              //  free(v);
            }
            atual = atual->prox;
        }
        destruirLista(grafo->listaVertices);
        //free(grafo);
    }
}

#endif