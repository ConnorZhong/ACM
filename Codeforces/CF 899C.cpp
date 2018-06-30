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
const int MAXN = 1000005; // 1e6;
const int mod = 1e9+7;
int n,k;
LL g[MAXN];
LL f[MAXN],sum[MAXN];
LL fact[MAXN];
LL inv[MAXN];
LL comb(int n, int m)
{
	return fact[n]*inv[m]%mod*inv[n-m]%mod;
}
LL powmod(LL x, LL n)
{
	LL ret = 1;
	while(n)
	{
		if (n&1) ret=ret*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ret;
}
LL ans = 0;
void upd(LL &t, LL q)
{
	t += q;
	if (t>=mod) t-=mod;
	if (t<0) t+=mod;
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	fact[0]=1;
	rep(i,1,MAXN) fact[i]=1ll*fact[i-1]*i%mod;
	inv[MAXN-1] = powmod(fact[MAXN-1],mod-2);
	per(i,0,MAXN-1) inv[i]=inv[i+1]*(i+1ll)%mod;
	g[0]=1;
	sum[0]=1;
	f[0]=1;
	rep(i,1,n+1)
	{
		g[i] = fact[n-i]*comb(n-1,i-1)%mod;
		f[i] = sum[i-1];

		if (i >= k+1) upd(f[i],-sum[i-k-1]);
		
		f[i]=f[i]*fact[i-1]%mod;
		g[i] = g[i]*f[i-1]%mod;
		sum[i]=sum[i-1];
		upd(sum[i],f[i]*inv[i]%mod);
		upd(ans,g[i]);
	}

	ans = fact[n]-ans;
	ans = (ans+mod)%mod;
	printf("%lld\n",ans);

	return 0;
}

