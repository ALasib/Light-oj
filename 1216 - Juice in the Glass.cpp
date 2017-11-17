#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
 
#define PI acos(-1)
 
int main()
{
    int i=0,test;
    double R,V,r1,r2,h,p;
 
    cin>>test;
    while(test--)
{
        cin>>r1>>r2>>h>>p;
        R= r2 + (r1-r2)*(double(p)/h);
        V = 1/3.0 * PI * p *( R*R + R*r2 + r2*r2 );
        printf("Case %d: %lf\n",++i,V);
    }
    return 0;
}
 
