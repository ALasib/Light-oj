#include<iostream>
#include<cmath>
 
using namespace std;
int main()
{
    int a,b,c,test,value,i=0;
    cin>>test;
    while(test--)
    {
        cin>>a>>b>>c;
        if(a>b&&a>c)
            {
            value=sqrt(pow(b,2)+pow(c,2));
            if(a==value)
                cout<<"Case "<<++i<<": "<<"yes"<<endl;
            else
                cout<<"Case "<<++i<<": "<<"no"<<endl;
            }
        else if(b>a&&b>c)
        {
            value=sqrt(pow(a,2)+pow(c,2));
             if(b==value)
                cout<<"Case "<<++i<<": "<<"yes"<<endl;
             else
                cout<<"Case "<<++i<<": "<<"no"<<endl;
 
        }
        else if(c>a&&c>b)
        {
            value=sqrt(pow(a,2)+pow(b,2));
            if(c==value)
                cout<<"Case "<<++i<<": "<<"yes"<<endl;
            else
                cout<<"Case "<<++i<<": "<<"no"<<endl;
 
 
        }
 
    }
    return 0;
}
 
