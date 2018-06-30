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
vector<int> G[MAXN];
int du[MAXN];
int p[MAXN];
int clean[MAXN];
vector<int> ans;
void _try(int u)
{
	if (((du[u]&1)==0) && clean[u]==false) 
	{
		clean[u]=true;
		ans.pb(u);
		for (auto v:G[u]) 
		{
			du[v]--;
		}

	}
}
void dfs(int u, int fa)
{
	_try(u);
	for (auto v:G[u]) 
	{
		if (v==fa || clean[v] || (du[v]&1)) continue;
		dfs(v,u);
	}
}
int que[MAXN],f,t,n;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i, 1, n+1)
	{

		scanf("%d",p+i);
		if (p[i]!=0)
		{
			G[i].pb(p[i]);
			du[i]++;du[p[i]]++;
			G[p[i]].pb(i);
		}
	}
	rep(i,1,n+1) 
	{
		if (clean[i] || du[i]&1) continue;
		dfs(i,-1);
	}
	if (ans.size() == n) 
	{
		printf("YES\n");
		for (int x:ans)
		{
			cout<<x<<endl;
		}
	}
	else cout<<"NO"<<endl;
	

	return 0;
}

