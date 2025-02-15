
#ifndef DESTRUIR_GRAFO_H
#define DESTRUIR_GRAFO_H

void destruirGrafo(pDGrafo grafo) {
    if (grafo == NULL) return;
    
    // Destroy all vertices and their adjacency lists
    pNoh atual = grafo->vertices->primeiro;
    while (atual != NULL) {
        pVertice vertice = (pVertice)atual->info;
        destruirLista(vertice->listaAdjacencias);
        free(vertice->info);
        free(vertice);
        atual = atual->prox;
    }
    
    // Destroy the vertices list and the graph itself
    destruirLista(grafo->vertices);
    free(grafo);
}

#endif
