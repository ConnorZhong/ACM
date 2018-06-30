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
struct query
{
	int l, x, id;
	bool operator<(const query &q) const
	{
		return l < q.l;
	}

} qq[MAXN];
LL ans[MAXN];
const int mod = 1e9+7;
/* 模2意义下线性基，也就是异或线性基*/
struct LinearBase {
	vector<long long> base;
	bool insert(LL x)
	{
		for (int i = 0; i < (int)base.size(); i++)
		{
			x = min(x,x^base[i]);
		}
		if (x) base.pb(x);
		if (x) return true;
		else return false;
	}
	bool find(LL x)
	{
		for (int i = 0; i < (int)base.size(); i++)
		{
			x = min(x,x^base[i]);
		}
		if (x == 0) return true;
		else return false;
	}
	long long max_element()
	{
		sort(base.begin(),base.end()); 
		long long ret = 0;
		for (int i = (int)base.size()-1; i >= 0; i--)
		{
			ret = max(ret, ret ^ base[i]);
		}
		return ret;
	}
	long long min_element()
	{
		sort(base.begin(),base.end());
		return base[0];
	}
	long long kth_elment(int k)
	{
		sort(base.begin(),base.end());
		for (int i = (int)base.size()-1; i >= 0; i--)
		{	
			for (int j = i-1; j >= 0; j--)
			{
				base[i] = min(base[i],base[i]^base[j]);
			}
		}
		LL ret = 0;
		if (k > (1ll<<base.size())) return -1;
		int i = 0;
		while (k)
		{
			if (k&1) ret ^= base[i];
			i++; k>>=1;
		}
		return ret;

	}
} lb;
LinearBase merge(LinearBase x, LinearBase &y)
{
	for (int i = 0; i <(int) y.base.size(); i++)
	{
		x.insert(y.base[i]);
	}
	return x;
}
int a[MAXN];
int k = 0,n,q;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&q);

	rep(i, 1, n+1) scanf("%d",a+i);
	rep(i, 1, q+1) 
	{
		scanf("%d%d",&qq[i].l,&qq[i].x);
		qq[i].id=i;
	}
	sort(qq+1,qq+1+q);
	int now = 0;
	rep(i, 1, q+1)
	{
		// de(qq[i].id)
		while (now < qq[i].l) k += !(lb.insert(a[++now]));
		// de(k)
		if (lb.find(qq[i].x)) ans[qq[i].id]=powmod(2,k,mod);
		else ans[qq[i].id]=0;
		// de(ans[qq[i].id])
	}
	rep(i, 1, q+1) printf("%lld\n",ans[i]);
	return 0;
}

