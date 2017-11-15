/*Hints:Bitmask+Meet in the Middle+Binary Search*/
 
#include<bits/stdc++.h>
#define mx 32
 
using namespace std;
typedef long long LL;
 
LL n,Weight[mx],Ans,w,len1,len2;
vector<LL>Part1;
vector<LL>Part2;
vector<LL>::iterator it;
 
void Generate1(LL ind,LL val)
{
    if(ind==n/2)
    {
        Part1.push_back(val);
        return;
    }
    Generate1(ind+1,val);
    Generate1(ind+1,val+Weight[ind]);
}
 
void Generate2(LL ind,LL val)
{
 
    if(ind==n)
    {
        Part2.push_back(val);
        return;
    }
    Generate2(ind+1,val);
    Generate2(ind+1,val+Weight[ind]);
}
 
 
int main()
{
    LL test,cs=0;
    scanf("%lld",&test);
 
    while(test--)
    {
        Part1.clear();
        Part2.clear();
 
        scanf("%lld%lld",&n,&w);
        for(LL i=0;i<n;i++) scanf("%lld",&Weight[i]);
 
        if(n==1 and Weight[0]<=w)
        {
            printf("Case %lld: 2\n",++cs);
            continue;
        }
 
        if(n==1 and Weight[0]>w)
        {
            printf("Case %lld: 1\n",++cs);
            continue;
        }
 
        Generate1(0,0);
        Generate2(n/2,0);
 
        sort(Part1.begin(),Part1.end());
        Ans=0;
        len1=Part1.size();
        len2=Part2.size();
 
        for(LL i=0;i<len2;i++)
        {
            if(w-Part2[i]<0)continue;
 
            it=upper_bound(Part1.begin(),Part1.end(),w-Part2[i]);
            Ans+=distance(Part1.begin(),it);
         }
        printf("Case %lld: %lld\n",++cs,Ans);
 
    }
    return 0;
}
