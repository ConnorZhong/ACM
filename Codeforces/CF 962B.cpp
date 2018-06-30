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
int n,a,b;
char s[MAXN];
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	scanf("%d%d",&a,&b);
	scanf("%s",s+1);
	// de(s+1)
	int ans = 0;
	rep(i,1,n+1)
	{
		// de(s[i])
		if (s[i] == '.')
		{
			// de(s[i])
			if (s[i-1]=='a') {
				if (b) b--,ans++,s[i]='b';
			}
			else if (s[i-1]=='b')
			{
				if(a) a--,ans++,s[i]='a';
			}
			else 
			{
				if (a>=b) 
				{
					if (a)
					a--,ans++,s[i]='a';
				}
				else 
				{
					if (b) b--,ans++,s[i]='b';
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

