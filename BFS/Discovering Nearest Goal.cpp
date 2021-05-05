#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;


vector<int>adj[100];
queue<int>Q;
int u,v,n,e,color[100],prev[100],d[100],k=0,c=500;

void build_graph()
{
    for(int i=0; i<e; i++)
    {
        cout<< "Vertices "<<i+1<< ":";
        cin>>u>>v;
        cout<<endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(int s)
{
    for(int i=0; i<n; i++)
    {
        color[i]=0;
        prev[i]=-1;
        d[i]=11122220;
    }
    color[s]=1;
    d[s]=0;
    prev[s]=-1;
    Q.push(s);
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            v=adj[u][i];
            if(color[v]==0)
            {
                color[v]=1;
                d[v]=d[u]+1;
                prev[v]=u;
                Q.push(v);
            }
        }
        color[u]=2;
    }
}

void nearest_goal(int A, int B,int C)
{
    if(d[A]>d[B])
    {
        cout<<A<< " no. node is closer to node no. "<<C<< " than node no. "<<B<<endl;
    }
    else
    {
        cout<<B<< " no. node is closer to node no. "<<C<< " than node no. "<<A<<endl;
    }

}






int main()
{
    int A,B,C;
    cout<<"Enter the number of node:";
    cin>>n;
    cout<< "Enter the number of edges:";
    cin>>e;
    build_graph();
    cout<< "Enter the first source:";
    cin>>A;
    cout<<endl;
    cout<< "Enter the second source:";
    cin>>B;
    cout<<endl;
    cout<< "Enter the Goal:";
    cin>>C;
    cout<<endl;
    bfs(A);
    cout<<endl;
    nearest_goal(A,B,C);

}


