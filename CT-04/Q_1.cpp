#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
class AdjListNode
{
public:
    int v;
    int w;

    AdjListNode(int v,int w)
    {
        this->v=v;
        this->w=w;
    }

};

// **************************for the pq ************************//
class PQNode
{
public:
    int v;
    int key;
    PQNode(int v,int key)
    {
        this->v=v;
        this->key=key;
    }
};

class Comparator
{
public:
    bool operator()(const PQNode &a, const PQNode &b)
    {
        return a.key<b.key;
    }
};

// **************************for the pq ************************//

class Graph
{
public:
    int V;
    list <AdjListNode> *adjList;

    Graph(int V)
    {
        this->V=V;
        adjList = new list <AdjListNode> [V+1];
    }

    void addEdge(int u,int v, int w)
    {
        adjList[u].push_back(AdjListNode( v, w));
        adjList[v].push_back(AdjListNode( u, w));
    }

    void printAdjList()
    {
        for(int i=1; i<=V; i++)
        {
            for(AdjListNode x : adjList[i])
            {
                cout<<"("<<x.v<<","<<x.w<<")"<<" ";
            }
            cout<<endl;
        }
    }

    void primsAlgorithm(int source)
{
    int key[V + 1];
    int parent[V + 1];
    bool inMST[V + 1];

    for (int i = 1; i <= V; i++)
    {
        key[i] = -9999; // Negative
        parent[i] = -1;
        inMST[i] = false;
    }

    key[source] = 0;
    priority_queue<PQNode, vector<PQNode>, Comparator> pq;
    pq.push(PQNode(source, key[source]));

    while (!pq.empty())
    {
        PQNode pqNode = pq.top();
        pq.pop();

        int u = pqNode.v;

        if (inMST[u] == true)
        {
            continue;
        }
        else
        {
            inMST[u] = true;
        }

        for (AdjListNode adjListNode : adjList[u])
        {
            int v = adjListNode.v;
            int w = adjListNode.w;

            if (inMST[v] == false && w > key[v]) //condition
            {
                key[v] = w;
                parent[v] = u;
                pq.push(PQNode(v, key[v]));
            }
        }
    }
    int maxSpanningTreeWeightSum = 0;
    cout << "Parent values are: "<<endl;
    for (int i = 1; i <= V; i++)
    {
        maxSpanningTreeWeightSum += key[i];
        cout << parent[i] << " ";
    }
    cout << endl;
     cout << "Key values are: "<<endl;
    for (int i = 1; i <= V; i++)
    {
        cout << key[i] << " ";
    }
    cout << "\nThe weight of the Maximum Spanning Tree is: " << maxSpanningTreeWeightSum << endl;
}

};

int main()
{
    int V,E;
    cout << "Enter the Number of Vertices and Edges: ";
    cin >> V >> E;

    Graph graph(V);
 cout << "Enter the Edges in the Format (u v w):" << endl;
    for(int i=1; i<=E; i++)
    {
        int u,v,w;
        cin>>u;
        cin>>v;
        cin>>w;
        graph.addEdge(u,v,w);
    }

    graph.printAdjList();
    cout<<"After Running Prim's Algorithm"<<endl;
    graph.primsAlgorithm(1);

}

/*
6 8
1 2 10
2 4 20
4 5 5
5 6 5
6 3 10
1 3 10
1 5 10
3 5 5
*/



