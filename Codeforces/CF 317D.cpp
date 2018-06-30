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
int s[MAXN], tot, n;
vector<int> G;
int f[MAXN];
int p[]={2,3,5,7,11,13,17,19,23,29,31};
int dfs(int n)
{
	if (f[n]!=-1) return f[n];
	vector<int> t;
	rep(i, 0, 11) 
	{
		t.pb(n/p[i]);
	}
	LL ans = 0;
	rep(i, 0, 11)
	{
		de(n)
		de(t[i])
		ans ^= dfs(t[i]);
	}	
	return f[n]=ans;
}

int main()
{
	freopen("in.txt","r",stdin);
	memset(f,-1,sizeof f);
	scanf("%d",&n);
	f[1]=1;
	f[0]=0;
	// de(dfs(0))
	tot = n; tot --;
	for (int i=2;1ll*i*i<=n; i++)
	{	
		LL k = i;
		if (!s[k])
		{
			while(k <= n)
			{
				s[i]++;
				if (k*k>n) tot--;
				else s[k]=1;
				k*=i;
			}
			G.pb(s[i]);
		}
		tot--;
	}
	de(tot)
	tot %= 2; G.pb(tot);
	LL ans = 0;
	G.pb(1);
	de(dfs(1))
	de(dfs(2))
	de(dfs(3))
	rep(i ,0 ,SZ(G)) 
	{
		de(G[i])
		ans ^= dfs(G[i]);
		de(dfs(G[i]))
	}

	de(dfs(1))
	de(dfs(2))
	de(dfs(3))


	de(ans)
	if (ans) puts("Vasya");
	else puts("Petya");
	return 0;
}

