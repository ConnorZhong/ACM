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
string f0 ="What are you doing at the end of the world? Are you busy? Will you save us?";
string f1 ="What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
LL len[MAXN];
//34,66，32
char ans='.';
int n;
LL k;
bool flag;
int t;

void dfs(int i, LL &l)
{
	// de(i) de(l)
	if (flag) return;
	if (i <= t && len[i]<l) return;
	if (i == 0) 
	{
		if (l > f0.length()) return;
		else 
		{
			ans = f0[l-1];
			flag = true;
			return;
		}
	}
	if (l <= 34)
	{
		ans = f1[l-1];
		flag = true;
		return;
	}
	l -= 34;
	if (i > t || len[i-1]>=l) dfs(i-1,l);
	else 
	{
		l -= len[i-1];
		if (l+34 <= 66)
		{
			ans = f1[l+33];
			flag = true;
			return;
		}
		l -= 66-34;
		if (i > t || len[i-1]>=l) dfs(i-1,l);
		else 
		{
			l -= len[i-1];

			ans = f1[l+65];
			flag = true;
			return;
		}
	}
	


}
int main()
{
	freopen("in.txt","r",stdin);
	len[0]=f0.length();

	rep(i,1,MAXN) 
	{
		len[i]=len[i-1]*2ll+f1.length();
		if (len[i]>=1e18) 
		{
			t = i;
			break;
		}
	}
	// de(t)
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans='.';flag=false;
		scanf("%d%lld",&n,&k);
		dfs(n,k);
		// de(k)
		// de(len[1])
		printf("%c",ans);
	}
	return 0;
}

