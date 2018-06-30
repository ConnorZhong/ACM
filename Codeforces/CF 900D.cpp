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
int x, y;
const int mod = 1e9+7;
map<LL, LL> dp;
LL dfs(int k)
{
	if (dp[k]) return dp[k];
	else
	{
		dp[k] = powmod(2, k-1, mod);
		for (LL i = 1; i*i <= k; i++)
		{
			if (k % i == 0)
			{
				if (i != 1 && i*i != k) dp[k] -= dfs(k/i);
				dp[k]-=dfs(k/(k/i)); 
				dp[k]=(dp[k]%mod+mod)%mod;
			}
		}
	}
	return dp[k];
}
int main()
{
	freopen("in.txt","r",stdin);
	
	scanf("%d%d",&x,&y);
	de(x) de(y)
	if (y % x != 0) puts("0");
	else 
	{
		dp[1]=1;
		y/=x;
		printf("%lld\n",dfs(y));
	}
	return 0;
}

