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
LL shift[MAXN];
int n;
void inline gao(LL layer, LL k)
{
	// de(layer) de(k)
	shift[layer] = ((shift[layer]+k)%(1ll<<layer-1)+(1ll<<layer-1))%(1ll<<layer-1);
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i, 0, n)
	{
		int ty;
		LL x,k;
		scanf("%d",&ty);
		// de(ty)
		if (ty==3)
		{
			// rep(i,0,5) printf("%d%c",shift[i]," \n"[i==4]);
			scanf("%lld",&x);
			LL X = x, L =0;
			while(X) L++, X>>=1;
			printf("%lld",x);
			x=(1ll<<(L-1)) + ((shift[L]+x%(1ll<<(L-1)))%(1ll<<L-1)+(1ll<<L-1))%(1ll<<L-1);
			x>>=1;
			L--;
			// de(x)
			while(L)
			{

				// de(L)
				// de(shift[L])
				LL tp = x;
				x=((-shift[L]+x%(1ll<<(L-1)))%(1ll<<(L-1))+(1ll<<L-1))%(1ll<<L-1)+(1LL<<(L-1));
				printf(" %lld",x);
				x=tp>>1;
				// de(x)
				L--;
			}
			printf("\n");
		}
		else
		{
			scanf("%lld%lld",&x,&k);
			LL X = x, L =0;
			while(X) L++, X>>=1;
			if (ty==1)
			{
				gao(L,k);
			}
			else 
			{
				rep(i,L,61) gao(i,k*(1ll<<(i-L)));
			}
		}
	}
	return 0;
}

