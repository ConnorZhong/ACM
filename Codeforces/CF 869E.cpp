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
#include <ctime>
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
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int INF = 0x3f3f3f3f;
const int MAXN = 2555; // 1e6;
int n,m,q;
map<pair<PII,PII>, ULL> hs;
ULL c[MAXN][MAXN];
void add(int x, int y, ULL val)
{
	for (int i=x;i<=n;i+=i&-i)
	for (int j=y;j<=m;j+=j&-j) c[i][j]+=val;
}
ULL sum(int x, int y)
{
	ULL ret = 0;
	for (int i=x;i;i-=i&-i) for (int j=y;j;j-=j&-j) ret += c[i][j];
	return ret;
}
ULL myRand()
{
	return ((ULL)rand()<<48)^((ULL)rand()<<32)^((ULL)rand()<<16)^(ULL)rand();
}
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&q);
	srand(time(0));
	rep(_,0,q)
	{
		int ty,x1,y1,x2,y2;
		scanf("%d%d%d%d%d",&ty,&x1,&y1,&x2,&y2);
		if (ty == 1) 
		{
			ULL HS = myRand();
			hs[mkp(mkp(x1,y1),mkp(x2,y2))]=HS;
			add(x1,y1,HS);
			add(x2+1,y2+1,HS);
			add(x1,y2+1,-HS);
			add(x2+1,y1,-HS);
		}
		else if (ty == 2)
		{
			ULL HS = hs[mkp(mkp(x1,y1),mkp(x2,y2))];
			add(x1,y1,-HS);
			add(x2+1,y2+1,-HS);
			add(x1,y2+1,HS);
			add(x2+1,y1,HS);
		}
		else 
		{
			ULL d1 = sum(x1,y1),d2 = sum(x2,y2);
			if (d1==d2) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}

