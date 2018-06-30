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
const double eps = 1e-10;
int x[MAXN], n, r;
double y[MAXN];
int abs(int x)
{
	if (x<0) return -x;
	else return x;
}
double d(int i, int j)
{
	double R = 2*r;
	return y[j] + sqrt(1.0*R*R - 1.0*(abs(x[i]-x[j])*abs(x[i]-x[j])));
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&r);
	rep(i, 1, n+1) scanf("%d",x+i);
	rep(i, 1, n+1)
	{
		double ans = r;
		rep(j, 1, i)
		{
			if (abs(x[i]-x[j]) <= 2*r)
			{
				ans = max(ans, d(i, j));
			}
		}
		y[i] = ans;
	}
	rep(i, 1, n+1)
	{
		printf("%.10f%c",y[i]," \n"[i==n]);
	}
	return 0;
}

