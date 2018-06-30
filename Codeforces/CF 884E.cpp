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
const int MAXN = (1<<14)+5; // 1e6;
int n,m,now,tot,comb;
int pp[2][MAXN];
int rt[MAXN],cp[MAXN],used[MAXN];
int find_root(int x)
{
	if (rt[x]!=x) return rt[x]=find_root(rt[x]);
	return rt[x];
}
bool Union(int x, int y)
{
	x=find_root(x);
	y=find_root(y);

	if (x!=y) 
	{
		rt[y]=x;
		return 1;
	}
	return 0;
}
char s[MAXN];
void get()
{
	rep(i, 0, m/4)
	{
		int x;
		if (s[i] >='A') x = s[i]-'A'+10;
		else x=s[i]-'0';
		rep(k,0,4)
		{
			pp[now][i*4+3-k]=x>>k&1;
			tot += x>>k&1;
		}
	}
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i, 0, m) rt[i]=i;
	rep(i, 0, n)
	{
		scanf("%s",s);
		get();
		// de("---")
		rep(i, 0, m)
		{
			// de(pp[now][i])
			if (pp[now][i])
			{
				// de(find_root(3)) de(find_root(2))
				if (pp[now^1][i]) comb++;
				if (i >= 1 && pp[now][i-1]) comb+=Union(i-1,i);
				// de(comb) de(tot)
			}
			
		}
		memset(cp,-1,sizeof cp);
		memset(used,-1,sizeof used);
		rep(i, 0, m)
		{
			int x = find_root(i);
			if (pp[now][i] == 0) cp[i]=i;
			else if (~used[x]) cp[i]=used[x];
			else 
			{
				if (pp[now][x]==0) cp[i] = i, used[x] = i;
				else cp[i]=x, used[x]=x;
			}
		}
		memcpy(rt,cp,sizeof cp);
		now=now^1;
	}
	printf("%d\n",tot-comb);
	return 0;
}

