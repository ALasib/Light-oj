/*Hints:Trie Tree+Bit manipulation*/

#include<bits/stdc++.h>

using namespace std;

struct prefix_trie
{
    int sz;
    struct Trie
    {
        int next[2];
        int endmark;
        int cnt;
        void clean()
        {
            for(int i=0;i<2;i++)
                next[i] = -1;
            endmark = 0;
        }
    };

    Trie *arr = new Trie[50005 * 33];

    void init()
    {
        arr[0].clean();
        sz = 0;
    }

    void Insert(int mask)
    {
        int idx = 0;

        for(int i=31;i>=0; i--)
        {
            int x = (mask>>i)&1;
            if(arr[idx].next[x] == -1)
            {
                sz++;
                arr[sz].clean();
                arr[idx].next[x] = sz;
            }
            idx = arr[idx].next[x];
        }
        arr[idx].endmark++;
    }

    int get_max(int mask)
    {
         int idx = 0;
         int ans=0;

         for(int i=31;i>=0; i--)
         {
            int x = (mask>>i)&1;
            x=x^1;

            if(arr[idx].next[x] != -1)
            {
                ans<<=1;
                ans++;
                idx=arr[idx].next[x];
            }
            else
            {
                ans<<=1;
                idx=arr[idx].next[x^1];
            }
         }

         arr[idx].endmark++;
         return ans;
    }

    int get_min(int mask)
    {
         int idx = 0;
         int ans=0;

         for(int i=31;i>=0; i--)
         {
            int x = (mask>>i)&1;

            if(arr[idx].next[x] != -1)
            {
                ans<<=1;
                idx=arr[idx].next[x];
            }
            else
            {
                ans<<=1;
                ans++;
                idx=arr[idx].next[x^1];
            }
         }

         arr[idx].endmark++;
         return ans;
    }

    int query(char *s)
    {
        int idx = 0;
        int len=strlen(s);
        for(int i=0;i<len; i++)
        {
            int x = s[i]-'0';
            if(arr[idx].endmark)return 1;
            idx = arr[idx].next[x];
        }
        return 0;
    }
};

int main()
{
    int test,cs=0,num;
    prefix_trie Tr;
    scanf("%d",&test);

    while(test--)
    {
        scanf("%d",&num);
        Tr.init();
        Tr.Insert(0);
        int ans_min,taken,ans_max;
        int so_far=0;

        for(int i=0;i<num;i++)
        {
            scanf("%d",&taken);
            if(i==0)
            {
                ans_min=taken;
                ans_max=taken;
            }
            so_far=so_far^taken;
            ans_max=max(ans_max,Tr.get_max(so_far));
            ans_min=min(ans_min,Tr.get_min(so_far));
            Tr.Insert(so_far);
        }
        printf("Case %d: %d %d\n",++cs,ans_max,ans_min);

    }
    return 0;
}

