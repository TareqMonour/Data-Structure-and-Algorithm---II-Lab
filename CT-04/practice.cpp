#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    string u;
    string v;
    int w;
    string safety;

    Edge(string u, string v, int w, string safety) {
        this->u = u;
        this->v = v;
        this->w = w;
        this->safety = safety;
    }
};

bool comparator(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

class Graph {
public:
    int V;
    int E;
    string vertexSet[100];
    vector<Edge> edgesVector;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void makeSet() {
        for (int i = 1; i <= V; i++) {
            vertexSet[i] = "";
        }
    }

    int findSet(string a) {
        for (int i = 1; i <= V; i++) {
            if (vertexSet[i] == a) {
                return i;
            }
        }
        return -1;
    }

    void unionVertices(string a, string b) {
        int u = findSet(a);
        int v = findSet(b);
        if (u != -1 && v != -1 && u != v) {
            vertexSet[u] = b;
        }
    }

    void addEdge(string u, string v, int w, string safety) {
        edgesVector.push_back(Edge(u, v, w, safety));
        if (findSet(u) == -1) {
            for (int i = 1; i <= V; i++) {
                if (vertexSet[i] == "") {
                    vertexSet[i] = u;
                    break;
                }
            }
        }
        if (findSet(v) == -1) {
            for (int i = 1; i <= V; i++) {
                if (vertexSet[i] == "") {
                    vertexSet[i] = v;
                    break;
                }
            }
        }
    }

    void printEdgesVector() {
        for (Edge e : edgesVector) {
            cout << "(" << e.u << "," << e.v << "," << e.w << "," << e.safety << ")" << endl;
        }
    }

    void mstKruskal() {
        vector<Edge> A;
        makeSet();
        sort(edgesVector.begin(), edgesVector.end(), comparator);
        for (Edge e : edgesVector) {
            string u = e.u;
            string v = e.v;
            if (findSet(u) != findSet(v) && e.safety == "safe") {
                A.push_back(e);
                unionVertices(u, v);
            }
        }

        cout << "The selected edges:" << endl;
        for (Edge e : A) {
            cout << "(" << e.u << "," << e.v << "," << e.w << "," << e.safety << ")" << endl;
        }

        int totalWeight = 0;
        for (Edge e : A) {
            totalWeight += e.w;
        }
        cout << "Total weight of the MST: " << totalWeight << endl;
    }
};

int main() {
    int V, E;
    cout << "Number of cities: ";
    cin >> V;
    cout << "Number of routes: ";
    cin >> E;
    Graph graph(V, E);

    cout << "Enter routes in the format (source destination weight safety):" << endl;
    for (int i = 1; i <= E; i++) {
        string source, destination, safety;
        int weight;
        cin >> source >> destination >> weight >> safety;
        graph.addEdge(source, destination, weight, safety);
    }

    graph.mstKruskal();
}

