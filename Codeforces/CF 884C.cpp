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
int rt[MAXN],cnt[MAXN];
int n;
LL ans =0;
int find_root(int x)
{
	if (rt[x]==x)return x;
	else return rt[x]=find_root(rt[x]);
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i, 1, n+1) rt[i]=i;
	rep(i, 1, n+1)
	{
		int p;scanf("%d",&p);
		int x = find_root(i), y = find_root(p); rt[y]=x;
	}
	rep(i, 1, n+1) cnt[find_root(i)]++;
	sort(cnt+1,cnt+n+1); cnt[n-1]+=cnt[n];
	per(i, 0, n)
	{
		ans +=  1ll*(cnt[i])*cnt[i];
	}
	printf("%lld\n",ans);
	return 0;
}

