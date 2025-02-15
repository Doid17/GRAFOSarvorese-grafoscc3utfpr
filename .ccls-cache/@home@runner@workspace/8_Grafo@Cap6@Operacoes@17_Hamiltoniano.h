#ifndef GRAFO_HAMILTONIANO_H
#define GRAFO_HAMILTONIANO_H

#include "../Grafo.h"

/* Verifica se um vértice pode ser adicionado ao caminho */
int podeAdicionarAoCaminho(pVertice v, pDLista caminho, int pos, FuncaoComparacao fc) {
    if (contemInfo(caminho, v, fc)) {
        return 0;
    }
    if (pos > 0) {
        pVertice ultimoVertice = (pVertice) buscarInfoPos(caminho, pos);
        if (!contemInfo(ultimoVertice->listaAdjacencias, v, fc)) {
            return 0;
        }
    }
    return 1;
}

/* Função recursiva para encontrar um caminho Hamiltoniano */
int caminhoHamiltonianoRecursivo(pDGrafo grafo, pDLista caminho, int pos, FuncaoComparacao fc) {
    if (pos == grafo->listaVertices->quantidade) {
        return 1;
    }

    pNoh atual = grafo->listaVertices->primeiro;
    while (atual != NULL) {
        pVertice v = (pVertice) atual->info;
        if (podeAdicionarAoCaminho(v, caminho, pos, fc)) {
            incluirInfo(caminho, v);
            if (caminhoHamiltonianoRecursivo(grafo, caminho, pos + 1, fc)) {
                return 1;
            }
            excluirInfoPos(caminho, pos);
        }
        atual = atual->prox;
    }
    return 0;
}

/* Verifica se o grafo é Hamiltoniano */
int ehHamiltoniano(pDGrafo grafo, FuncaoComparacao fc) {
    if (grafo == NULL || grafo->listaVertices == NULL || grafo->listaVertices->quantidade == 0) {
        return 0;
    }
    if (grafo->listaVertices->quantidade == 1) {
        return 1;
    }

    pDLista caminho = criarLista();
    pNoh primeiroVertice = grafo->listaVertices->primeiro;
    incluirInfo(caminho, primeiroVertice->info);

    int resultado = caminhoHamiltonianoRecursivo(grafo, caminho, 1, fc);

    destruirListaInfo(caminho, NULL);
    return resultado;
}

#endif // IS_HAMILTONIAN_H
