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
const int MAXN = 300005; // 1e6;
int n;
int m;

namespace BCC // 边双
{	
	vector<int> G[MAXN], bcc[MAXN];
	int dfn[MAXN], low[MAXN], bccno[MAXN], iscut[MAXN],time_out,bcc_cnt;
	int D[MAXN];
	stack<pair<int, int> > S;
	int dfs(int u, int fa)
	{
		low[u]=dfn[u]=++time_out;//1-idx
		int child=0;
		for (int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			pair<int, int> e = mkp(u,v);
			if (!dfn[v])
			{
				S.push(e);
				child++;
				dfs(v,u);
				low[u]=min(low[v],low[u]);
				if (low[v]>=dfn[u])
				{
					iscut[u]=true;
					bcc_cnt++; bcc[bcc_cnt].clear();// 1-idx;
					while(1)
					{
						pair<int,int> x = S.top();S.pop();
						if (bccno[x.fi]!=bcc_cnt) 
						{
							bcc[bcc_cnt].push_back(x.fi);
							bccno[x.fi]=bcc_cnt;
						}
						if (bccno[x.se]!=bcc_cnt)
						{
							bcc[bcc_cnt].push_back(x.se);
							bccno[x.se]=bcc_cnt;
						}
						if (x.fi == u && x.se == v) break;
					}
				}
			}
			else if (dfn[v] < dfn[u] && v != fa) {
				S.push(e);
				low[u]=min(low[u], dfn[v]);
			}
		}
		if (fa < 0 && child == 1) iscut[u] = 0;
		return low[u];
	}
	void solve()
	{
		memset(dfn,0,sizeof dfn);
		memset(low,0,sizeof low);
		memset(iscut,0,sizeof iscut);
		memset(bccno,0,sizeof bccno);
		time_out=bcc_cnt=0;
		for (int i=1; i<=n ;i++) //1-idx
			if (!dfn[i]) dfs(i,-1);
	}

};
using namespace BCC;
int aim[MAXN];
LL anss[MAXN];
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	memset(aim,-1,sizeof aim);
	rep(i, 1, m+1)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	solve();
	rep(i, 1, bcc_cnt+1) 
	{

		if (SZ(bcc[i])>1)
		{
			sort(all(bcc[i]));
			int l = bcc[i][0], r = bcc[i][SZ(bcc[i])-1];
			de(l) de(r)
			aim[l]=r;
			aim[r]=l;
		}
	}
	MOO();
	return 0;
}

