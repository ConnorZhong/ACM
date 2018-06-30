//树状数组维护。
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
#define rep(i,a,b) for (int i=(a);i<(b);i++)
#define per(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,a,b) for (int i=(a);i<=(b);i++)
#define PER(i,a,b) for (int i=(b);b>=(a);i--)
using namespace std;
typedef long long LL;

const LL INF = 1LL<<60;

const int MAXN = 1000005; // 1e6;
int n;
int a[MAXN],b[MAXN],h[MAXN],x[MAXN];
LL dp[MAXN];
int id[MAXN];
LL bit[MAXN<<1];
void upd(int i, LL val)
{
	for (; i > 0; i -= i&-i) bit[i]=max(bit[i],val);
}
LL query(int i)
{
	LL ans = 0;
	for (; i <= 2*n+2; i += i&-i) ans = max(bit[i],ans);
	return ans;
}
bool cmp(int x, int y)
{
	if (b[x]==b[y]) return a[x] < a[y]; else return b[x] < b[y];
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i,0,n) 
	{
		scanf("%d%d%d",&a[i],&b[i],&h[i]);
		x[2*i+1]=a[i], x[2*i+2]=b[i];
	}
	sort(x+1,x+2*n+1);
	rep(i,0,n)
	{
		a[i] = lower_bound(x,x+2*n,a[i]) - x;
		b[i] = lower_bound(x,x+2*n,b[i]) - x;
	}
	rep(i,0,n) id[i]=i;
	sort(id,id+n,cmp);
	rep(i,0,n)
	{
		int ii = id[i];
		LL t = query(a[ii]+1); 
		// cout<<t<<" "<<h[ii]<<" "<<t+h[ii]<<endl;
		dp[i] = t+h[ii];

		upd(b[ii],dp[i]);
	}
	LL res = -INF;
	rep(i,0,n) res = max(dp[i],res);
	cout<<res<<endl; 


}


