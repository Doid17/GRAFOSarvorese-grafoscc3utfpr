#ifndef EXISTE_CAMINHO_H
#define EXISTE_CAMINHO_H
#include "../Grafo.h"
/* ----------------------------------------------------------------
A estrat�gia empregada para a verifica�o de exist�ncia do caminho
parte do v�rtice de destino e procede com a busca pelos v�rtices
que incidem sobre este, e assim sucessivamente, at� o momento
que um dos v�rtices incidentes seja o v�rtice de origem.
Resumindo, a busca � feita no sentido do v�rtice de destino para o
v�rtice de origem.
-------------------------------------------------------------------*/
int existeCaminhoRecursivo(pDGrafo grafo, pVertice vOrig, pVertice vDest, FuncaoComparacao fc){

   // encontrou o caminho se o vertice de destino coincidir com o de origem
   if (fc(vOrig, vDest)==0){
       return 1; // return true
   }

   // busca todos os v�rtices que levam a vDestino e
   // dispara uma chamada recursiva para cada um deles
   pDLista verticesIncidentes = buscarVerticesIncidentes(grafo, vDest, fc);

   // n�o � um caminho poss�vel
   if (verticesIncidentes->quantidade == 0){
      return 0;   // return false
   }

   int cont = 1;
   int flag = 0;
   while (cont <= verticesIncidentes->quantidade){

      pVertice verticeIncidente  = (pVertice) buscarInfoPos(verticesIncidentes, cont);
      cont++;

      if (existeCaminhoRecursivo(grafo, vOrig, verticeIncidente, fc) != 0){
          flag = 1;
          break;
      }
   }

   return flag;
}


/* --------------------------- */
int existeCaminho(pDGrafo grafo, void *idOrig, void *idDest, FuncaoComparacao fc){

   // busca os v�rtices para a origem e destino
   pVertice vOrigem  = buscarVertice(grafo, idOrig, fc);
   pVertice vDestino = buscarVertice(grafo, idDest, fc);

   if (vOrigem==NULL || vDestino==NULL){
      return 0;
   }
   return existeCaminhoRecursivo(grafo, vOrigem, vDestino, fc);

}
#endif
