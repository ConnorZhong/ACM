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
const int MAXN = 1000005; // 1e6;
int n,m;
int deg[MAXN], que[MAXN], head, tail;
int d[MAXN][26];
char s[MAXN];
vector<int> G[MAXN];
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	rep(i, 0, m)
	{
		int u, v;scanf("%d%d",&u,&v);G[u].pb(v);
		deg[v]++; 
	}
	rep(i, 1, n+1) 
	{
		if (!deg[i]) que[tail++] = i;
		d[i][s[i]-'a']=1;
	}
	int ans = 0;
	while(head<tail)
	{
		int x = que[head++];
		rep(i,0,26) ans = max(ans, d[x][i]);
		rep(i,0,G[x].size())
		{
			int v=G[x][i];
			deg[v]--;
			rep(j, 0, 26) 
			{
				d[v][j] = max(d[v][j], d[x][j]+(s[v]-'a'==j));
			}
			if (!deg[v]) que[tail++] = v;
		}
	} 
	// de(tail)
	if (tail != n) puts("-1");
	else 
	printf("%d\n",ans);
	return 0;
}

