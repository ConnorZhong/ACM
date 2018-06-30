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
const int MAXN = 1000005; // 1e6;
map<int ,int> bit[MAXN];
void add(int i, int w, int val)
{
	w++;
	for (;w<=100001;w+=w&-w) 
	{
		// de(w)
		bit[i][w]=max(bit[i][w],val);
	}
}
int query(int i, int w)
{
	w++;
	int ret = 0;
	for (;w>0;w-=w&-w) ret=max(ret,bit[i][w]);
		return ret;
}
int n,m;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	// rep(i,1,n+1) dp[i][-1]=0;
	map<int,int> :: iterator ite;
	int ans = 0;
	rep(i,0,m)
	{
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		int p = query(u,w-1)+1;
		// de(p)
		add(v,w,p);
		ans = max(ans,p);
		// de(u)
	}
	printf("%d\n",ans);

	return 0;
}

