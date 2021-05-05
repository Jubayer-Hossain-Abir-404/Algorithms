#include<iostream>
#include<queue>
using namespace std;
int adj[100][100]= {0},color[100],prev[100],d[100],s,v,p,q,u,b[100][100];

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

void display1()
{
    cout<<"\nDisplay graph data in matrix form:\n";
    for(int i=1; i<=v; i++)
    {
        for(int j=1; j<=v; j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void square_of_directed_graph()
{
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            int sum=0;
            for(int k=1;k<=v;k++)
            {
                sum=sum+adj[i][k]*adj[k][j];
            }
            b[i][j]=sum;
        }
    }
}

int main()
{
    cout<<"Input Number of Vertex:";
    cin>>v;
    build_graph();
    display();
    square_of_directed_graph();
    display1();
    return 0;
}

