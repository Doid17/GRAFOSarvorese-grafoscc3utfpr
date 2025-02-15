#ifndef MOSTRAR_GRAFO_COLORIDO_B_MAIS_H
#define MOSTRAR_GRAFO_COLORIDO_B_MAIS_H

#include "../Grafo.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

const char *cores_nome[] = {"Azul", "Verde", "Vermelho", "Amarelo", "Laranja", "Roxo"};
const char *cores_ansi[] = {"\033[34m", "\033[32m", "\033[31m", "\033[33m", "\033[35m", "\033[36m"};
#ifdef _WIN32
const int cores_windows[] = {1, 2, 4, 6, 5, 3}; 
#endif

void mostrarGrafoColorido(pDGrafo grafo) {
    if (!grafo || !grafo->listaVertices) {
        printf("Erro: Grafo não inicializado.\n");
        return;
    }

#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

    printf("\n=== Grafo Colorido ===\n");

    pNoh noh = grafo->listaVertices->primeiro;
    while (noh) {
        pVertice v = (pVertice)noh->info;
        int corIndex = *((int *)v->info) % 6;

#ifdef _WIN32
        SetConsoleTextAttribute(hConsole, cores_windows[corIndex]);
        printf("Vértice %d -> Cor: %s\n", *((int *)v->info), cores_nome[corIndex]);
        SetConsoleTextAttribute(hConsole, 7); 
#else
        printf("%sVértice %d -> Cor: %s\033[0m\n", cores_ansi[corIndex], *((int *)v->info), cores_nome[corIndex]);
#endif

        noh = noh->prox;
    }
}

#endif

