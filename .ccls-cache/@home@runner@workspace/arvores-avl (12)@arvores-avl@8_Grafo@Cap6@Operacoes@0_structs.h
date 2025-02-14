#ifndef STRUCTS_GRAFO_H
#define STRUCTS_GRAFO_H
#include "../Grafo.h"

struct dGrafo{
   pDLista listaVertices;

};

struct vertice{
   void          *info; 
   int            grau; 
   int            cor; //cor vertice
   pDLista        listaAdjacencias;
};


#endif
