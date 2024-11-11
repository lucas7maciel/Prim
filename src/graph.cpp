
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <fstream>

#include "../include/graph.h"

using namespace std;

class Graph
{
    vector<vector<int>> adjMatrix;
    int edgesCount;

public:
    Graph(int vectorCount, int edges)
    {
        adjMatrix = vector<vector<int>>(vectorCount, vector<int>(vectorCount, -1));
        edgesCount = edges;
    }

    void addEdge(int a, int b, int weight)
    {
        adjMatrix[a][b] = weight;
        adjMatrix[b][a] = weight;
    }

    void printAgm()
    {
        int iterator = 0, currVector = 0;
        vector<vector<int>> agm = vector<vector<int>>(edgesCount, vector<int>(3, 0));

        // Encontrar o menor peso
        while (true)
        {
            int weight = -1, to = -1;

            for (int i = 0; i < adjMatrix.size(); i++)
            {
                if ((weight == -1 || weight > adjMatrix[currVector][i]) && adjMatrix[currVector][i] != -1)
                {
                    weight = adjMatrix[currVector][i];
                    to = i;
                }
            }

            if (weight == -1)
            {
                break;
            }

            agm[iterator][0] = currVector;
            agm[iterator][1] = to;

            // Impede que o vertice seja indicado 2 vezes
            for (int i = 0; i < adjMatrix.size(); i++)
            {
                adjMatrix[currVector][i] = -1;
                adjMatrix[i][currVector] = -1;
            }

            currVector = to;
            iterator++;
        }

        // Printar AGM
        for (int i = 0; i < iterator; i++)
        {
            printf("(%i, %i)", agm[i][0] + 1, agm[i][1] + 1);

            if (i != iterator)
            {
                printf(" ");
            }
        }
    }
};

void solution(string inputPath, string outputPath, int initialVert)
{
    printf("Solucionando");

    ifstream inputFile(inputPath);

    // Neste caso, os inputs serao lidos a partir deste arquivo
    if (inputFile.is_open())
    {
        string line;

        int verts, edges;

        if (getline(inputFile, line))
        {
            stringstream ss(line);

            if (ss >> verts >> edges)
            {
            }
            else
            {
                cout << "Erro ao ler numeros do arquivo\n" << line << endl;
                return;
            }
        }
        else
        {
            cout << "Falha ao informar entradas corretamente\n";
            return;
        }

        for (int i = 0; i < edges; i++)
        {
            if (!getline(inputFile, line))
            {
                cout << "Faltam linhas no input\n";
                return;
            }

            stringstream ss(line);
            int from, to, weight;

            ss >> from >> to >> weight;

            printf("From: %i, To: %i, Weight: %i\n", from, to, weight);
            // graph.addEdge(from - 1, to - 1);
        }

        // graph.print(outputPath);

        inputFile.close();
    }
    else if (inputPath.empty())
    {
        // printf("Digite os inputs pelo terminal (A formatacao pode ser encontrada no helper)\n");
        // Fazer depois...
    } else {
        printf("Falha ao abrir arquivo informado, verifique se o caminho esta correto\n");
    }

    printf("Its over\n");
}