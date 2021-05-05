#include<iostream>
#include<queue>
using namespace std;
int adj[100][100]= {0},color[100],prev[100],d[100],s,v,p,q,u,visited[100]= {0},e=0,bd[100],c=0;

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




void print_shortest_distance(int m,int n)
{
    visited[m]=1;
    if(d[m]==0)
    {
        e=2;
        if(n==m)
        {
            cout<< " "<<m;
        }
        else if(prev[n]==-1)
        {
            c++;
            cout<<"\n\nThere is no path between the source and destination\n\n";
        }
        else
        {
            c++;
            print_shortest_distance(m,prev[n]);
            cout<< " "<<n;
        }
    }
    else if(color[n]==0)
    {
        cout<<"\n\nThere is no path between the source and destination\n\n";
    }
    else
    {
        e=1;
        if(prev[n]==-1)
        {
            visited[n]=1;
            c++;
            for(int i=1; i<=v; i++)
            {
                if(adj[n][i]==1&&visited[i]==0)
                {
                    print_shortest_distance(m,i);
                }
            }
        }
        else
        {
            visited[n]=1;
            c++;
            print_shortest_distance(m,prev[n]);
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
    while(1)
    {
        cout<<endl<< "Enter the source:";
        cin>>m;
        cout<<endl<< "Enter the destination:";
        cin>>n;
        if(m<=0||n<=0)
        {
            cout<<"\nInvalid Input\n";
        }
        else if(m>v||n>v)
        {
            cout<<"\nInvalid Input\n";
        }
        else
        {
            break;
        }
    }
    cout<< endl<<"The shortest distance from source to destination is:"<<endl;
    print_shortest_distance(m,n);
    int bd[100][100];
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            bd[i][j]=adj[i][j];
        }
    }
    if(e==1)
    {
        cout<< " "<<m;
        for(int i=1; i<=v; i++)
        {
            for(int j=1; j<=v; j++)
            {
                if(bd[m][j]==1&&bd[j][m]==1&&visited[j]==1)
                {
                    cout<< " "<<j;
                    bd[m][j]=-1;
                    bd[j][m]=-1;
                    m=j;
                    break;
                }
            }
        }
        cout<<endl<< "Shortest path length is:"<<c-1<<endl;
    }
    else if(e==2)
    {
        cout<<endl<< "Shortest path length is:"<<c<<endl;
    }
    return 0;
}
