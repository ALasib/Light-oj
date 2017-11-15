#include<iostream>
using namespace std;
int main()
{
    int test,n,k,i=0,sum;
    cin>>test;
    if(test<=100)
        while(test--)
    {
        cin>>n;
        if((n>=1)&&(n<=1000))
        {
            sum=0;
            while(n--)
            {
                cin>>k;
                if((k>=0)&&(k<100))
                    sum+=k;
 
            }
            cout<<"Case "<<++i<<": "<<sum<<endl;
        }
    }
    return 0;
}
