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
const int MAXN = 5000005; // 1e6;
int n;
int a[MAXN];
int b[MAXN], bn;
bool isprime[MAXN];
vector<int> fac[MAXN];
set<int> p;
bool addNum(int x)
{
	rep(j, 0, SZ(fac[x])) if (p.count(fac[x][j])!=0) return false;
	b[++bn]=x;
	rep(j, 0, SZ(fac[x]))
	{
		p.insert(fac[x][j]);
	}
	return true;
}
int main()
{
	// freopen("in.txt","r",stdin);

	int cnt = 0;
	rep(i, 2, MAXN)
	{
		if (!isprime[i]) 
		{
			fac[i].pb(i);
			cnt++;
			for (int j = i+i;j<MAXN;j+=i) 
			{
				fac[j].pb(i);
				isprime[j]=true;
			}
		}
	}
	//de(cnt)
	scanf("%d",&n);
	rep(i, 1, n+1) scanf("%d",a+i);
	int now = 2; bool flag = false;
	for (int i = 1; i <= n && !flag; i++)
	{
		if (!addNum(a[i])) 
		{
			for (int j=a[i]+1;;j++) 
			{
				if (addNum(j))
				{
					flag = true;
					break;
				}
				
			}
		}
	}
	for (int i = 2;bn<n;i++)
	{
		if (!isprime[i]) addNum(i);
	}
	rep(i, 1, n+1) printf("%d%c",b[i]," \n"[i==n]);
	return 0;
}

