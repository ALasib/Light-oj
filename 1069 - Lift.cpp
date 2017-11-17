#include<iostream>
#include<cmath>
 
using namespace std;
int main()
{
    int test,me,lift,time,i=0;
    cin>>test;
    while(test--)
    {
        cin>>me>>lift;
        if(me!=lift)
            time = 19 + (4*abs(me-lift)) + (4*me);
 
        else
            time = 19 + (me*4);
 
        cout<<"Case "<<++i<<": "<<time<<endl;
    }
 
    return 0;
}
