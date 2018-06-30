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
const LL INFLL = 0x3f3f3f3f3f3f3f3fll;
const int MAXN = 305; // 1e6;
LL dp[MAXN][MAXN];
int n,m,k;
vector<pair<int, int > > d[MAXN]; 
LL t[MAXN];
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	rep(i, 1, m+1) 
	{
		int l,r,c;
		scanf("%d%d%d",&l,&r,&c);
		d[l-1].emplace_back(r,c);
	}
	memset(dp,INF,sizeof dp);
	dp[0][0] = 0;
	// de(dp[1][1])
	memset(t,INF,sizeof t);
	rep(i, 0, n+1) 
	{
		if (SZ(d[i])) memset(t,INF,sizeof t);
		rep(u, 0, SZ(d[i])) 
		{
			// de(r) de(c)
			int r = d[i][u].fi, c = d[i][u].se;
			t[r]=min(t[r],1ll*c);
			// de(t[r])
		}
		per(x, i+1, n+1) 
		{
			if (x < n) t[x] = min(t[x],t[x+1]);
			// de(t[x])
		}
		rep(j, 0, k+1)
		{
			// de(i) de(j) de(dp[i][j])
			if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j]);
			// de(i) de(j) de(dp[i][j])
			// de(i) de(j) de(dp[i][j])
			rep(x, i+1, n+1)
			{
				if (t[x] == INFLL) break;
				// de(t[x])
				dp[x][j+x-i] = min(dp[x][j+x-i] , dp[i][j]+t[x]);
			}
			// de(i) de(j) de(dp[i][j])
		}
	}
	if (dp[n][k] == INFLL) puts("-1");
	else  printf("%lld\n",dp[n][k]);
	
	return 0;
}


