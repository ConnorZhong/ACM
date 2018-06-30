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
const int MAX_LOG_N=18;
struct Tree{ 

	const int MAXN = 1000005;
	const int MAX_LOG_N=20;
	vector<int> G[MAXN];
	int parent[20][MAXN];
	int depth[MAXN];
	int n, root; // 1-idx
	void lca_init()
	{
		dfs(root,-1);
		for (int k=0;k+1<MAX_LOG_N;k++)
		for (int v=1;v<=n;v++)
		{
			if (parent[k][v]<0)parent[k+1][v]=-1;
			else parent[k+1][v]=parent[k][parent[k][v]];
		}
	}
	void dfs(int u, int fa){
		if (fa == -1) depth[u]=0;
		parent[0][u]=fa;
		for (int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if (v==fa)continue;
			dfs(v,u);
		}
	}
	int lca(int u,int v)
	{
		if (depth[u]>depth[v]) swap(u,v);
		for (int k=0;k<MAX_LOG_N;k++)
		{
			if ((depth[v]-depth[u])>>k&1) v=parent[k][v];
		}
		if (u==v) return u;
		for (int k=MAX_LOG_N-1;k>=0;k--){
			if (parent[k][u]!=parent[k][v]){
				u=parent[k][u];
				v=parent[k][v];
			}
		}
		return parent[0][u];
	}
	int dis(int u, int v)
	{
		return depth[u]-depth[v]-2*depth[lca(u,v)];
	}

} tree;
int parent[20][MAXN];
int ans[MAXN],m;
int s1[MAXN],s2[MAXN],top1,top2;
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&m); tree.n=m+1;
	rep(i,2,m+2)
	{
		int fa;
		scanf("%d",&fa);
		tree.G[i].pb(fa);
		tree.G[fa].pb(i);
	}
	tree.lca_init();
	s1[top1++]=1;
	return 0;
}

