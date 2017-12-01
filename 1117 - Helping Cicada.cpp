#include<bits/stdc++.h>
#define mx 16

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef unsigned int ui;
int n,m;
ll arr[mx];

bool check(int mask,int pos)
{
      return (bool)(mask&(1<<pos));
}

int slove(int mask)
{
      int ret;
      ll lcm=1;
      int cnt=0;
      for(int i=0;i<m;i++)
      {
           if(check(mask,i)==1)
           {
                lcm=(lcm*arr[i])/__gcd(lcm,arr[i]);
                cnt++;
           }
      }

      if(cnt%2)
          return n/lcm;
      else
          return -(n/lcm);
}

int main()
{
      int test,cs=0,i,ans;
      scanf("%d",&test);

      while(test--)
      {
             ans=0;
             scanf("%d%d",&n,&m);
             for(i=0;i<m;i++)
                scanf("%lld",&arr[i]);

             for(ll i=1;i<(1<<m);i++)
                ans+=slove(i);
             printf("Case %d: %d\n",++cs,n-ans);
      }
      return 0;
}
