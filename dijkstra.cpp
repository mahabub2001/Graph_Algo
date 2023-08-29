#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>vertices;

class Graph
{
    int V;
    list<pair<int,int>>*adj;

    public:
    Graph(int V);
    void addEdge(int v1,int v2,int w);
    void dijkstra(int source);
};

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<vertices>[V];
}

void Graph::addEdge(int v1,int v2,int w)
{
    adj[v1].push_back(make_pair(v2,w));
    adj[v2].push_back(make_pair(v1,w));
}

void Graph::dijkstra(int source)
{
    priority_queue<vertices,vector<vertices>,greater<vertices>>pq;

    vector<int>distance(V,INT_MAX);

    pq.push(make_pair(0,source));
    distance[source]=0;

    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();

        list<pair<int,int>>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
            int v=(*it).first;
            int weight=(*it).second;

            if(distance[v]>distance[u]+weight)
            {
                distance[v]=distance[u]+weight;
                pq.push(make_pair(distance[v],v));
            }
        }
    }
    for(int i=0;i<V;i++)
    {
        cout<<distance[i]<<endl;
    }
}


int main()
{
    int vertex,edge;
    cin>>vertex>>edge;
    Graph g(vertex);

    int arr[edge][3];

    for(int i=0;i<edge;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<edge;i++)
    {
        g.addEdge(arr[i][0],arr[i][1],arr[i][2]);
    }

    g.dijkstra(0);
}