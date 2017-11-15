#include<iostream>
#include<cmath>
#include<cstdio>
 
using namespace std;
int main()
{
    int test,i=0;
    double a,b,c,d,x,h,triangle_area,trapizium_area,s;
    cin>>test;
    while(test--)
    {
        cin>>a>>b>>c>>d;
        x = fabs(a-c);
        s = (b+d+x)/2;
        triangle_area = sqrt(s*(s-b)*(s-d)*(s-x));
        h = (2*triangle_area)/x;
        trapizium_area = 0.5*(a+c)*h;
        printf("Case %d: %lf\n",++i,trapizium_area);
    }
    return 0;
}
