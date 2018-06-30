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
const int MAXN = 1005; // 1e6;
int n, m, s, t; 
vector<int> G[MAXN];
int ds[MAXN],dt[MAXN];
int matrix[MAXN][MAXN];
void bfs(int *d, int s)
{

	queue<pair<int, int> > que;
	d[s]=0;
	que.push(mkp(0, s));
	while(!que.empty())
	{
		int u = que.front().se;
		int x = que.front().fi;
		que.pop();
		rep(i, 0, SZ(G[u]))
		{
			int v = G[u][i];
			if (d[v]>x+1) d[v]=x+1, que.push(mkp(x+1,v));
		}
	}
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d%d%d",&n,&m,&s,&t);
	rep(i, 0, m)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);G[v].pb(u);
		matrix[u][v]=matrix[v][u]=1;
	}
	memset(ds,INF,sizeof ds);
	memset(dt,INF,sizeof dt);
	bfs(ds,s);
	bfs(dt,t);
	int d = ds[t], tot = 0;
	// de(d)
	rep(i, 1, n+1) rep(j, i+1, n+1)
	{
		if (matrix[i][j] ==0 && d <= min(ds[i]+dt[j], ds[j]+dt[i])+1) tot++;
	}
	printf("%d\n",tot);
	return 0;
}

