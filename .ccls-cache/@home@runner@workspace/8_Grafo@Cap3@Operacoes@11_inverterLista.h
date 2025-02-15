#ifndef INVERTER_LISTA_H
#define INVERTER_LISTA_H

#include "../Lista.h"
/* -------------------------------------*/
void inverterLista(pDLista pd){

    pNoh atual, aux, aux1;

    atual       = pd->primeiro;
    aux         = atual->prox;
    atual->prox = NULL;

    while(aux != NULL){
        aux1      = aux->prox;
        aux->prox = atual;

        atual = aux;
        aux   = aux1;
    }

    pd->ultimo   = pd->primeiro;
    pd->primeiro = atual;

}

#endif

