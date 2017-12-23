/* I am ordinary as well as very bad coder*/

#include<bits/stdc++.h>
long long sieve_size;
using namespace std;
 
bitset<10000010> bs;
vector <int>primes;
typedef long long ll;
 
void sieve(ll upperbound)
{
     sieve_size = upperbound + 1;
     bs.set();
     bs[0] = bs[1] = 0;
     primes.push_back(2);
     for(ll i = 4; i <= sieve_size; i += 2) bs[i] = 0;
     for (ll i = 3; i <= sieve_size; i++)
        if (bs[i])
        {
            for (ll j = i * i,k=i*2; j <= sieve_size; j += k)
                bs[j] = 0;
            primes.push_back((int)i);
        }
}
 
int main()
{
    int test,caseno=0,i;
    ll a,b,c,lcm,l,p,len,p_l,p_lcm;
    sieve(5000099);
    len=primes.size();
    scanf("%d",&test);
 
    while(test--)
    {
        scanf("%lld%lld%lld",&a,&b,&l);
        lcm=a*b/__gcd(a,b);
        if(l%a!=0 || l%b!=0)
            printf("Case %d: impossible\n",++caseno);
        else
        {
            c=l;
            for(i=0;i<len,primes[i]<=sqrt(l);i++)
            {
                if(l<=1 || lcm<=1)
                    break;
                p_l=1;
                p_lcm=1;
 
                while(l%primes[i]==0)
                {
                    l/=primes[i];
                    p_l*=primes[i];
                }
 
                while(lcm%primes[i]==0)
                {
                    lcm/=primes[i];
                    p_lcm*=primes[i];
                }
 
                if(p_l==p_lcm)
                    c/=p_l;
            }
            if(lcm==l)
                c=c/l;
            printf("Case %d: %lld\n",++caseno,c);
        }
    }
    return 0;
}
 
