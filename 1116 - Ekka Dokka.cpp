#include<iostream>
 
using namespace std;
int main()
{
    int test,i=0;
    long long w,m;
    cin>>test;
    while(test--)
    {
        cin>>w;
        if(w%2==1)
            cout<<"Case "<<++i<<": Impossible"<<endl;
 
        else
        {
            m=1;
            while(w%2==0)
            {
                m*=2;
                w/=2;
            }
 
             cout<<"Case "<<++i<<": "<<w<<" "<<m<<endl;
        }
    }
 
    return 0;
}
