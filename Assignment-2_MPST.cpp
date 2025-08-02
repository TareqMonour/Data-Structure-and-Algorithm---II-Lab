#include <iostream>
#include <list>
#include <limits>
#include <cmath>
using namespace std;

class AdjListNode {
public:
    int v;
    int w;

    AdjListNode(int v, int w) {
        this->v = v;
        this->w = w;
    }

    class Comparator {
        public:
        bool operator()(const AdjListNode& a, const AdjListNode& b) {
            return a.w < b.w;
        }
    };
};

class Graph {
public:
    int V;
    list<AdjListNode> *adjList;

    Graph(int V) {
        this->V = V;
        adjList = new list<AdjListNode>[V];
    }

    void addEdge(int u, int v, int w) {
        adjList[u].push_back(AdjListNode(v, w));
        adjList[v].push_back(AdjListNode(u, w));
        adjList[u].sort(AdjListNode::Comparator());
        adjList[v].sort(AdjListNode::Comparator());
    }

    int minKey(int key[], bool mstSet[]) {
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; v++)
            if (mstSet[v] == false && key[v] < min)
                min = key[v], min_index = v;
        return min_index;
    }

    void printMPST(int parent[]) {
        cout << "Edges:\n";
        int minProduct = 1;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << "-" << i << endl;
            for (auto it = adjList[i].begin(); it != adjList[i].end(); it++) {
                if (it->v == parent[i]) {
                    minProduct *= it->w;
                    break;
                }
            }
        }
        cout << "Minimum Product: " << minProduct << endl;
    }

    void primMPST() {
        int parent[V];
        int key[V];
        bool mstSet[V];
        for (int i = 0; i < V; i++)
            key[i] = INT_MAX, mstSet[i] = false;

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
                int v = it->v;
                int w = it->w;
                if (mstSet[v] == false && w < key[v]) {
                    parent[v] = u, key[v] = w;
                }
            }
        }

        printMPST(parent);
    }
};

int main() {
    int V, E;
    cout << "Enter the Number of Vertexes and Edges: ";
    cin >> V >> E;

    Graph graph(V);
    cout << "Enter the Edges in the Format (u v w):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    graph.primMPST();

    return 0;
}
