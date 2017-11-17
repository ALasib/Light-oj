#include<iostream>
#include<cstring>
 
using namespace std;
int main()
{
    int test,n,amount,i=0;
    char str[10];
    cin>>test;
    while(test--)
    {
 
        cin>>n;
        cout<<"Case "<<++i<<":"<<endl;
        int sum = 0;
        while(n--)
        {
            cin>>str;
 
            if(!strcmp(str,"donate"))
            {
                cin>>amount;
                sum+=amount;
            }
 
            else if(!strcmp(str,"report"))
 
                 cout<<sum<<endl;
 
        }
    }
 
    return 0;
}
 
