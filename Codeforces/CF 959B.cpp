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
map<int, int> cc;
map<string, int> g;
string s[MAXN];
int c[MAXN],n,k,m;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&k,&m);

	rep(i, 1, n+1)
	{
		cin>>s[i];
	}
	rep(i, 1, n+1) scanf("%d",c+i);
	// 
	rep(i, 1, k+1) 
	{
		int t;
		scanf("%d",&t);
		cc[i] = INF;
		rep(j, 0, t)
		{
			int x;scanf("%d",&x);
			g[s[x]] = i;
			cc[i] = min(cc[i], c[x]);
		}
		// de(cc[i])
	}
	LL ans = 0;
	rep(i, 1, m+1) 
	{
		string x;cin>>x;
		// de(x) de(g[x])
		ans += cc[g[x]];
		// de(ans)
	}
	printf("%lld\n",ans );
	return 0;
}

