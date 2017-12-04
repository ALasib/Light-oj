#include<stdio.h>
#include<iostream>
int num_of_2,num_of_5;
using namespace std;
 
int prime_fact(int n,int div)
{
    int c=0;
    while(n>0 && n%div==0)
    {
        n/=div;
        c++;
    }
    return c;
}
 
int cnt(int n,int div)
{
    int c=0;
    while(n)
    {
        c+=n/div;
        n/=div;
    }
    return c;
}
 
void how_many_2_5 (int n,int r)
{
    int a2,b2,c2,a5,b5,c5;
    a2=cnt(n,2);
    b2=cnt(r,2);
    c2=cnt(n-r,2);
    a5=cnt(n,5);
    b5=cnt(r,5);
    c5=cnt(n-r,5);
 
    num_of_2=a2-(b2+c2);
    num_of_5=a5-(b5+c5);
}
 
int main()
{
    int test,caseno=0,ans,p,q,r,n;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d%d%d",&n,&r,&p,&q);
        num_of_2=0;
        num_of_5=0;
        how_many_2_5(n,r);
        num_of_2+=(prime_fact(p,2)*q);
        num_of_5+=(prime_fact(p,5)*q);
        ans=min(num_of_2,num_of_5);
        printf("Case %d: %d\n",++caseno,ans);
    }
    return 0;
}
 
