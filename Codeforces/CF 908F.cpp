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
int x[MAXN], n;
char c[MAXN];
int g[MAXN], gc, b[MAXN], bc, r[MAXN], rc;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i, 0, n) 
	{
		scanf("%d %c",&x[i], &c[i]);
		if (c[i] == 'P') g[gc++] = x[i];
		else if (c[i] == 'R') r[rc++]=x[i];
		else if (c[i] == 'B') b[bc++]=x[i];
	}
	if (gc == 0) 
	{
		LL ans = 0;
		if (bc != 0) ans += b[bc-1] - b[0];
		if (rc != 0) ans += r[rc-1] - r[0];
		printf("%lld\n",ans);
	}
	else 
	{
		LL ans = 0;
		int i = 0, j = 0, k = 0;
		while (j < rc && r[j] < g[i]) j++;
		while (k < bc && b[k] < g[i]) k++;
		if (j) ans += g[i]-r[0];
		if (k) ans += g[i]-b[0];
		for (i = 1;i < gc;i++)
		{
			// de(i) de(j) de(k)
			int tj = j, tk = k;
			// de(j) de(k)
			LL tmp = g[i]-g[i-1];
			// de(tmp)
			LL t1 = 0 , t2 = 0;
			while(tj < rc && r[tj] < g[i]) 
			{
				if (tj >= j+1) t1 = max(t1, 1ll*r[tj]-r[tj-1]);
				tj++;
			}
			while(tk < bc && b[tk] < g[i]) 
			{
				if (tk >= k+1) t2 = max(t2, 1ll*b[tk]-b[tk-1]);
				tk++;
			}
			tj --; tk --;
			if (tj >= j) 
			{
				t1 = max(1ll*g[i]-r[tj],t1);
				t1 = max(t1, 1ll*r[j]-g[i-1]), tmp += g[i]-g[i-1]-t1;
			}
			if (tk >= k) 
			{
				t2 = max(1ll*g[i]-b[tk],t2);
				t2 = max(1ll*b[k]-g[i-1],t2);
				tmp += g[i]-g[i-1]-t2;
			}
			ans += min(tmp , 2ll*(g[i]-g[i-1]));
			// de(t1) de(t2)
			// de(tmp) de(ans)
			j = tj + 1; k = tk + 1;
		}
		// de(ans)
		ans += max(0, r[rc-1]-g[gc-1]);
		ans += max(0, b[bc-1]-g[gc-1]);
		// de(b[bc-1])
		// de(ans)
		printf("%lld\n",ans);
	}
	return 0;
}

