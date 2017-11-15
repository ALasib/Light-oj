/*Hints:meet in the middle+bitmask+set*/

#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

set<LL>Dp1;
vector<LL>Dp2;
LL n,Coins[19],k;

void Generate1(LL ind,LL val)
{
    Dp1.insert(val);
    if(ind==n/2)return;
    Generate1(ind+1,val);
    Generate1(ind+1,val+Coins[ind]);
    Generate1(ind+1,val+2*Coins[ind]);
}

void Generate2(LL ind,LL val)
{
    Dp2.push_back(val);
    if(ind==n)return;
    Generate2(ind+1,val);
    Generate2(ind+1,val+Coins[ind]);
    Generate2(ind+1,val+2*Coins[ind]);
}

int main()
{
    int test,cs=0;
    scanf("%d",&test);

    while(test--)
    {
        Dp1.clear();
        Dp2.clear();
        scanf("%lld%lld",&n,&k);
        for(LL i=0;i<n;i++) scanf("%lld",&Coins[i]);

        Generate1(0,0);
        Generate2(n/2,0);

        printf("Case %d: ",++cs);
        LL len=Dp2.size();
        bool sig=0;
        for(LL i=0;i<len;i++)
        {
            if(Dp1.find(k-Dp2[i])!=Dp1.end())
            {
                printf("Yes\n");
                sig=1;
                break;
            }
        }
        if(!sig)printf("No\n");
    }
    return 0;

}
