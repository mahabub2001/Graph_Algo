#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    bool *visited;
    list<int>*adj;

    public:
    Graph(int V);
    void addEdge(int v1,int v2);
    void DFS(int source);
};

Graph::Graph(int vertex)
{
    V=vertex;
    adj=new list<int>[vertex];
    visited=new bool[vertex];
}

void Graph::addEdge(int v1,int v2)
{
    adj[v1].push_back(v2);
}

void Graph::DFS(int source)
{
    visited[source]=true;
    list<int>l=adj[source];
    cout<<source<<" ";

    list<int>::iterator it;
    for(it=l.begin();it!=l.end();it++)
    {
        if(!visited[*it])
        {
            DFS(*it);
        }
    }
}

int main()
{
    int vertex,edge;
    cin>>vertex>>edge;

    Graph g(vertex);

    int arr[edge][2];

    for(int i=0;i<edge;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<edge;i++)
    {
        g.addEdge(arr[i][0],arr[i][1]);
    }

    g.DFS(0);

}

