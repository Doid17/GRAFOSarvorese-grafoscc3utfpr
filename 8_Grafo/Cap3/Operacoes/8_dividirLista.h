#ifndef DIVIDIR_LISTA_H
#define DIVIDIR_LISTA_H
#include "../Lista.h"
pDLista dividirLista(pDLista pListaOriginal, int pos)
{
    /* cria a nova lista para guardar parte do nohs da lista original */
    pDLista pNovaLista = criarLista();

    /* percorre a lista original para encontrar a posicao onde deve ser dividida */
    pNoh atual    = pListaOriginal->primeiro;
    int  contador = 1;
    /* a condicao do loop preve o caso em que a posicao seja maior que a
       quantidade de nohs da lista */
    while (contador < pos && atual != NULL)
    {
       atual = atual->prox;
       contador++;
    }

    /* verifica se alcancou o final da lista */
    if (atual != NULL){
       /* atualiza o descritor da nova lista */
       pNovaLista->primeiro   = atual->prox;
       pNovaLista->ultimo     = pListaOriginal->ultimo;
       pNovaLista->quantidade =
                pListaOriginal->quantidade - pos;

       /* atualiza o descritor da lista original */
       pListaOriginal->ultimo = atual;
       pListaOriginal->quantidade = pos;
       /* finaliza a lista original */
       atual->prox = NULL;
    }

    return pNovaLista;
}

#endif
