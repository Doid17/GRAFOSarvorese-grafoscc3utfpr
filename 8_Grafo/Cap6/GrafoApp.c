#include "../Cap3/Utils.h"
#include "Grafo.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <conio.h>
#else
#define getch() getchar()
#endif

int comparaVertice(void *info1, void *info2) {
    pVertice v1 = (pVertice)info1;
    pVertice v2 = (pVertice)info2;
    int *id1 = (int *)v1->info;
    int *id2 = (int *)v2->info;
    return *id2 - *id1;
}

void imprimeAdjacencia(void *info1) {
    pVertice v = (pVertice)info1;
    printf("%d - ", *((int *)(v->info)));
}

void imprimeVertice(void *info1) {
    pVertice v = (pVertice)info1;
    printf("\nVértice %d - Adjacências [", *((int *)v->info));
    imprimirLista(v->listaAdjacencias, imprimeAdjacencia);
    printf("]\n");
}

int main() {
    system("chcp 65001 > nul");

    int opcao, vOrigem, vDestino;
    int *pv;
    pDGrafo grafo = criarGrafo();

    do {
        printf("\n=============================================");
        printf("\n|           MENU - OPERAÇÕES NO GRAFO       |");
        printf("\n=============================================\n");
        printf("|  0  - Criar grafo                         |\n");
        printf("|  1  - Incluir Vértice                     |\n");
        printf("|  2  - Incluir Aresta                      |\n");
        printf("|  3  - Mostrar grafo                       |\n");
        printf("|  4  - Criação de exemplo para coloração   |\n");
        printf("|  5  - Coloração do grafo                  |\n");
        printf("|  6  - Grafo bipartido                     |\n");
        printf("|  7  - Grafo bipartido para emparelhamento |\n");
        printf("|  8  - Criar Grafo conexo                  |\n");
        printf("|  9  - Verifica se o grafo é conexo        |\n");
        printf("| 10  - Excluir grafo atual                 |\n");
        printf("| 11  - Criar grafo Hamiltoniano/Euleriano  |\n");
        printf("| 12  - Verificar se o grafo é Hamiltoniano |\n");
        printf("| 13  - Verificar se o grafo é Euleriano    |\n");
        printf("| 14  - Sair                                |\n");
        printf("=============================================\n");
        printf("Escolha uma opção: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                if (grafo) destruirGrafo(grafo);
                grafo = criarGrafo();
                printf("Novo grafo criado!\n");
                break;

            case 1:
                pv = (int *)malloc(sizeof(int));
                printf("ID do vértice: ");
                scanf("%d", pv);
                incluirVertice(grafo, pv, comparaVertice);
                mostrarGrafo(grafo, imprimeVertice);
                getchar();
                break;

            case 2:
                printf("\nID do vértice origem: ");
                scanf("%d", &vOrigem);
                printf("\nID do vértice destino: ");
                scanf("%d", &vDestino);
                incluirAresta(grafo, &vOrigem, &vDestino, comparaVertice);
                mostrarGrafo(grafo, imprimeVertice);
                getchar();
                break;

            case 3:
                mostrarGrafo(grafo, imprimeVertice);
                getchar();
                break;

            case 4:
                if (grafo) destruirGrafo(grafo);
                grafo = criarGrafo();
                printf("\nCriando um grafo perfeito para coloração...\n");

                int vertices_coloracao[] = {1, 2, 3, 4, 5, 6};
                for (int i = 0; i < 6; i++) {
                    incluirVertice(grafo, &vertices_coloracao[i], comparaVertice);
                }

                incluirAresta(grafo, &vertices_coloracao[0], &vertices_coloracao[1], comparaVertice);
                incluirAresta(grafo, &vertices_coloracao[1], &vertices_coloracao[2], comparaVertice);
                incluirAresta(grafo, &vertices_coloracao[3], &vertices_coloracao[4], comparaVertice);
                incluirAresta(grafo, &vertices_coloracao[4], &vertices_coloracao[5], comparaVertice);
                incluirAresta(grafo, &vertices_coloracao[5], &vertices_coloracao[0], comparaVertice);

                colorirGrafo(grafo, comparaVertice);
                mostrarGrafoColorido(grafo);
                getchar();
                break;

            case 5:
                colorirGrafo(grafo, comparaVertice);
                mostrarGrafoColorido(grafo);
                getchar();
                break;

            case 6:
                if (grafo) destruirGrafo(grafo);
                grafo = criarGrafo();
                printf("\nCriando um grafo bipartido...\n");

                int vertices_bipartidos[] = {1, 2, 3, 4, 5, 6};
                for (int i = 0; i < 6; i++) {
                    incluirVertice(grafo, &vertices_bipartidos[i], comparaVertice);
                }

                incluirAresta(grafo, &vertices_bipartidos[0], &vertices_bipartidos[3], comparaVertice);
                incluirAresta(grafo, &vertices_bipartidos[1], &vertices_bipartidos[4], comparaVertice);
                incluirAresta(grafo, &vertices_bipartidos[2], &vertices_bipartidos[5], comparaVertice);

                mostrarGrafo(grafo, imprimeVertice);
                getchar();
                break;

            case 7:
                printf("\nCriando um grafo bipartido para emparelhamento...\n");
                // Implementar a lógica de emparelhamento
                getchar();
                break;

            case 8:
                printf("\nCriando um grafo conexo...\n");
                // Implementar a lógica do grafo conexo
                getchar();
                break;

            case 9:
                printf("\nVerificando se o grafo é conexo...\n");
                if (ehGrafoConexo(grafo, comparaVertice)) {
                    printf("O grafo é conexo!\n");
                } else {
                    printf("NÃO é um grafo conexo.\n");
                }
                getchar();
                break;

            case 10:
                if (grafo) {
                    destruirGrafo(grafo);
                    grafo = criarGrafo();
                    printf("Grafo excluído com sucesso!\n");
                } else {
                    printf("Nenhum grafo para excluir!\n");
                }
                getchar();
                break;

            case 11:
                printf("\nCriando grafo Hamiltoniano/Euleriano...\n");
                // Implementar lógica para criar grafo Hamiltoniano/Euleriano
                getchar();
                break;

            case 12:
                printf("\nVerificando se o grafo é Hamiltoniano...\n");
                if (ehHamiltoniano(grafo, comparaVertice)) {
                    printf("O grafo é Hamiltoniano!\n");
                } else {
                    printf("NÃO é um grafo Hamiltoniano.\n");
                }
                getchar();
                break;

            case 13:
                printf("\nVerificando se o grafo é Euleriano...\n");
                if (ehEuleriano(grafo)) {
                    printf("O grafo é Euleriano!\n");
                } else {
                    printf("NÃO é um grafo Euleriano.\n");
                }
                getchar();
                break;
        }
    } while (opcao != 14);

    destruirGrafo(grafo);
    return 0;
}
