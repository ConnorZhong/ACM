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
int n,m,c,x;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&c);
	rep(_,1,m+1)
	{
		scanf("%d",&x);
		if (x <= c/2)
		{
			for (int i=1;i<=n;i++)
			{
				if (a[i]==0||a[i]>x) 
				{
					a[i]=x;
					printf("%d\n",i);
					break;
				}

			}
		}
		else
		{
			for (int i=n;i>=1;i--)
			{
				if (a[i]<x)
				{
					a[i]=x;
					printf("%d\n",i);
					break;
				}
			}
		}
		bool flag = true;
		rep(i,1,n+1) if (a[i]==0) flag =false;
		if (flag)
		rep(i,2,n)
		{
			if (a[i-1] > a[i] || a[i] <= a[i+1]) flag = false;
		}
		fflush(stdout);
		if (flag) break;
	}
	return 0;
}

