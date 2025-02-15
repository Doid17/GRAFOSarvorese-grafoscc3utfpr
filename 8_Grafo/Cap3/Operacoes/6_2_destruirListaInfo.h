#ifndef DESTRUIR_LISTA_INFO_H
#define DESTRUIR_LISTA_INFO_H
/* -------------------------------------*/
#include "../Lista.h"


void destruirListaInfo(pDLista lista, FuncaoLiberacao fl) {
    if (lista == NULL) return;

    pNoh atual = lista->primeiro;
    while (atual != NULL) {
        pNoh proximo = atual->prox;
        if (fl != NULL) {
            fl(atual->info); 
        }
        free(atual); 
        atual = proximo;
    }
    free(lista); 
}

#endif
