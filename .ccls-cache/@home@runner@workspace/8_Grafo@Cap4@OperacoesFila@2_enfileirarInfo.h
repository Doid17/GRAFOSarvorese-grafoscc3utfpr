#ifndef ENFILEIRAR_INFO_FILA_H
#define ENFILEIRAR_INFO_FILA_H
#include "../Fila.h"
void enfileirarInfo(pDFila pdFila, void *info){

   if (pdFila != NULL)
       incluirInfo(pdFila->pdLista, info);
}

#endif
