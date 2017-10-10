#include<bits/stdc++.h>

using namespace std;

struct prefix_trie
{
    int sz;

    struct Trie
    {
        int next[5];
        int endmark;
        int cnt,level;
        void clean()
        {
            for(int i=0;i<5;i++)
                next[i] = -1;
            endmark = 0;
            cnt=0;
            level=0;
        }
    };

    Trie *arr = new Trie[1000009];

    void init()
    {
        arr[0].clean();
        sz = 0;
    }

    void Insert(char *s)
    {
        int idx = 0;
        int len=strlen(s);

        for(int i=0;i<len; i++)
        {
            int x;
            if(s[i]=='A')x=0;
            if(s[i]=='C')x=1;
            if(s[i]=='G')x=2;
            if(s[i]=='T')x=3;

            if(arr[idx].next[x] == -1)
            {
                sz++;
                arr[sz].clean();
                arr[idx].next[x] = sz;
            }
            idx = arr[idx].next[x];
            arr[idx].cnt++;
            arr[idx].level=i+1;
        }
        arr[idx].endmark++;
    }

};

int main()
{
    int test,cs=0;
    scanf("%d",&test);
    prefix_trie Tr;

    while(test--)
    {
        int n;
        scanf("%d",&n);
        Tr.init();

        char str[55];
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            Tr.Insert(str);
        }

        int ans=-1;
        for(int i=0;i<=Tr.sz;i++)
        {
            ans=max(ans,Tr.arr[i].level*Tr.arr[i].cnt);
        }
        printf("Case %d: %d\n",++cs,ans);
    }
    return 0;
}
