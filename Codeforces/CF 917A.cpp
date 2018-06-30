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
char a[MAXN];
int n;
int abs(int x)
{
	if (x<0) return -x;
	else return x;
}
bool check(int x, int t)
{
	return (x <= t && (x%2) == (t%2));
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%s",a);
	n = strlen(a);
	int ans = 0;
	rep(i,0,n)
	{
		// de(i)
		int l = 0, r = 0, m = 0;
		rep(j, i, n)
		{
			// de(a[j])
			// de(j)
			if (a[j] == '(') l++;
			if (a[j] == ')') r++;
			if (a[j] == '?')
			{
				if (r + 1> l + m) l++;
				else m ++;
			}
			if (r > l && m) l ++, m --;
			else if (r > l && !m) break;
			if (m && r + m > l) l++, m --;
			if ( (check(abs(l-r),m))) 
			{
				// de("=")
				ans ++;
				// de(i) de(j)
				// de(l) de(r) de(m)
			}
		}	
	}
	printf("%d\n",ans);
	return 0;
}

