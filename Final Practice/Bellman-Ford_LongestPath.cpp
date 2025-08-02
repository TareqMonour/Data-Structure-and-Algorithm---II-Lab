#include <iostream>
#include <list>
#include <vector>
using namespace std;

class AdjListNode {
public:
    int v;
    int w;

    AdjListNode(int v, int w) {
        this->v = v;
        this->w = w;
    }
};

class Graph {
public:
    int V;
    list<AdjListNode>* adjList;

    Graph(int V) {
        this->V = V;
        adjList = new list<AdjListNode>[V + 1];
    }

    void addEdge(int u, int v, int w) {
        adjList[u].push_back(AdjListNode(v, w));
    }

    void printAdjList() {
        for (int i = 1; i <= V; i++) {
            for (AdjListNode x : adjList[i]) {
                cout << "(" << x.v << "," << x.w << ") ";
            }
            cout << endl;
        }
    }

    void bellmanFordAlgorithm(int s) {
        vector<int> d(V + 1, -9999); // Initialize distances with negative infinity
        vector<int> p(V + 1, -1); // Initialize parents with -1

        d[s] = 0;

        // Relax edges repeatedly
        for (int i = 1; i <= V - 1; i++) {
            for (int u = 1; u <= V; u++) {
                for (AdjListNode aln : adjList[u]) {
                    int v = aln.v;
                    int w = aln.w;
                    if (d[u] + w > d[v]) {
                        d[v] = d[u] + w;
                        p[v] = u;
                    }
                }
            }
        }

        // Print parents (optional)
        for (int i = 1; i <= V; i++) {
            cout << "Parent of " << i << " is " << p[i] << endl;
        }

        // Print distances (optional)
        for (int i = 1; i <= V; i++) {
            cout << "Longest distance to " << i << " is " << d[i] << endl;
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    Graph graph(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    graph.printAdjList();
    cout << "After running Bellman-Ford's algorithm" << endl;
    graph.bellmanFordAlgorithm(1);

    return 0;
}
