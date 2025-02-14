#ifndef BUSCA_AMPLITUDE_H
#define BUSCA_AMPLITUDE_H
#include "../Grafo.h"
/* --------------------------- */
void buscaAmplitude(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi){

   if (fc == NULL)
       fc = grafo->fc;

   if (fi == NULL)
       fi = grafo->fi;

}
#endif
