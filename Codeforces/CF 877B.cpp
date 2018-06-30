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
int cnt;
int a[MAXN],b[MAXN];
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%s",s+1);
	int n = strlen(s+1);
	rep(i, 1, n+1)
	{
		a[i] = a[i-1] + (s[i]=='a');
		b[i] = b[i-1] + (s[i]=='b');
	}	
	int ans = 0;
	rep(i, 0, n+1) rep(j, i, n+1)
	{
		ans = max(ans, a[i]+b[j]-b[i]+a[n]-a[j]);
	}
	printf("%d\n",ans);

	return 0;
}

