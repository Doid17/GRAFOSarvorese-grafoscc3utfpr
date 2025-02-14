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

void imprimeVerticeSemAdjacencias(void *info1) {
  pVertice v = (pVertice)info1;
  printf("\nVértice %d - ", *((int *)v->info));
}

void *alocaInfoVertice(void *info) {
  pVertice pv = (pVertice)malloc(sizeof(Vertice));
  pv->info = alocaInfoInt(((pVertice)info)->info);
  return pv;
}

int main() {
  int vertices[] = {1, 2, 3, 4, 5};
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
    printf("|  3  - Excluir Vértice [implementar]       |\n");
    printf("|  4  - Excluir Aresta  [implementar]       |\n");
    printf("|  5  - Mostrar grafo                       |\n");
    printf("|  6  - Busca em profundidade               |\n");
    printf("|  7  - Busca em amplitude [implementar]    |\n");
    printf("|  8  - Existe caminho? entre dois vértices |\n");
    printf("|  9  - Encontra caminho entre dois vértices|\n");
    printf("| 11  - Criação de exemplo para coloração   |\n");
    printf("| 12  - Coloração do grafo                  |\n");
    printf("| 13  - grafo bipartido                     |\n");
    printf("| 14  - grafo bipartido para emparelhamento |\n");
    printf("| 16  - Criar Grafo conexo                  |\n");
    printf("| 17  - Verifica se o grafo e conexo        |\n");
    printf("| 18  - Excluir grafo atual                 |\n");
    printf("| 19  - Criar grafo Hamiltoniano/Euleriano  |\n");
    printf("| 20  - Verificar se o grafo é Hamiltoniano |\n");
    printf("| 21  - Verificar se o grafo é Euleriano    |\n");
    printf("| 10  - Sair                                |\n");
    printf("=============================================\n");
    printf("Escolha uma opção: ");

    scanf("%d", &opcao);

    switch (opcao) {
    case 0:
      for (int i = 0; i < 5; i++) {
        incluirVertice(grafo, &vertices[i], comparaVertice);
      }
      incluirAresta(grafo, &vertices[0], &vertices[1], comparaVertice);
      incluirAresta(grafo, &vertices[1], &vertices[3], comparaVertice);
      incluirAresta(grafo, &vertices[2], &vertices[3], comparaVertice);
      incluirAresta(grafo, &vertices[2], &vertices[4], comparaVertice);
      incluirAresta(grafo, &vertices[3], &vertices[4], comparaVertice);
      incluirAresta(grafo, &vertices[4], &vertices[1], comparaVertice);
      mostrarGrafo(grafo, imprimeVertice);
      getchar();
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

    case 5:
      mostrarGrafo(grafo, imprimeVertice);
      getchar();
      break;

    case 6:
      buscaEmProfundidade(grafo, comparaVertice, imprimeVerticeSemAdjacencias);
      getchar();
      break;

    case 8:
      printf("\nID do vértice origem: ");
      scanf("%d", &vOrigem);
      printf("\nID do vértice destino: ");
      scanf("%d", &vDestino);
      int result = existeCaminho(grafo, &vOrigem, &vDestino, comparaVertice);
      printf(result ? "Existe caminho!" : "Não existe caminho!");
      getchar();
      break;

    case 9:
      printf("\nID do vértice origem: ");
      scanf("%d", &vOrigem);
      printf("\nID do vértice destino: ");
      scanf("%d", &vDestino);
      pDLista caminho = getCaminho(grafo, &vOrigem, &vDestino, comparaVertice,
                                   alocaInfoVertice);
      if (caminho->quantidade > 0) {
        printf("\n Existe um caminho: ");
        imprimirLista(caminho, imprimeVerticeSemAdjacencias);
      } else {
        printf("\n *** NÃO existe um caminho. *** ");
      }
      getchar();
      break;
 case 11:
    printf("\nCriando um grafo perfeito para coloração...\n");

    destruirListaInfo(grafo->listaVertices, free);
    grafo->listaVertices = criarLista();

    int vertices_perfeitos[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        incluirVertice(grafo, &vertices_perfeitos[i], comparaVertice);
    }

    incluirAresta(grafo, &vertices_perfeitos[0], &vertices_perfeitos[1], comparaVertice);
    incluirAresta(grafo, &vertices_perfeitos[1], &vertices_perfeitos[2], comparaVertice);
    incluirAresta(grafo, &vertices_perfeitos[2], &vertices_perfeitos[3], comparaVertice);
    incluirAresta(grafo, &vertices_perfeitos[3], &vertices_perfeitos[4], comparaVertice);
    incluirAresta(grafo, &vertices_perfeitos[4], &vertices_perfeitos[5], comparaVertice);
    incluirAresta(grafo, &vertices_perfeitos[5], &vertices_perfeitos[0], comparaVertice);

    printf("Grafo criado com sucesso! Estrutura:\n");
    mostrarGrafo(grafo, imprimeVertice);

    // Chamando a coloração do grafo
    colorirGrafo(grafo, comparaVertice);

    // Chamando a nova representação gráfica colorida
    mostrarGrafoColorido(grafo);

    getchar();
    break;



    case 12:
      colorirGrafo(grafo, comparaVertice);
      getchar();
      break;



      case 13:
      printf("\nCriando um grafo bipartido...\n");

      destruirListaInfo(grafo->listaVertices, free);
      grafo->listaVertices = criarLista();

      int vertices_nao_bipartidos[] = {1, 2, 3, 4, 5, 6};
      for (int i = 0; i < 6; i++) {
          incluirVertice(grafo, &vertices_nao_bipartidos[i], comparaVertice);
      }

      incluirAresta(grafo, &vertices_nao_bipartidos[0], &vertices_nao_bipartidos[3], comparaVertice);
      incluirAresta(grafo, &vertices_nao_bipartidos[0], &vertices_nao_bipartidos[4], comparaVertice);
      incluirAresta(grafo, &vertices_nao_bipartidos[0], &vertices_nao_bipartidos[5], comparaVertice);
      incluirAresta(grafo, &vertices_nao_bipartidos[1], &vertices_nao_bipartidos[3], comparaVertice);
      incluirAresta(grafo, &vertices_nao_bipartidos[1], &vertices_nao_bipartidos[4], comparaVertice);
      incluirAresta(grafo, &vertices_nao_bipartidos[1], &vertices_nao_bipartidos[5], comparaVertice);
      incluirAresta(grafo, &vertices_nao_bipartidos[2], &vertices_nao_bipartidos[3], comparaVertice);
      incluirAresta(grafo, &vertices_nao_bipartidos[2], &vertices_nao_bipartidos[4], comparaVertice);
      incluirAresta(grafo, &vertices_nao_bipartidos[2], &vertices_nao_bipartidos[5], comparaVertice);

  
      printf("Grafo criado com sucesso! Estrutura:\n");
      mostrarGrafo(grafo, imprimeVertice);

      if (grafoBipartido(grafo, comparaVertice)) {
          printf("O grafo é bipartido!\n");
      } else {
          printf("O grafo NÃO é bipartido.\n");
      }
        incluirAresta(grafo, &vertices_nao_bipartidos[3], &vertices_nao_bipartidos[4], comparaVertice);

        printf("criado aresta extra entre vértices do mesmo conjunto\n");
        //mostrarGrafo(grafo, imprimeVertice);

        if (grafoBipartido(grafo, comparaVertice)) {
            printf("O grafo é bipartido!\n");
        } else {
            printf("O grafo NÃO é bipartido.\n");
        }

      getchar();
      break;

      case 14:
      printf("\nCriando um grafo bipartido para emparelhamento...\n");

      destruirListaInfo(grafo->listaVertices, free);
      grafo->listaVertices = criarLista();

      int vertices_emparelhamento[] = {1, 2, 3, 4, 5, 6};
      for (int i = 0; i < 6; i++) {
          incluirVertice(grafo, &vertices_emparelhamento[i], comparaVertice);
      }

      incluirAresta(grafo, &vertices_emparelhamento[0], &vertices_emparelhamento[3], comparaVertice);
      incluirAresta(grafo, &vertices_emparelhamento[0], &vertices_emparelhamento[4], comparaVertice);
      incluirAresta(grafo, &vertices_emparelhamento[1], &vertices_emparelhamento[4], comparaVertice);
      incluirAresta(grafo, &vertices_emparelhamento[1], &vertices_emparelhamento[5], comparaVertice);
      incluirAresta(grafo, &vertices_emparelhamento[2], &vertices_emparelhamento[5], comparaVertice);

      printf("Grafo criado com sucesso! Estrutura:\n");
      mostrarGrafo(grafo, imprimeVertice);

      int numEmparelhamentos = emparelhamentoGrafoBipartido(grafo, comparaVertice);
      printf("Número máximo de emparelhamentos: %d\n", numEmparelhamentos);

      getchar();
      break;




      case 16:
          printf("\nCriando um grafo perfeitamente conexo...\n");

          destruirListaInfo(grafo->listaVertices, free);
          grafo->listaVertices = criarLista();

          int vertices_conexos[] = {1, 2, 3, 4, 5, 6};
          for (int i = 0; i < 6; i++) {
              incluirVertice(grafo, &vertices_conexos[i], comparaVertice);
          }

          for (int i = 0; i < 6; i++) {
              for (int j = i + 1; j < 6; j++) {
                  incluirAresta(grafo, &vertices_conexos[i], &vertices_conexos[j], comparaVertice);
              }
          }

          printf("Grafo criado com sucesso! Estrutura:\n");
          mostrarGrafo(grafo, imprimeVertice);
          getchar();
          break;

      case 17:
          printf("\nVerificando se o grafo é conexo...\n");
          if (ehGrafoConexo(grafo, comparaVertice)) {
              printf("O grafo é conexo!\n");
          } else {
              printf("NÃO e um grafo conexo.\n");
          }
          getchar();
          break;
      
    case 18:
      printf("\nExcluindo o grafo atual...\n");
      destruirListaInfo(grafo->listaVertices, free);
      grafo->listaVertices = criarLista();
      printf("Grafo excluído com sucesso!\n");
      getchar();
      break;
        
    case 19:
      printf("\nCriando grafo Hamiltoniano e Euleriano...\n");

      destruirListaInfo(grafo->listaVertices, free);
      grafo->listaVertices = criarLista();

      int vertices_ham_eul[] = {1, 2, 3, 4, 5, 6};
      for (int i = 0; i < 6; i++) {
        incluirVertice(grafo, &vertices_ham_eul[i], comparaVertice);
      }
      incluirAresta(grafo, &vertices_ham_eul[0], &vertices_ham_eul[1],
                    comparaVertice);
      incluirAresta(grafo, &vertices_ham_eul[1], &vertices_ham_eul[2],
                    comparaVertice);
      incluirAresta(grafo, &vertices_ham_eul[2], &vertices_ham_eul[3],
                    comparaVertice);
      incluirAresta(grafo, &vertices_ham_eul[3], &vertices_ham_eul[4],
                    comparaVertice);
      incluirAresta(grafo, &vertices_ham_eul[4], &vertices_ham_eul[5],
                    comparaVertice);
      incluirAresta(grafo, &vertices_ham_eul[5], &vertices_ham_eul[0],
                    comparaVertice);
      incluirAresta(grafo, &vertices_ham_eul[1], &vertices_ham_eul[4],
                    comparaVertice);
      incluirAresta(grafo, &vertices_ham_eul[2], &vertices_ham_eul[5],
                    comparaVertice);

      printf("Grafo criado com sucesso! Estrutura:\n");
      mostrarGrafo(grafo, imprimeVertice);
      getchar();
      break;
    case 20:
      printf("\nVerificando se o grafo é Hamiltoniano...\n");
      if (ehHamiltoniano(grafo, comparaVertice)) {
        printf("O grafo é Hamiltoniano!\n");
      } else {
        printf("NÃO é um Hamiltoniano.\n");
      }
      getchar();
      mostrarGrafo(grafo, imprimeVertice);
      break;

    case 21:
      printf("\nVerificando se o grafo é Euleriano...\n");
      if (ehEuleriano(grafo)) {
        printf("O grafo é Euleriano!\n");
      } else {
        printf("NÃO é um grafo Euleriano.\n");
      }
      getchar();
      break;
    }
  } while (opcao != 10);
  return 0;
}
