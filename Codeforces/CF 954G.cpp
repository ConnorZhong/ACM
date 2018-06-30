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
int n, r;
LL k;
LL a[MAXN];
bool check(LL x)
{
	LL b[MAXN];
	LL p = 0; LL t = 0;
	rep(i, 1, r+1) p += a[i];
	rep(i, 1, n+1) b[i]=a[i];
	rep(i, 1, n+1)
	{
		if (i + r <= n) p += b[i+r];
		if (p < x) b[min(i+r,n)] += x-p, t+= x-p, p = x;
		if (i - r >=1) p -= b[i-r];
		if (t > k) return false;
	}

	return t<=k;
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d%lld",&n,&r,&k);
	rep(i, 1, n+1) scanf("%lld", a+i);
	LL l = 0, r = 2e18; 
	while(r-l>1)
	{
		LL m = (l+r)>>1;
		if (check(m)) l = m;
		else r = m;
	}
	printf("%lld\n",l);
	return 0;
}

