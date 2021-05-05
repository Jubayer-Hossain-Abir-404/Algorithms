#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Q
{
    int node;
    int dis;
}Q[100];
int adj[100][100];
int u,v,q,n,e,prev[100],d[100],h[100];

void build_graph()
{
    for(int i=0; i<e; i++)
    {
        cout<< "Vertices "<<i+1<< ":";
        cin>>u>>v;
        cout<<endl<< "Weight:";
        cin>>q;
        cout<<endl<< "Heuristic Cost:";
        cin>>h[i];
        cout<<endl;
        adj[u][v]=q;
        adj[v][u]=q;
    }
}


void A_star(int s,int d)
{
    int minimum=100000;
    for(int i=0; i<n; i++)
    {
        Q[i].node=i;
        Q[i].dis=9999;
        prev[i]=-1;
    }
    Q[s].dis=0;
    while(Q[s].node!=d)
    {
        for(int v=0; v<n; v++)
        {
            if(adj[s][v]>0)
            {
                Q[v].dis=h[v]+Q[v].dis+adj[s][v];
                if(Q[v].dis<minimum)
                {
                    minimum=Q[v].dis;
                }
            }
        }
        u=minimum;
        prev[v]=u;
        s=u;
    }
}

void display()
{
    cout<< "Nodes:\n";
    for(int i=0; i<n; i++)
    {
        cout<<Q[i].node<< " ";
    }
    cout<< "\nDistance:\n";
    for(int i=0; i<n; i++)
    {
        cout<< Q[i].dis<< " ";
    }
    cout<< "\nPrevious:\n";
    for(int i=0; i<n; i++)
    {
        cout<<prev[i]<< " ";
    }

}






int main()
{
    cout<<"Enter the number of node:";
    cin>>n;
    cout<< "Enter the number of edges:";
    cin>>e;
    build_graph();
    A_star(0,4);
    display();

}


