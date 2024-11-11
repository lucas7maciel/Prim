
#include <iostream>
#include "../include/helper.h"

void printHelper() {
    printf("Esta aplicacao e destinada a encontrar a arvore geradora minima de um grafo utilizando o algoritmo de Prim!\n\n");

    printf("O usuario pode escolher as seguintes opcoes atraves do terminal:\n");
    printf("-f <arquivo> : Faz a leitura dos inputs utilizados a partir do arquivo informado\n");
    printf("-o <arquivo> : Redireciona a saida da aplicacao para o arquivo especificado\n");
    printf("-i <vertice> : Escolhe um vertice inicial para que a busca seja iniciada\n");
    printf("-s           : Exibe a solucao\n");
    printf("-h           : Exibe este helper\n\n");

    printf("Formatacao desejada do input:\n");
    printf("-vertices -arestas\n");
    printf("-v1 -v2 -peso\n");
    printf("-v1 -v2 -peso\n");
    printf("(...)\n");
}