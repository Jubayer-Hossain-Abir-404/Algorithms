#include<iostream>
#include<queue>
using namespace std;

int adj[100][100]= {0},color[100],prev[100],d[100],v,p,q,u;

void build_graph()
{
    cout<< "\nInput\n\n";
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
            k++;
        }
    }
    while(1);
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
            if(adj[u][i]==1&&color[i]==0)
            {
                color[i]=1;
                d[i]=d[u]+1;
                prev[i]=u;
                q.push(i);
            }
        }
        color[u]=2;
    }
}
void display()
{
    cout<< "\n\nSample Output:\n";
    cout<< "\n\nVertex   : ";
    for(int i=1; i<=v; i++)
    {
        cout<<i<<" ";
    }
    cout<< "\n\nColor    : ";
    for(int i=1; i<=v; i++)
    {
        cout<<color[i]<< " ";
    }
    cout<< "\n\nPrevious : ";
    for(int i=1; i<=v; i++)
    {
        cout<<prev[i]<< " ";
    }
    cout<< "\n\nDistance : ";
    for(int i=1; i<=v; i++)
    {
        cout<<d[i]<< " ";
    }
    cout<<"\n";
}

int main()
{
    cout<< "Input number of vertex:";
    cin>>v;
    build_graph();
    BFS(1);
    display();
}
