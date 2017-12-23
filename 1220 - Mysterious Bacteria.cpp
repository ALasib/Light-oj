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
    ll x,temp,p,c,l;
    sieve(5000099);
    ll len=primes.size();
    scanf("%d",&test);
 
    while(test--)
    {
        scanf("%lld",&x);
        temp=abs(x);
        p=0;
        for(i=0;i<len, primes[i]<=sqrt(temp);i++)
        {
            if(temp<=1)
                break;
            if(temp<5000000)
                if(bs[temp])
            {
                p=1;
                break;
            }
 
            c=0;
            while(temp%primes[i]==0)
            {
                temp/=primes[i];
                c++;
            }
            p=__gcd(p,c);
 
            if(p==1)
                break;
 
        }
        if(p==0)
            p=1;
         //cout<<p<<endl;//  - sign thakle jor bijor banate hobe ,nahole samne -sign asbe na,tai  2diye vag krte hoi//
        if(x<0)
        {
            while(p%2==0)
                p/=2;
        }
        printf("Case %d: %lld\n",++caseno,p);
    }
    return 0;
}
