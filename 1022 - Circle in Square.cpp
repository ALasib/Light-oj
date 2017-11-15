#include<iostream>
#include<math.h>
#include<stdio.h>
 
using namespace std;
int main()
{
    int test,i=0;
    double e = pow(10,-9);
    double r,a,circle_area,squre_area,shaded_area;
    cin>>test;
    if(test<=1000)
    while(test--)
    {
        cin>>r;
        circle_area=2*acos(0.0)*r*r;
        squre_area=pow((2*r),2);
        shaded_area=squre_area-circle_area;
       
        printf("Case %d: %.2f\n",++i,shaded_area+e);
        }
 
    return 0;
}
