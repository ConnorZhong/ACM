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
int du[MAXN];
int used[MAXN];
set<int> vis;set<int> G[MAXN];
int n,m,k;

void dfs(int u)
{
	set<int> :: iterator  ite;
	int cnt = 0;
	for (ite = vis.begin();ite!=vis.end();)
	{
		int v=*ite;
		if (!G[u].count(v))
		{
			vis.erase(v);
			dfs(v);
			ite = vis.lower_bound(v);
			cnt++;
		}
		else ite++;
	}
	if (u == 1 && cnt > k) return exit(0*puts("impossible")); 

}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	rep(i, 2, n+1) vis.insert(i);
	rep(i ,0 ,m)
	{
		int u,v;scanf("%d%d",&u,&v);
		G[u].insert(v);
		G[v].insert(u);
		du[u]--;du[v]--;
	}
	// de(1a)
	du[1]+=n-1;
	if (du[1] < k) return 0*puts("impossible");
	// de(1)
	dfs(1);
	if (vis.size()) puts("impossible");
	else puts("possible");
	return 0;
}

