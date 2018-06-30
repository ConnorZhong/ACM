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
int n;
LL k;
int a[MAXN], cnt[MAXN];
queue<int> que;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%lld",&n,&k);
	rep(i, 1, n+1) scanf("%d",a+i);
	if (k > n)
	{	
		int ans = 0;
		rep(i,1,n+1)
		{
			if (a[ans] < a[i]) ans = i;
		}
		printf("%d\n",a[ans]);
	} else
	{
		int now = 1;
		rep(i, 2, n+1) 
		{
			que.push(i);
		}
		while(1)
		{
			int x = que.front();
			// de(x)
			que.pop();
			if (a[now] > a[x]) {
				cnt[now]++;
				que.push(x);
			} else 
			{
				que.push(now);
				now = x;
				cnt[now]++;
			}
			// de(now)
			if (cnt[now] == k) return 0*printf("%d\n",a[now]);
		}
	}
	return 0;
}

