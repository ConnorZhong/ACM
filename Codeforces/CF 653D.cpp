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
int n,m,x;
namespace Dinic {
	const int INF = 0x3f3f3f3f;
	const int MAXN = 1005;
	const int MAXM = 100005;
	int S,T;
	int ecnt,head[MAXN],cur[MAXN];
	struct arc
	{
		LL v, c, nxt;
	} edge[MAXM],_copy[MAXM];
	int d[MAXN], q[MAXN];
	void inline add_edge(int u, int v, int c)
	{
		edge[ecnt]=(arc){v,c,head[u]}; head[u]=ecnt++;
		edge[ecnt]=(arc){u,0,head[v]}; head[v]=ecnt++;
	}
	bool BFS()
	{
		memset(d,-1,sizeof d);
		int top=0,bot=0;
		q[bot++]=S;d[S]=0;

		while(top!=bot)
		{
			int x = q[top++];
			for (int j=head[x];~j;j=edge[j].nxt)
			{
				int v=edge[j].v;
				if (d[v]==-1 && edge[j].c) 
				{
					d[v]=d[x]+1;
					q[bot++]=v;
					if (v==T) return 1;
				}
			}
		}
		return 0;
	}
	int DFS(int x, LL flow=1<<30)
	{
		if (x==T || !flow) return flow;
		int sum = 0, u;
		for (int &j=cur[x];~j;j=edge[j].nxt)
		{
			int v=edge[j].v;
			if (d[v]==d[x]+1 && (u = DFS(v, min(flow,edge[j].c))))
			{
				edge[j].c -= u; edge[j^1].c += u;
				flow -= u, sum += u;
				if (!flow) break;
			}
		}
		if (!sum) d[x]=-1;
		return sum;
	}
	int dinic()
	{
		LL ans = 0;

		while(BFS())
		{
			// de(1)
			memcpy(cur,head,sizeof cur);
			ans += DFS(S);
			if (ans >= x) return x;
		}
		// de(ans)
		return ans;
	}
}; 
using namespace Dinic;
int main()
{
	// freopen("in.txt","r",stdin);
	// de(1)
	memset(head,-1,sizeof head);
	scanf("%d%d%d",&n,&m,&x);
	// de(x)
	rep(i, 0, m)
	{
		int u,v,f;
		scanf("%d%d%d",&u,&v,&f);
		add_edge(u,v,f);
	}
	S = 1, T = n;
	memcpy(_copy, edge, sizeof edge);
	// de(2)
	double l=0, r=1000000;
	rep(_,0,150)
	{
		double m=(l+r)/2;
		// de(m)
		rep(i, 0, ecnt) 
		{
			edge[i].c = (double)(_copy[i].c)/m;
		}
		int p = dinic();
		// de(p)

		if (p < x) r = m;
		else l=m;
	}
	// de(l)
	printf("%.10f\n",l*x);
	return 0;
}

