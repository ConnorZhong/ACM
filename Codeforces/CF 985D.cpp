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
LL n, H;
LL gao(LL x)
{
	LL ret = 0;
	if (x > H) ret += (H + x - 1)*(x - H)/2;
	ret += (x + 1)*x/2;
	return ret;
}
bool C(LL x)
{
	// de(gao(x))
	return gao(x) < n;
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%lld%lld",&n,&H);
	LL l = 0, r = 2e9;
	while(r-l > 1)
	{
		// de(l)
		LL m =(l+r)/2;
		if (C(m)) l = m;
		else r = m;
	}
	// de(l)
	LL ans = 0;
	if (l < H) 
	{
		ans = l+1;
	}
	else 
	{
		ans = l + (l-H);
		// de(ans)
		if (n - gao(l) > l) ans+=2;
		else ans+=1;
		// de(an)
	}
	
	printf("%lld\n",ans);
	return 0;
}

