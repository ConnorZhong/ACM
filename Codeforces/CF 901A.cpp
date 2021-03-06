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
int a[MAXN], n;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i, 0, n+1) scanf("%d",a+i);
	bool flag = true;
	rep(i, 1, n+1)
	{
		if (a[i] > 1 && a[i-1] > 1) flag = false;
	}
	if (flag) puts("perfect");
	else 
	{
		puts("ambiguous");
		int last = 1;
		int cnt = 1;
		printf("0 ");
		rep(i, 1, n+1)
		{
			rep(j,0,a[i]) printf("%d ",last), cnt++;
			last = cnt;
		}
		printf("\n");
		printf("%d ",0);
		last = 1, cnt = 1;
		int llast = 1;
		rep(i, 1, n+1)
		{
			rep(j, 0, a[i])
			{
				if (cnt & 1)
					printf("%d ",last);
				else 
					printf("%d ",llast);
				cnt++;
			}
			llast = last+1, last = cnt;
		}
	}
	return 0;
}

