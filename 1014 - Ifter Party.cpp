#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
 
using namespace std;
int main()
{
    unsigned long p,l,q,i,a,b;
    vector<unsigned long>Q;
    int test,caseno=0;
    bool sig;
 
    scanf("%d",&test);
    while(test--)
    {
        scanf("%lu%lu",&p,&l);
        printf("Case %d:",++caseno);
        q=p-l;
 
        for(i=1;i<=sqrt(q);i++)
            {
                if(q%i==0)
                    {
                       a=i;
                       b=q/i;
                       if(a!=b && a>l)
                              Q.push_back(a);
                        if(a!=b && b>l)
                                Q.push_back(b);
 
                         if(a==b && a>l)
                            Q.push_back(a);
 
                    }
            }
         sort(Q.begin(),Q.end());
         if(Q.empty())
                printf(" impossible");
          else
          {
              for(i=0;i<Q.size();i++)
                printf(" %lu",Q[i]);
          }
         printf("\n");
         Q.clear();
    }
    return 0;
}
