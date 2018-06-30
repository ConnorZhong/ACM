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
const int mod = 1e9+9;
LL n,a,b,k;
char str[MAXN];
int s[MAXN];
int main()
{
	// freopen("in.txt","r",stdin);
	cin>>n>>a>>b>>k>>str;
	rep(i,0,k) if (str[i]=='+')s[i]=1;else s[i]=-1;
	LL ans = 0; LL now = 0;
	LL p = powmod(a,mod-2,mod)*b%mod;
	LL x = powmod(a,n,mod);
	if (n >= k-1)
	{
		rep(i,0,k) 
		{
			now =(now+ x*s[i]+mod)%mod;
			x = x*p%mod;
		}
		LL t = (n+1)/k;
		LL q = powmod(p,k,mod);
		if (q == 1) ans = now*t%mod; 
		else ans = now*((powmod(q,t,mod)-1 + mod)%mod) %mod*powmod((q-1+mod)%mod,mod-2,mod)%mod;
		for (LL i=(n+1)/k*k;i<=n;i++)
		{
			ans = (ans + x*(s[i%k]) + mod)%mod;
			x = x*p%mod;
		}
	}
	else 
	{
		for (int i=0;i<=n;i++)
		{
			now = (now+ x*s[i]+mod)%mod;
			x = x*p%mod;
		}
		ans = now;
	}
	cout<<ans<<endl;
	return 0;
}

