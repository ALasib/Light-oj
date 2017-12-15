#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
 
 
bool cmp(pair <int, int> a, pair<int,int> b)
{
 
    if(a.first < b.first)
        return true;
 
    if(a.first > b.first)
        return false;
 
   if(a.second > b.second)
        return true;
    return false;
 
}
 
int main()
{
    int n;
    int test;
 
    vector < pair <int, int> > a(1001);
 
    for (int i = 1; i <= 1000; i++) {
        a[i].second = i;
        a[i].first = 0;
    }
 
    for (int i = 1; i <= 1000; i++) {
            for (int j = i; j <= 1000; j = j + i) {
                a[j].first++;
            }
    }
  sort(a.begin(), a.end(), cmp);
  scanf("%d", &test);
 
 
    for (int caseno = 1; caseno <= test; caseno++) {
        scanf("%d", &n);
        printf("Case %d: %d\n", caseno, a[n].second);
 
    }
 
return 0;
}
 
