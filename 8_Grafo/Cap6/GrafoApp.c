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
  printf("\nVertice %d - Adjacencias [", *((int *)v->info));
  imprimirLista(v->listaAdjacencias, imprimeAdjacencia);
  printf("]\n");
}

void imprimeVerticeSemAdjacencias(void *info1) {
  pVertice v = (pVertice)info1;
  printf("\nVertice %d - ", *((int *)v->info));
}

void *alocaInfoVertice(void *info) {
  pVertice pv = (pVertice)malloc(sizeof(Vertice));
  pv->info = alocaInfoInt(((pVertice)info)->info);
  return pv;
}

int main() {
  system("chcp 65001 > nul");
  int vertices[] = {1, 2, 3, 4, 5};
  int opcao, vOrigem, vDestino;
  int *pv;
  pDGrafo grafo = criarGrafo();

  do {
    printf("\n=============================================");
    printf("\n|           MENU - OPERACOES NO GRAFO       |");
    printf("\n=============================================\n");
    printf("|  0  - Criar grafo                         |\n");
    printf("|  1  - Incluir Vertice                     |\n");
    printf("|  2  - Incluir Aresta                      |\n");
    printf("|  3  - Mostrar grafo                       |\n");
    printf("|  4  - Criacao de exemplo para coloracao   |\n");
    printf("|  5  - Coloracao do grafo                  |\n");
    printf("|  6  - grafo bipartido                     |\n");
    printf("|  7  - grafo bipartido para emparelhamento |\n");
    printf("|  8  - Criar Grafo conexo                  |\n");
    printf("|  9  - Verifica se o grafo e conexo        |\n");
    printf("|  10  - Excluir grafo atual                 |\n");
    printf("|  11  - Criar grafo Hamiltoniano/Euleriano  |\n");
    printf("|  12  - Verificar se o grafo e Hamiltoniano |\n");
    printf("|  13  - Verificar se o grafo e Euleriano    |\n");
    printf("|  14 - Sair                                |\n");
    printf("=============================================\n");
    printf("Escolha uma opcao: ");

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
      printf("ID do vertice: ");
      scanf("%d", pv);
      incluirVertice(grafo, pv, comparaVertice);
      mostrarGrafo(grafo, imprimeVertice);
      getchar();
      break;

    case 2:
      printf("\nID do vertice origem: ");
      scanf("%d", &vOrigem);
      printf("\nID do vertice destino: ");
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
        printf("\nCriando um grafo perfeito para coloração...\n");

        destruirGrafo(grafo);
        grafo = criarGrafo();

        int vertices_perfeitos[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for (int i = 0; i < 10; i++) {
            incluirVertice(grafo, &vertices_perfeitos[i], comparaVertice);
        }
         printf("\nCriando ...\n");

        // Criando conexões para garantir um número alto de cores
        incluirAresta(grafo, &vertices_perfeitos[0], &vertices_perfeitos[1], comparaVertice);
        incluirAresta(grafo, &vertices_perfeitos[0], &vertices_perfeitos[3], comparaVertice);
        incluirAresta(grafo, &vertices_perfeitos[0], &vertices_perfeitos[5], comparaVertice);

        incluirAresta(grafo, &vertices_perfeitos[1], &vertices_perfeitos[2], comparaVertice);
        incluirAresta(grafo, &vertices_perfeitos[1], &vertices_perfeitos[4], comparaVertice);

        incluirAresta(grafo, &vertices_perfeitos[2], &vertices_perfeitos[5], comparaVertice);
        incluirAresta(grafo, &vertices_perfeitos[2], &vertices_perfeitos[6], comparaVertice);

        incluirAresta(grafo, &vertices_perfeitos[3], &vertices_perfeitos[4], comparaVertice);
        incluirAresta(grafo, &vertices_perfeitos[3], &vertices_perfeitos[7], comparaVertice);

        incluirAresta(grafo, &vertices_perfeitos[4], &vertices_perfeitos[5], comparaVertice);
        incluirAresta(grafo, &vertices_perfeitos[4], &vertices_perfeitos[8], comparaVertice);

        incluirAresta(grafo, &vertices_perfeitos[5], &vertices_perfeitos[6], comparaVertice);
        incluirAresta(grafo, &vertices_perfeitos[5], &vertices_perfeitos[9], comparaVertice);

        incluirAresta(grafo, &vertices_perfeitos[6], &vertices_perfeitos[7], comparaVertice);
        incluirAresta(grafo, &vertices_perfeitos[7], &vertices_perfeitos[8], comparaVertice);
        incluirAresta(grafo, &vertices_perfeitos[8], &vertices_perfeitos[9], comparaVertice);

        printf("Grafo criado com sucesso! Estrutura:\n");
        mostrarGrafo(grafo, imprimeVertice);
        printf("\nCriando ...\n");
        colorirGrafo(grafo, comparaVertice);
        printf("\nCriando ...\n");
        mostrarGrafoColorido(grafo);

        getchar();
        break;


    case 5:
      mostrarGrafo(grafo, imprimeVertice);
      printf("\n");
      colorirGrafo(grafo, comparaVertice);
      mostrarGrafoColorido(grafo);
      getchar();
      break;

    case 6:
      printf("\nCriando um grafo bipartido...\n");

        destruirGrafo(grafo);
        grafo = criarGrafo();

      int vertices_nao_bipartidos[] = {1, 2, 3, 4, 5, 6};
      for (int i = 0; i < 6; i++) {
        incluirVertice(grafo, &vertices_nao_bipartidos[i], comparaVertice);
      }

      incluirAresta(grafo, &vertices_nao_bipartidos[0],
                    &vertices_nao_bipartidos[3], comparaVertice);
      incluirAresta(grafo, &vertices_nao_bipartidos[0],
                    &vertices_nao_bipartidos[4], comparaVertice);
      incluirAresta(grafo, &vertices_nao_bipartidos[0],
                    &vertices_nao_bipartidos[5], comparaVertice);
      incluirAresta(grafo, &vertices_nao_bipartidos[1],
                    &vertices_nao_bipartidos[3], comparaVertice);
      incluirAresta(grafo, &vertices_nao_bipartidos[1],
                    &vertices_nao_bipartidos[4], comparaVertice);
      incluirAresta(grafo, &vertices_nao_bipartidos[1],
                    &vertices_nao_bipartidos[5], comparaVertice);
      incluirAresta(grafo, &vertices_nao_bipartidos[2],
                    &vertices_nao_bipartidos[3], comparaVertice);
      incluirAresta(grafo, &vertices_nao_bipartidos[2],
                    &vertices_nao_bipartidos[4], comparaVertice);
      incluirAresta(grafo, &vertices_nao_bipartidos[2],
                    &vertices_nao_bipartidos[5], comparaVertice);

      printf("Grafo criado com sucesso! Estrutura:\n");
      mostrarGrafo(grafo, imprimeVertice);

      if (grafoBipartido(grafo, comparaVertice)) {
        printf("O grafo e bipartido!\n");
      } else {
        printf("O grafo NAO e bipartido.\n");
      }
      incluirAresta(grafo, &vertices_nao_bipartidos[3],
                    &vertices_nao_bipartidos[4], comparaVertice);

      printf("criado aresta extra entre vertices do mesmo conjunto\n");
      // mostrarGrafo(grafo, imprimeVertice);

      if (grafoBipartido(grafo, comparaVertice)) {
        printf("O grafo e bipartido!\n");
      } else {
        printf("O grafo NAO e bipartido.\n");
      }

      getchar();
      break;

    case 7:
      printf("\nCriando um grafo bipartido para emparelhamento...\n");


        destruirGrafo(grafo);
        grafo = criarGrafo();

      int vertices_emparelhamento[] = {1, 2, 3, 4, 5, 6};
      for (int i = 0; i < 6; i++) {
        incluirVertice(grafo, &vertices_emparelhamento[i], comparaVertice);
      }

      incluirAresta(grafo, &vertices_emparelhamento[0],
                    &vertices_emparelhamento[3], comparaVertice);
      incluirAresta(grafo, &vertices_emparelhamento[0],
                    &vertices_emparelhamento[4], comparaVertice);
      incluirAresta(grafo, &vertices_emparelhamento[1],
                    &vertices_emparelhamento[4], comparaVertice);
      incluirAresta(grafo, &vertices_emparelhamento[1],
                    &vertices_emparelhamento[5], comparaVertice);
      incluirAresta(grafo, &vertices_emparelhamento[2],
                    &vertices_emparelhamento[5], comparaVertice);

      printf("Grafo criado com sucesso! Estrutura:\n");
      mostrarGrafo(grafo, imprimeVertice);

      int numEmparelhamentos =
          emparelhamentoGrafoBipartido(grafo, comparaVertice);
      printf("Numero maximo de emparelhamentos: %d\n", numEmparelhamentos);

      //Teste 2: Remover uma aresta e verificar se o emparelhamento diminui
      excluirAresta(grafo, &vertices_emparelhamento[0], &vertices_emparelhamento[3], comparaVertice);
      printf("\nApós remover a aresta 1 ↔ 4:\n");
      mostrarGrafo(grafo, imprimeVertice);
      int emparelhamentoReduzido = emparelhamentoGrafoBipartido(grafo, comparaVertice);
      printf("Número máximo de emparelhamentos (reduzido): %d\n", emparelhamentoReduzido);


      getchar();
      break;

    case 8:
      printf("\nCriando um grafo perfeitamente conexo...\n");


        destruirGrafo(grafo);
        grafo = criarGrafo();

      int vertices_conexos[] = {1, 2, 3, 4, 5, 6};
      for (int i = 0; i < 6; i++) {
        incluirVertice(grafo, &vertices_conexos[i], comparaVertice);
      }

      for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
          incluirAresta(grafo, &vertices_conexos[i], &vertices_conexos[j],
                        comparaVertice);
        }
      }

      printf("Grafo criado com sucesso! Estrutura:\n");
      mostrarGrafo(grafo, imprimeVertice);
      getchar();
      break;

    case 9:
      printf("\nVerificando se o grafo e conexo...\n");
      if (ehGrafoConexo(grafo, comparaVertice)) {
        printf("O grafo e conexo!\n");
      } else {
        printf("NAO e um grafo conexo.\n");
      }
      getchar();
      break;

    case 10:
        
      printf("\nExcluindo o grafo atual...\n");
        destruirGrafo(grafo);
        
      destruirListaInfo(grafo->listaVertices, free);
      grafo->listaVertices = criarLista();
      printf("Grafo excluido com sucesso!\n");
      getchar();
      break;

          case 11:
          printf("\nCriando grafo Hamiltoniano e Euleriano...\n");

          destruirGrafo(grafo);
          grafo = criarGrafo();

          int vertices_ham_eul[] = {1, 2, 3, 4, 5, 6};
          for (int i = 0; i < 6; i++) {
              incluirVertice(grafo, &vertices_ham_eul[i], comparaVertice);
          }

            incluirAresta(grafo, &vertices_ham_eul[0], &vertices_ham_eul[1], comparaVertice);
            incluirAresta(grafo, &vertices_ham_eul[1], &vertices_ham_eul[2], comparaVertice);
            incluirAresta(grafo, &vertices_ham_eul[2], &vertices_ham_eul[3], comparaVertice);
            incluirAresta(grafo, &vertices_ham_eul[3], &vertices_ham_eul[4], comparaVertice);
            incluirAresta(grafo, &vertices_ham_eul[4], &vertices_ham_eul[5], comparaVertice);
            incluirAresta(grafo, &vertices_ham_eul[5], &vertices_ham_eul[0], comparaVertice);



            printf("Grafo Hamiltoniano e Euleriano criado com sucesso! Estrutura:\n");
            mostrarGrafo(grafo, imprimeVertice);
            getchar();
            break;




    case 12:
      printf("\nVerificando se o grafo é Hamiltoniano...\n");
      if (ehHamiltoniano(grafo, comparaVertice)) {
        printf("O grafo é Hamiltoniano!\n");
      } else {
        printf("NÃO é um Hamiltoniano.\n");
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
  return 0;
}
