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
string s[MAXN], a;

int n,cnt;
int main()
{
	// freopen("in.txt","r",stdin);
	cin>>a>>n; rep(i,0,n)cin>>s[cnt++];
	rep(i,0,n) rep(j,0,n) 
	{
		s[cnt++]=(string)""+s[i][1]+s[j][0];
	}
	rep(i,0,cnt) if (s[i]==a) return 0*puts("YES");
	puts("NO");
 	return 0;
}

