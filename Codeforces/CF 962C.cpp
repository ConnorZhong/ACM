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
int n;
int check(int k)
{
	// de(k)
	int d = 0;
	int K = k, N = n;
	while(K) K/=10, d++;
	while(N) N/=10, d--;
	K = k, N = n;
	int ans = 0;
	while(K && N)
	{
		
		int x = K%10;
		// de(x)
		while(N&&N%10 != x) N/=10;
		if (N%10 == x) N/=10, K/=10;
	}
	// de(K) de(d)
	if(K!= 0) return INF;
	else return -d;
}
int main()
{
	// freopen("in.txt","r",stdin);
	cin>>n;
	int ans = INF;
	for (int i=1;1ll*i*i<=n;i++)
	{
		ans=min(ans,check(i*i));
	}
	// de(ans)
	if (ans == INF) printf("-1");
	else  printf("%d\n",ans);
	return 0;
}

