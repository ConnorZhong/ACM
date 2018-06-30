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
struct ee
{
	int a,b,w;
	bool operator<(const ee &y) const
	{
		return w > y.w;
	}
} wife[MAXN];
int root[MAXN],e[MAXN],v[MAXN],n,m;
int find_root(int x)
{
	if (root[x]==x) return x;
	else return root[x]=find_root(root[x]);
}

int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i, 1, n+1) root[i]=i,v[i]=1;
	rep(i, 1, m+1)
	{
		scanf("%d%d%d",&wife[i].a,&wife[i].b,&wife[i].w);
	}
	sort(wife+1,wife+m+1);
	int ans = 0;
	rep(i, 1, m+1)
	{
		int x = find_root(wife[i].a),y = find_root(wife[i].b);
		if (x != y && e[x]+e[y]+1 <= v[x]+v[y]) root[y] = x, e[x] += e[y]+1, v[x] += v[y], ans += wife[i].w;
		else if (e[x] < v[x]) e[x]++,ans += wife[i].w;
	}
	printf("%d\n",ans);
	return 0;
}

