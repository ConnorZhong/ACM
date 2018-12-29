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
int n, m;
LL a[MAXN];
int fa[MAXN];
struct edge
{
        int u, v;
        LL cost;
        bool operator<(const edge & y) const
        {
                return cost < y.cost;
        }
} e[MAXN];
int find_root(int x)
{
        if (fa[x]==x) return x;
        else return fa[x]=find_root(fa[x]);
}
void unite(int x, int y)
{
        x = find_root(x), y = find_root(y);
        if (x == y) return;
        a[x] = min(a[x], a[y]);
        fa[y] = x;
}
priority_queue<pair<LL,LL>, vector<pair<LL,LL> > ,greater<pair<LL,LL> > > que;
int main()
{
        // freopen("in.txt","r",stdin);
        // de(1)
        scanf("%d%d",&n,&m);
        rep(i, 1, n+1) fa[i]=i;
        rep(i, 1, n+1) scanf("%lld", a+i), que.push(mkp(a[i], i));
        rep(i, 1, m+1) {
                scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].cost);
        }
        sort(e+1,e+1+m);
        int cnt = n-1;
        int now = 1;
        LL ans = 0;
        // fa[2]=1;
        rep(_, 0, n-1)
        {
                int u,v;
                LL cu,cv;
                while(1){
                        u = que.top().se, cu = que.top().fi;
                        que.pop();
                        u = find_root(u);
                        if (a[u] != cu) continue;
                        else break;
                }
                while(1){
                        v = que.top().se, cv = que.top().fi;
                        que.pop();
                        v = find_root(v);
                        if (a[v] != cv || u==v) continue;
                        else break;
                }

                LL c = cu + cv;
                while(now <= m && find_root(e[now].u) == find_root(e[now].v)) now++;
                if (now > m || c < e[now].cost) 
                {
                        ans += c;
                        unite(u, v);
                        u = find_root(u);
                        c = a[u];
                        que.push(mkp(c, u));
                }
                else {
                        ans += e[now].cost;
                        que.push(mkp(cu,u));
                        que.push(mkp(cv,v));
                        u = e[now].u, v = e[now].v;
                        unite(u, v);
                        u = find_root(u);
                        c = a[u];
                        que.push(mkp(c, u));
                        now++;
                }

        }
        printf("%lld\n",ans);
        return 0;
}

