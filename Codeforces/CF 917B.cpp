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
const int MAXN = 205; // 1e6;
int n, m;
int dp[MAXN][MAXN][26];
vector<pair<int, int > > G[MAXN];
bool dfs(int u, int v, int d)
{
	// de(u)de(v)
	if (dp[u][v][d]!=-1) return dp[u][v][d];
	bool flag = 1;
	rep(i, 0, G[u].size())
	{
		int x = G[u][i].fi, ch = G[u][i].se;
		// de(x) de(ch)
		if (ch >= d) flag &= dfs(v,x,ch);
	}
	// de(u) de(v) de(d)
	if (flag == 0) dp[u][v][d] = 1;
	else dp[u][v][d] = 0;
	return dp[u][v][d];
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i, 0, m)
	{
		int u,v;
		char c;
		// de(c)
		scanf("%d%d %c",&u,&v,&c);
		G[u].pb(mkp(v,c-'a'));
	}
	memset(dp,-1,sizeof dp);
	rep(i, 1, n+1) 
	{
		rep(j, 1, n+1) 
		{
			dfs(i,j,0);
			// de(dp[i][j][0])
			printf("%c",dp[i][j][0]?'A':'B');
		}
		printf("\n");
	}
	return 0;
}

