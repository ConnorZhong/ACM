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
int res[MAXN];
void gao(int n)
{
	if (n == 0) return ;
	int p = 0;
	int x = n;
	while(x) x>>=1, p++;
	p--;
	rep(i, (1<<p), n+1) 
	{
		swap(res[i], res[(1<<p)-1-(i-(1<<p))]);
	}
	gao((1<<p) - (n - (1<<p) + 1) - 1);
}
void task1(int n)
{
           if (n&1) 
           {
           	puts("NO");return;
           }
           puts("YES");
           rep(i, 1, n+1) res[i]=i;
           gao(n);
           rep(i, 1, n+1) 
           {
           	// if ((res[i] & i)) puts("====");
           	printf("%d%c",res[i]," \n"[i==n]);
           }
}
void task2(int n)
{
	if (n < 6 || (n & (n-1)) == 0) 
	{
		puts("NO"); return;
	}
	puts("YES");
	int i;
	rep(i, 1, n+1) res[i]=i;
	if (n & 1)
	{
		i = 8;
		rep(i, 1, 8)
		{
			res[i]=" 5326174"[i] - '0';
		}
	}
	else 
	{
		i = 7;
		rep(i, 1, 7)
		{
			res[i]=" 532614"[i]-'0';
		}
		// printf("5 3 2 6 1 4");

	}

	for (;i<n;i+=2)
	{
		if (!(i & (i+1)))
		{
			swap(res[i],res[i+2]); swap(res[i+1], res[i+3]);
			i += 2;
		}
		else  res[i]=i+1, res[i+1]=i;
	}
	rep(i, 1, n+1) 
	{
		// if ((i&(res[i])) == 0 && res[i]!=i) puts("???");
		printf("%d%c",res[i]," \n"[i==n]);
	}
	// printf("\n");
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	task1(n);
	task2(n);
	return 0;
}

