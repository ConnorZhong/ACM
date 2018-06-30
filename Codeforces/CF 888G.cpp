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
const int MAXN = 10000005; // 1e6;
int n,a[MAXN],ch[MAXN][2],val[MAXN],cnt;
LL ans = 0;
void insert(int x)
{
	int v=0;
	per (i,0,31)
	{
		int c = x>>i&1;
		// de(c)
		if (ch[v][c]==-1) 
		{
			ch[v][c]=++cnt;
		}
		v = ch[v][c];
		val[v]++;
	}	
}
int gao(int u, int v, int d)
{
	int ret = ~(1<<31);
	int p = 0;
	if (~ch[u][0] && ~ch[v][0])
	{
		ret = min(ret,gao(ch[u][0], ch[v][0], d-1));
	}
	if (~ch[u][1] && ~ch[v][1])
	{
		ret = min(ret,gao(ch[u][1], ch[v][1], d-1));
	}
	if (ret == ~(1<<31))
	{
		if (~ch[u][0] && ~ch[v][1]) 
		{
			ret = min(ret,gao(ch[u][0],ch[v][1],d-1)|(1<<(d-1)));
		}
		if (~ch[u][1] && ~ch[v][0]) 
		{
			ret = min(ret,gao(ch[u][1],ch[v][0],d-1)|(1<<(d-1)));
		}
	}
	if (d==0) return 0;
	return ret;
}
void dfs(int u, int d)
{
	if (u==-1) return ;
	rep(i, 0, 2) dfs(ch[u][i],d-1);
	if (ch[u][0] == -1 || ch[u][1] == -1) return;
	else 
	{
		int v = val[ch[u][0]] > val[ch[u][1]]? 1: 0;
		int x = ch[u][v], y = ch[u][v^1];
		ans += gao(x,y,d-1)|(1<<(d-1));
	}
}

int main()
{
	// de(~(1<<31))
	// freopen("in.txt","r",stdin);
	memset(ch,-1,sizeof ch);
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i),insert(a[i]);
	dfs(0,31);
	printf("%lld\n",ans);
	return 0;
}

