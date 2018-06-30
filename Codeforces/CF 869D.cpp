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
#include <bitset>
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

const int INF = 0x3f3f3f3f;
const int MAXN = 1000005; // 1e6;
const int MOD = 1e9+7;
int n,m,cnt;
int num[MAXN];
map<int, int> hs;
map<pair<int,int> , int> used;
LL ans = 0;
vector<int> G[MAXN];
LL get_num(int x)
{
	int ret = 1;
	if (hs.find(x << 1) == hs.end()) 
	{
		int mi = x<<1, ma = x<<1;
		while(ma <= n)
		{
			ret += ma+1-mi;
			ma = ma<<1|1;
			mi = mi<<1;
		}
		if (mi <= n && ma >= n) ret += n+1-mi; 
	}
	if (hs.find(x<<1|1) == hs.end())
	{
		int mi = x<<1|1, ma = x<<1|1;
		while(ma <= n)
		{
			ret += ma+1-mi;
			ma = ma<<1|1;
			mi = mi<<1;
		}
		if (mi <= n && ma >= n) ret += n+1-mi; 
	}
	return ret;
}
int vis[MAXN];
void dfs(int i, int s)
{
	vis[i]=true;
	ans = (ans+ 1ll*num[s]*num[i]%MOD)%MOD;
	rep(j,0,G[i].size())
	{
		int v=G[i][j];
		if (!vis[v]) dfs(v,s);
	}
	vis[i]=false;

}
int main()
{
	// freopen("in.txt","r",stdin);

	scanf("%d%d",&n,&m);
	hs[1]=++cnt;
	rep(i, 0, m)
	{
		int u, v;
		scanf("%d%d",&u,&v);
		if (!hs[u]) hs[u]=++cnt;
		if (!hs[v]) hs[v]=++cnt;
		G[hs[u]].pb(hs[v]);
		G[hs[v]].pb(hs[u]);
		while (u>1) 
		{
			if (!hs[u>>1]) hs[u>>1]=++cnt;
			if (!used[mkp(u>>1,u)]) G[hs[u]].pb(hs[u>>1]);
			if (!used[mkp(u,u>>1)]) G[hs[u>>1]].pb(hs[u]);
			used[mkp(u>>1,u)]=used[mkp(u,u>>1)]=1;
			u>>=1;
		}
		while(v>1)
		{
			if (!hs[v>>1]) hs[v>>1]=++cnt;
			if (!used[mkp(v>>1,v)]) G[hs[v]].pb(hs[v>>1]);
			if (!used[mkp(v,v>>1)]) G[hs[v>>1]].pb(hs[v]);
			used[mkp(v>>1,v)]=used[mkp(v,v>>1)]=1;
			v>>=1;
		}
	}
	for (auto x: hs)
	{
		num[x.se] = get_num(x.fi);
	}
	for (auto x: hs)
	{
		dfs(x.se,x.se);
	}
	printf("%lld\n",ans);
	return 0;
}

