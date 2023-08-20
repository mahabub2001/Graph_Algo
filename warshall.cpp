#include<bits/stdc++.h>
using namespace std;

#define V 4
#define INF INT_MAX

void solution(int dist[][V]);

void floyd_warshall(int dist[][V])
{
    int i,j,k;

    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(dist[i][j] > (dist[i][k]+dist[k][j]) && (dist[i][k]!=INF) && (dist[k][j]!=INF))
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    solution(dist);
}

void solution(int dist[][V])
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(dist[i][j]==INF)
            {
                cout<<"INF"<<" ";
            }
            else
            {
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    int Graph[V][V]= {
        {0,9,-4,INF},
        {6,0,INF,2},
        {INF,5,0,INF},
        {INF,INF,1,0}

    };

    floyd_warshall(Graph);
}