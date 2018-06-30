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
const int MAXN = 505; // 1e6;

char fld[MAXN][MAXN];
char op[MAXN];
int sx, sy, n, m;
int len = 0;
int perm[4];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int gao()
{

	int x = sx, y = sy;
	// de("==")
	// de(x) de(y)
	rep(i, 0, len)
	{
		int o = op[i]-'0';
		x += dx[perm[o]], y+=dy[perm[o]];
		// de(x) de(y)
		if (x>n||x<=0||y>m||y<=0||fld[x][y]=='#') return 0;
		if (fld[x][y] == 'E') return 1;
	}
	// de(x) de(y)
	return 0;
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	rep(i, 1, n+1)
	{
		scanf("%s", fld[i]+1);
	}

	scanf("%s",op);len=strlen(op);
	per(i, 0, 4) perm[i]=i;
	rep(i, 1, n+1) rep(j, 1, m+1) if (fld[i][j] == 'S') sx=i, sy=j;
	LL ans = 0;
	do
	{
		ans += gao();
	} while (next_permutation(perm,perm+4));
	printf("%lld\n",ans);
	return 0;
}

