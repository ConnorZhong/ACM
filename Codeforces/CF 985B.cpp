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
#include <cassert>
#include <bitset>
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
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
LL powmod(LL a,LL b,LL mod) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL gcd(LL a, LL b) {if (b==0)return a;else return gcd(b,a%b);}
const int INF = 0x3f3f3f3f;
const int MAXN = 2005; // 1e6;
int n ,m;
char s[MAXN][MAXN];
int cnt[MAXN];
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i, 0, n)
	{
		scanf("%s",s[i]);
	}
	rep(i,0,n)
	{
		rep(j,0,m) cnt[j] += s[i][j]-'0';
	}
	bool flag= false;
	rep(i, 0, n)
	{
		bool go = true;
		rep(j, 0, m) if (s[i][j]=='1' && cnt[j]==1) go =false;
		flag |= go;
	}
	if (flag)puts("YES");
	else puts("NO");
	return 0;
}

