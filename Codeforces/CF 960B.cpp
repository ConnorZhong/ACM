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
int n,k1,k2;
int a[MAXN],b[MAXN],c[MAXN];
int main()
{
	// freopen("in.txt","r",stdin);
	cin>>n>>k1>>k2;
	rep(i,1,n+1) cin>>a[i];
	rep(i,1,n+1) cin>>b[i];
	rep(i,1,n+1) c[i]=max(a[i]-b[i],b[i]-a[i]);
	k1+=k2;
	while(k1>0)
	{
		// de(k1)
		int p = 1;
		rep(i,2,n+1)
		{
			if (c[i]>c[p]) p=i;
			// de(i)
		}
		if (!c[p]) break;
		else c[p]--,k1--;
	}
	LL ans = 0;
	rep(i,1,n+1) ans += 1ll*c[i]*c[i];
	if (!k1) printf("%lld\n",ans);
	else if (k1&1) puts("1");
	else puts("0");
	return 0;
}

