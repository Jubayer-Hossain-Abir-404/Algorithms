#include<bits/stdc++.h>
using namespace std;

#define size 7

int main()
{
    int x1[] = {2,5,1,12,3,7,12};
    int x2[] = {3,7,2,13,4,8,16};
    int y[] = {7,6,10,15,5,10,9};

    double p = 0, q = 0, r = 0;
    double l = 0.001;
    
    int j = 0, iteration = 10000;
    double cp, cq, cr;

    while(j < iteration)
    {
	cr = cq = cp = 0;
        for(int i = 0; i < size; i++)
        {    
            cp += p;
            cp += q*x1[i];
	    cp += r*x2[i];

	    cp -= y[i]; 
		
	    cr = cq = cp;

	    cq = cq * x1[i];
	    cr = cr * x2[i];
        }

        p -= l * cp;
        q -= l * cq;
        r -= l * cr;

        cout << p << endl;
	cout << q << endl;
	cout << r << endl;

        j++;
    }

    return 0;
}
