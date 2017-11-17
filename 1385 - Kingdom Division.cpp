#include<iostream>
#include<cstdio>
 
using namespace std;
int main()
{
    int test,i=0;
    double a,b,c,d1,d2,d;
    bool flag;
    cin>>test;
    while(test--)
    {
        flag = true;
        cin>>a>>b>>c;
        if(b)
        {
             d1 = (a*c)/b;
        }
 
        else
            flag = false;
 
        if(b!=d1)
              d2 = ((a+d1)*(c+d1))/(b-d1);
        else
           flag = false;
 
        d = d1 + d2;
 
        if(!flag)
             printf("Case %d: -1\n",++i);
 
        else if(d<0)
              printf("Case %d: -1\n",++i);
 
        else
              printf("Case %d: %lf\n",++i,d);
 
    }
 
    return 0;
}
 
