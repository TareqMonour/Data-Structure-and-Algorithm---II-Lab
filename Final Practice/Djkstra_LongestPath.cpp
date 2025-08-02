#include <iostream>
#include <list>
#include <queue>
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

class PQNode {
public:
    int v;
    int key;
    PQNode(int v, int key) {
        this->v = v;
        this->key = key;
    }
};

class Comparator {
public:
    bool operator()(const PQNode &a, const PQNode &b) {
        return a.key < b.key;
    }
};

class Graph {
public:
    int V;
    list<AdjListNode> *adjList;

    Graph(int V) {
        this->V = V;
        adjList = new list<AdjListNode>[V + 1];
    }

    void addEdge(int u, int v, int w) {
        adjList[u].push_back(AdjListNode(v, w));
        // Removed the reverse edge for longest path problem
    }

    void printAdjList() {
        for (int i = 1; i <= V; i++) {
            cout << "Vertex " << i << ": ";
            for (AdjListNode x : adjList[i]) {
                cout << "(" << x.v << "," << x.w << ") ";
            }
            cout << endl;
        }
    }

    void dijkstraAlgorithm(int source) {
        int dist[V + 1];
        int parent[V + 1];
        bool visited[V + 1];

        for (int i = 1; i <= V; i++) {
            dist[i] = INT_MIN; // Initialize distances to negative infinity
            parent[i] = -1;
            visited[i] = false;
        }

        dist[source] = 0;
        priority_queue<PQNode, vector<PQNode>, Comparator> pq;
        pq.push(PQNode(source, dist[source]));

        while (!pq.empty()) {
            PQNode pqNode = pq.top();
            pq.pop();

            int u = pqNode.v;

            if (visited[u] == true) {
                continue;
            } else {
                visited[u] = true;
            }

            for (AdjListNode adjListNode : adjList[u]) {
                int v = adjListNode.v;
                int w = adjListNode.w;

                if (visited[v] == false && dist[u] + w > dist[v]) { // Check for longer path
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push(PQNode(v, dist[v]));
                }
            }
        }

        for (int i = 1; i <= V; i++) {
            cout << "Parent of " << i << " is " << parent[i] << endl;
            cout << "Distance of " << i << " from source is " << dist[i] << endl;
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    Graph graph(V);

    for (int i = 1; i <= E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    graph.printAdjList();
    cout << "After running Dijkstra's algorithm: " << endl;
    graph.dijkstraAlgorithm(1);

    return 0;
}
