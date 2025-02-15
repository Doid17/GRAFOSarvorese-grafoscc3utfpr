#ifndef GRAFO_IMPL_H
#define GRAFO_IMPL_H

/* observe que o grafo utiliza as bibliotecas Lista.h e Pilha.h*/
#include "../Cap3/Lista.h"
#include "../Cap4/Pilha.h"

/* implementacao de grafo */
#include "TAD_Grafo.h"

#include "Operacoes/0_structs.h"
#include "Operacoes/1_criarGrafo.h"
#include "Operacoes/2_incluirVertice.h"
#include "Operacoes/3_incluirAresta.h"
#include "Operacoes/4_mostrarGrafo.h"
#include "Operacoes/5_excluirVertice.h"
#include "Operacoes/6_excluirAresta.h"
#include "Operacoes/7_buscaProfundidade.h"
#include "Operacoes/9_existeCaminho.h"
#include "Operacoes/10_getCaminho.h"
#include "Operacoes/11_buscarVerticesIncidentes.h"
#include "Operacoes/11.1_buscarVertice.h"

#include "Operacoes/12_colorirGrafo.h"
#include "Operacoes/13_mostrarGrafoColorido.h"

#include "Operacoes/14_grafoConexo.h"
#include "Operacoes/15_grafoBipartido.h"
#include "Operacoes/16_EmparelhamentoGrafoBipartido.h"

#include "Operacoes/17_Hamiltoniano.h"
#include "Operacoes/18_Euleriano.h"
#include "Operacoes/19_destruirGrafo.h"


#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <fcntl.h>
#include <stddef.h>
#include <signal.h>
#include <errno.h>
#ifdef _WIN32
#include <conio.h>
#else
#define getch() getchar()
#endif
// system("chcp 65001 > nul");




#endif