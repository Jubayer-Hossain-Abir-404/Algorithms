#include<iostream>
using namespace std;
#define maxlter 34

int X1[100]={2,5,1,12,3,7,12};
int X2[100]={3,7,2,13,4,8,16};
int Y[100]={7,6,10,15,5,10,9};
int n=2,m=7,X0[100],c=0,slope[100]={0},y_p,e;
int X[3][7]={{1,1,1,1,1,1,1},
             {2,5,1,12,3,7,12},
             {3,7,2,13,4,8,16}};
 double alpha=0.0000025,W_P[100],W0=1,W1=2,W2=3;



void Gradient()
{
    int p=0;
    while(p<maxlter)
    {
        c++;
        cout<< "\nC:"<<c<<endl;
        cout<< "\nW0 = "<<W0<< " W1 = "<<W1<< " W2 = "<<W2<<endl;
        for(int i=0;i<m;i++)
        {
            y_p=W0+W1*X[1][i]+W2*X[2][i];
            e=y_p-Y[i];
            for(int j=0;j<=n;j++)
            {
                slope[j]=slope[j]+e*X[j][i];
            }
        }
        W_P[0]=W0,W_P[1]=W1,W_P[2]=W2;
        for(int j=0;j<=n;j++)
        {
            W_P[j]=W_P[j]-alpha*slope[j];
        }
        W0=W_P[0],W1=W_P[1],W2=W_P[2];
        p++;
    }
}

int main()
{
    Gradient();
}
