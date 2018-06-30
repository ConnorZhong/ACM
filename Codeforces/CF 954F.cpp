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
const int mod = 1e9+7;
struct Node{
	LL x, pos;
	int flag;
	bool operator<(const Node &y) const
	{
		return x < y.x;
	}
} node[MAXN];
LL n, m;
struct mat{
	int n;
	LL d[4][4];
	mat operator*(const mat &b)
	{
		mat c; c.n = b.n;
		rep(i, 0, c.n) rep(j, 0, c.n) 
		{
			LL p = 0;
			rep(k, 0, c.n)
			{
				p += d[i][k]*b.d[k][j];
			}
			c.d[i][j]=p%mod;
		}
		return c;
	}
};
mat powmod(mat x, LL n)
{
	mat res; res.n = x.n;
	rep(i, 0, x.n) rep(j, 0, x.n) if (i == j) res.d[i][j]=1; else res.d[i][j]= 0;
	while(n)
	{
		if (n&1) res = res*x;
		x = x*x;
		n>>=1;
	}
	return res;
}
LL dp[3],b[3];
LL now = 1;
void gao(LL x)
{
	mat ma; memset(&ma,0,sizeof ma);
	ma.n = 3;
	// de(b[0]) de(b[1]) de(b[2])
	if (b[0]<=0) ma.d[0][0]=ma.d[0][1]=1;
	if (b[1]<=0) ma.d[1][0]=ma.d[1][1]=ma.d[1][2]=1;
	if (b[2]<=0) ma.d[2][1]=ma.d[2][2]=1;
	// de(ma.d[0][0]) de(ma.d[0][1]) de(ma.d[0][2])
	ma = powmod(ma, x-now-1);
	// de(ma.d[0][0]) de(ma.d[0][1]) de(ma.d[0][2])
	LL q[3];
	rep(i, 0, 3) 
	{ 	
		LL p = 0;
		rep(j, 0, 3) p += ma.d[i][j]*dp[j];
		// de(p)
		q[i]=p%mod;
	}
	rep(i, 0, 3) dp[i]=q[i];
	now = x-1;


}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%lld%lld",&n,&m);
	rep(i, 0, n)
	{
		LL l, r, x;
		scanf("%lld%lld%lld",&x,&l,&r);
		node[i*2].pos = node[i*2+1].pos = x-1;
		node[i*2].flag=1; node[i*2].x=l, node[i*2+1].x=r+1;
	}
	node[2*n].flag=0,node[2*n].x=m+1;
	sort(node,node+n+n);
	dp[1]=1; LL now = 1;
	rep(i, 0, n+n+1)
	{
		// de(node[i].x) de(node[i].flag)
		gao(node[i].x);
		if (node[i].flag) b[node[i].pos]++;
		else b[node[i].pos]--;
		
		// de(dp[0]) de(dp[1]) de(dp[2])
	}
	printf("%lld\n",dp[1]);
	return 0;
}

