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
const int MAXN = 5005; // 1e6;
const int mod = 1e9+7;
int f[MAXN];
int q[MAXN],n;
void upd(int &x, int y)
{
	x+=y;
	if (x>=mod) x-=mod;
	if (x<0) x+=mod;
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	char op[5];
	f[1]=1;
	bool flag = false;
	rep(_, 1, n+1)
	{
		scanf("%s",op);
		memset(q, 0, sizeof q);
		rep(i, 1, n+1) 
		{
			upd(q[flag?i+1:1], f[i]), upd(q[i+1+flag], -f[i]);
		}
		if (op[0]=='s') flag = false;
		else flag = true;
		int tt = 0;
		rep(i, 1, n+1) 
		{
			f[i]=f[i-1];
			upd(f[i], q[i]);
			upd(tt,f[i]);
		}
	}
	int ans = 0;
	rep(i, 1, n+1) upd(ans,f[i]);
	printf("%d\n",ans); 
	return 0;
}

