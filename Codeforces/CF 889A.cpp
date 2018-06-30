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
int cnt=0;
int n,t[MAXN];
bool used[MAXN];
int vis[MAXN],last[MAXN];
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);rep(i,1,n+1) scanf("%d",t+i);
	vis[0]=++cnt;
	last[1]=0;
	rep(i,1,n+1)
	{
		if (last[vis[t[i]]] ==t[i]) 
		{
			vis[i]=vis[t[i]];
			last[vis[i]]=i;
		}
		else 
		{
			vis[i]=++cnt;
			last[vis[i]]=i;
		}
	}
	printf("%d\n",cnt);
	return 0;
}

