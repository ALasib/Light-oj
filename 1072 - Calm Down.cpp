#include<iostream>
#include<cstdio>
#include<cmath>
#define pi acos(-1)
 
using namespace std;
 
int main()
{
    int test,i=0,n;
    double r,R;
    cin>>test;
    while(test--)
    {
        cin>>R>>n;
        r=(R*sin(pi/n))/(1+sin(pi/n));
        printf("Case %d: %lf\n",++i,r);
    }
    return 0;
}
