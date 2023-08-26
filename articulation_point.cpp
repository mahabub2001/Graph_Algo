#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[],vector<bool>&visited,int V,int i,int source)
{
    visited[source]=true;
    for(auto x:adj[source])
    {
        if(x!=i)
        {
            if(!visited[x])
            {
                dfs(adj,visited,V,i,x);
            }
        }
    }
}

void articulation(vector<int>adj[],int V)
{
    for(int i=0;i<V;i++)
    {
        vector<bool>visited(V,false);

        int apart=0;

        for(int j=0;j<V;j++)
        {
            if(j!=i)
            {
                if(!visited[j])
                {
                    apart++;
                    dfs(adj,visited,V,i,j);
                }
            }
        }
        if(apart>1)
        {
            cout<<i<<" ";
        }
    }
}

void addEdge(vector<int>adj[],int v1,int v2)
{
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}

int main()
{
    int vertex,edge;
    cin>>vertex>>edge;

    vector<int>adj[vertex];
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
        addEdge(adj,arr[i][0],arr[i][1]);
    }

    articulation(adj,vertex);
}