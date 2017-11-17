#include<iostream>
#include<cmath>
#include<cstdio>
 
using namespace std;
int main()
{
    int test,i=0;
    double ax,ay,cx,cy,ox,oy,a,c,o,angle_o,s;
    cin>>test;
    while(test--)
    {
        cin>>ox>>oy>>ax>>ay>>cx>>cy;
        a = hypot(ox-cx,oy-cy);
        c = hypot(ox-ax,oy-ay);
        o = hypot(cx-ax,cy-ay);
        angle_o = acos((a*a+c*c-o*o)/(2*a*c));
        s = a*angle_o;
        printf("Case %d: %lf\n",++i,s) ;
 
    }
    return 0;
}
