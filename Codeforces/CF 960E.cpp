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
const int mod = 1e9+7;
int n;
vector<int> G[MAXN];
int o[MAXN],e[MAXN],d[MAXN],v[MAXN],pa[MAXN];
void dfs(int u, int fa)
{
	pa[u]=fa;
	if (fa==-1)d[u]=0;
	else d[u]=d[fa]+1;
	e[u]=1;
	for (int v:G[u])
	{
		if (v!=fa) 
		{
			dfs(v,u);
			o[u] += e[v];
			e[u] += o[v];
		}
	}
}
void upd(LL &x, LL y)
{
	x += y;
	if (x>=mod) x-=mod;
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",v+i);
	rep(i,1,n)
	{
		int v,u;scanf("%d%d",&u,&v);
		G[u].pb(v);G[v].pb(u);
	}
	dfs(1,-1);
	LL ans = 0;
	rep(i, 1, n+1)
	{
		LL tot = 0;
		rep(j,0,SZ(G[i]))
		{
			int v=G[i][j];
			if (v == pa[i]) continue;
			upd(tot,1ll*o[v]*(n-o[v]-e[v]));
			upd(tot,((-1ll*e[v]*(n-o[v]-e[v])%mod)+mod)%mod);
		}
		if ((d[i]-d[1])&1)
		{
			upd(tot,1ll*(o[1]-e[i])*(e[i]+o[i]));
			upd(tot,(-1ll*(e[1]-o[i])*(e[i]+o[i])%mod+mod)%mod);
		}
		else
		{
			upd(tot,1ll*(e[1]-e[i])*(e[i]+o[i]));
			upd(tot,(-1ll*(o[1]-o[i])*(e[i]+o[i])%mod+mod)%mod);
		}
		upd(tot,n);
		upd(ans,(tot*v[i]%mod+mod)%mod);
	}
	printf("%lld\n",ans);
	return 0;
}

