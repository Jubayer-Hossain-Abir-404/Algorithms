#include<iostream>
#include<queue>
#include<list>
using namespace std;
int v,a,b,color[100],prev[100],d[100],u;
list <int> adj[100];
list<int>::iterator it;

void build_graph()
{
    int k=1;
    cout<< "\nInput:\n\n";
    do
    {
        cout<<"Edge "<<k<<":";
        cin>>a>>b;
        if(a==0&&b==0)
        {
            break;
        }
        else if(a<=0||b<=0)
        {
            cout<<"\nInvalid Input\n";
        }
        else if(a>v||b>v)
        {
            cout<<"\nInvalid Input\n";
        }
        else
        {
            adj[a].push_back(b);
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
        for(it=adj[u].begin(); it!=adj[u].end(); it++)
        {
            if(color[*it]==0)
            {
                color[*it]=1;
                d[*it]=d[u]+1;
                prev[*it]=u;
                q.push(*it);
            }
        }
        color[u]=2;
    }
}
void display2()
{
    cout<<"\nDisplay graph data in list form:\n";
    for(int i=1; i<=v; i++)
    {
        cout<< "Adj["<<i<< "]";
        for(it=adj[i].begin(); it!=adj[i].end(); it++)
        {
            cout<< "->"<<*it;
        }
        cout<<"\n";
    }
}
void display()
{
    cout<< "\nSample Output:\n";
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
    display2();
    BFS(1);
    display();
}

