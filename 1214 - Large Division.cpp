#include<iostream>
#include<cstring>
 
using namespace std;
int main()
{
    int test,j=0;
    long long sum,div;
    char str[200];
    cin>>test;
    while(test--)
    {
        cin>>str>>div;
        if(div<0)
            div = -div;
               
        int  len = strlen(str);
        sum=0;
        for(int i=0;i<len;i++)
        {
            if(str[i]=='-')
                continue;
            sum+=(str[i]-'0');
           
            if(sum>=div)
                sum%=div;
           
             if(i!=len -1 && sum<div)
                sum = sum*10;
 
            else if(i==len-1 && sum>div)
                sum%=div;
 
        }
 
        if(sum==0)
            cout<<"Case "<<++j<<": divisible"<<endl;
 
        else
            cout<<"Case "<<++j<<": not divisible"<<endl;
    }
 
    return 0;
 
}
 
