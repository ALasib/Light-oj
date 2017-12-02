#include<bits/stdc++.h>
#define mx 1000009
#define mod 100000007

using namespace std;
typedef long long LL;

LL fact[mx],lower[15],upper[15],nn,k,n,cnt;

bool check(LL mask,LL pos)
{
    return (bool)(mask&(1<<pos));
}

LL modInverse(LL a, LL m)
{
    LL m0 = m, t, q;
    LL x0 = 0, x1 = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
       x1 += m0;

    return x1;
}

LL cal(LL mask)
{
    LL ret=nn;
    for(LL i=0;i<k;i++)
    {
        if(check(mask,i)==1)
        {
            cnt++;
            ret-=(upper[i]-lower[i]+1);
        }
    }
    return ret;
}

int main()
{
    fact[0]=1;
    for(LL i=1;i<mx;i++)
        fact[i]=(fact[i-1]*i)%mod;

    LL test,cs=0;
    scanf("%lld",&test);

    while(test--)
    {
        scanf("%lld%lld",&k,&n);
        for(LL i=0;i<k;i++)
            scanf("%lld%lld",&lower[i],&upper[i]);

        nn=n;
        LL sum=0;
        for(LL i=0;i<k;i++)sum+=lower[i];
        nn-=sum;

        LL ans=0;
       // cout<<"nn:"<<nn<<endl;
        if(nn<0)
        {
            printf("Case %lld: 0\n",++cs);
           // cout<<"ok"<<endl;
            continue;
        }

        for(LL i=0;i<(1<<k);i++)
        {
            cnt=0;
            LL temp=cal(i);
            //cout<<"temp:"<<temp<<endl;
            LL res;
            if(k+temp-1<k-1)
               res=0;
                //cout<<"res:"<<res<<endl;

            else
            {
                res=fact[k+temp-1];
                //cout<<"res1:"<<res<<endl;
                LL hor;
                hor=(fact[k-1]*fact[temp])%mod;
                //cout<<"hor1:"<<hor<<endl;
                hor=modInverse(hor,mod);
                //cout<<"hor2:"<<hor<<endl;
                res=(res*hor)%mod;
                //cout<<"res2:"<<res<<endl;
            }
            if(cnt%2==0)
              ans=(ans+res)%mod;
            else
              ans=(ans-res+mod)%mod;
            //cout<<"ans1:"<<ans<<endl;
        }
        printf("Case %lld: %lld\n",++cs,ans);
    }
    return 0;
}

