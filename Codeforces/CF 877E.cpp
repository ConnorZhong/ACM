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
vector<int> G[MAXN];
int idx=1,in[MAXN],out[MAXN],p[MAXN],n,q;
int Lazy[MAXN],STree[MAXN];
int t[MAXN];
#define lson(k) (k<<1)
#define rson(k) (k<<1|1)
void push_up(int k)
{
	STree[k]=STree[lson(k)]+STree[rson(k)];
}
void push_down(int k, int l, int r)
{
	if (Lazy[k])
	{
		Lazy[k]=0;
		int m=(l+r)>>1;
		Lazy[lson(k)]^=1;
		Lazy[rson(k)]^=1;
		STree[lson(k)]=m-l-STree[lson(k)];
		STree[rson(k)]=r-m-STree[rson(k)];
	}
}
void build(int k, int l, int r)
{
	if (r - l <= 1)
	{
		if (r - l == 1) STree[k]=t[p[l]];
		// de(l) de(p[l]) de(t[p[l]])

		return;
	}
	int m=(l+r)>>1;
	build(lson(k),l,m);
	build(rson(k),m,r);
	push_up(k);

}
void modify(int k, int l, int r, int ql, int qr)
{
	if (qr <= l || ql >= r) return ;
	if (ql <= l && r <= qr)
	{
		Lazy[k]^=1;
		STree[k]=r-l-STree[k];
		return;
	}
	int m=(l+r)>>1;
	push_down(k,l,r);
	modify(lson(k),l,m,ql,qr);
	modify(rson(k),m,r,ql,qr);
	push_up(k);

}
int query(int k, int l, int r, int ql, int qr)
{
	if (qr <= l || ql >= r) return 0;
	if (ql <= l && r <= qr)
	{
		// de(STree[k])
		return STree[k];
	}
	int m=(l+r)>>1;
	push_down(k,l,r);
	int ret = query(lson(k),l,m,ql,qr)+query(rson(k),m,r,ql,qr);
	push_up(k);
	// de(ret)
	return ret;
}
void dfs(int u, int fa)
{
	in[u]=idx++;p[in[u]]=u;
	rep(j, 0, G[u].size())
	{
		int v=G[u][j];
		if (v == fa) continue;
		dfs(v,u);
	}
	out[u]=idx;
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i, 2, n+1)
	{
		int p;scanf("%d",&p);
		G[p].pb(i);G[i].pb(p);
	}
	rep(i,1,n+1) scanf("%d",t+i);
	dfs(1,-1);
	scanf("%d",&q);
	build(1,1,n+1);
	rep(i,0,q)
	{
		char op[5];
		int v;
		scanf("%s%d",op,&v);
		if (op[0]=='g') printf("%d\n",query(1,1,n+1,in[v],out[v]));
		else modify(1, 1, n+1, in[v], out[v]);
	}
	return 0;
}

