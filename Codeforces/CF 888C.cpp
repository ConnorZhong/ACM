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
char s[MAXN];
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%s",s);
	int len=strlen(s);
	int ans = INF;
	rep(k,0,26)
	{
		char ch='a'+k;
		int t = 0;
		int r = 0;
		rep(i,0,len)
		{
			if (s[i]==ch) t=0;
			else t++, r = max(t,r);
		}
		ans = min(ans, r);
	}
	printf("%d\n",ans+1);
	return 0;
}

