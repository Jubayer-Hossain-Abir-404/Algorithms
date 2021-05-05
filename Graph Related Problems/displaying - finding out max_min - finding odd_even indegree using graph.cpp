#include<stdio.h>
int adj[100][100]={0},v=0,p,q,b[100];

void build_graph()
{
    int k=1;
    do
    {
          printf("Edge %d:",k);
          scanf("%d%d",&p,&q);
          if(p==0&&q==0)
          {
                break;
          }
          else if(p<=0||q<=0)
          {
                printf("\nInvalid Input\n");
          }
          else if(p>v||q>v)
          {
                printf("\nInvalid Input\n");
          }
          else if(adj[p][q]==1)
          {
                printf("\nInvalid Input\n");
          }
          else
          {
                adj[p][q]=1;
                //adj[q][p]=1;
                k++;
          }
    }while(1);
}

void display()
{
      printf("The graph you entered is as Follows\n");
      for(int i=1;i<=v;i++)
      {
            for(int j=1;j<=v;j++)
            {
                  printf("%d ",adj[i][j]);
            }
            printf("\n");
      }
}

void find_out_max()
{
      for(int i=1;i<=v;i++)
      {
            int c=0;
            for(int j=1;j<=v;j++)
            {
                  if(adj[i][j]==1)
                  {
                        c++;
                  }
            }
            b[i]=c;
      }
      int maximum=b[1];
      for(int i=2;i<=v;i++)
      {
            if(b[i]>maximum)
            {
                  maximum=b[i];
            }
      }
      printf("The vertices having the maximum out degree\n");
      for(int i=1;i<=v;i++)
      {
            if(b[i]==maximum)
            {
                  printf("%d ",i);
            }
      }
}

void find_out_min()
{
      for(int i=1;i<=v;i++)
      {
            int c=0;
            for(int j=1;j<=v;j++)
            {
                  if(adj[i][j]==1)
                  {
                        c++;
                  }
            }
            b[i]=c;
      }
      int minimum=b[1];
      for(int i=2;i<=v;i++)
      {
            if(b[i]<minimum)
            {
                  minimum=b[i];
            }
      }
      printf("\nThe vertices having the minimum out degree\n");
      for(int i=1;i<=v;i++)
      {
            if(b[i]==minimum)
            {
                  printf("%d ",i);
            }
      }
}

void find_odd_indegree()
{
      for(int i=1;i<=v;i++)
      {
            int c=0;
            for(int j=1;j<=v;j++)
            {
                  if(adj[j][i]==1)
                  {
                        c++;
                  }
            }
            b[i]=c;
      }
      printf("\nThe vertices which has odd in degree:\n");
      for(int i=1;i<=v;i++)
      {
            if(b[i]%2!=0)
            {
                  printf("%d ",i);
            }
      }
}
void find_even_indegree()
{
      for(int i=1;i<=v;i++)
      {
            int c=0;
            for(int j=1;j<=v;j++)
            {
                  if(adj[j][i]==1)
                  {
                        c++;
                  }
            }
            b[i]=c;
      }
      printf("\nThe vertices which has even in degree:\n");
      for(int i=1;i<=v;i++)
      {
            if(b[i]%2==0)
            {
                  printf("%d ",i);
            }
      }
}


int main()
{
      printf("Input Number of Vertex:");
      scanf("%d",&v);
      build_graph();
      display();
      find_out_max();
      find_out_min();
      find_odd_indegree();
      find_even_indegree();
      return 0;
}
