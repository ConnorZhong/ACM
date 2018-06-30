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
int n;
typedef pair<LL,int> P;
vector<LL> ans;
LL a[MAXN],b[MAXN];
priority_queue<P,vector<P>,greater<P>> que;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i,1,n+1)
	{
		LL x;scanf("%lld",&x);
		que.push(mkp(x,i));
	}

	while(!que.empty())
	{
		LL x=que.top().fi, id =que.top().se;
		que.pop();
		if (!que.empty() && que.top().fi == x)
		{
			id=que.top().se;que.pop();
			que.push(mkp(x<<1, id));
		}
		else 
		{
			a[id]=x;
		}
	}
	rep(i,1,n+1) if(a[i]) ans.pb(a[i]);
	printf("%lu\n",ans.size());
	rep(i,0,ans.size()) printf("%lld%c",ans[i]," \n"[i==n]);
	return 0;

}

