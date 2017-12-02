/*
question reduces to determining how many lattice points lie on the line segment from
(x1, y1) to (x2, y2). Since the answer stays the same under translation by an integer, 
this reduces to determining how many lattice points lie on the line segment from (0, 0) 
to (x, y) for arbitrary x and y.

If x=0 or y=0, the answer is 1D and trivial (i.e. x+1 or y+1).

Otherwise, the answer is gcd(x,y) + 1. You prove this by showing (a) that any lattice point 
between (0,0) and (x,y) must be a multiple of the "least" lattice point; and (b) that any 
lattice point must have coordinates that are factors of (x,y)
*/

#include<stdio.h>
#include<math.h>
 
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}
 
long long Abs (long long n)
 {
       return n> 0? n:-n;
 }
 
int main()
{
    long long ax,ay,bx,by;
    int test,caseno=0;
    scanf("%d",&test);
 
    while(test--)
    {
        scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
        printf("Case %d: %lld\n",++caseno,gcd(Abs(ax-bx),Abs(ay-by))+1);
    }
    return 0;
}
 
