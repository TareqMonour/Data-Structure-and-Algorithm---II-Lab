#include <bits/stdc++.h>
using namespace std;
#define MAX_V 100

int adjMatrix[MAX_V][MAX_V];

void constructAdjacencyMatrix(int V, int edges[][3], int E) {
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            adjMatrix[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < E; ++i) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        int w = edges[i][2];
        adjMatrix[u][v] = w;
    }

    for (int i = 0; i < V; ++i)
        adjMatrix[i][i] = 0;
}

void printAdjacencyMatrix(int V) {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (adjMatrix[i][j] == INT_MAX)
               cout << "INF ";
            else
                cout << adjMatrix[i][j] << " ";
        }
        cout <<endl;
    }
}

void floydWarshall(int V) {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (adjMatrix[i][k] != INT_MAX && adjMatrix[k][j] != INT_MAX &&
                    adjMatrix[i][k] + adjMatrix[k][j] < adjMatrix[i][j]) {
                    adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
                }
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the Number of Vertices and Edges: ";
    cin >> V >> E;

    int edges[MAX_V][3];
    cout << "Enter Edges (u v w):\n";
    for (int i = 0; i < E; ++i)
    cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    constructAdjacencyMatrix(V, edges, E);
    printAdjacencyMatrix(V);

    floydWarshall(V);

    cout << "Shortest Distances Between Every Pair of Vertices:\n";
    printAdjacencyMatrix(V);

    return 0;
}
