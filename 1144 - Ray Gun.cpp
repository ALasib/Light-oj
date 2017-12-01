#include<bits/stdc++.h>
#define mx 1000009

using namespace std;
typedef long long LL;

bool prime[mx];
vector<LL>pr;
LL Meu[mx];

void seive()
{
    LL i,j,x;
    x = sqrt(mx);

    for(i=1;i<=mx;i++)
        prime[i] = 1;

    prime[1] = 0;

    for(i=4;i<=mx;i+=2)
        prime[i] = 0;

    for(i=3;i<=x;i+=2)
    {
        if(prime[i]==1)
        {
            for(j=i*i;j<=mx;j+=i)
                prime[j] = 0;
        }
    }

    for(i=2;i<=mx;i++)
        if(prime[i])pr.push_back(i);

}

int main()
{
    LL test,cs=0;
    seive();
    //freopen("out.txt","w",stdout);

    Meu[1]=1;
    for(LL i=2;i<=mx;i++)
    {
        LL cnt=0;
        bool sig=0;
        LL temp=i;

        while(temp!=1)
        {
            for(LL j=0;pr[j]<=sqrt(i);j++)
            {
                if(temp%pr[j]==0)
                {
                    temp/=pr[j];
                    cnt++;
                    LL p=1;

                    while(temp%pr[j]==0)
                    {
                        temp/=pr[j];
                        p++;
                        if(p>=2)break;
                    }
                    if(p>=2)
                        sig=1;
                }
                if(sig)
                    break;
            }
            if(sig==1)
                temp=1;
            if(temp!=1)
            {
                temp=1;
                cnt++;
            }
        }
        if(sig)
            Meu[i]=0;
        else if(!sig)
            Meu[i]=(cnt%2==0)?1:-1;
    }

    scanf("%lld",&test);

    while(test--)
    {
        LL n,m;
        scanf("%lld%lld",&n,&m);
        LL ans=2;

        for(LL i=1;i<=min(n,m);i++)
            ans+=(Meu[i]*(n/i)*(m/i));
        if(min(n,m)==0)
            ans=1;
        if(m==0 and n==0)
            ans=0;
        printf("Case %lld: %lld\n",++cs,ans);
    }

    return 0;
}

