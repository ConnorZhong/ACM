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
string s[MAXN], t[MAXN];
int n,q,ans;
void gao(string str)
{
	rep(i, 0, n-1)
	{
		rep(i,0,q)
		{
			if (str.substr(0,2)==s[i]) 
			{
				str.replace(0,2,t[i]);
				break;
			}
		}
	}
	if (str == "a") ans++;
}
void dfs(string p)
{
	// de(p)
	if (p.length()>=n)
	{
		gao(p);
		return;
	}
	rep(i, 0, 6)
	{
		dfs(p+(char)('a'+i));
	}
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&q);
	rep(i, 0, q)
	{
		cin >> s[i] >> t[i];
	}
	dfs("");
	printf("%d\n",ans);
	return 0;
}

