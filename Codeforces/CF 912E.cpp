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
const LL inff = 1000000000000000000ll;
bool check(LL x, LL y) 
{
	if (x*y > inff) return false;
	if (x*y/y==x) return true;

	return false;
}
int n;
LL pr[MAXN],k;
vector<LL> ans;
void dfs(LL now, int i)
{		
	if (SZ(ans)%1000000==0) de(SZ(ans)) 
	rep(j, i, n)
	{
		if (1e18/now>=pr[j]) 
		{
			ans.pb(now*pr[j]);
			dfs(now*pr[j],j);
		}
	}
}


int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i, 0, n) scanf("%lld",&pr[i]);
	scanf("%lld",&k);
	ans.pb(1);
	dfs(1,0);
	sort(all(ans));
	printf("%lld\n",ans[k-1]);
	return 0;
}

