/*Solution Idea : 
          1. factorize n, 
          2. n can be written as in the form of  ^ (K1) * P2 ^ (K2) ........ PM * (km) 
          3. Then the answer is ((2k1 +1) * (2k2 +1) * ....... (2km +1) +1) / 2.
          4. Its principle is separately for each factor to see 2 * k +1, and then for each factor.
          5.  Multiplying all factors, so that the last draw answers, each pair calculated twice (addition <n,n> the),
         6.  the final answer (ANS +1) / 2;
         */
         
         #include<bits/stdc++.h>
long long sieve_size;
using namespace std;
typedef long long ll;
bitset<10100010> bs;
vector<int>primes;
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
    long long ans,n,c,len;
    double pair_lcm;
    sieve(10000099);
    len=primes.size();
    scanf("%d",&test);
 
    while(test--)
    {
        scanf("%lld",&n);
        pair_lcm=1;
        for(i=0;i<len,primes[i]<=sqrt(n);i++)
        {
            if(n<=1)
                break;
            if(n<10000000)
                if(bs[n])
            {
                pair_lcm*=3;
                n=1;
                break;
            }
 
            c=0;
            while(n%primes[i]==0)
            {
                n/=primes[i];
                c++;
            }
            pair_lcm*=((2*c)+1);
        }
        if(n!=1)
            pair_lcm*=3;
        ans=ceil(pair_lcm/2);
        printf("Case %d: %lld\n",++caseno,ans);
    }
    return 0;
 
}
 
