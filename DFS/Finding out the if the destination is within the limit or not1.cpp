#include<iostream>
#include<vector>
using namespace std;


vector <int>adj[100];
int color[100],prev[100],d[100],v,u,e,n,time,U,dst,lim;
bool f;

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

bool DFS_Visit(int U, int dst, int lim)
{
    bool r;
    cout<< endl<<"U:"<<U<<endl;
    cout<<endl<< "V:"<<v<<endl;
    cout<<endl<< "Limit:"<<lim<<endl;
    if(U==dst)
    {
        return true;
    }
    if(lim<=0)
    {
        return false;
    }
    color[U]=1;
    for(int i=0; i<adj[U].size(); i++)
    {
        v=adj[U][i];
        r=DFS_Visit(v,dst,lim-1);
        if(r==true)
        {
            f=true;
        }
    }
}
void DFS()
{
    for(int i=0; i<n; i++)
    {
        color[i]=0;
    }
    cout<< "Enter the source:";
    cin>>U;
    cout<< "Enter the destination:";
    cin>>dst;
    cout<< "Enter the limit:";
    cin>>lim;
    DFS_Visit(U,dst,lim);
    if(f==true)
    {
        cout<< "The "<<dst<< " no. node is within the limit "<<lim<< " of source "<<U;
    }
    else
    {
        cout<< "The "<<dst<< " no. node is outside the limit "<<lim<< " of source "<<U;
    }
}



int main()
{
    cout<<"Enter the number of node:";
    cin>>n;
    cout<< "Enter the number of edges:";
    cin>>e;
    build_graph();
    DFS();
}


