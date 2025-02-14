#ifndef EXCLUIR_VERTICE_H
#define EXCLUIR_VERTICE_H
#include "../Grafo.h"
/* --------------------------- */
void excluirVertice(pDGrafo grafo, void* info, FuncaoComparacao fc){

   if (fc == NULL)
       fc = grafo->fc;
}
#endif
