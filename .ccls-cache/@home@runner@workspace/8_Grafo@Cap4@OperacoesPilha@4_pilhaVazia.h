#ifndef PILHAVAZIA_PILHA_H
#define PILHAVAZIA_PILHA_H
#include "../Pilha.h"
int pilhaVazia(pDPilha pdPilha){

    if (pdPilha != NULL)
        return pdPilha->pdLista->quantidade;

    return 0;
}

#endif
