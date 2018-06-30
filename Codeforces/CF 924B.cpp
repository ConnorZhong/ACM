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
int n, U, e[MAXN];

int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&U);
	rep(i, 1, n+1) scanf("%d",e+i);
	double ans = 0;
	int now = 1;
	rep(i, 1, n)
	{
		while(now < n && e[now+1]-e[i]<=U) now++;
		if (now>i+1) ans = max(ans, 1.0*(e[now]-e[i+1])/(e[now]-e[i]));
	}
	if (ans == 0)puts("-1");
	else printf("%.10f\n",ans);
	return 0;
}

