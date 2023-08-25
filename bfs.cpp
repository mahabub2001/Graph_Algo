#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<list<int>>adj;
    vector<bool>visited;

    public:
    Graph(int V);
    void addEdge(int v1,int v2);
    void BFS(int source);
};

Graph::Graph(int V)
{
    this->V=V;
    adj.resize(V);
}

void Graph::addEdge(int v1,int v2)
{
    adj[v1].push_back(v2);
}

void Graph::BFS(int source)
{
    vector<bool>visited(V+1,false);

    queue<int>q;

    visited[source]=true;
    q.push(source);

    while(!q.empty())
    {
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        for(auto adjacent:adj[x])
        {
            if(!visited[adjacent])
            {
                visited[adjacent]=true;
                q.push(adjacent);
            }
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

    g.BFS(0);
}

