#include <iostream>
#include <string.h>
#include <cstdlib>

#include "../include/helper.h"
#include "../include/graph.h"

using namespace std;

int main(int argc, char **args)
{
    string outputPath, inputPath;
    int initialVert;

    // Checar opcoes escolhidas
    for (int i = 0; i < argc; i++)
    {
        // Printar helper
        if (!strcmp(args[i], "-h"))
        {
            printHelper();
        }

        // Printar solucao
        if (!strcmp(args[i], "-s")) {
            printf("Solucao\n");
            // Printar solucao
        }

        // Redirecionar saida para arquivo
        if (!strcmp(args[i], "-o") && i != argc - 1)
        {
            outputPath = args[++i];
        }
        else if (!strcmp(args[i], "-o"))
        {
            printf("Um caminho para o arquivo precisa ser especificado apos '-o'\n");
        }

        // Indicar arquivo que contem o grafo de entrada
        if (!strcmp(args[i], "-f") && i != argc - 1)
        {
            inputPath = args[++i];
        }
        else if (!strcmp(args[i], "-f"))
        {
            printf("Um caminho para o arquivo precisa ser especificado apos '-f'\n");
        }

        // Definir vertice inicial
        if (!strcmp(args[i], "-i") && i != argc - 1)
        {
            int vert = atoi(args[++i]); // Converte o valor para um inteiro
            initialVert = vert;
            printf("Vertice inicial: %i", vert);
        }
        else if (!strcmp(args[i], "-i"))
        {
            printf("O vertice inicial precisa ser especificado apos '-i'\n");
        }
    }

    solution(inputPath, outputPath, initialVert);
    return 0;
}