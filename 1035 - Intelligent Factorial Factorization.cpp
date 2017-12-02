#include<bits/stdc++.h>
 
using namespace std;
void cal(int a,int b)
{
    int sum=0;
    while(b)
    {
        b=b/a;
        sum+=b;
    }
 
    printf(" %d (%d)",a,sum);
}
 
int main()
{
    int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103 };
    int test,i,caseno=0,n,a;
    scanf("%d",&test);
 
    while(test--)
    {
        scanf("%d",&n);
        printf("Case %d: %d =",++caseno,n);
        for(i=0;prime[i]<=n;i++)
        {
            a=prime[i];
            if(i)
                printf(" *");
            cal(a,n);
        }
        printf("\n");
    }
    return 0;
}
 
