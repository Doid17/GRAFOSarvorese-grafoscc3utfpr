#ifndef EMPILHAR_INFO_PILHA_H
#define EMPILHAR_INFO_PILHA_H
#include "../Pilha.h"
void empilharInfo(pDPilha pdPilha, void *info){

   if (pdPilha != NULL)
       incluirInfo(pdPilha->pdLista, info);
}

#endif
