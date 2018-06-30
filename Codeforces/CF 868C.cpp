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
int n,k;
int d[20];
int main()
{
	// freopen("in.txt","r",stdin);
	cin>>n>>k;
	rep(_, 0, n)
	{
		int ret = 0;
		rep(i, 0, k) 
		{
			int p; cin>>p; 
			// de(p)
			ret |= p<<i;
		}
		d[ret]++;
		// de(ret)
	}
	rep(mask, 1, 1<<(1<<k))
	{
		int ret[5];memset(ret,0,sizeof ret);
		int cnt = 0;
		rep(i, 0, (1<<k))
		{
			if ((mask >> i & 1) && d[i])
			{
				// de(d[i])
				cnt ++;
				rep(j, 0, k)
				{
					if (i >> j & 1) ret[j]++;
				}
			}
		}
		bool flag = false;
		if (cnt == 0) flag = true;;
		rep(i, 0, k) if (ret[i]*2 > cnt) flag= true;
		if (!flag) return 0*puts("YES");
		
	}
	puts("NO");
	return 0;
}

