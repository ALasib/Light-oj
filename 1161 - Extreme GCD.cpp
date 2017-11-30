#include<bits/stdc++.h>
#define mx 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef unsigned int ui;
int n,a;
map<int,int>cnt;
ll dp[mx];
ll ans[mx];
 
void ncr()
{
      dp[0]=dp[1]=dp[2]=dp[3]=0;
      dp[4]=1;
      for(int i=5;i<mx;i++)
         dp[i]=dp[i-1]*i/(i-4);
}
 
int main()
{
       int test,cs=0,i,maxm;
       scanf("%d",&test);
       ncr();
       while(test--)
       {
             scanf("%d",&n);
             maxm=-1;
             memset(ans,0,sizeof(ans));
             for(i=0;i<n;i++)
             {
                   scanf("%d",&a);
                   maxm=max(a,maxm);
                   for(int j=1;j*j<=a;j++)
                   {
                         if(a%j==0)
                          {
                                cnt[j]++;
                                if(j*j!=a)
                                   cnt[a/j]++;
                          }
                   }
             }
 
             for(int i=maxm;i>=1;i--)
             {
                    ans[i]=dp[cnt[i]];
                    for(int j=(2*i);j<=maxm;j+=i)
                        ans[i]-=ans[j];
             }
 
             printf("Case %d: %lld\n",++cs,ans[1]);
             cnt.clear();
 
       }
       return 0;
}
 
