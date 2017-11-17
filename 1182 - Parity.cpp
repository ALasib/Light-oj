#include<iostream>
 
using namespace std;
int main()
{
    int dec,test,i=0,c;
    cin>>test;
    while(test--)
    {
        cin>>dec;
        c=0;
        while(dec>0)
        {
            if(dec%2==1)
            {
                c++;
                dec/=2;
            }
 
            else
                dec/=2;
        }
 
      if(c%2==0)
 
        cout<<"Case "<<++i<<": even"<<endl;
 
      else
 
        cout<<"Case "<<++i<<": odd"<<endl;
    }
 
    return 0;
}
