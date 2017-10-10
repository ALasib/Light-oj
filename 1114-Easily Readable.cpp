 /*Nahid Al-Asib*/

#include<bits/stdc++.h>
using namespace std;

struct prefix_trie
{
    int sz;
    struct Trie
    {
        int next[60];
        int endmark;
        void clean()
        {
            for(int i=0;i<60;i++)
                next[i] = -1;
            endmark = 0;
        }
    };

    Trie *arr = new Trie[100099];
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
            int x =(s[i]>='a')?s[i]-'a'+26:s[i]-'A';
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

    int query(char *s)
    {
        int idx = 0;
        int len=strlen(s);

        for(int i=0;i<len; i++)
        {
            int x = (s[i]>='a')?s[i]-'a'+26:s[i]-'A';
            if(arr[idx].next[x] == -1)
                return 0;
            idx = arr[idx].next[x];
        }
        return arr[idx].endmark;
    }
};

char str[100005],s[100005];

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

        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            int len=strlen(str);
            if(len>3)
                sort(str+1,str+len-1);
            Tr.Insert(str);
        }

        int m;
        scanf("%d",&m);
        printf("Case %d:\n",++cs);
        gets(s);

        for(int i=0;i<m;i++)
        {
            gets(s);
            int len=strlen(s);
            int j=0;
            int ans=1;

            while(true)
            {
                while(s[j]==' ')j++;
                if(s[j]=='\0')break;
                int k=0;
                while(s[j]!=' 'and s[j]!='\0')str[k++]=s[j++];
                str[k]='\0';

                int l=strlen(str);
                if(l>3)sort(str+1,str+l-1);

                ans*=Tr.query(str);
            }
            printf("%d\n",ans);
        }

    }
    return 0;
}
