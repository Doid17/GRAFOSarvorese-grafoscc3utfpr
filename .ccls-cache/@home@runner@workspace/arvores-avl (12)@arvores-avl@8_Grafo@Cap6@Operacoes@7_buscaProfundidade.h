#ifndef BUSCA_PROFUNDIDADE_H
#define BUSCA_PROFUNDIDADE_H
#include "../Grafo.h"
/* --------------------------- */
void buscaEmProfundidade(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi){

   pDPilha verticesPendentes;
   pDLista verticesVisitados;

   verticesPendentes = criarPilha();
   verticesVisitados = criarLista();

   /* empilha o primeiro v�rtice do grafo (ou seja, o primeiro v�rtice da lista) */
   empilharInfo(verticesPendentes, grafo->listaVertices->primeiro->info);

   /* processa todos os v�rtices da pilha */
   while(pilhaVazia(verticesPendentes)!=0)
   {
       pVertice vAtual = desempilharInfo(verticesPendentes);

       /* visita o vertice se ainda n�o foi visitado */
       if (contemInfo(verticesVisitados, vAtual, fc) == 0){
          fi(vAtual);
          incluirInfo(verticesVisitados, vAtual);
       }

       /* empilha todas as adjac�ncias do v�rtice atual que n�o foram visitadas */
       pNoh atual = vAtual->listaAdjacencias->primeiro;
       while(atual != NULL){
          if (contemInfo(verticesVisitados, atual->info, fc) == 0){
             empilharInfo(verticesPendentes, atual->info);
          }
          atual = atual->prox;
       }
   }
}

#endif
