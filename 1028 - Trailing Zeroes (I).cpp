#include<stdio.h>
#include<vector>
#include<bitset>
#include<math.h>
typedef long long ll;
typedef unsigned long long llu;
typedef unsigned int ui;
using namespace std;
vector<int>primes;
bitset<10000010> bs;
 
void sieve(ll upperbound)
{
     ll sieve_size = upperbound + 1;
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
    int test,caseno=0;
    llu i,n,c,ans;
    sieve(5000090);
    scanf("%d",&test);
 
    while(test--)
    {
        scanf("%llu",&n);
        ans=1;
        for(i=0;primes[i]<=sqrt(n);i++)
        {
            if(n==1)
                break;
            if(n<5000000)
                if(bs[n])
            {
                ans*=2;
                n=1;
                break;
            }
            c=0;
 
            while(n%primes[i]==0)
            {
                n/=primes[i];
                c++;
            }
            ans*=(c+1);
        }
 
        if(n!=1)
            ans*=2;
        printf("Case %d: %llu\n",++caseno,ans-1);
    }
    return 0;
}
 
