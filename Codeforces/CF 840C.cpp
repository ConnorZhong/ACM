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
#include <bitset>
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

const int INF = 0x3f3f3f3f;
const int MAXN = 1005; // 1e6;
const int mod = 1e9+7;
int a[MAXN],n,d[MAXN],comb[MAXN][MAXN],used[MAXN],cnt,fc[MAXN];
map<int,int> fac[MAXN];
void upd(int &x, int y)
{
	x+=y;
	if (x>=mod) x-=mod;
}
bool check(int i, int j)
{
	// de(i) de(j)
	map<int,int> mmp;
	for (auto x: fac[i]) mmp[x.fi]+=x.se;
	for (auto x: fac[j]) mmp[x.fi]+=x.se;
	for (auto x: mmp) 
	{
		// de(x.fi) de(x.se)
		if (x.se & 1) return false;
	}
	return true; 
}
int f[MAXN][MAXN];
int main()
{
	// freopen("in.txt","r",stdin);
	fc[0]=1;
	rep(i, 1, MAXN) fc[i]=1ll*i*(fc[i-1])%mod;
	rep(i, 0, MAXN)
	{
		comb[i][0]=1;
		rep(j, 1, i+1) comb[i][j] = (comb[i-1][j-1]+comb[i-1][j])%mod;
	}
	scanf("%d",&n);
	rep(i, 1, n+1) 
	{
		scanf("%d",a+i);
		for (LL j=2;j*j<=a[i];j++)
		{
			while(a[i]%j==0) a[i]/=j, fac[i][j]++;
		}
		if (a[i]>1) fac[i][a[i]]++;
	}
	cnt = 1;
	rep(i, 1, n+1)
	{
		if (!used[i])
		{
			used[i]=true;
			d[cnt]=1;
			rep(j, i+1, n+1)
			{
				if (!used[j])
				{
					if (check(i,j))
					{
						used[j]=1;
						d[cnt]++;
					}
				}
			}
			cnt++;
		}
	}
	// de(check(1,3))
	f[0][0]=1;
	int tot=0;
	rep(i, 1, cnt)
	{
		rep(j, 0, n)
		{
			rep(k, 0, d[i]) // 有 k 个相邻，即 k 个元素，剩下 d-k 个块。
			{
				LL tt = 1ll*fc[d[i]]*comb[d[i]-1][d[i]-k-1]%mod;
				rep(t, 0, d[i]-k+1)
				{
					if (j < t) break;
					upd(f[i][j+k-t], 1ll*f[i-1][j]*comb[j][t]%mod*comb[tot+1-j][d[i]-k-t]%mod*tt%mod);
				}
			}
		}
		tot += d[i];
	}
	printf("%d\n",f[cnt-1][0]);
	return 0;
}

