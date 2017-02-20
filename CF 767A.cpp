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
#define rep(i,a,b) for (int i=(a);i<(b);i++)
#define per(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,a,b) for (int i=(a);i<=(b);i++)
#define PER(i,a,b) for (int i=(b);b>=(a);i--)
using namespace std;
typedef long long LL;

const int INF = 0x3f3f3f3f;

const int MAXN = 1000005; // 1e6;
int n;
bool a[MAXN];
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	int bottom = n;
	rep(i,0,n) 
	{
		int now;
		scanf("%d",&now);
		a[now] =1 ;
		// cout<<">> "<<now<<endl;
		while(a[bottom]) printf("%d ",bottom--);
		printf("\n");
		
	}


}

