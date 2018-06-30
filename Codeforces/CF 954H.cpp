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
const int MAXN = 5005; // 1e6;
const int mod = 1e9+7;
int n,a[MAXN];
int f[2][MAXN<<1];
int g[MAXN][MAXN];
int ans[MAXN<<1];
LL p[MAXN];
void upd(int &x, int y)
{
	x+=y;if (x>=mod) x-=mod;
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	p[1]=1;
	rep(i, 1, n) scanf("%d",a+i);
	rep(i, 1, n) p[i+1]=a[i]*p[i]%mod;
	rep(i, 1, n+1) 
	{
		g[i][0]=1;
		for (int j = 1; j+i <= n; j++)
		{
			g[i][j] = 1ll*g[i][j-1]*a[i+j-1]%mod;
			// de(g[i][j])
			upd(ans[j], g[i][j]*p[i]%mod);
		}
	}
	int now = 0;
	rep(i, 1, n+1)
	{
		memset(f[now], 0, sizeof f[now]);
		f[now][0]=1;
		//de(i)
		if (i > 1)
		for (int j = 1; j<=n+n-2; j++)
		{
			// de(f[i-1][j-1])
			f[now][j]= f[now^1][j-1]+(1ll*((j-2<0||j-2>n)?0:g[i][j-2])*(a[i-1]-1))%mod;
			f[now][j]%=mod;
			upd(ans[j],p[i]*f[now][j]%mod);
			// de(i) de(j)
			// de(f[i][j])
		}
		now^=1;
	}
	
	rep(i, 1, n+n-1) ans[i] = 500000004ll*ans[i]%mod;
	rep(i, 1, n+n-1) printf("%d%c",ans[i]," \n"[i==(n+n-1)]);
	return 0;
}

