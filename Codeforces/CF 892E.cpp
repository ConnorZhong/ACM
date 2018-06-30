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
int fa[MAXN],n,m;
bool ok[MAXN];
int u[MAXN],v[MAXN];
int find_root(int x)
{
	if (x==fa[x]) return fa[x];
	else return fa[x]=find_root(fa[x]);
}
void unite(int x, int y)
{
	x=find_root(x);
	y=find_root(y);
	fa[x]=y;
}
struct ee{
	int u, v, c, id;
	bool operator<(const ee &y) const
	{
		return c < y.c;
	}
} edge[MAXN];
int d[MAXN];
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) fa[i]=i;
	rep(i, 1, m+1)
	{
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].c);
		u[i]=edge[i].u, v[i]=edge[i].v;
		edge[i].id = i;
	}
	sort(edge+1,edge+m+1);
	for (int last=0,i=1;i<=m;i++)
	{
		int u=edge[i].u, v=edge[i].v;
		de(find_root(u)) de(find_root(v))
		if (find_root(u)==find_root(v)) ok[edge[i].id]=false;
		else ok[edge[i].id]=true;
		if (i == m || edge[i+1].c != edge[i].c)
		{
			rep(k,last+1,i+1) unite(edge[k].u,edge[k].v);
			last = i;
		}
	}
	rep(i,1,n+1) fa[i]=i;
	stack<int> c;
	int q;
	scanf("%d",&q);
	rep(i,1,m+1) cout<<i<<" "<<ok[i]<<endl; 
	rep(i,0,q)
	{
		bool flag = true;
		int k;
		scanf("%d",&k);
		rep(i,0,k)
		{
			int d;scanf("%d",&d);
			if (!ok[d]) flag=false;
			if (find_root(u[d])==find_root(v[d])) flag = false;
			else unite(u[d],v[d]);
			// de(flag)
			c.push(u[d]);c.push(v[d]);
		}
		if (flag) puts("YES");
		else puts("NO");
		while (!c.empty()) fa[c.top()]=c.top(),c.pop();
	}
	return 0;
}

