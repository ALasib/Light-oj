#include<stdio.h>
#include<limits.h>
 
int count_zero(int n)
{
    int c=0;
    while(n!=0)
    {
       n=n/5;
       c+=n;
    }
    return c;
}
 
int zero(int q)
{
    int low=1,high=INT_MAX,mid,ans=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(count_zero(mid)<q)
            low=mid+1;
        else if(count_zero(mid)>q)
            high=mid-1;
        else
        {
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
}
 
int main()
{
    int test,caseno=0,q,ans;
    scanf("%d",&test);
 
    while(test--)
    {
        scanf("%d",&q);
        ans=zero(q);
        if(!ans)
            printf("Case %d: impossible\n",++caseno);
        else
            printf("Case %d: %d\n",++caseno,ans);
    }
    return 0;
}
