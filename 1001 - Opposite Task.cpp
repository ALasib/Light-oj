#include<iostream>
using namespace std;
int main()
{
    int test,n,r;
    cin>>test;
    while(test--)
    {
        cin>>n;
        if(n>10)
             cout<<n-10<<" "<<n-(n-10)<<endl;
        else
            cout<<"0 "<<n<<endl;
    }
    return 0;
}
