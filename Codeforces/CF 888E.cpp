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
int n, p;
int a[MAXN];
int cnt1, cnt2, s1[MAXN],s2[MAXN];
int main()
{
	// freopen("in.txt","r",stdin);
	cin>>n>>p;
	rep(i,0,n) cin>>a[i];	
	int m = n>>1;
	rep(i,0,1<<m)
	{
		int d = 0;
		rep(j,0,m)
		{
			if (i >> j & 1) (d+=a[j])%=p; 
		}
		s1[cnt1++]=d;
	}
	rep(i,0,1<<(n-m))
	{
		int d = 0;
		rep(j,0,(n-m))
		{
			if (i >> j & 1) (d+=a[m+j])%=p;
		}
		s2[cnt2++]=d;
	}
	sort(s1,s1+cnt1);
	int ans = s1[cnt1-1];

	rep(i,0,cnt2)
	{
		int pos = lower_bound(s1,s1+cnt1,p-s2[i])-s1;
		pos --; 
		// de(s1[pos])
		ans = max(s1[pos]+s2[i],ans);
	}
	printf("%d\n",ans);
	return 0;
}

