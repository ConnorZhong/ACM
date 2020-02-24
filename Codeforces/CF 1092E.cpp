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
const int MAXN = 1005; // 1e3;
int d[MAXN];
int maxd, argd, mid, ok;

vector<int> G[MAXN];
int n,m;
bool vis[MAXN];

void dfs1(int u, int fa)
{
        if (fa == -1) d[u]=0;
        else d[u]=d[fa]+1;
        if (d[u] > maxd) argd = u, maxd = d[u];
        for (int v : G[u])
        {
                if (v == fa) continue;
                else dfs1(v,u);
        }
}

void dfs2(int u, int fa, int q)
{

        if (q == u) ok = true, maxd /= 2;
        if (!ok)
                for (int v : G[u])
                {
                        if (ok) break;
                        if (v == fa) continue;
                        else dfs2(v,u,q);
                }
        if (ok && maxd == 0) mid = u; 
        if (ok) maxd --;
}

pair<int,int> get_diameter(int i)
{
        maxd = 0, argd = i;
        dfs1(i,-1);
        // de(maxd)
        int p = argd;
        maxd = 0; 
        dfs1(argd, -1);
        // de(maxd)
        int q = argd, dia = maxd;
        ok = 0;
        dfs2(p, -1, q);
        return make_pair(dia,mid);
}




int main()
{
        // freopen("in.txt","r",stdin);
        scanf("%d%d",&n,&m);
        rep(i, 1, m+1)
        {
                int u,v;scanf("%d%d",&u,&v);
                G[u].pb(v);G[v].pb(u);
        }
        vector<pair<int,int> > edge;
        int c = n-1-m;

        rep(_, 0, c){
                memset(d, -1, sizeof d);
                pair<int,int> m1, m2, tmp;
                m1 = mkp(-1,0);
                m2 = mkp(INF,0);
                rep(i, 1, n+1)
                {
                        if (d[i] == -1) 
                        {
                                tmp = get_diameter(i);
                                if (m1.fi < tmp.fi) m1 = tmp;
                                if (m2.fi >= tmp.fi) m2 = tmp;
                        }
                } 
                // de(m1.se) de(m2.se)
                int u = m1.second, v = m2.second;
                // de(_)

                edge.pb(mkp(u, v)); 
                G[u].pb(v);
                G[v].pb(u);
        }
        printf("%d\n",get_diameter(1).first);
        // printf("%d\n",edge.size());
        rep(i, 0, c) printf("%d %d\n",edge[i].fi,edge[i].se);
        
        return 0;
}

