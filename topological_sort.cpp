#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int>*adj;
    vector<int>*adjoint;
    
    //void topological_function(int source,bool visited[],stack<int>&st);
    void topo_sort(int source,bool visited[],stack<int>&st);

    public:
    Graph(int V);
    void addEdge(int v,int w);
    void topological_sort();

};

Graph::Graph(int V)
{
    this->V=V;
    adjoint = new vector<int>[V];
}

void Graph::addEdge(int v,int w)
{
    adjoint[v].push_back(w);
}

/*void Graph::topological_function(int source,bool visited[],stack<int>&st)
{
    visited[source]=true;
    list<int>::iterator it;
    for(it=adj[source].begin();it!=adj[source].end();it++)
    {
        if(!visited[*it])
        {
            topological_function(*it,visited,st);
            
        }
    }
    st.push(source);
}*/

void Graph::topo_sort(int source,bool visited[],stack<int>&st)
{
    visited[source]=true;
    //cout<<source<<" ";
    for(auto it:adjoint[source])
    {
        if(visited[it]==false)
        {
            topo_sort(it,visited,st);
        }
    }
    st.push(source);
}

void Graph::topological_sort()
{
    stack<int>st;
    bool* visited=new bool[V];

    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }

    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            topo_sort(i,visited,st);
        }
    }

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
    int vertex,edge;
    cin>>vertex;
    cin>>edge;
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

    g.topological_sort();

}