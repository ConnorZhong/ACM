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
int a[MAXN],n,ans;
vector<int> w;
bool ok (int i)
{
	if ((i&1) && (a[i-1] <= a[i] || a[i] >= a[i+1])) return false;
	if (!(i&1) && (a[i-1] >= a[i] || a[i] <= a[i+1])) return false;

	return true;
}
bool check(int i, int j)
{
	if (i == j) return 0;
	
	if (!ok(i)) return false;
	if (!ok(j)) return false;
	rep(i, 0, w.size()) if (!ok(w[i])) return false;
	return true;
	// swap(a[i])
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i, 1, n+1) scanf("%d",a+i);
	rep(i, 1, n)
	{
		if (i & 1 && a[i] >= a[i+1]) w.pb(i), w.pb(i+1);
		if (!(i & 1) && a[i] <= a[i+1]) w.pb(i), w.pb(i+1);
	}
	a[0]=INF;
	if ((n+1)&1) a[n+1]=0;
	else a[n+1]=INF;

	w.erase(unique(w.begin(),w.end()),w.end());
	if (w.size() > 10) return 0*puts("0");
	// de(w.size())
	rep(i, 0, w.size())
	{
		rep(j,1,n+1)
		{
			swap(a[w[i]],a[j]);
			ans += check(w[i], j);
			swap(a[w[i]],a[j]);
		}
	}
	rep(i, 0, w.size()) rep(j, i, w.size()) 
	{
		swap(a[w[i]], a[w[j]]);
		ans -= check(w[i],w[j]);
		swap(a[w[i]], a[w[j]]);
	}
	printf("%d\n",ans);
	return 0;
}

