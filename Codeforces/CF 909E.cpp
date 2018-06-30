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
int n, m;
int deg[MAXN], e[MAXN];
vector<int> G[MAXN];
queue<int> qqq[2];
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i, 1, n+1) scanf("%d",e+i);
	rep(i, 1, m+1)
	{
		int u, v;scanf("%d%d",&u,&v); u++, v++;
		G[u].pb(v);
		deg[v]++;
	}
	rep(i, 1, n+1) if (!deg[i]) qqq[e[i]].push(i);
	int ans = 0;
	while(!qqq[0].empty() || !qqq[1].empty())
	{
		rep(i, 0, 2)
		{
			bool flag = true;
			while(!qqq[i].empty())
			{
				ans += (i&&flag);
				flag = false;
				int x = qqq[i].front();
				if (deg[x]) break;
				qqq[i].pop();
				rep(j, 0, SZ(G[x]))
				{
					int v = G[x][j];
					deg[v]--;
					if (!deg[v]) qqq[e[v]].push(v);
				}
			}
		}
		
	}
	printf("%d\n",ans);
	return 0;
}

