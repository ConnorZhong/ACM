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
vector<int> B,R,P;
int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i,1,n+1)
	{
		int x, char s[5];
		scanf("%d%s",&x,s);
		if (s[0]=='R') R.pb(x);
		else if (s[i]=='B') B.pb(x);
		else P.pb(x);
	}
	LL ans = 0;
	if (P.size()==0)
	{
		if (B.size()>=1) ans += B[B.size()-1]-B[0];
		if (R.size()>=1) ans += R[R.size()-1]-R[0];
	}

	else 
	{
		int i = 0, ni = B.size();
		int j = 0, nj = R.size();
		int k = 0, nk = P.size();
		while(i<ni&&B[i]<P[k]) i++;
		while(i<ni&&B[ni-1]>P[nk-1])ni--;
		while(j<nj&&R[j]<P[k]) j++;
		while(j<nj&&R[nj-1]>P[nk-1])nj--;
		if (i!=0) ans += P[k]-B[0];
		if (j!=0) ans += P[k]-R[0];
		if (ni!=B.size()) ans += B[B.size()-1] - P[nk];
		if (nj!=R.size()) ans += R[R.size()-1] - P[nk];
		
		for (k=k+1;k<nk;k++)
		{
			LL maB = -INF, maR = -INF;
			if (i<ni&&B[i]<P[k]) maB = max(P[k]-B[i], B[i]-P[k-1]), i++;
			if (j<nj&&R[j]<P[k]) maR = max(P[k]-R[j], R[j]-P[k-1]), j++;
			while(i<ni && B[i]<P[k]) maB = max(maB, B[i]-B[i-1]), i++;
			while(j<nj && R[j]<P[k]) maR = max(maR, R[j]-P[j-1]), j++;
			ans += min(2ll*(P[k]-P[k-1]), 3ll*(P[k]-P[k-1])-maB-maR);
		}
	}
	printf("%lld\n",ans);
	return 0;
}

