#include<iostream>
#include<queue>
using namespace std;
int adj[100][100]= {0},color[100],prev[100],d[100],s,v,p,q,u;

void build_graph()
{
    int k=1;
    do
    {
        cout<<"Edge "<<k<<":";
        cin>>p>>q;
        if(p==0&&q==0)
        {
            break;
        }
        else if(p<=0||q<=0)
        {
            cout<<"\nInvalid Input\n";
        }
        else if(p>v||q>v)
        {
            cout<<"\nInvalid Input\n";
        }
        else
        {
            adj[p][q]=1;
            adj[q][p]=1;
            k++;
        }
    }
    while(1);
}
void display()
{
    cout<<"\nDisplay graph data in matrix form:\n";
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
}


void BFS(int s)
{
    for(int i=1; i<=v; i++)
    {
        color[i]=0;
        prev[i]=-1;
        d[i]=112000;
    }
    color[s]=1;
    d[s]=0;
    prev[s]=-1;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(int i=1; i<=v; i++)
        {
            if(adj[u][i]==1)
            {
                if(color[i]==0)
                {
                    color[i]=1;
                    d[i]=d[u]+1;
                    prev[i]=u;
                    q.push(i);
                }
            }
        }
        color[u]=2;
    }
}


void most_distant_node()
{
    int maximum=d[1];
    for(int i=2; i<=v; i++)
    {
        if(color[i]==2)
        {
            if(d[i]>maximum)
            {
                maximum=d[i];
            }
        }
    }
    for(int i=1; i<=v; i++)
    {
        if(color[i]==2)
        {
            if(maximum==d[i])
            {
                cout<<endl<< "The most distant node from the starting node is "<<i<< " with cost"<<maximum<<endl;
            }
        }
    }
}

void at_distance_from_source()
{
    cout<<endl<< "The nodes that are at distance 2 from source"<<endl;
    for(int i=1;i<=v;i++)
    {
        if(d[i]==2)
        {
            cout<<endl<< " "<<i<<endl;
        }
    }
}

int main()
{
    int m,n;
    cout<<"Input Number of Vertex:";
    cin>>v;
    build_graph();
    BFS(1);
    display();
    at_distance_from_source();
    return 0;
}
