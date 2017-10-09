    #include<bits/stdc++.h>
     
    using namespace std;
    struct prefix_trie
    {
        int sz;
        struct Trie
        {
            int next[11];
            int endmark;
            int cnt;
            void clean()
            {
                for(int i=0;i<10;i++)
                    next[i] = -1;
                endmark = 0;
                cnt=0;
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
                int x = s[i]-'0';
                if(arr[idx].next[x] == -1)
                {
                    sz++;
                    arr[sz].clean();
                    arr[idx].next[x] = sz;
                }
                idx = arr[idx].next[x];
                arr[idx].cnt++;
            }
            arr[idx].endmark++;
        }
     
        int query(char *s)
        {
            int idx = 0;
            int len=strlen(s);
            for(int i=0;i<len; i++)
            {
                int x = s[i]-'0';
                if(arr[idx].next[x] == -1)
                    return 0;
                idx = arr[idx].next[x];
            }
            return arr[idx].endmark;
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
            char str[12];
     
            for(int j=0;j<num;j++)
            {
                cin>>str;
                Tr.Insert(str);
            }
     
            int sig=1;
            //cout<<"ok"<<endl;
            for(int i=0;i<=Tr.sz;i++)
            {
                if(Tr.arr[i].endmark>0 and Tr.arr[i].cnt>1)
                    sig=0;
            }
            if(!sig)
                printf("Case %d: NO\n",++cs);
            else
                printf("Case %d: YES\n",++cs);
        }
        return 0;
    }
