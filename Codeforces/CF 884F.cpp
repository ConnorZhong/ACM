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

namespace MinCostFlow
{
    const int MAXN = 3005;
    const int MAXM = 500005;
    int S,T,head[MAXN],ecnt;
    bool vis[MAXN];
    struct arc{
        int v, f, c, nxt;
    }edge[MAXM];
    void inline add_edge(int u, int v, int c, int cost)
    {
        edge[ecnt]=(arc){v,c,cost,head[u]};head[u]=ecnt++;
        edge[ecnt]=(arc){u,0,-cost,head[v]};head[v]=ecnt++;
    }
    int maxflow, mincost, d[MAXN], h[MAXN];
    bool Dijkstra()
    {
        priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int> > > Q;
        memset(d,0x3f,sizeof d);
        d[S]=0; Q.push(make_pair(d[S],S));
        while(!Q.empty())
        {

            int x=Q.top().second, w = Q.top().first; Q.pop();
            // de(x)
            if (w > d[x]) continue;
            if (x == T) {
                for (int i=0; i<= T; i++)
                {
                    h[i]=min(h[i]+d[i],INF);
                }
                // de(h[T])
                return 1;
            }
            for (int j=head[x];~j;j=edge[j].nxt)
            {
                int v=edge[j].v, z=edge[j].c+h[x]-h[v];
                if (edge[j].f && d[v] > d[x] + z) {
                    d[v] = d[x] + z;
                    Q.push(make_pair(d[v],v));
                }
            }
        }
        return 0;
    }
    int DFS(int x, int flow = 1<<30)
    {
        if (x == T)
        {
        	// de(flow)
            maxflow += flow, mincost += h[T]*flow;
            return flow;
        } vis[x]=1; int sum = 0, u;
        for (int j = head[x]; ~j; j =edge[j].nxt)
        {
            int v=edge[j].v;
            if (edge[j].f && !vis[v] && h[v] == edge[j].c + h[x])
            {
            	// de(v)
                u = DFS(v, min(flow, edge[j].f));
                edge[j].f -= u, edge[j^1].f += u;
                flow -= u, sum += u;
                if (!flow) break;
            }
        }
        return sum;
    }
    pair<int,int> MinCostMaxFlow()
    {
        queue<int> Q;
        memset(vis,0,sizeof vis);
        memset(h,0x3f,sizeof h);
        h[S]=0, vis[S]=1, Q.push(S);
        while(!Q.empty())
        {
            int x = Q.front(); Q.pop(); vis[x]=0;
            for (int j = head[x];~j;j=edge[j].nxt)
            {
                int v=edge[j].v, z=edge[j].c;
                if (edge[j].f && h[v] > h[x]+z)
                {
                    h[v]=h[x]+z;
                    if (!vis[v])
                    {
                        Q.push(v);vis[v]=1;
                    }
                }
            }
        }
        // de(h[T])
        maxflow=0, mincost=0;
        while(Dijkstra())
        {

            do {
                memset(vis, 0, sizeof vis);
            } while(DFS(S));
        }
        return make_pair(maxflow,mincost);
    }

}; using namespace MinCostFlow;
int n, t[MAXN],ch[MAXN];
char a[MAXN];
int main()
{
	// freopen("in.txt","r",stdin);
	memset(head,-1,sizeof head);
	scanf("%d",&n);
	scanf("%s",a);
	S = 26+n/2*26+n, T = S+1;
	int cnt = 2*n+2;
	rep(i, 0, n) 
	{
		scanf("%d",t+i);
		ch[a[i]-'a']++;
	}
	int pp = 26+n/2*26;
	rep(i, 0, 26) // 0-26 ch 
	{
		add_edge(S,i,ch[i],0);
		rep(j,0,n/2) 
		{
			add_edge(i,26+j*26+i,1,0);
			if (i+'a' == a[j]) 
			{
				add_edge(26+j*26+i,pp+j,1,-t[j]);
			}
			else add_edge(26+j*26+i,pp+j,1,0);
			if (i+'a' == a[n-j-1]) add_edge(26+j*26+i,pp+n-j-1,1,-t[n-j-1]);
			else add_edge(26+j*26+i,pp+n-j-1,1,0);
		}
	}
	rep(i, 0, n)
	{
		add_edge(pp+i,T,1,0);
	}
	MinCostMaxFlow();
	printf("%d\n",-mincost);
	return 0;
}

