#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Q
{
    int node;
    int dis;
    bool flag;
    int key;
}Q[100];
int adj[100][100];
int u,v,q,n,e,prev[100],d[100];

void build_graph()
{
    for(int i=0; i<e; i++)
    {
        cout<< "Vertices "<<i+1<< ":";
        cin>>u>>v;
        cout<<endl<< "Weight:";
        cin>>q;
        cout<<endl;
        adj[u][v]=q;
        adj[v][u]=q;
    }
}

int pop()
{
    int minimum=100000,index;
    for(int i=0;i<n;i++)
    {
        if(Q[i].key<minimum&&Q[i].flag==true)
        {
            minimum=Q[i].dis;
            index=i;
        }
    }
    Q[index].flag=false;
    return index;
}

bool empty_Q()
{
    for(int i=0;i<n;i++)
    {
        if(Q[i].flag==true)
        {
            return true;
        }
    }
    return false;
}

void Dijkstra(int s)
{
    for(int i=0; i<n; i++)
    {
        Q[i].node=i;
        Q[i].dis=9999;
        Q[i].flag=true;
        prev[i]=-1;
    }
    Q[s].dis=0;
    while(empty_Q()!=false)
    {
        u=pop();
        for(int v=0; v<n; v++)
        {
            if(Q[v].dis>Q[u].dis+adj[u][v])
            {
                Q[v].dis=Q[u].dis+adj[u][v];
                prev[v]=u;
                Q[v].key=Q[v].dis+h[v];
            }
        }
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
    Dijkstra(0);
    display();

}


