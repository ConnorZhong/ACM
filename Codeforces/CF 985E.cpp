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
const int MAXN = 500005; // 1e6;

int bit[MAXN];
int a[MAXN],n,k,d;
int r[MAXN];
void add(int i, int val)
{
	for (;i<=n;i+=i&-i) bit[i]+=val;
}
int query(int i)
{
	int ret=0;
	for (;i;i-=i&-i) ret+=bit[i];
		return ret;
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&k,&d);
	rep(i, 1, n+1)scanf("%d",a+i);
	sort(a+1,a+n+1);
	int j = 1;
	rep(i, 1, n+1)
	{
		while (j<=n && a[j]<=a[i]+d) j++;
		// de(j)
		r[i]=j; 
	}
	if (r[1]>k){
		add(r[1],-1);
		add(k,1);
	}
	// de(1)
	// de(r[1])
	rep(i, 2, n+1)
	{
		if (query(i-1)>0)
		{
			// de(i) de(r[i])
			if (r[i] >= i-1+k)
			{
				add(r[i],-1);
				add(i-1+k,1);
			}
			
		}
	}
	if (query(n)) puts("YES");
	else puts("NO");
	return 0;
}

