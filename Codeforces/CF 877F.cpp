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
const int MAXN = 100005; // 1e6;
int t[MAXN],a[MAXN],n,k,q;
LL sum[MAXN],spk[MAXN],smk[MAXN];
LL xx[MAXN*3], nn;
LL hs[MAXN*3];
const int B = 316;
struct ev {
	int l, r, id, b;
	bool operator< (const ev &y) const
	{
		if (b==y.b) return r < y.r;
		else return b < y.b;
	}
} e[MAXN];
int getid(LL p)
{
	return lower_bound(xx,xx+nn,p)-xx;
}
LL res[MAXN];
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	rep(i, 1, n+1) scanf("%d",t+i);
	rep(i, 1, n+1) {
		scanf("%d",a+i); if (t[i]==2) a[i]=-a[i];
	}
	rep(i, 1, n+1) sum[i]=sum[i-1]+a[i];
	rep(i, 0, n+1) 
	{
		xx[nn++]=sum[i]+k;xx[nn++]=sum[i]-k;xx[nn++]=sum[i];
	}
	sort(xx,xx+nn);
	nn=unique(xx,xx+nn)-xx;
	rep(i, 0, n+1) 
	{
		spk[i]=getid(sum[i]+k);
		smk[i]=getid(sum[i]-k);
		sum[i]=getid(sum[i]);
	}
	scanf("%d",&q); 
	rep(i,1,q+1) scanf("%d%d",&e[i].l,&e[i].r),e[i].r++;
	rep(i,1,q+1) e[i].id=i,e[i].b=e[i].l/B;
	sort(e+1,e+q+1);
	int l=1,r=1;LL ans = 0;
	hs[sum[0]]++;
	for (int i=1;i<=q;i++)
	{
		while (r < e[i].r)
		{
			ans += hs[smk[r]];
			hs[sum[r]]++;
			r++;
		}while (r > e[i].r)
		{
			hs[sum[r-1]]--;
			ans -= hs[smk[r-1]];
			r--;
		}while (l < e[i].l)
		{
			hs[sum[l-1]]--;
			ans -= hs[spk[l-1]];
			l++;
		}while (l > e[i].l)
		{
			ans += hs[spk[l-2]];
			hs[sum[l-2]]++;
			l--;
		}
		res[e[i].id]=ans;
	}
	rep(i, 1, q+1) 
	printf("%lld\n",res[i]);
	return 0;
}

