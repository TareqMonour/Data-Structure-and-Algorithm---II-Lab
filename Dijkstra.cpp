#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class AdjListNode{
public:
    int v;
    int w;

    AdjListNode(int v,int w){
        this->v=v;
        this->w=w;
    }
};

// **************************for the pq ************************//
class PQNode{
public:
    int v;
    int key;
    PQNode(int v,int key){
        this->v=v;
        this->key=key;
    }
};

class Comparator{
public:
    bool operator()(const PQNode &a, const PQNode &b){
        return a.key > b.key; // Changed from '<' to '>' for Dijkstra's algorithm
    }
};

// **************************for the pq ************************//

class Graph{
public:
    int V;
    list <AdjListNode> *adjList;

    Graph(int V){
        this->V=V;
        adjList = new list <AdjListNode> [V+1];
    }

    void addEdge(int u,int v, int w){
        adjList[u].push_back(AdjListNode(v, w));
        adjList[v].push_back(AdjListNode(u, w));
    }

    void printAdjList(){
        for(int i=1;i<=V;i++){
            for(AdjListNode x : adjList[i]){
                cout<<"("<<x.v<<","<<x.w<<")"<<" ";
            }
            cout<<endl;
        }
    }

    void dijkstraAlgorithm(int source){ // Changed function name
        int dist[V+1]; // Changed array name from 'key' to 'dist'
        int parent[V+1];
        bool visited[V+1]; // Changed array name from 'inMST' to 'visited'

        for(int i=1;i<=V;i++){
            dist[i]=9999;
            parent[i]=-1;
            visited[i]=false;
        }

        dist[source]=0;
        priority_queue <PQNode,vector<PQNode>,Comparator> pq;
        pq.push(PQNode(source,dist[source]));

        while(!pq.empty()){
            PQNode pqNode = pq.top();
            pq.pop();

            int u = pqNode.v;

            if(visited[u]==true){
                continue;
            }else{
                visited[u]=true;
            }

            for(AdjListNode adjListNode : adjList[u]){
                int v = adjListNode.v;
                int w = adjListNode.w;

                if(visited[v]==false && dist[u]+w < dist[v]){ // Changed condition for relaxation
                    dist[v]=dist[u]+w;
                    parent[v]=u;
                    pq.push(PQNode(v,dist[v]));
                }
            }
        }

        for(int i=1;i<=V;i++){
            cout<<"parent of "<<i<<" is "<<parent[i]<<endl;
            cout<<"distance of "<<i<<" from source is "<<dist[i]<<endl; // Changed 'key' to 'distance'
        }
    }
};

int main(){
    int V,E;
    cin>>V;
    cin>>E;

    Graph graph(V);

    for(int i=1;i<=E;i++){
        int u,v,w;
        cin>>u;
        cin>>v;
        cin>>w;
        graph.addEdge(u,v,w);
    }

    graph.printAdjList();
    cout<<"After running Dijkstra's algorithm: "<<endl;
    graph.dijkstraAlgorithm(1); // Changed function call to dijkstraAlgorithm

    return 0;
}
/*
5 7
1 2 2
1 3 1
2 3 4
2 4 3
3 4 1
3 5 5
4 5 1
*/
