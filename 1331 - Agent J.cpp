#include<iostream>
#include<cmath>
#include<stdio.h>
 
using namespace std;
int main()
{
    int test,i=0;
    double r1,r2,r3,a,b,c,A1,A2,A3,v1,v2,v3,sq_a,sq_b,sq_c,s,area_triangle,area_arc1,area_arc2,area_arc3,area;
    cin>>test;
    while(test--)
    {
        cin>>r1>>r2>>r3;
        a=r1+r2;
        b=r2+r3;
        c=r3+r1;
        s=(a+b+c)/2;
        area_triangle=sqrt(s*(s-a)*(s-b)*(s-c));
        sq_a=pow(a,2);
        sq_b=pow(b,2);
        sq_c=pow(c,2);
        v1=(sq_a+sq_b-sq_c)/(2*a*b);
        v2=(sq_b+sq_c-sq_a)/(2*b*c);
        v3=(sq_c+sq_a-sq_b)/(2*c*a);
        A1=acos(v1);
        A2=acos(v2);
        A3=acos(v3);
        area_arc1=0.5*A3*r1*r1;
        area_arc2=0.5*A1*r2*r2;
        area_arc3=0.5*A2*r3*r3;
        area=area_triangle-(area_arc1+area_arc2+area_arc3);
        printf("Case %d: %.6lf\n",++i,area);
    }
    return 0;
}
 
