#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int>adj[100];
queue<int>Q;
int u,v,n,e,color[100],prev[100],d[100],no[100],c=0;

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
    if(s==0)  //only for source 0
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
    }
    if(s!=0&&prev[s]==-1)  //it will check whether there is a disconnected node
    {
        color[s]=1;
        d[s]=0;
        Q.push(s);
    }
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        int c=0;
        for(int i=0; i<adj[u].size(); i++)
        {
            v=adj[u][i];
            c++;
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

void display()
{
    cout<< "Nodes:\n";
    for(int i=0; i<n; i++)
    {
        cout<<i<< " ";
    }
    cout<< "\nColor:\n";
    for(int i=0; i<n; i++)
    {
        cout<<color[i]<< " ";
    }
    cout<< "\nDistance:\n";
    for(int i=0; i<n; i++)
    {
        cout<< d[i]<< " ";
    }
    cout<< "\nPrevious:\n";
    for(int i=0; i<n; i++)
    {
        cout<<prev[i]<< " ";
    }
    if(c==0)
    {
        cout<<endl<< "\nYes, Source can reach all the nodes"<<endl;
    }
    else
    {
        cout<<endl<< "\nNO"<<endl;
        cout<< "Source cannot get to ";
        for(int i=0; i<c; i++)
        {
            if(i==c-1)
            {
                cout<<no[i];
            }
            else
            {
                cout<<no[i]<< ", ";
            }
        }
        cout<< " no. nodes"<<endl;
    }

}

int main()
{
    cout<<"Enter the number of node:";
    cin>>n;
    cout<< "Enter the number of edges:";
    cin>>e;
    build_graph();
    for(int i=0; i<n; i++)
    {
        bfs(i);
        if(i==0)   //to check if there are any undiscovered node
        {
            c=0;
            for(int j=0; j<n; j++)
            {
                if(color[j]==0)
                {
                    no[c++]=j;  //storing the nodes which are disconnected from the source
                }
            }
        }
    }
    display();
}
