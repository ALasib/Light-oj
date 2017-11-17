#include<iostream>
 
using namespace std;
int main()
{
    int test,i=0;
    long long n,m,sum;
    cin>>test;
    while(test--)
    {
        cin>>n>>m;
        sum = (n*m)/2;
        cout<<"Case "<<++i<<": "<<sum<<endl;
    }
 
    return 0;
 
}
