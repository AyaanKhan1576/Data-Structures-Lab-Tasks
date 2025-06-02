#pragma once
#include <iostream>
using namespace std;

class graph
{
private:
    bool** adjMatrix;
    int numVertices;
    int count;
    int numEdges;
    int M;

public:
    graph()
    {
        numVertices = 0;
        adjMatrix = NULL;
        count = 0;
        M = 7;
        numEdges = 0;
    }

    graph(int x)
    {
        //x--;
        numVertices = x;
        M = 7;
        numEdges = 0;
        adjMatrix = new bool* [numVertices];
        for (int i = 0; i < numVertices; ++i)
        {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; ++j)
            {
                adjMatrix[i][j] = 0;
            }
        }

        count = 0;
    }

    graph(int x, int y)
    {
        //x--;
        numVertices = x;
        M = y;
        numEdges = 0;
        adjMatrix = new bool* [numVertices];
        for (int i = 0; i < numVertices; ++i)
        {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; ++j)
            {
                adjMatrix[i][j] = 0;
            }
        }

        count = 0;
    }

    bool isEdge(int x, int y)
    {
        if (x >= 0 && x < numVertices && y >= 0 && y < numVertices)
        {
            return adjMatrix[x][y];
        }
        else
        {
            cout << "Invalid vertices\n";
            return 0; // Return false for invalid vertices
        }
    }

    void addEdge(int x, int y)
    {
        x--;
        y--;
        if (x >= 0 && x < numVertices && y >= 0 && y < numVertices)
        {
            if (numEdges >= M)
            {
                cout << "Edges exceeding limit\n";
                return;
            }

            adjMatrix[x][y] = 1;
            adjMatrix[y][x] = 1;
            numEdges++;
        }
        else
        {
            cout << "Invalid vertices\n";
        }
    }

    void removeEdge(int x, int y)
    {
        x--;
        y--;

        if (x >= 0 && x < numVertices && y >= 0 && y < numVertices)
        {
            adjMatrix[x][y] = 0;
            adjMatrix[y][x] = 0;
            numEdges--;
        }
        else
        {
            cout << "Invalid vertices\n";
        }
    }

    void printGraph()
    {
        for (int i = 0; i < numVertices; ++i)
        {
            for (int j = 0; j < numVertices; ++j)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    void display()
    {
        printGraph();
    }

    ~graph()
    {
        for (int i = 0; i < numVertices; ++i)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};



//int main()
//{
//    graph g1(8, 7);
//    
//    g1.addEdge(1, 2);
//    g1.addEdge(2, 3);
//    g1.addEdge(4, 5);
//    g1.addEdge(1, 5);
//    g1.addEdge(6, 1);
//    g1.addEdge(7, 4);
//    g1.addEdge(3, 8);
//
//    g1.display();
//    
//    return 0;
//}