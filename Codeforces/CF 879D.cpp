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
const int MAXN = 1000005; // 1e6;
LL n,k,m,ttop;
LL ans = 0,total;
LL top;
pair<LL,LL> a[MAXN];
pair<LL,LL> stk[MAXN];
pair<LL,LL> sstk[MAXN*14]; LL cnt[MAXN];
LL damage=0;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%lld%lld%lld",&n,&k,&m);
	rep(i,1,n+1) 
	{
		scanf("%lld",&a[i].fi), a[i].se = 1;
	}
	bool flag = false;
	rep(i, 0, 31)
	{
		if (!flag){
			rep(i,1,n+1)
			{
				if (top && stk[top].fi == a[i].fi) 
				{
					stk[top].se += a[i].se;
					stk[top].se %= k;
					if (stk[top].se==0) top--;
				}
				else stk[++top]=a[i];
			}
			total = 0;
			rep(i,1,top+1) a[i]=stk[i],total += a[i].se; 
			cnt[i]=total;
			// top = 0;
			if (i >= 1 && top > 200000) 
			{
				damage = cnt[i-1]*2ll-cnt[i];
				flag = true;
				
			}
			n = top;
		}
		else 
		{
			cnt[i] = cnt[i-1]*2 - damage;
		}
		if (m >> i & 1) 
		{
			ans += cnt[i];
			rep(i ,1, top+1)
			{
				if (ttop && sstk[ttop].fi == stk[i].fi) 
				{
					sstk[ttop].se += stk[i].se;
					ans -= (sstk[ttop].se/k*k);
					sstk[ttop].se %= k;
					if (sstk[ttop].se==0) ttop--;
					// de(stk[top].se)
				}
				else sstk[++ttop]=stk[i];
			}
		}
	}	
	printf("%lld\n",ans);

	return 0;
}

