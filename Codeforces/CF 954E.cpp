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
int n,T; 
int c[MAXN],t[MAXN];
double ans = 0;
typedef pair<double,double> PDD;
priority_queue< PDD,vector<PDD>,greater<PDD>> a,b;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&T);
	rep(i, 0, n) scanf("%d",c+i);
	rep(i, 0, n) scanf("%d",t+i);
	rep(i, 0, n) 
	{
		if (t[i]==T) ans += c[i];
		else if (t[i]>T) a.push(mkp(t[i]-T,c[i]));
		else b.push(mkp(T-t[i],c[i]));
	}
	while(!a.empty() && !b.empty())
	{
		double xa = a.top().fi, xb = b.top().fi;
		double ya = a.top().se, yb = b.top().se;
		a.pop(), b.pop();
		if (xa*ya > xb*yb) 
		{
			ans += yb + xb*yb/xa;
			ya -= xb*yb/xa;
			a.push(mkp(xa,ya));
		}
		else if (xa*ya < xb*yb)
		{
			ans += ya + xa*ya/xb;
			yb -= xa*ya/xb;
			b.push(mkp(xb,yb));
		}
		else ans +=ya+yb;
	}
	printf("%.10f\n",ans);
	return 0;
}

