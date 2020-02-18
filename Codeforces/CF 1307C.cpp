#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <utility>
#include <cassert>
#include <bitset>
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define rep(i,a,b) for (int i=(a);i<(b);i++)
#define per(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,a,b) for (int i=(a);i<=(b);i++)
#define PER(i,a,b) for (int i=(b);i>=(a);i--)
#define de(x) cout<<">> "<<#x<<" = "<<x<<endl;
using namespace std;
typedef long long LL;
LL powmod(LL a,LL b,LL mod) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL gcd(LL a, LL b) {if (b==0)return a;else return gcd(b,a%b);}
const int INF = 0x3f3f3f3f;
const int MAXN = 1000005; // 1e6;
LL ans = 0;
struct Trie
{
        const static int MAX_NODE=1e5+5;
        const static int MAX_SIGMA=26; //节点数量，字符集大小。
        int ch[MAX_NODE][MAX_SIGMA];
        LL val[MAX_NODE],sz; // 0 永远表示根节点。
        void init()
        {
                memset(ch[0],0,sizeof ch[0]);
                sz=1;
                val[0]=0;
        }
        int inline idx(char c) {return c-'a';}
        void trie_insert(char *s, int v)
        {
                int u=0,n=strlen(s);
                for(int i=0;i<n;i++)
                {
                        int c=idx(s[i]);
                        if (!ch[u][c])
                        {
                                memset(ch[sz],0,sizeof ch[sz]);
                                val[sz]=0;
                                ch[u][c]=sz++;
                        }
                        u=ch[u][c];
                }
                val[u]=val[u]+v;
                // printf("%s %d\n",s,v);
                ans = max(ans, val[u]);
        }
        int trie_find(char *s, int v)
        {
                int u=0,n=strlen(s);
                for(int i=0;i<n;i++)
                {
                        int c=idx(s[i]);
                        if (!ch[u][c])
                        {
                                return -1;
                        }
                        u=ch[u][c];
                }
                return val[u];
        }
};
Trie trie;

char s[MAXN];
// int ans = 0;
char c[MAXN];
void inline insert(int pos, char ch)
{
        c[pos]=ch;c[pos+1]='\0';
}
map<char, int> m;
int main()
{
        // freopen("in.txt","r",stdin);
        scanf("%s",s);
        int n = strlen(s);
        trie.init();
        rep(i, 0, n) {
                m[s[i]]++;
        }
        rep(i, 0, n){
                m[s[i]]--;
                insert(0, s[i]);
                trie.trie_insert(c,1);
                for (map< char, int >::iterator ite=m.begin();ite!=m.end();ite++){
                        
                        char ch = ite->first;
                        int val = ite->second;
                        insert(1, ch);
                        trie.trie_insert(c, val);
                }

        }
       
        printf("%lld\n",ans);
        return 0;
}

