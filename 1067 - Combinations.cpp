#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#define mod 1000003
#define mx 1000005
 
using namespace std;
long long x,y;
 
void extended_euclid(long long a,long long b)
{
        if(b==0)
        {
              x=a;
              y=0;
              return;
        }
 
        extended_euclid(b,a%b);
 
        long long x1=y;
        long long y1=x-(a/b)*y;
        x=x1;
        y=y1;
}
 
int main()
{
       int test,caseno=0;
       long long fact[mx],n,r,i;
 
       fact[0]=1;
       for(i=1;i<mx;i++)
            fact[i]=(fact[i-1]*i)%mod;
 
        scanf("%d",&test);
 
       while(test--)
       {
              scanf("%lld%lld",&n,&r);
 
              if(n<r)
              {
                     printf("Case %d: 0\n",++caseno);
                     continue;
              }
 
 
                      long long b=(fact[r]*fact[n-r])%mod;
                      extended_euclid(b,mod);
                      b=x;
                      if(x<0)
                          b+=mod;
 
                      long long ans=(fact[n]*b)%mod;
                      printf("Case %d: %lld\n",++caseno,ans);
 
       }
 
       return 0;
}
 
