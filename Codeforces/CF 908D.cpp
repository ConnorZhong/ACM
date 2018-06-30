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
const int MAXN = 2005; // 1e6;
const int mod = 1e9+7;
int dp[MAXN][MAXN];
int k, pa, pb, a, b, invpb;
void upd(int &x, int y)
{
	x+=y;
	if (x>=mod) x-=mod;
}
int dfs(int ca, int l) // i , j 
{

	if (~dp[ca][l]) return dp[ca][l];
	if (l >= k) return dp[ca][l]=0;
	if (ca + l >= k) return dp[ca][l] = (ca+invpb)%mod;
	dp[ca][l] = 0;
	upd(dp[ca][l],1ll*dfs(ca+1, l)*pa%mod);
	upd(dp[ca][l],1ll*(dfs(ca, l+ca)+ca)%mod*pb%mod);
	return dp[ca][l] ;
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d%d",&k,&pa,&pb);
	pa = 1ll*pa * powmod(pa+pb, mod-2, mod)%mod;
	pb = (mod+1-pa)%mod;
	invpb = 1ll*pa*powmod(pb, mod-2, mod)%mod;
	memset(dp,-1,sizeof dp);
	printf("%d\n",dfs(1,0));
	return 0;
}

