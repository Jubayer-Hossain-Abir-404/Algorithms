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



bool bfs_wrestler()
{
    for(int i=1; i<=v; i++)
    {
        if(d[i]>2)
        {
            return false;
        }
    }
    for(int i=1; i<=v; i++)
    {
        if(d[i]%2!=0)
        {
            for(int j=1; j<=v; j++)
            {
                if(d[j]%2!=0)
                {
                    if(adj[i][j]==1)
                    {
                        return false;
                    }
                }
            }
        }
        else if(d[i]%2==0)
        {
            for(int j=1; j<=v; j++)
            {
                if(d[j]%2==0)
                {
                    if(adj[i][j]==1)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}


int main()
{
    cout<<"Input Number of Vertex:";
    cin>>v;
    build_graph();
    BFS(1);
    display();
    bool m=bfs_wrestler();
    if(m==true)
    {
        cout<<"\nThe designation in the professional wrestlers is possible\n";
        for(int i=1; i<=v; i++)
        {
            if(d[i]%2==0)
            {
                cout<<"\nWrestler No."<<i<<" is in the babyfaces\n";
            }
            else
            {
                cout<<"\nWrestler No."<<i<<" is in the heels\n";
            }
        }
    }
    else
    {
        cout<<"\nThe designation between the professional wrestlers is not possible\n";
    }
    return 0;
}

