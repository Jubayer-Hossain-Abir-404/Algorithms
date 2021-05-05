#include<iostream>
#include<list>
using namespace std;
int v,a,b;
list<int>adj[100];

list<int>::iterator it;

void build_graph()
{
    int k=1;
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
            adj[b].push_back(a);
            k++;
        }
    }
    while(1);
}
void display()
{
    cout<<"\nDisplay graph data in list form:\n";
    for(int i=1; i<=v; i++)
    {
        cout<< "Adj["<<i<< "]";
        for(it=adj[i].begin();it!=adj[i].end();it++)
        {
            cout<< "->"<<*it;
        }
        cout<<"\n";
    }
}
int main()
{
    cout<<"Input Number of Vertex:";
    cin>>v;
    build_graph();
    display();
}
