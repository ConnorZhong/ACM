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
int a[MAXN];
int stk[MAXN], top;
int l[MAXN],r[MAXN];
int seq[35][MAXN];
int len[35];
int n;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",a+i);
	for (int i=1;i<=n;i++)
	for (int j=0;j<30;j++)
	{
		if (a[i]>>j & 1) seq[j][len[j]++] = i;
	}
	for (int i=0;i<30;i++) sort(seq[i],seq[i]+len[i]);
	a[0]=a[n+1]=INF;
	stk[top++]=0;
	for (int i=1;i<=n+1;i++)
	{
		while (top && a[stk[top-1]] < a[i]) 
		{
			// de(stk[top-1]) de(i)
			r[stk[top-1]]=i;
			top--;
		}
		stk[top++]=i;
	}
	top=0;
	stk[top++]=n+1;
	for (int i=n;i>=0;i--)
	{
		while (top && a[stk[top-1]] <= a[i])
		{
			l[stk[top-1]]=i;
			top--;
		}
		stk[top++]=i;
	}
	LL ans = 1ll*n*(n-1)/2;
	int ite;
	for (int i=1;i<=n;i++)
	{
		int ll = l[i],rr = r[i];
		for (int j=0;j<30;j++)
		{

			if (!(a[i]>>j&1))
			{
				ite = lower_bound(seq[j],seq[j]+len[j],i) - seq[j];
				if (ite != len[j]) rr = min(rr, seq[j][ite]);
				if (ite != 0) ll = max(ll,seq[j][ite-1]);
			}
		}
		ans -= 1ll*(i - ll)*(rr-i-1) + (i-ll-1);
	}
	printf("%lld\n",ans);
	return 0;
}

