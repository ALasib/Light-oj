/* i am ordinary as well as very bad coder*/

#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
vector<LL>primes;

void seive(LL sz)
{
    vector<bool>is_prime(sz+2,1);
    is_prime[0]=is_prime[1]=0;

    for(LL i=4;i<=sz;i+=2)
        is_prime[i]=0;

    for(LL i=3;i<=sqrt(sz);i++)
    {
        if(is_prime[i])
        {
            for(LL j=2*i;j<=sz;j+=i)
                is_prime[j]=0;
        }
    }

    for(LL i=2;i<=sz;i++)
        if(is_prime[i])primes.push_back(i);
}

LL slove(LL low,LL high)
{
    LL cnt=0;
    vector<bool>check(high-low+2,1);
    for(LL i=0;primes[i]*primes[i]<=high;i++)
    {
        LL start=max(primes[i]*primes[i],low+(primes[i]-(low%primes[i]))%primes[i]);
        for(LL j=start;j<=high;j+=primes[i])
        {
            if(check[j-low])
            {
                check[j-low]=0;
                cnt++;
            }
        }
    }

    return (high-low-cnt+(low>1));
}

int main()
{
    int test,cs=0;
    scanf("%d",&test);
    seive(1<<17);
    while(test--)
    {
        LL low,high;
        scanf("%lld%lld",&low,&high);
        LL ans=slove(low,high);
        printf("Case %d: %lld\n",++cs,ans);
    }
    return 0;
}
