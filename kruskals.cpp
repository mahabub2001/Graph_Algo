#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>vertices;

struct Graph
{
    int V,E;
    vector<pair<int,vertices>>edges;

    Graph(int V,int E)
    {
        this->V=V;
        this->E=E;
    }

    void addEdge(int v1,int v2,int w)
    {
        edges.push_back({w,{v1,v2}});
    }

    int kruskals();
};

struct disjoint
{
    int *parent;
    int *rank;
    int n;

    disjoint(int n)
    {
        this->n=n;
        parent=new int[n+1];
        rank=new int[n+1];

        for(int i=0;i<=n;i++)
        {
            rank[i]=0;
            parent[i]=i;
        }
    }

    int find(int node)
    {
        if(node!=parent[node])
        {
            parent[node]=find(parent[node]);
        }

        return parent[node];
    }

    void union_by_rank(int a,int b)
    {
        a=find(a);
        b=find(b);

        if(rank[a]>rank[b])
        {
            parent[b]=a;
        }
        else
        {
            parent[a]=b;
        }

        if(rank[a]==rank[b])
        {
            rank[b]++;
        }
    }
};

int Graph::kruskals()
{
    int short_weight=0;

    sort(edges.begin(),edges.end());

    disjoint d(V);

    vector<pair<int,vertices>>::iterator it;

    for(it=edges.begin();it!=edges.end();it++)
    {
        int u=it->second.first;
        int v=it->second.second;

        int cycle_u=d.find(u);
        int cycle_v=d.find(v);

        if(cycle_u!=cycle_v)
        {
            //cout<<u<<"-"<<v<<endl;
            short_weight+=it->first;

            d.union_by_rank(cycle_u,cycle_v);
        }
    }
    return short_weight;
}

int main()
{
    int vertex,edge;
    cin>>vertex>>edge;
    Graph g(vertex,edge);

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

    int weight=g.kruskals();
    cout<<weight<<endl;
}