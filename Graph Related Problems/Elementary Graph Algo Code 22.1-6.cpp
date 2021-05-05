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
            //adj[q][p]=1;
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


bool universal_sink()
{
    for(int i=1; i<=v; i++)
    {
        int c=0;
        int d=0;
        for(int j=1; j<=v; j++)
        {
            if(adj[i][j]==1)
            {
                c++;
            }
            if(adj[j][i]==1)
            {
                d++;
            }
        }
        if(c==0&&d==v-1)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    cout<<"Input Number of Vertex:";
    cin>>v;
    build_graph();
    display();
    bool m=universal_sink();
    if(m==true)
    {
        cout<<endl<< "There is an universal sink"<<endl;
    }
    else
    {
        cout<<endl<< "There is no universal sink"<<endl;
    }
    return 0;
}
