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
const int MAXN = 5005; // 1e6;
const int MOD = 998244353;
int Comb[MAXN][MAXN];
int fact[MAXN];
int a,b,c;
LL solve(int x, int y)
{
	LL ret = 0;
	for (int k=0;k<=x&&k<=y;k++)
	{
		ret += 1ll*Comb[x][k]*Comb[y][k]%MOD*fact[k]%MOD;
		ret %= MOD;
	}
	return ret;
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d%d",&a,&b,&c);
	fact[0]=1;
	rep(i, 1, MAXN) fact[i]=fact[i-1]*1ll*i%MOD;
	rep(i, 0, MAXN)
	{
		Comb[i][0]=1;
		rep(j, 1, i+1) Comb[i][j]=(Comb[i-1][j]+Comb[i-1][j-1])%MOD;
	}
	LL ans = 1;
	ans = ans*solve(a,b)%MOD;
	ans = ans*solve(a,c)%MOD;
	ans = ans*solve(c,b)%MOD;
	printf("%lld\n",ans);
	return 0;
}

