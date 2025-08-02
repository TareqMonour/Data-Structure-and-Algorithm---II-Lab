#include <bits/stdc++.h>
using namespace std;

class AdjListNode
{
public:
    int v;
    double log_w;

    AdjListNode(int v, double w)
    {
        this->v = v;
        this->log_w = w;
    }
};

class PQNode
{
public:
    int u, v;
    double log_key;

    PQNode(int u, int v, double key)
    {
        this->u = u;
        this->v = v;
        this->log_key = key;
    }
};

class Comparator
{
public:
    bool operator()(const PQNode &a, const PQNode &b)
    {
        return a.log_key > b.log_key;
    }
};

struct Edge
{
    int u, v;
    Edge(int u, int v)
    {
        this->u = u;
        this->v = v;
    }
};

class Graph
{
public:
    int V;
    list<AdjListNode> *adjList;

    Graph(int V)
    {
        this->V = V;
        adjList = new list<AdjListNode>[V];
    }

    void addEdge(int u, int v, double w)
    {
        adjList[u].push_back(AdjListNode(v, log(w)));
        adjList[v].push_back(AdjListNode(u, log(w)));
    }

    void minimumProductMST()
    {
        double log_product = 0;
        bool *inMST = new bool[V + 1];
        int *parent = new int[V + 1];
        stack<Edge> st;
        priority_queue<PQNode, vector<PQNode>, Comparator> pq;

        memset(inMST, false, sizeof(bool) * (V + 1));
        memset(parent, -1, sizeof(int) * (V + 1));

        pq.push(PQNode(-1, 0, 0));

        while (!pq.empty())
        {
            PQNode pqNode = pq.top();
            pq.pop();
            int ans = pqNode.u;
            int u = pqNode.v;
            if (inMST[u])
                continue;
            if (ans != -1)
            {
                st.push(Edge(ans, u));
            }
            inMST[u] = true;
            log_product += pqNode.log_key;

            for (AdjListNode &adjNode : adjList[u])
            {
                int v = adjNode.v;
                double log_w = adjNode.log_w;

                if (!inMST[v])
                {
                    pq.push(PQNode(u, v, log_w));
                }
            }
        }

        cout << "Minimum Product Spanning Tree Edges:" << endl;
        while (!st.empty())
        {
            Edge e = st.top();
            st.pop();
            cout << e.u << " - " << e.v << endl;
        }
        cout << "Minimum Product of Weights: " << exp(log_product) << endl;

        delete[] inMST;
        delete[] parent;
    }
};

int main()
{
    int V, E;
    cout << "Enter the Number of Vertices and Edges: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "Enter the Edges in the Format (u v w):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        double w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    graph.minimumProductMST();

    return 0;
}
