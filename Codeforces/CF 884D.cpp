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
const int MAXN = 1000005; // 1e6;
priority_queue<LL, vector<LL> , greater<LL> > Q;

int n;
int main()
{
	// freopen("in.txt","r",stdin);
	scanf("%d",&n);
	rep(i, 0, n) 
	{
		int x;scanf("%d",&x); Q.push(x);
	}
	if (n%2==0) Q.push(0);
	LL ans = 0;
	while(!Q.empty())
	{
		LL p = Q.top(); Q.pop();
		if (Q.empty()) break;
		p += Q.top();Q.pop();
		p += Q.top();Q.pop();
		ans += p;
		Q.push(p);
	}
	printf("%lld\n",ans);
	return 0;
}

