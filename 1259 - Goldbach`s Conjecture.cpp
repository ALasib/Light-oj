#include<iostream>
#include<cmath>
#define MAX 10000000
 
bool prime[10000015];
long int b[667753];
 
long int num;
 
using namespace std;
 
void seive()
{
 
    long int i,j,x;
 
    x = sqrt(MAX);
 
    prime[0] = prime[1] = false;
 
    for(i=4;i<=MAX;i+=2)
        prime[i] = false;
 
    for(i=3;i<=x;i+=2)
    {
        if(prime[i]==true)
        {
            for(j=i*i;j<=MAX;j+=i)
                prime[j] = false;
        }
    }
 
    return;
 
}
 
int main()
{
    int test,i,j = 0,k = 0;
    long int c,n;
 
    for(i=0;i<=MAX;i++)
        prime[i] = true;
 
    seive();
 
    for(i=2;i<=MAX;i++)
    {
        if(prime[i])
        {
 
            b[j++] = i;
            num = j;
        }
    }
 
    cin>>test;
 
    while(test--)
    {
        cin>>n;
        c = 0;
 
        for(i=0;i<num && b[i]<=n/2;i++)
        {
            if(prime[n-b[i]])
                c++;
        }
 
        cout<<"Case "<<++k<<": "<<c<<endl;
 
    }
 
    return 0;
 
}
