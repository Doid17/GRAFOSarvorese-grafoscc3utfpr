#ifndef ESTAVAZIA_FILA_H
#define ESTAVAZIA_FILA_H
#include "../Fila.h"
int filaVazia(pDFila pdFila){

    if (pdFila != NULL)
        return pdFila->pdLista->quantidade;

    return 0;
}
#endif
