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

const int INF = 0x3f3f3f3f;

const int MAXN = 1000005; // 1e6;
LL n,ts,tf,t;
LL arr[MAXN],now;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%lld%lld%lld",&ts,&tf,&t);
	scanf("%lld",&n);
	rep(i,0,n) scanf("%lld",&arr[i]);
	arr[n++] = tf-t+1;
	now = ts;
	LL ans = 0, ti = ts;
	rep(i,0,n)
	{
		// cout<<arr[i]<<" 1 1 "<<now<<endl;
		if (arr[i] <= now) now = now + t;
		else  
		{
			// cout<<now<<endl;
			if (now + t > tf) break;
			else 
			return 0*printf("%lld\n",now);
		}
		if (now > tf) break;
		// cout<<now<<" "<<ti<<endl;

		if (ti > now-t-arr[i]+1) ans = arr[i]-1, ti = now - t-arr[i]+1;
		// cout<<now<<"   "<<ti<<endl;
	}
	cout<<ans<<endl;

}

